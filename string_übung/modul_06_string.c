/*
Aufgaben C Modul 06 string
---------------------------------

Hinweis: Beachten Sie den in diesem Unterverzeichnis enthaltenen Beispielcode.
         Beachten Sie die Datei "Aufgaben lösen.txt" in ./M00_start


Aufgabe 5a)
----------
Gegeben sei folgender String:
string hallo = "Meine Harley is cool";
Geben Sie die Länge des Strings aus.
Entfernen Sie das letzte Zeichen und geben Sie die Länge erneut aus.


Aufgabe 5b)
----------
Erstellen Sie eine Benutzereingabe: "Bitte einen Satz eingeben: ". 
Speichern Sie die Eingabe in string eingabe;
Vergleichen Sie die Variable eingabe mit hallo aus Aufgabe 01.
Geben Sie entsprechende Meldungen für Gleicheit bzw. Ungleichheit aus.

5b2)
Geben Sie das 18. Zeichen aus der eingabe von Aufgabe 02 aus.
Prüfen Sie unbedingt, ob dieses Zeichen überhaupt existiert.

Hinweis: Beachten Sie, dass die Zählung bei 0 beginnt!
 

Aufgabe 5c)
----------
Geben Sie das erste, dritte und 8. Zeichen von String aus Aufgabe 01 aus.

Schreiben Sie an die genannten Positionen ein Fragezeichen: '?'
und geben Sie den geänderten String hallo aus. 


Aufgabe 5d)
-----------
Gegeben ist der String "Kalli geht in die Schule";
Schneiden Sie aus diesem String das Wort "geht" aus und speichern dies in einer anderen String Variable string verb.

Erstellen Sie zwei String Variablen mit dem Inhalt "Mir" und "es gut".
Fügen Sie die diese beiden String zusammen mit der Variable verb zu einem sinnvollen Satz zusammen.
Dazu wird zunächst eine Variable "string satz" erstellt.
Beachten Sie auch die notwendigen Leerzeichen.
Geben Sie diesen neuen Satz aus.

Aufgabe 05e)
------------
Gegeben ist der String "Kalli geht in die Schule";
Suchen Sie in diesem String nach den Wörtern "Schule" und "geht". 
Geben Sie jeweils die Position, an der das Wort gefunden wurde aus.
Suchen Sie nach dem Wort "fahren". Falls dies nicht gefunden wurde,
geben Sie aus: "fahren" nicht gefunden.

Aufgabe 05f)
------------
Gegeben ist der String "Kalli geht in die Schule";
Fügen Sie per Programm das Wort "neue " vor Schule ein.
Geben Sie den geänderten String aus.

Löschen Sie das Wort "geht" aus dem String und geben Sie den geänderten String aus.

Zum Schluss löschen Sie den ganzen String

Aufgabe 05g)
----------------
Gegeben sei folgender String:
string hallo = "Dies ist meine neue Welt";
Suchen Sie mit einer Stringfunktion, ob in diesem String "neue" vorkommt
und geben die Position aus.
Testen Sie auch den String: "Meine heile Welt".


Aufgabe 05h)
----------------
Gegeben ist folgender String
string test = "Die Welt ist mir zu klein";
Ersetzen Sie das Wort "mir" durch das Wort "ihm".


Aufgabe 05i)
------------
Benutzereingabe einer Kommazahl in String eingabe.
Wandeln Sie den String eingabe in eine double Zahl um.
Geben Sie diese double Variable aus.

Hinweis: "Google is your friend", Siehe auch STL_1_string.cpp
         Die Behandlung von ungültigen Werten kommt später. 
		 Für diese Aufgabe nur gültige Zahlen eingeben.

 

Aufgabe 05j)
------------
Gegeben ist ein std::string meinString {"Dies ist eine $$$ Welt"};
Schreiben Sie eine Funktion ersetzePlatzhalter().
Eingabeparameter: 1) Ein konstanter String original 2) Ein konstanter std::string neu 3) Ein konstanter std::string platzhalter
Rückgabeparameter: Ein std::string, bei dem platzhalter (hier $$$) durch neu ersetzt wurde.

Beispielaufruf:
 string meinString = "Dies ist eine $$$ Welt";
 ersetzePlatzhalter(meinString, "tolle", "$$$");
 
 Geben Sie mit cout zunächst meinString aus und in der nächsten Zeile das Ergebnis der Funktion.
 


Aufgabe 05k)
----------------
Schreiben Sie eine Funktion zaehleFragezeichen()
Eingabeparameter: Ein konstanter String
Rückgabeparameter: Die Anzahl der im String vorhandenen Fragezeichen()


Aufgabe 05l)
------------
Schreiben Sie eine Funktion pruefeZeichen, die einen String, ein Zeichen und eine Anzahl übergeben bekommt.
Die Funktion prüft, ob das Zeichen in dem String genau Anzahl oft vorkommt.
Falls nein, gibt sie false zurück, sonst true.
Der Aufruf der Funktion ist wie folgt:
bool ergebnis = pruefeZeichen("banane", 'a', 2);
if (ergebnis == true)
	cout "Passt";
else
	cout "Passt nicht";
	
b) Jetzt sollen alle drei Parameter vom Benutzer eingebeben werden.
   Danach wird die Funktion aufgerufen.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h> // für strlen
#include <stdbool.h>






//search function to find a row of characters. Will also search if a string is a part of another word.


int finde_string(char text[], char string[]){
    int fundstelle;
    for(int i = 0; i<strlen(text); ++i){
        if(string[0] == text[i]){
            fundstelle = i+1;
            int temp_found_character = 1;
            while(temp_found_character != strlen(string)){
                if(string[temp_found_character] != text[i+1]){
                    break;    
                }
                ++i;
                ++temp_found_character;
            }
            if(temp_found_character == strlen(string)){
                printf("Der String %s wurde in dem Text an der %d. Stelle gefunden.\n", string, fundstelle);
                return fundstelle;
            }
        }
        
    }
    printf("Der String %s wurde in dem Text nicht gefunden.\n", string);
    return -1;
}


void add_word(char text[], char word_to_add[], char word_after_added_word[]){
    char temp[strlen(text)];
    strcat(temp, text);   
    int string_number_for_adding = finde_string(text, word_after_added_word)-1 ; 
    if(string_number_for_adding == -2){
        printf("Das Wort nach dem hinzuzufügenden existiert nicht.");
        return;
    }

    return;
}

//function that counts a certain character and looks if it appears a certain number of times


bool pruefeZeichen(char string[], char zeichen, unsigned int anzahl){
    int zeichenanzahl = 0;
    for(int i = 0; i < strlen(string); ++i){
        if(string[i] == zeichen){
            zeichenanzahl += 1;
        }
    }
    if(anzahl == zeichenanzahl) return true;
    return false;
}


int main(void){

    // Aufgabe 5a)

    char hallo[] = "Meine Harley is cool";
    printf("Die Länge vom string hallo ist: %ld \n", strlen(hallo));
    hallo[19] = '\0';
    printf("Die Länge vom string hallo ist nun: %ld \n", strlen(hallo));

    
    // Aufgabe 5b)

    printf("Bitte einen Satz eingeben:\n");
    char eingabe[100];

    //%[^\n] ist ein scanset, was einem sagt, dass erst nach einem \n die Eingabe in 
    //der Konsole aufhört.  Der * zeigt an, dass der eingelesene \n verworfen wird.

    scanf("%[^\n]%*c",&eingabe[0]);


    int comp_value = strcmp(hallo, eingabe);

    if(strcmp(hallo, eingabe) == 0){
        printf("Strings sind die Gleichen.\n");
    }else{
        printf("Strings sind nicht die Gleichen.\n");
    }

    //Aufgabe 5b2)

    if(strlen(eingabe) >= 18){
        printf("Das ist das 18. Zeichen von \"eingabe\": %c \n", eingabe[17]);
    }

    //Aufgabe 5c)

    printf("Das erste Zeichen von \"hallo\" ist: %c \nDas Dritte ist: %c und das Achte ist: %c \n", hallo[0], hallo[2], hallo[7]);
    
    hallo[0] = hallo[2] = hallo[7] = '?';

    for(int i = 0; i<strlen(hallo); ++i){
        printf("%c", hallo[i]);
    }
    printf("\n");
    //Aufgabe 5d)
    
    char str5d[] = "Kalli geht in die Schule";

    char verb[] = "geht";

    // Da man  keinen leeren string erschaffen kann, kann aus dem string str5d nichts rausgeschnitten werden. Wenn ein feste Länge bestimmt wird, überlappt der String
    // verb mit einem andern nämlich mir und verändert sich dadurch.
    

    //for(int i = 6; i<10; ++i){
    //    verb[i-6] = str5d[i];
    //}



    printf("\n");
    char mir[] = "Mir";

    char es_gut[] = "es gut";

    char satz[15] = "";



    strcat(satz, mir);
    strcat(satz, " ");
    strcat(satz, verb);
    strcat(satz, " ");
    strcat(satz, es_gut);

    for(int i = 0; i<strlen(satz); ++i){
        printf("%c", satz[i]);
    }
    printf("\n");

    // Aufgabe 5e)

    char schule[] = "Schule";

    finde_string(str5d, schule);

    finde_string(str5d, verb);

    char fahren[] = "fahren";

    finde_string(str5d, fahren);

    // Aufgabe 5f)


    // Aufgabe 5g)

    char hallo2[] = "Dies ist meine neue Welt";

    char neue[] = "neue";

    

    finde_string(hallo2, neue);

    char meine_heile_welt[] = "Meine heile Welt";

    finde_string(hallo2, meine_heile_welt);

    // Aufgabe 5h)


    // Aufgabe 5i)

    char doublestring[10];
    char *eptr;
    double wert_von_string;

    printf("Geben Sie eine Kommazahl ein: \n");

    scanf("%[^\n]%*c", &doublestring[0]);

    wert_von_string = strtod(doublestring, &eptr);

    printf("%.2f \n", wert_von_string);




    // Aufgabe 5l)

    char banane[] = "banane";

    bool ergebnis = pruefeZeichen(banane, 'a', 2);
    if (ergebnis == true)
        printf("Passt\n");
    else
        printf("Passt nicht\n");


    return 0;
}
