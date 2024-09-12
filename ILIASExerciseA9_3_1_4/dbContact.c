#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <string.h>

//Function declaration
char* TypeInfo(enum enum_field_types type);
void ConnectDatabase();
void ClearBuffer();
void CreateTable();
void DataBankCredentials(char* username, char* password);
void DisconnetDatabse();
void InsertData();
bool IsNumber(char const* const input);
void Menu();
void PrintError();
void PrintLine(MYSQL_RES* res);
void PrintUnderline(int count);
void ShowTable();
void RemoveSpace(char* restrict str_trimmed, const char* str_untrimmed);


// Global variable
MYSQL* conn;

// Function definition

/**
 * Clears input buffer to prevent scanf faults
 */
void ClearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    };
}

/**
 * Print MYSQL error messages with error codes
 */
void PrintError()
{
    if (mysql_errno(conn) != 0)
    {
        fprintf(stderr, "ERROR: %u %s\n", mysql_errno(conn), mysql_error(conn));
        exit(EXIT_FAILURE);
    }
}

/**
 * Prints a divider as part of a MYSQL table
 * @param res
 */
void PrintLine(MYSQL_RES* res)
{
    MYSQL_FIELD* field;
    unsigned int i, j;

    mysql_field_seek(res, 0);

    printf("+");

    for (i = 0; i < mysql_num_fields(res); i++)
    {
        field = mysql_fetch_field(res);
        for (j = 0; j < field->max_length + 2; j++) printf("-");
        printf("+");
    }
    printf("\n");
}

/**
 * Prints a certain amount of _
 * @param count Number of _ that should be printed
 */
void PrintUnderline(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("_");
    }
    printf("\n");
}

/**
 * Checks if a given string is a number
 * @param input String input that should be checked
 * @return True if input was a number, false otherwise
 */
bool IsNumber(char const* const input)
{
    if (input == NULL || input[0] == '\0' || input[0] == '.')
    {
        return false;
    }

    int dot_counter = 0;
    char character = '0';
    for (int i = 0; input[i] != '\0'; i++)
    {
        character = input[i];
        if ((!isdigit(character) && input[i] != '.') || (character == '.' && dot_counter > 1))
        {
            return false;
        }
        if (input[i] == '.') dot_counter++;
    }
    return true;
}

/**
 * Removes white spaces  from a string
 * @param str_trimmed String that will be changed
 * @param str_untrimmed Unchanged string
 */
void RemoveSpace(char* restrict str_trimmed, const char* str_untrimmed)
{
    while (*str_untrimmed != '\0')
    {
        if (!isspace(*str_untrimmed))
        {
            *str_trimmed = *str_untrimmed;
            str_trimmed++;
        }
        str_untrimmed++;
    }
    *str_trimmed = '\0';
}

/**
 * Displays all elements of a MYSQL table
 */
void ShowTable()
{
    unsigned int i, col_len;
    int size = 0;
    char table[255];
    char *ptr, *query, *str[2];
    MYSQL_ROW row;
    MYSQL_RES* res;
    MYSQL_FIELD* field;

    system("clear");
    printf("\nPlease enter the name of the table you would like to access: ");
    fgets(table, 254, stdin);
    if ((ptr = strchr(table, '\n')) != NULL) *ptr = '\0';

    // Create request string parts
    str[0] = "SELECT * from ";
    str[1] = malloc(strlen(table) + 1);
    strcpy(str[1], table);

    // Create whole request string
    size = strlen(str[0]) + strlen(str[1]);
    query = malloc(size + 1);
    strcpy(query, str[0]);
    strcat(query, str[1]);

    // Check if query is build correct
    //printf ("%s\n", query);

    // Request to data bank server
    mysql_real_query(conn, query, strlen(query));
    PrintError();

    // Load request into MYSQL_RES
    res = mysql_store_result(conn);
    PrintError();

    mysql_field_seek(res, 0);

    // Find max column length
    for (i = 0; i < mysql_num_fields(res); i++)
    {
        field = mysql_fetch_field(res);
        col_len = strlen(field->name);
        if (col_len < field->max_length) col_len = field->max_length;

        // Case Empty column
        if (col_len < 4 && !IS_NOT_NULL(field->flags)) col_len = 4;

        field->max_length = col_len;
    }

    system("clear");
    printf("\nHere is the table of %s:\n\n", field->table);
    PrintLine(res);

    printf("|");

    mysql_field_seek(res, 0);

    // Print table header
    for (i = 0; i < mysql_num_fields(res); i++)
    {
        field = mysql_fetch_field(res);
        printf(" %-*s |", field->max_length, field->name);
    }

    printf("\n");

    PrintLine(res);

    // Print Table
    while ((row = mysql_fetch_row(res)) != NULL)
    {
        mysql_field_seek(res, 0);
        printf("|");
        for (i = 0; i < mysql_num_fields(res); i++)
        {
            field = mysql_fetch_field(res);

            // Case no data in column
            if (row[i] == NULL)
            {
                printf(" %-*s |", field->max_length, "NULL");
            }
            // Case Number
            else if (IS_NUM(field->type))
            {
                printf(" %*s |", field->max_length, row[i]);
            }
            // Case Text
            else
            {
                printf(" %-*s |", field->max_length, row[i]);
            }
        }
        printf("\n");
    }

    PrintLine(res);
    mysql_free_result(res);


    printf("\n\nPress Enter to return to menu:\n");
    getchar();
    free(query);
}

