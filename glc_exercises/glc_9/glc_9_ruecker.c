#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
a) Erstellen Sie ein C Programm, welches eine Textdatei öffnet und den Text darin analysiert.
Das Programm wird wie folgt mit 3 Kommandozeilenparametern aufgerufen:
./txtcheck filename mincount maxcount
Beispiel:
./txtcheck testfile.txt 10 30

Das Programm liest die Textdatei zeilenweise ein.
Pro Zeile muss der Buchstabe e mind. 3 mal vorhanden sein.
Leerzeilen werden ignoriert.
In der ganzen Datei muss der Buchstabe e wie folgt vorhanden sein:
 - mindestens mincount mal und 
 - maximal maxcount mal.
Im Beispiel oben also zwischen 10 und 30 mal.

Sind alle Bedingungen erfüllt, dann gibt das Programm folgendes aus:
"testfile.txt erfüllt die notwendigen Bedingungen"
ansonsten:
"testfile.txt ist fehlerhaft"
Erstellen Sie sich 2 bis 3 Testdateien und testen Sie ihr Programm damit.
Hinweis: testfile.txt wird durch den übergebenen Dateinamen ersetzt.

Hinweis2: Teilen Sie Aufgabe in kleine Teilprobleme auf und arbeiten
                    Sie Stück für Stück daran.

Hinweise 3: Umwandlung string nach zahl: Siehe Programm im Anhang.

b) Eine Zeile, die beliebig viele Leerzeichen (aber *keine* anderen Zeichen) enthält,    wird auch als Leerzeile behandelt.
  Schreiben Sie dazu eine Funktion, die feststellt, ob eine Zeile nur aus Leerzeichen besteht   und bauen Sie diese in das obige Programm ein.
*/

// Function to check if line only consists of empty space

bool Is_line_just_empty_space(char* line){
    while(*line != '\n'){
        if(*line != ' '){
            return false;
        }
        line++;
    }
    return true;
}

int main(int argc, char *argv[]){

    // Check if enough command line parameter are given
    
    // command line parameters are: Filename mincount maxcount

    if(argc == 4){
        for(int i = 0; i < 4; ++i){
            printf("The argument %s was given.\n", argv[i]);
        }
    } 
    else {
            printf("Argument count is not right. There should be 3 Arguments given.\n");
    }

    // Creating an pointer to a file and open it

    FILE *fp;

    fp = fopen(argv[1], "r");

    // Check if File exist 

    if(fp==NULL){
        printf("No File to open.");
        exit(1);
    }

    // Converting string to integer

    int mincount = atoi(argv[2]);
    int maxcount = atoi(argv[3]);

    // line is containing the string read in that instance, len, getline is returning the size of the line (if file ends it returns -1)
    // and is putting the string in line. n is the allocated buffer for the line. Resizes automatically if not big enough.

    char *line = NULL;
    size_t len = 0;

    int e_line_counter;
    int e_file_counter = 0;

    bool is_file_fine = true;

    // Function to check if criterias are met

    while(getline(&line, &len, fp) != -1){
        e_line_counter=0;

        // For loop that runs through the line and counts e's

        for(int i = 0; i<strlen(line); ++i){
            if(line[i]=='e'){
                e_file_counter++;
                e_line_counter++;
            }
        }

        // Check if text doesn't fullfill criteria

        // e's in file should be max maxcount, empty line's should be ignored as well as line's with only empty spaces 
        // and e's in one line dhould be more than 3

        if((e_line_counter < 3 || e_file_counter > maxcount) && line[0] != '\n' && !Is_line_just_empty_space(line)){
            printf("%s ist fehlerhaft\n", argv[1]);
            is_file_fine = false;
            break;
        }
    }

    if(is_file_fine && e_file_counter >= mincount){
        printf("%s erfüllt die notwendigen Bedingungen.\n", argv[1]);
    }else if(is_file_fine){
        printf("%s ist fehlerhaft\n", argv[1]);
    }

    fclose(fp);
    
    return 0;
}