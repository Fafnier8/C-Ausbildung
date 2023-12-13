/*
Aufgaben C Modul 07 Pointer und Referenzen
--------------------------------------------

Hinweis: Beachten Sie den in diesem Unterverzeichnis enthaltenen Beispielcode.
         Beachten Sie die Datei "Aufgaben lösen.txt" in ./M00_start

         

    Erstellen Sie eine Variable int wert = 44;
    Erstellen Sie einen Pointer int* ptr auf diese Variable
    Ändern Sie wert über den Pointer
    Erstellen Sie einen zweiten Pointer int* ptr2 auf diese Variable, indem Sie ptr kopieren
    Lesen Sie über ptr2 wert aus und speichern dies in einer Variablen int hh;
    Geben Sie alle Zwischenstände mit printf aus.

    Erstellen Sie eine String Variable inhalt mit folgendem Beispielinhalt "     test     "
    Übergeben Sie einen Pointer auf die Variable inhalt an eine zu erstellende Funktion trim()
    Diese Funktion entfernt vorne und hinten die Leerzeichen.
    Die Rückgabe ist ein string (kein Pointer)

    Erstellen Sie eine Funktion tausche()
    Diese erhält zwei Ganzzahlen und hat keinen Rückgabewert.
    Die Aufgabe der Funktion ist das Vertauschen der beiden Zahlen


    Erstellen Sie eine Funktion trulli()
    Diese erhält 3 Strings als Parameter und liefert einen bool zurück.
    Die Aufgabe der Funktion ist, vor jeden String einen Unterstrich zu setzen. 
    Alle 3 geänderten Strings sollen an den Aufrufer zurück geliefert werden.
*/

#include <stdio.h>
#include <stdint.h>
#include <cstring>

// function to remove space characters in front und at the end of the word
// Has a pointer connected to the first element of the string that should be trimmed 

void trim(char* ptrstring){
    int counter = 0;  
    char empty_space = ' ';

    // While function counts how many white spaces are in front of the word

    while(*(ptrstring + counter) == empty_space){
        counter += 1;
    }
    int begin_word = counter;

    // While function counts where the word ends then and will also end if the word has no empty spaces at the end

    while(*(ptrstring + counter) != empty_space && *(ptrstring + counter) != '\0'){
        counter += 1;
    }
    int end_word = counter;

    // writes the word at the beginning of it's string
    
    for(counter = begin_word; counter != end_word; ++counter){
        *(ptrstring + counter - begin_word) = *(ptrstring + counter);
    }

    // places a \0 at the end of the word to finish the string after the word

    *(ptrstring + (end_word-begin_word)) = '\0';
}

void swap(int *number1, int *number2){
    int temp = *number2;
    *number2 = *number1;
    number2 = &temp;
    *number1 = *number2;
}


void sortArr(int arr[], int size){
    int temp;   // temporary variable for switching values
        for(int i = 0; i < size-1;){
            if(arr[i]>arr[i+1]){ // looks if number next to it is bigger to sort it
                for(;;++i){
                    if(i == size-1){ // reached the end of the array
                        i = 0;
                        break;
                    } 
                
                    if(arr[i]<=arr[i+1]){ // next number is bigger don't need to switch anymore
                        i = 0;
                        break;
                    }
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
        } else{
            i++; // i is raised at the end because otherwise it would otherwise compare if last array number is bigger then the number behind in memory
        }
    }
}


int main(){
    int wert = 44;
    int* ptr = &wert;
    printf("Der Wert der Variable \"wert\" ist: %d\n", wert);
    *ptr = 55;
    printf("Der Wert der Variable \"wert\" ist nun: %d\n", wert);
    int* ptr2 = ptr;
    int hh = *ptr2;
    printf("Der Wert der Variable \"hh\" ist: %d\n", hh);


    //test for the trim function

    char inhalt[] = "     test     ";
    printf("%s\n", inhalt);
    char *ptrstr = inhalt;
    trim(ptrstr);
    printf("%s\n", inhalt);

    // Swap numbers exercise

    int test_number1 = 5;
    int test_number2 = 10;

    int *ptr_test_number1 = &test_number1;
    int *ptr_test_number2 = &test_number2;

    printf("This is the value of \"test_number1\": %d and this is the value of \"test_number2\": %d\n", test_number1, test_number2);

    swap(ptr_test_number1, ptr_test_number2);

    printf("Now this is the value of \"test_number1\": %d and this is the value of \"test_number2\": %d\n", test_number1, test_number2);

    int arr[]= {6, 2, 5, 100, 30, 42, 69, 1, 69, 12, 6, 7, 2};

    sortArr(arr, (sizeof(arr)/sizeof(arr[0])));

    for(int i = 0; i < (sizeof(arr)/sizeof(arr[0]));++i){
        printf("%d\t", arr[i]);
    }


    return 0;
}