/**
 * Checks the datatype of a MYSQL field enum
 * @param type enum element of the field type parameter
 * @return returns string naming the data type
 */
char* TypeInfo(enum enum_field_types type)
{
    switch (type)
    {
    case MYSQL_TYPE_VAR_STRING:
        return "Word";

    case MYSQL_TYPE_DOUBLE:
        return "Decimal";

    case MYSQL_TYPE_LONG:
        return "Integer";
    }
}

/**
 * Function that let user create a table
 */
void CreateTable()
{
    // Function parameters
    int datatypeChoice = 0;
    int i = 0;
    int querySize = 0;
    int maxTableName = 10;
    int maxTableNum = 5;
    int tableNum = 0;
    char answer;
    char* datatype;
    char *queryParts[5], *ptr;
    char* query;
    char* temp[maxTableName + 1];
    bool finished = false;
    bool firstTime = true;
    MYSQL_RES* res;

    queryParts[0] = "CREATE TABLE ";
    queryParts[1] = malloc(11);
    system("clear");
    do
    {
        printf("Please enter the name of your table.\n"
            "The name can only be 10 characters long.\n"
            "Any longer input will be cut off!\"Empty spaces will be removed!!\n"
            "Press enter (at least once) to confirm input.\n");

        PrintUnderline(10);
        fgets(queryParts[1], 10, stdin);
        ClearBuffer();
        RemoveSpace(queryParts[1], queryParts[1]);
        if (queryParts[1] == '\0')
        {
            printf("Table name can't be empty!\n"
                "Please try again:\n");
        }
    }
    while (queryParts[1] == "\0");
    queryParts[2] = " (";
    system("clear");
    do
    {
        printf("Please enter a number between 1 and 5 for the number of "
            "columns you would like to have:\n");
        scanf("%d", &tableNum);
        ClearBuffer();
        if (tableNum > maxTableNum || tableNum < 1)
        {
            printf("Wrong Input!\nPress enter to try again.\n");
            getchar();
        }
    }
    while (tableNum > maxTableNum || tableNum < 1);

    for (i = 0; i < tableNum; i++)
    {
        // Asking for the names of the columns
        system("clear");
        do
        {
            printf("Please enter the name of the %d. column.\n"
                   "All white spaces will be removed and input can't be empty!\n"
                   "the maximum input size is %d\n", i + 1, maxTableName);
            PrintUnderline(10);
            fgets(temp, maxTableName, stdin);
            ClearBuffer();
            RemoveSpace(temp, temp);
            if (temp[0] == '\0')
            {
                printf("Input can't be empty!!\nPress enter to try again\n");
                getchar();
            }
        }
        while (temp == '\0');

        // Asking for the datatype of the columns
        do
        {
            system("clear");
            printf("Which datatype should your %d. column have?\n"
                   "Please enter the number next to the datatype and press enter.\n"
                   "1. Integer\n"
                   "2. String\n", i + 1);
            scanf("%d", &datatypeChoice);
            ClearBuffer();

            if (datatypeChoice > 2 || datatypeChoice < 1)
            {
                printf("Wrong input!\nPlease press enter to try again:\n");
                getchar();
            }
        }
        while (datatypeChoice > 2 && datatypeChoice < 1);

        switch (datatypeChoice)
        {
        case 1:
            datatype = "int";
            break;

        case 2:
            datatype = "varchar(255)";
            break;
        }
        // Sets together the table name query part
        if (firstTime)
        {
            queryParts[3] = malloc(strlen(temp) + strlen(datatype)
                + (tableNum - 1) * 3 + 1 + 1);
            strcpy(queryParts[3], temp);
            strcat(queryParts[3], " ");
            strcat(queryParts[3], datatype);
            firstTime = false;
        }
        else
        {
            strcat(queryParts[3], ", ");
            ptr = realloc(queryParts[3], sizeof (queryParts[3]) * strlen(queryParts[3]) + strlen(datatype)
                          + strlen(temp));
            queryParts[3] = ptr;
            strcat(queryParts[3], temp);
            strcat(queryParts[3], " ");
            strcat(queryParts[3], datatype);
        }
    }

    queryParts[4] = ");";

    // Create the query
    for (i = 0; i < 5; i++)
    {
        querySize += strlen(queryParts[i]);
    }

    query = malloc(querySize + 1);
    strcpy(query, queryParts[0]);
    for (i = 1; i < 5; i++)
    {
        strcat(query, queryParts[i]);
    }

    // Request to data bank server
    mysql_real_query(conn, query, strlen(query));
    PrintError();


    printf("Following table with name %s and columns %s will be created.\n", queryParts[1], queryParts[3]);
    printf("Do you want to create another table?\n Enter 'n' for no and any other key for yes and press enter:\n");
    scanf("%c", &answer);
    ClearBuffer();
    if (answer != 'n') CreateTable();
}

