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
    Diese erhält 3 Strings ala Parameter und liefert einen bool zurück.
    Die Aufgabe der Funktion ist, vor jeden String einen Unterstrich zu setzen. 
    Alle 3 geänderten Strings sollen an den Aufrufer zurück geliefert werden.
*/

#include <stdio.h>
#include <stdint.h>

void trim(char* ptrstring){
    int counter = 0;
    char empty_space = ' ';
    while(*ptrstring == empty_space){
        counter +=1;
        ptrstring++;
        printf("%d\n", counter);
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
    char inhalt[] = "     test     ";
    char *ptrstr = inhalt;
    trim(ptrstr);
}