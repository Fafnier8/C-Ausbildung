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

int main(void){

    // Aufgabe 5 a)

    char hallo[] = "Meine Harley is cool";
    printf("Die Länge vom string hallo ist: %ld \n", strlen(hallo));
    hallo[19] = '\0';
    printf("Die Länge vom string hallo ist nun: %ld \n", strlen(hallo));


    printf("Bitte einen Satz eingeben:\n");
    char eingabe[100];
    scanf("%[^\n]%*c",&eingabe[0]);


    int comp_value = strcmp(hallo, eingabe);

    if(strcmp(hallo, eingabe) == 0){
        printf("Strings sind die Gleichen.\n");
    }else{
        printf("Strings sind nicht die Gleichen.\n");
    }
    return 0;
}