/**
 * Function that will add data to a table
 */
void InsertData()
{
    // Function parameter
    int i = 0;
    int size = 0;
    int input = 0;
    int length = 0;
    bool finished = false;
    bool firstTime = true;
    char answer = "0";
    char *ptr, *query, *str[7], *strTable[3], *tableName;
    char* database;
    MYSQL_RES* res;
    MYSQL_FIELD* field;
    MYSQL_ROW row;

    size = 0;
    // Find database name
    mysql_real_query(conn, "SELECT DATABASE()", strlen("SELECT DATABASE()"));
    PrintError();

    res = mysql_store_result(conn);
    PrintError();

    mysql_field_seek(res, 0);
    field = mysql_fetch_field(res);

    row = mysql_fetch_row(res);
    database = row[0];

    mysql_free_result(res);

    // User selection for table to put data in
    system("clear");
    printf("To which table would you like to add Data?\n");

    // MYSQl request to get table names
    strTable[0] = "SELECT TABLE_NAME FROM information_schema.tables WHERE table_schema = '";
    strTable[1] = database;
    strTable[2] = "'";
    query = malloc(strlen(strTable[0]) + strlen(strTable[1]) + strlen(strTable[2]) + 1);
    strcpy(query, strTable[0]);
    strcat(query, strTable[1]);
    strcat(query, strTable[2]);

    // Request to database
    mysql_real_query(conn, query, strlen(query));
    PrintError();

    res = mysql_store_result(conn);
    PrintError();
    do
    {
        system("clear");
        // Print table names
        i = 0;
        mysql_data_seek(res, 0);
        printf("In which table would you like to insert data:\n");
        while ((row = mysql_fetch_row(res)) != NULL)
        {
            mysql_field_seek(res, 0);
            field = mysql_fetch_field(res);
            printf("%d. %s", i + 1, row[0]);
            printf("\n");
            i++;
        }
        printf("Please Enter the number of the corresponding table:\n");
        scanf("%d", &input);
        ClearBuffer();

        if (input > mysql_num_rows(res) || input < 1)
        {
            printf("This table number does not exist.\nPress Enter to try again:\n");
            getchar();
        }
    }
    while (input > mysql_num_rows(res) || input < 1);

    mysql_data_seek(res, input - 1);
    row = mysql_fetch_row(res);
    tableName = row[0];
    // Test if tableName is correctly set
    // printf ("%s\n", tableName);

    mysql_free_result(res);

    mysql_real_query(conn, query, strlen(query));
    PrintError();

    res = mysql_store_result(conn);
    PrintError();

    free(query);

    // Query to select table
    str[0] = "SELECT * from ";
    str[1] = malloc(strlen(tableName) + 1);
    strcpy(str[1], tableName);
    query = malloc(strlen(str[0]) + strlen(str[1]) + 1);
    strcpy(query, str[0]);
    strcat(query, str[1]);

    // New MYSQL Request to get field names of table
    mysql_real_query(conn, query, strlen(query));
    PrintError();

    res = mysql_store_result(conn);
    PrintError();

    // checks if query is correct
    // printf("%s\n", query);

    // Create query to insert data
    str[0] = "INSERT INTO ";
    str[1] = malloc(strlen(tableName) + 1);
    strcpy(str[1], tableName);
    str[2] = " (";


    mysql_field_seek(res, 0);

    // Find size for memory allocation for str[3]
    for (i = 0; i < mysql_num_fields(res); i++)
    {
        field = mysql_fetch_field(res);
        if (field->flags & AUTO_INCREMENT_FLAG)
        {
            continue;
        }
        size += field->name_length;
    }
    size += (mysql_num_fields(res) - 1) * 2;
    str[3] = malloc(size + 1);
    mysql_field_seek(res, 0);

    // field = mysql_fetch_field (res);


    for (i = 0; i < mysql_num_fields(res); i++)
    {
        field = mysql_fetch_field(res);
        if (field->flags & AUTO_INCREMENT_FLAG)
        {
            continue;
        }
        if (firstTime)
        {
            strcpy(str[3], field->name);
            firstTime = false;
        }
        else
        {
            strcat(str[3], ", ");
            strcat(str[3], field->name);
        }
    }
    firstTime = true;


    str[4] = ") VALUES (";
    mysql_field_seek(res, 0);

    // User data input for the table
    for (i = 0; i < mysql_num_fields(res); i++)
    {
        field = mysql_fetch_field(res);
        // Check if variable is auto_increment
        if (field->flags & AUTO_INCREMENT_FLAG)
        {
            continue;
        }
        if (TypeInfo(field->type) == "Word")
        {
            length = field->length / 4;
        }
        else
        {
            length = field->length;
        }
        system("clear");
        printf("Please enter the value for %s.\n"
               "The value should be a %s and maximal %lu character(s) long.\n"
               "Longer parts will be cut off.\n"
               "Allowed number formats are: d.d dd\n"
               "Press Enter (at least once) to log data in.\n"
               , field->name, TypeInfo(field->type), length);
        PrintUnderline(length);

        char* temp[length + 1];
        if (TypeInfo(field->type) == "Word")
        {
            fgets(temp, length, stdin);
            ClearBuffer();
            if ((ptr = strchr(temp, '\n')) != NULL) *ptr = '\0';
        }
        else if (TypeInfo(field->type) == "Decimal" || TypeInfo(field->type) == "Integer")
        {
            // Case Number should be entered
            do
            {
                fgets(temp, length, stdin);
                ClearBuffer();
                if ((ptr = strchr(temp, '\n')) != NULL) *ptr = '\0';
                if (!IsNumber(temp))
                {
                    printf("Number is not a digit!!\nPlease try again:\n");
                }

                // Case integer should be entered but decimal was given
                if (IsNumber(temp) && TypeInfo(field->type) == "Integer" && strchr(temp, '.') != NULL)
                {
                    printf("Number should not be a decimal but an integer digit!!\nPlease try again:\n");
                }
            }
            while (!IsNumber(temp) || (IsNumber(temp) && TypeInfo(field->type) == "Integer" && strchr(temp, '.') !=
                NULL));
        }
        // Case first time reached
        if (firstTime)
        {
            str[5] = malloc(strlen(temp) + 4 + 1);
            strcpy(str[5], "\"");
            strcat(str[5], temp);
            strcat(str[5], "\"");
            firstTime = false;
        }
        else
        {
            strcat(str[5], ", \"");
            ptr = realloc(str[5], sizeof (str[5]) + strlen(temp) * sizeof (str) + 4);
            str[5] = ptr;
            strcat(str[5], temp);
            strcat(str[5], "\"");
        }
    }

    str[6] = ");";

    // Create INSERT query
    query = malloc(strlen(str[0]) + strlen(str[1]) + strlen(str[2]) + strlen(str[3]) +
        strlen(str[4]) + strlen(str[5]) + strlen(str[6]) + 1);

    strcpy(query, str[0]);

    for (i = 1; i <= 6; i++)
    {
        strcat(query, str[i]);
    }
    printf("%s\n", query);

    // Give INSERT query to db
    mysql_real_query(conn, query, strlen(query));
    PrintError();

    res = mysql_store_result(conn);
    PrintError();

    free(query);

    // Question if user want to add more data
    system("clear");
    printf("Following data was entered into table %s: %s\n", tableName, str[5]);
    printf("Do you want to enter more data?\n Enter 'n' for no and any other key for yes and press enter:\n");
    scanf("%c", &answer);
    if (answer != 'n') InsertData();
}

