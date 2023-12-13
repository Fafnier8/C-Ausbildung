#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// for function isdigit()
#include <ctype.h>
/*
Für eine kleine Wahl sollen Daten erfasst werden. 
Erstellen Sie eine Struktur mit folgenden Werten:
name, vorname, wahldatum, anzahlStimmen

Erstellen Sie ein array  “wahldaten” mit diesen Structs und 4 Einträgen. 
Füllen Sie dieses Array, indem Sie vom User in einer Do-While Schleife
die entsprechenden Daten abfragen.

Sobald 4 Einträge erreicht sind, wird die Schleife beendet.
Die Schleife wird sofort abgebrochen, sobald  der User das Eingabefeld für Name leer lässt,
Verwenden Sie hierfür den Befehl break. 

Geben Sie nach der Eingabeschleife alle Daten in übersichtlicher Form auf der Kommandozeile aus.
Markieren Sie den Datensatz mit höchsten Stimmenanzahl  (z.B. mit *** vor dem Namen)

Hinweis: Vor der Ausgabeschleife müssen Sie nach dem Datensatz mit der höchsten Stimmenzahl suchen.
Den Index dieses Datensatzes merken Sie sich in einer Variablen 

b) Freiwillig:
Das Datum soll in der Form tt.mm.jj eingegeben werden. Schreiben Sie eine Funktion, welche das Datum vom User eingeben lässt, die Eingabe auf Korrektheit prüft und erst beendet wird, wenn der Benutzer ein korrektes Datumsformat eingibt oder eine Leereingabe macht.
Hinweis: Das Datum selbst muss nicht auf Gültigkeit geprüft werden, nur das Eingabeformat. 
*/


// struct für die Daten von den Kandidaten für die Wahl
typedef struct {
    char name[21];
    char vorname[21];
    char wahldatum[9];
    int anzahlStimmen;
} wahl;

// find max value in array

int find_max(unsigned int arr[], int size){
    int max = 0;
    for(int i = 0; i < size; ++i){
        if(arr[i]> max){
            max = arr[i];
        }
    }
    return max;
}

// is datum in the format tt.mm.yy 

bool is_date_ttmmyy(char date[9]){
    if((isdigit(date[0]) && isdigit(date[1]) && (date[2] == '.') && isdigit(date[3]) && isdigit(date[4]) && (date[5] == '.') && isdigit(date[6]) && isdigit(date[7])) || (date[0] == ' ' && date[1]=='\0')){
        return false;
    }
    return true;
}


int main(){

    //variables

    wahl kandidaten[4];

    int full_kandidaten = 0;

    unsigned int stimmanzahl[4] = {0, 0, 0, 0};



    // loop for entering date until it has format dd.mm.yy
    //adding getchar() after every scanf to prevent scanf from reading \n as it's input

    char date[9];

    for(;is_date_ttmmyy(date);){
        printf("Bitte Geben Sie das Wahldatum an:\n");
        scanf("%[^\n]8s", date);
        getchar(); 
    }


    strcpy(kandidaten[0].wahldatum, date);
    strcpy(kandidaten[1].wahldatum, kandidaten[0].wahldatum);
    strcpy(kandidaten[2].wahldatum, kandidaten[0].wahldatum);
    strcpy(kandidaten[3].wahldatum, kandidaten[0].wahldatum);

    // Schleife für die Eingabe der Daten der verschiedenen Kandidaten.

    do{
        printf("Bitte geben Sie den Nachnamen des %d. Kandidaten ein:\n", full_kandidaten+1);
        scanf("%[^\n]20s", kandidaten[full_kandidaten].name); // Kann durch [^\n] auch nur ein Leerzeichen eingegeben werden. 
        getchar();

        // Ist ein weiterer Kandidat vorhanden? Wenn nicht spring raus
        if(kandidaten[full_kandidaten].name[0] == ' '){
            break;
        }

        printf("Bitte geben Sie den Vornamen des %d. Kandidaten ein:\n", full_kandidaten+1);
        scanf("%20s", kandidaten[full_kandidaten].vorname);
        getchar();

        printf("Bitte geben Sie die Anzahl der Stimmen an:\n");
        scanf("%d", &kandidaten[full_kandidaten].anzahlStimmen);
        getchar();

        stimmanzahl[full_kandidaten] = kandidaten[full_kandidaten].anzahlStimmen;

        full_kandidaten++;
    } while(full_kandidaten < 4);

    // Find the maximum vote count

    int maxAnzahlStimmen = find_max(stimmanzahl, (sizeof(stimmanzahl)/sizeof(int)));


    // Is there a date?

    if(date[0] == ' '){
        printf("Hier sind die Ergebnisse der Wahl:\n\n");
    }else{
        printf("Hier sind die Ergebnisse der Wahl vom %s:\n\n", kandidaten[0].wahldatum);
    }

    // print the candidates and who won. the left part of the final && operator is there to finish the loop if there are less than 4 candidates
    

    for(int i = 0; ((!((kandidaten[i].name[0] == ' ') && (kandidaten[i].name[1]=='\0'))) && (i < 4)) ; ++i){
        if(kandidaten[i].anzahlStimmen == maxAnzahlStimmen){
            printf("%d. Kandidat *** %s %s: %d Stimmen\n\n", i+1, kandidaten[i].vorname, kandidaten[i].name, kandidaten[i].anzahlStimmen);    
        }else{
            printf("%d. Kandidat %s %s: %d Stimmen\n\n", i+1, kandidaten[i].vorname, kandidaten[i].name, kandidaten[i].anzahlStimmen);
        }
    }

    return 0;
}