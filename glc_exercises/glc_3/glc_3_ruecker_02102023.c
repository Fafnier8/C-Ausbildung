#include <stdio.h>
#include <stdbool.h>

/*
1.
Für einen Flug ist 20kg Gepäck frei. 
Jedes Kg darüber hinaus kostet 6.50 Euro.
Schreiben Sie eine Funktion, welche die korrekte Gebühr zurückliefert.
double gepaeckPreis(double gepaeckGewicht)
Grundsätzlich erfolgen alle printfs außerhalb der Funktion.

Schreiben Sie alle relevanten Testfälle (= Funktionsaufrufe mit verschiedenen Werten).
Beispiele:
double preis1 = gepaeckPreis(17);
double preis2 = gepaeckPreis(30);
double preis3 = gepaeckPreis(0);
double preis4 = gepaeckPreis(-10);
double preis5 = gepaeckPreis(2000);

b)
Erweitern Sie die Funktion. Zulässige Gepäckgewichte liegen zwischen 0.0 und 50kg.
Die Funktion gibt bei ungültigen Parametern eine -100.0 zurück.
*/

double gepaeckPreis(double gepaeckGewicht){
    if(gepaeckGewicht>=50 || gepaeckGewicht<=0){
        return -100;
    }
    if(gepaeckGewicht <= 20){
        return 0;
    }
    double zahlender_Preis = ((int)gepaeckGewicht-20)*6.50;

    return zahlender_Preis;
}

/*
2.
Schreiben Sie eine Funktion "bmi".
Diese berechnet den Body-Mass-Index nach folgender Formel:
   -  Körpergewicht (in kg) geteilt durch Größe (in Meter) zum Quadrat  -
Die Funktion macht keine printf-Ausgaben, sondern gibt den 
berechneten BMI-Wert zurück.
Die Main-Funktion macht dann die Ausgabe des Werts nach diesem Muster:
"Der BMI bei einem Gewicht von 75kg und einer Größe von 176cm beträgt: 24,2

Hinweis: Überlegen Sie sich, welche Parameter und welchen Rückgabewert 
        die Funktion "bmi" haben muss.

b)
Schreiben Sie eine weitere Funktion "bmiBewertung". Diese bekommt den
von der obigen Funktion berechneten Wert übergeben und gibt mit printf
eine Bewertung aus.
Beispiele:
"Sie haben Normalgewicht"
"Sie haben Übergewicht"
etc.
Googeln Sie nach den passenden Wertebereichen.
Bei Normalgewicht gibt die Funktion true zurück, ansonsten false.

Sowohl "bmi" als auch "bmiBewertung" werden von main aufgerufen.
Ausgabe per printf in main liefert "bmiBewertung" true zurück erfolgt 
die Ausgabe "Alles okay"  ansonsten "Bitte sprechen Sie mit Ihrem Arzt!".
*/

double bmi(double körpergewicht, double körpergröße){
    return körpergewicht/(körpergröße*körpergröße);
}

bool bmiBewertung(double bmi_wert){
    if(bmi_wert <= 24.9 && bmi_wert >= 18.5){
        printf("Sie haben Normalgewicht.\n");
        return true;
    } else {
        if(bmi_wert<18.5){
            printf("Sie haben Untergewicht.\n");
        } else if(bmi_wert>24.9){
            printf("Sie haben Übergewicht.\n");
        }
        return false;
    }
}


int main(){

    /*
        Aufgabe 1
    */
    double preis1 = gepaeckPreis(17);
    printf("Es muss als Gepäckpreis %.2f € bezahlt werden.\n", preis1);
    double preis2 = gepaeckPreis(30);
    printf("Es muss als Gepäckpreis %.2f € bezahlt werden.\n", preis2);
    double preis3 = gepaeckPreis(0);
    printf("Es muss als Gepäckpreis %.2f € bezahlt werden.\n", preis3);
    double preis4 = gepaeckPreis(-10);
    printf("Es muss als Gepäckpreis %.2f € bezahlt werden.\n", preis4);
    double preis5 = gepaeckPreis(2000);
    printf("Es muss als Gepäckpreis %.2f € bezahlt werden.\n", preis5);

    /*
        Aufgabe 2
    */
    double body_size1 = 1.90;
    double body_mass1 = 60;

    double bmi_testwert1 = bmi(body_mass1, body_size1);

    printf("Der BMI bei einem Gewicht von %.2fkg und einer Größe von %.2fcm beträgt: %.2f\n",body_mass1, body_size1*100, bmi_testwert1);

    bool bmi_testbewertung1 = bmiBewertung(bmi_testwert1);

    if(bmi_testbewertung1 == false){
        printf("Bitte sprechen Sie mit Ihrem Arzt!\n");
    }else{
        printf("Alles okay.\n");
    }

    double body_size2 = 1.70;
    double body_mass2 = 60;

    double bmi_testwert2 = bmi(body_mass2, body_size2);

    printf("Der BMI bei einem Gewicht von %.2fkg und einer Größe von %.2fcm beträgt: %.2f\n",body_mass2, body_size2*100, bmi_testwert2);

    bool bmi_testbewertung2 = bmiBewertung(bmi_testwert2);

    if(bmi_testbewertung2 == false){
        printf("Bitte sprechen Sie mit Ihrem Arzt!\n");
    }else{
        printf("Alles okay.\n");
    }


    return 0;
}