/**
 * Function purely for faster tests
 * Need to be removed later
 */
void AutoConnect()
{
    conn = mysql_init(NULL);
    if (conn == NULL)
    {
        fprintf(stderr, "Unable to intitialize connection struc\n");
        exit(1);
    }
    if (mysql_real_connect(
        conn,
        "localhost",
        "User1",
        "t*LP-x*OzMOBH.ZN",
        "lieblingsKfz",
        0,
        NULL,
        0) == NULL)
    {
        PrintError();
    }
}

/**
 * Builds up a connection to the data bank
 */
void ConnectDatabase()
{
    system("clear");
    char username[9];
    char password[17];
    char dbName[20];
    char* ptr;

    //printf ("\nInitializing Data Bank Connection\n\n");

    //Initialize connection

    conn = mysql_init(NULL);
    if (conn == NULL)
    {
        fprintf(stderr, "Unable to intitialize connection struc\n");
        exit(1);
    }

    //printf ("\nInitialization successful\n"
    //       "\nBuilding up server connection\n");

    DataBankCredentials(username, password);

    printf("\nPlease enter the name of the databank, you like to connect with:\n");
    fgets(dbName, 19, stdin);
    ClearBuffer();
    if ((ptr = strchr(dbName, '\n')) != NULL) *ptr = '\0';

    printf("%s", dbName);

    if (mysql_real_connect(
        conn,
        "localhost",
        username,
        password,
        dbName,
        0,
        NULL,
        0) == NULL)
    {
        PrintError();
    }
}

