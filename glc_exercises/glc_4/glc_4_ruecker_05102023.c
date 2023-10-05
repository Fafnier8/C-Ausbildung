#include <stdio.h>
/*
Erstellen Sie eine Funktion double bergfest(int gipfel)
Die Funktion erstellt intern ein array  berg mit der festen Länge 11.
In der Mitte des arrays wird die Zahl gipfel geschrieben. 
Rechts und links neben gipfel steht gipfel-1
usw. bis das array komplett gefüllt ist.
Das array soll nur positive Zahlen enthalten. Prüfen Sie gipfel auf Gültigkeit.
Die Funktion gibt das erzeugte Array aus.
Die Funktion gibt den Durchschnitt aller Zahlen im array zurück.
Der Durchschnitt wird in der Main-Funktion ausgegeben.

Beispiel: bergfest(10) ergibt [5,6,7,8,9,10,9,8,7,6,5]  und als Durchschnitt: 7,27

Hinweis: Zeichnen Sie sich das Problem zunächst auf einem Blatt Papier auf.
*/

double bergfest(int gipfel){
    int berg[11];
    double sum;
    for(int i = 0;i < 11; i++){
        if(gipfel - 5 + i < 0 || gipfel + 5 - i < 0){
        berg[i] = 0;
        } else if(i<6){
                berg[i] = gipfel - 5 + i;
        } else {
            berg[i] = gipfel - i + 5;
        }
        printf("%d\t", berg[i]);
        sum += berg[i];
    }
    return sum/11;
}




int main(){
    double median = bergfest(1);
    printf("\nDer Durschnitt des Arrays beträgt ungefähr %.2f.\n", median);
    return 0;
}