/**
* Asks for Databank Credentials as console inputs
*/
void DataBankCredentials(char* username, char* password)
{
    printf("\nPlease enter your username: ");
    scanf("%8s", username);
    ClearBuffer();

    printf("\nPlease enter your password: ");
    scanf("%16s", password);
    ClearBuffer();
}

/**
 * Disconnects from the databank
 */
void DisconnectDatabase()
{
    mysql_close(conn);
    //printf("\nClosed database connection.\n");
}

/**
 * Calls a menu for user navigation
 */
void Menu()
{
    bool endProgramm = false;
    bool connectedDb = false;
    int menuChoice = 0;
    int maxMenuChoice = 4;
    do
    {
        system("clear");
        printf("Welcome dear Customer,\n What would you like to do?\n "
            "1. Show table content\n"
            " 2. Insert new data\n"
            " 3. Create table\n"
            " 4. Exit\n"
            "\nEnter the menu number to proceed:\n");

        scanf("%d", &menuChoice);
        ClearBuffer();

        if (menuChoice >= 1 && menuChoice <= maxMenuChoice && !connectedDb)
        {
            connectedDb = true;

            // Autoconnect just for tests remove when finished
            AutoConnect();
            //ConnectDatabase ();
        }

        switch (menuChoice)
        {
        case 1:
            ShowTable();
            break;

        case 2:
            InsertData();
            break;

        case 3:
            CreateTable();
            break;

        case 4:
            endProgramm = true;
            break;

        default:
            system("clear");
            printf("\nInvalid input! Pls enter a number according to the menu.\n");
            printf("Press enter to try again");
            getchar();
        }
    }
    while (!endProgramm || (menuChoice > maxMenuChoice));

    if (connectedDb)
    {
        DisconnectDatabase();
        connectedDb = false;
    }
    system("clear");
    printf("\nThx for using our service.\nUntil next time o/\n");
}

/**
 * Start of programm, calls the menu
 * @return
 */
int main(void)
{
    Menu();
    return 0;
}
