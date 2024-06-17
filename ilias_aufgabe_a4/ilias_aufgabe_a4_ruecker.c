#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <ctype.h>
#include "meine_funktionen.h"
#define MAXL 100

/*hello world - das erste C-Programm*/

void fswap(float *p1 , float *p2){
  float temp;

  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}  

//Neue Adresse eines Mitarbeiters einlesen

// A 4.1.8 structures - Datensätze aus unterschiedlichen Datentypen - Gruppe der komplexen Datentypen

// 1 Definition der structures adresse & artikel

void getNewadr( struct personal *p);            //Bitte erinnern: ein Funktionsparameter = Variablendeklaration!!!

struct adresse
{
  char strasse[100];

  char ort [30];

  long tel;
};

// 2 Initialisieren von Strukturvariablen

//Erweitern Sie das obige Programm.

//Tippen Sie diese Zeilen hinzu:

// In Wahrheit aber 56 Bytes, da 2 als Puffer für den struct dazukommen
struct personal
{
  unsigned long nummer;       // Personalnummer

  char name[50];                    // Name

  struct adresse adr;              // Adresse - hier eine Verschachtelung...

  double income;                   //Gehalt
};

 

//Definition & Initialisierung einer Strukturvariablen vom Typ "struct personal":

struct personal chef =
{
  1234567,
  "Spenzer, Max",

  {
    "Flowerweg 12",
    "81234 München",
    2606799
  },

  260679.90  
};



int main()
{

// Aufgabe A 4.1.1

  printf("\n\n Hello, World! \n\n");
/*
Beenden Sie, wie in der vorigen Übung, Ihren Editiervorgang.

tippen Sie an der Kommandozeile nun:

gcc eins.c -o eins

Ihr Programm wird vom gcc kompiliert.

Tippen Sie anschließend:

./eins

Was sehen Sie?
*/
/*
Man sieht "Hello, World!" auf der Konsole ausgegeben mit Abstand von zwei Zeilen.
*/


// Aufgabe A 4.1.2

/*Variablen und Datentypen 1*/
  /*Variablendeklaration:*/
  char buchstabe_1;
  char buchstabe_2;
  char buchstabe_3;
  int zahl_1, zahl_2;
  int ergebnis;

  /*Variableninitialisierung:*/
    int zahl_3 = 2;

  /*Wertzuweisungen:*/
  buchstabe_1 = 'a'; 
  buchstabe_2 = 'b'; 
  buchstabe_3 = 'c'; 
  zahl_2 = 3;
  zahl_3 = 2;


  /*Zugriff!*/
  printf("\n Variante %c: Addition.\n", buchstabe_1);
  ergebnis = zahl_1 + zahl_2;
  printf("\n Die Summe aus der %i und %i beträgt %i\n", zahl_1, zahl_2, ergebnis);

  /*Zusätzliche Anweisung: erstellen Sie eine Berechnung in den weiteren drei Grundrechenarten*/
  printf("\n Variante %c: Subtraktion.\n", buchstabe_2);
  ergebnis = zahl_1 - zahl_2;
  printf("\n Die Differenz aus der %i und %i beträgt %i\n", zahl_1, zahl_2, ergebnis);

  printf("\n Variante %c: Division.\n", buchstabe_3);
  ergebnis = zahl_1 / zahl_2;
  printf("\n Der Quotient aus der %i und %i beträgt %i\n", zahl_1, zahl_2, ergebnis);

  printf("\n Variante %c: Multiplikation.\n", 'd');
  ergebnis = zahl_1 * zahl_2;
  printf("\n Das Produkt aus der %i und %i beträgt %i\n", zahl_1, zahl_2, ergebnis);

  // Variablen und Datentypen 2

  float zahl_4, zahl_5, ergebnis_2;

  zahl_4 = 5;
  zahl_5 = 3;

  ergebnis_2 = zahl_4 / zahl_5;

  printf("\n Der Quotient aus dem Divisor %f und dem Dividenden %f beträgt %.2f\n", zahl_4, zahl_5, ergebnis_2);

  /*Aufgabe: geben Sie das Endergebnis mit 2 gerundeten Nachkommastellen an.*/

  /*Variablen und Datentypen 3 --- Variablengroessen*/

  char buchstabe = 'a';
  int zahl_6 = 5;
  float zahl_7 = 3;

  printf("\n Eine Character-Variable belegt %li Byte im Arbeitsspeicher", sizeof(buchstabe));

  printf("\n Eine Int-Variable belegt %li Byte im Arbeitsspeicher\n", sizeof(zahl_6));

  printf("\n Eine Float-Variable belegt %li Byte im Arbeitsspeicher\n", sizeof(zahl_7));

  /*Erweitern Sie diese Aufgabe auf die Messung der Groesse von integer- und float-Variablen*/

  /*Variablen und Datentypen 4 --- adressen der Variablen */

  printf("Die Character-Variable Buchstabe liegt im Arbeitsspeicher an Adresse %p und enthält ein %c\n", &buchstabe, buchstabe);

  printf("Die Character-Variable Buchstabe liegt im Arbeitsspeicher an Adresse %p und enthält ein %i\n", &zahl_6, zahl_6);

  printf("Die Character-Variable Buchstabe liegt im Arbeitsspeicher an Adresse %p und enthält ein %f\n", &zahl_7, zahl_7);

  /*Variablen und Datentypen 5 --- ASCII Code und Zahlensysteme */

  printf("\n Der Buchstabe %c als ASCII-Zeichen\n", buchstabe);
  printf("\n Der Buchstabe %i als Dezimal-Zahl\n", buchstabe);
  printf("\n Der Buchstabe %x als Hexadezimalzahl\n", buchstabe);
  printf("\n Der Buchstabe %o als Oktalzahl\n", buchstabe);

  /*Eingabe 1 Eingabe mit scanf*/

  int i = 5;

  printf("\n in der Variable i steht eine %i\n", i);
  printf("\n Bitte geben Sie eine Zahl ein.\n");

  fflush(stdin);
  scanf("%d", &i);
  fflush(stdin);

  printf("\n in der Variable i steht eine %i\n", i);

  /*Bitte erweitern Sie das zu einem "Taschenrechner" für die vier Grundrechenarten*/

  int j;

  printf("\nBitte geben Sie eine zweite Zahl zum verrechnen ein:\n");
  scanf("%d", &j);
  fflush(stdin);

  float ergebnis_3;

  ergebnis_3 = i+j;


  printf("\nDie Summe der beiden Zahlen i und j entspricht: %.2f\n", ergebnis_3);

  ergebnis_3 = i-j;

  printf("\nDie Differenz der beiden Zahlen i und j entspricht: %.2f\n", ergebnis_3);

  ergebnis_3 = i*j;

  printf("\nDas Produkt der beiden Zahlen i und j entspricht: %.2f\n", ergebnis_3);
  ergebnis_3 = (float)i/j;

  printf("\nDer Quotient der beiden Zahlen i und j entspricht: %.2f\n", ergebnis_3);
  
  /*Definieren Sie nacheinander bitte 2 float, 2 int und 2 char-Variablen.
  Ermitteln Sie für jede der sechs Variablen nun nochmals den Platzbedarf mithilfe von sizeof().
  Lassen Sie sich bitte nacheinander die Speicheradressen mithilfe des Adress-Operators(&) anzeigen.

  Bitte vergleichen Sie untereinander, welche Adressen Sie erhalten.
  */

  float float_1 = 1.5;
  float float_2 = 2.5;
  int int_1 = 1;
  int int_2 = 2;
  char char_1 = 'b';
  char char_2 = 'f';

  printf("\nDie Variable float_1 hat einen Platzbedarf von %li Bytes und ist an der Speicheradresse %p zu finden.\n", sizeof(float_1), &float_1);
  printf("\nDie Variable float_2 hat einen Platzbedarf von %li Bytes und ist an der Speicheradresse %p zu finden.\n", sizeof(float_2), &float_2);
  printf("\nDie Variable int_1 hat einen Platzbedarf von %li Bytes und ist an der Speicheradresse %p zu finden.\n", sizeof(int_1), &int_1);
  printf("\nDie Variable int_2 hat einen Platzbedarf von %li Bytes und ist an der Speicheradresse %p zu finden.\n", sizeof(int_2), &int_2);
  printf("\nDie Variable char_1 hat einen Platzbedarf von %li Byte und ist an der Speicheradresse %p zu finden.\n", sizeof(char_1), &char_1);
  printf("\nDie Variable char_2 hat einen Platzbedarf von %li Byte und ist an der Speicheradresse %p zu finden.\n", sizeof(char_2), &char_2);

  // A 4.1.3 Formatierte Ein- und Ausgabe

  // 1 Einführung formatierte Ausgabe
  // Tippen Sie:
  
  int a = 5;

  printf("\n2 * %d ergibt %d \n", a, 2*a);
  /*
  Kompilieren Sie.
  Ausgabe:

  2 * 5 ergibt 10

  
  Die Funktion printf() erwartet mindestens ein Argument, nämlich den "Formatstring". Dieser wird auf dem Bildschirm ausgegeben. Der Formatstring kann Formatelemente enthalten, welche selbst nicht ausgegeben werden, sondern die Ausgabe weiterer Argumente steuern.
  Für jedes Formatelement muss genau ein Argument eingegeben sein.
  */

  // 2 Ausgabe von Gleitkommazahlen 

  /*
  Typangaben:

  f: float / double -> Gleitpunktzahl
  e: float / double -> Gleitpunktzahl in Exponenten-Schreibweise  
  s: String -> Ausgabe bis '\0' im String auftaucht (String-Ende)

  Beispiel:
  double x = 231,75;
  printf("%f    %e ", x, x );
  Ausgabe: 231.750000   2.317500e+02
  Ohne weitere Angaben werden sechs dezimale Ziffern hinter dem Dezimalpunkt ausgegeben, wobei eventuell gerundet wird.

  Genauigkeit und Feldbreite:

  float y = 2.98765
  printf(">%10f\n<  ", y);   Feldbreite: 10
  printf(">%-10f\n<  ", y);   Linksbündig
  printf(">%10.2f\n<  ", y);   Genauigkeit: 2 Stellen hinter dem Komma

  Die Genauigkeit lässt sich auch ohne die Angabe der Feldbreite festgelegt werden:

  printf(">%.1f < -->%4.0f< -->%4.3f", y);
  Dieses Beispiel zeigt auch, dass bei der Genauigkeit "0" kein Dezimalpunkt mit ausgegeben wird.

  Aufgabe 1: Bitte coden Sie das Beispiel nach.

  */

  double x = 231.75;

  printf("\n%f    %e \n", x, x );

  float y = 2.98765;

  printf("\n>%10f\n<  ", y);

  printf("\n>%-10f\n<  ", y);

  printf("\n>%10.2f\n<  ", y);

  printf("\n>%.1f < -->%4.0f< -->%4.3f\n", y, y, y);

  // 3 Ausgabe von Strings

  //Beipiel:

  //printf(">%-10s< -->%10.3s< ", "Tomate", "Tomate" );

  //Bitte coden Sie dies nach.

  printf("\n>%-10s< -->%10.3s< \n", "Tomate", "Tomate" );

  // 4 Eingabe von Zeichen und Zahlen mit scanf()

  /*
  Coden Sie das folgende Beispiel:

  #include < stdio.h>
  #include < stdlib.h>

  int main(){

  int tag, monat, jahr
  printf("Bitte geben Sie Ihr Geburtsdatum ein.\n");

  printf("\nTag:");
  scanf("%d", &tag);

  printf("\nMonat:");
  scanf("%d", &monat);Coden Sie das folgende Beispiel:

  printf("\nJahr:");
  scanf("%d", &jahr);


  //Zufallszahlengenerator initialisieren

  srand(tag + monat + jahr);
  printf("\nIhre Glückszahl lautet heute: " rand());

  return 0;
  }

  WICHTIG bei scanf():
  Das Lesen der Tastatur durch Standardfunktionen ist zeilenweise gepuffert.
  Folge: Solange die Return-Taste nicht betätigt wurde, lassen sich Eingaben noch korrigieren.
  Die Eingabe wird auf dem Bildschirm angezeigt.
  Die Eingabe in eine Variable wird mittels des Adressoperators "&" bestimmt.
  Beispielhaft ist "&var" die Speicheradreses der Variable "var".
  */

  int tag, monat, jahr;

  printf("\nBitte geben Sie Ihr Geburtsdatum ein.\n");

  printf("\nTag:\n");
  scanf("%d", &tag);
  fflush(stdin);

  printf("\nMonat:\n");
  scanf("%d", &monat);
  fflush(stdin);

  printf("\nJahr:\n");
  scanf("%d", &jahr);
  fflush(stdin);

  //Zufallszahlengenerator initialisieren
  srand(tag + monat + jahr);
  printf("\nIhre Glückszahl lautet heute: %i", rand());


  // 5 Probleme mit scanf()

  /*
  long nummer;
  double betrag;
  
  printf("\nBitte geben Sie die Kontonummer ein:\n );
  scanf( %8ld ", &nummer);   //Feldbreite hier auf 8 begrenzt

  //bei cygwin-Compilern funktioniert es - s. linux manual page für scanf (man scanf)
  
  fflush(stdin); // Den Eingabe-Puffer löschen
  
  printf("\n Bitte den Geldbetrag eingeben:  ");
  scanf( %lf ", &betrag);

  //Hier folgt nun das weitere Programm...
  */

  long nummer;
  double betrag;

  printf("\nBitte geben Sie die Kontonummer ein:\n");
  scanf("%8ld", &nummer);
  fflush(stdin);

  printf("\nBitte geben den Geldbetrag eingeben: \n");
  scanf("%lf", &betrag);
  fflush(stdin);
  
  // Frage: Wie verhält sich das Programm ohne fflush(stdin); ?
  
  // Programm verhält sich normal bei meiner gcc Version


  //Betriebssichere Eingabe:Eingabefilter
  /*
  Aufgabe 1:
  Schreiben Sie ein Programm, welches Eingaben erfordert, die lediglich als Buchstaben gefiltert werden
  Die Eingaben von Zahlen sollen dabei ignoriert werden
  Stichworte: getc(), getchar()

  Aufgabe 2:
  Stellen Sie sicher, dass die eingegebenen Buchstaben, falls als Kleinbuchstaben eingegeben, Kleinbuchstaben bleiben.
  Falls Großbuchstaben eingegeben werden, sollen diese in Kleinbuchstaben in einer Variable abgelegt werden.

  Aufgabe 3:
  Stellen Sie sicher, dass eine Eingab lediglich Zahlen annimmt - Buchstaben und Sonderzeichen sollen dabei ignoriert werden.

  Versuchen Sie bitte auch die einschlägigen C-Bücher im Ausbildungsraum
  */

  // Aufgabe 1

  char c;
  
  printf("\nBitte geben Sie einen Buchstaben ein:\n"); 

  getchar(); 
  c = getchar();

  printf("\nSie haben den folgendes eingegeben: %c \n", c);

  // Aufgabe 2

  c = tolower(c);

  printf("\nDer Buchstabe ist nun definitv klein: %c\n", c);

  // Aufgabe 3

  int int0;

  scanf("%d", &int0);

  // A 4.1.4 Kontrollstrukturen

  // 1 Struktogramme

  // 2 Kopfgesteuerte Schleife

  int test = 0;

  printf("\nTest While-Schleife\n");

  while(++test < 10){
    printf("%i\n", test);
  }

  // 3 Fussgesteuerte Schleife

  test = 0;

  printf("\nTest Do-While-Schleife\n");

  do{
    printf("%i\n", test);
  }while(++test<10);

  // 4 Zählerschleifen / for-Schleife

  printf("\nTest For-Schleife\n");

  for(test = 0; test > -5; test--){
    printf("%i\n", test);
  }

  // 5 Entscheidungen: Wenn-Dann - die zweiseitige Entscheidung

  printf("\nTest If-Bedingung\n");

  if(test<0){
    printf("\nDon't be so negative.\n");
  }else{
    printf("\nSee it postive.\n");
  }

  // 6 die Mehrfachentscheidung mit switch-case

  printf("\nTest Switch-Case\n");

  enum Mood{
    sad,
    angry,
    happy,
    depressive
  };

  enum Mood mymood = depressive;

  switch(mymood){
    case sad: printf("\nHeads up, Buddy\n"); break;
    case angry: printf("\nCalm down\n"); break;
    case happy: printf("\nYay!\n"); break;
    case depressive: printf("\n*Hug*\n"); break;
    default: printf("\nNo Feelings today\n"); break;
  }

  // A 4.1.5 Vektoren und Strings

  // 1 Vektoren

  // Bitte probieren Sie es aus:
  // Dreh.c --- eine Zeile einlesen und sie umgekehrt wieder auslesen

  int h;
  char buffer [MAXL];

  printf("\n Bitte geben Sie eine Zeile Text ein: \n");
  getchar();
  for (i = 0; i <  MAXL && ( h = getchar())  != '\n'; i++){        
    buffer[i] = h;                                                                    //Zeile Zeichenweise einlesen
  }
  putchar('\n');                                                                      //Danach neue Zeile

  while( --i >= 0){                                                                  // Zeile rückwärts
    putchar(buffer[i]);                                                           //ausgeben
  }  


  putchar('\n');                                                                      //Danach neue Zeile

  // 2 Initialisierung von Vektoren

  

  int zahl[6] = {0, 1, 17};
  /*
  ABER: Versuch: Länge eines Vektors vordefinieren:
  int zahl[6] = {0, 1, 17};
  Bitte lassen Sie sich sämtliche Vektorelemente ausgeben.
  */
  //Zugriff:
  printf("Erstes Vektorelement: %i \n", zahl[0]);
  printf("Zweites Vektorelement: %i\n", zahl[1]);
  printf("Drittes Vektorelement: %i\n", zahl[2]);
  printf("Viertes Vektorelement: %i\n", zahl[3]);
  printf("Fünftes Vektorelement: %i\n", zahl[4]);
  printf("Sechstes Vektorelement: %i\n", zahl[5]);



  // 3 Adressen und Vektoren

  int zahlen[] = {3, 9, 17};

  printf("Die Vektoradresse von zahl[] lautet: %p \n",  zahlen);
  printf("Die Vektoradresse von zahl[] lautet: %p\n",  &zahlen[0]);

  printf("Die Vektoradresse von zahl[] lautet: %p\n",  zahlen + 1);
  printf("Die Vektoradresse von zahl[] lautet: %p\n",  &zahlen[1]);

  // Ergebnis der prints

  /*
  Die Vektoradresse von zahl[] lautet: 0x7ffe5765f8c4 
  Die Vektoradresse von zahl[] lautet: 0x7ffe5765f8c4
  Die Vektoradresse von zahl[] lautet: 0x7ffe5765f8c8
  Die Vektoradresse von zahl[] lautet: 0x7ffe5765f8c8
  */

  // Leiten Sie eine Regel ab. Laden Sie sie hier hoch.

  printf("Vektorgröße: %li\n" , sizeof(zahlen) );
  printf("Vektorgröße: %li\n" , sizeof(zahlen[0]) );
  printf("Vektorgröße: %li\n" , sizeof(zahlen[1]) );
  printf("Vektorgröße: %li\n" , sizeof(zahlen[2]) );

  // Gesamtgröße des Speichers = n * sizeof(datatype)
  // n: anzahl array elements

  // 4 Sonderform des Vektors: Strings

  char wort[] = "münchen";

  // A: Was erwarten Sie?

  printf("Das Wort lautet: %s: \n", wort);
  //printf("Das Wort lautet: %s: ", wort[]);
  //printf("Das Wort lautet: %s: ", wort[0]);
  printf("Das Wort lautet: %c: \n", wort[0]);
  
  /*
  Meine Erwartung ist, dass bei den ersten beiden das ganze Wort kommt, während beim dritten und vierten nur ein m ausgegeben wird.

  Realität wort[] und wort[0] mit %s werfen Fehler.
  */

  // B: Wie lautet das angegebene 4. Zeichen?

  // wort[3]

  // A 4.1.6 Funktionen

  // 3 Auslagern von Funktionen

  // Testen Sie das alles.
  
  // Legen Sie eine neue Funktion in Ihrer Header-Datei an:

  printf("Hallo aus der Main-Funktion. Wir rufen nun die Testfunktion auf:");
  testfunktion();
  printf("Zurück in Main. Tschüß.");


  // 4 Rückgabewert einer Funktion nutzen

  int result = 0;

  result = addiere();

  printf("Die addiere-Funktion ermittelte eine %i\n", result);

  // 5 Übergabewert an Funktion übermitteln

  int number_1, number_2;

  number_1 = 5;
  number_2 = 3;

  result = uebergabetest(number_1, number_2);

  // 6 Taschenrechner für vier Grundrechenarten

  /*
  1) Erzeugen Sie für die vier Grundrechenarten jeweils eine Funktion in Ihrer Header-Datei an.
  2.) Lassen Sie die AnwenderIn auswählen, a) welche beiden Werte und b) in welcher Grundrechenart berechnet werden sollen
  3.) Fragen Sie den Anwender ANSCHLIESSEND, ob er noch eine Berechnung durchführen möchte.

  2.) Vor dem Programmieren planen Sie bitte die Main(): Legen Sie bitte ein Struktogramm dafür an.
  2a) Tauschen Sie das Struktogramm bitte mit Ihrem Platznachbarn - Auch Sie werden ein fremdes Struktogramm erhalten.
  2b) Coden Sie die Main stringent nach dem Struktogramm. Lassen Sie es ggf. bei Fehlern ändern
  */

  printf("Bitte zahl_1 eingeben: \n");
  scanf("%d", &zahl_1);

  printf("Bitte zahl_2 eingeben: \n");
  scanf("%d", &zahl_2);

  getchar();
  char rechnung;
  printf("Welche Rechenart? Addition = 1, Subtraktion = 2, Multiplikation = 3, Division = 4 \n");
  scanf("%c", &rechnung);

  getchar();
  char answer;
  printf("\nRechnung durchführen? yes = 1 no = 2.\n");
  scanf("%c", &answer);

  if(answer == '1'){
    switch(rechnung){
      case '1': 
        int result1; 
        result1 = add(zahl_1, zahl_2); 
        printf("\nDas Ergebnis = %d\n", result1);
      case '2':
        int result2; 
        result2 = subtract(zahl_1, zahl_2); 
        printf("\nDas Ergebnis = %d\n", result2);
      case '3':
        int result3; 
        result3 = multiply(zahl_1, zahl_2); 
        printf("\nDas Ergebnis = %d\n", result3);
      case '4':
        int result4; 
        result4 = divide(zahl_1, zahl_2); 
        printf("\nDas Ergebnis = %d\n", result4);
    }
  } 
  else{
    printf("Ihre Zahlen lauten %d und %d\n", zahl_1, zahl_2);
  }

  // A 4.1.7 Zeiger

  // 4 Zeiger als Parameter von Funktionen

  float xx = 5.5F;
  float yy = 10.7F;

  

  printf("\nx has the adress %f\n and y has the value %f\n", xx, yy);

  fswap (&xx, &yy);

  printf("\nNow x has the value %f\n and y has the value %f\n", xx, yy);

  // A 4.1.8 structures - Datensätze aus unterschiedlichen Datentypen - Gruppe der komplexen Datentypen

  // 1 Definition der structures adresse & artikel

    struct adresse e, f;
  
  /*
    Speicherbedarf per Hand:
    a und b haben 100 Byte durch "strasse", 30 Byte durch "ort" und 8 Byte durch long
    Macht 138 Bytes.
  */ 

  printf("\nDer Speicherbedarf von a ist: %li\n", sizeof(e));
  printf("\nDer Speicherbedarf von b ist: %li\n", sizeof(f));

  // In Wahrheit sind es 144 6 werden als Puffer angelegt.
  
  
  struct
  {
    char artikel_bez[50];

    int stueckzahl;
  } artikel1, artikel2;

  /*
    artikel_1 und artikel_2 haben 54 Bytes jeweils.
  */

  printf("\nDer Speicherbedarf von a ist: %li\n", sizeof(artikel1));
  printf("\nDer Speicherbedarf von b ist: %li\n", sizeof(artikel2));  

  // 2 Initialisieren von Strukturvariablen
  
  printf("Gehalt des Chefs: %f\n", chef.income);

  printf("Strasse, in der der Chef wohnt: %s\n", chef.adr.strasse);

  // 3 Zeiger auf Strukturen

  getNewadr(&chef);

  // A 4.1.9 High-Level Dateizugriff

  

  return 0;
}

// Erweitern Sie ihr Programm wie folgt:

//Neue Adresse eines Mitarbeiters einlesen

void getNewadr( struct personal *p)            //Bitte erinnern: ein Funktionsparameter = Variablendeklaration!!!
{

  //Personalnummer und Name anzeigen...

  printf("Personalnummer: %1lu\n", p->nummer);

  printf("Name: %s\n\n", p->name);

 

  //Neue Adresse anlegen:

  printf("Bitte neue Adresse eingeben: \n\n");

  printf("Strasse mit max. 29 Zeichen:  ");

  fgets(p->adr.strasse, 30, stdin);

  printf("Wohnort mit max. 29 Zeichen:  ");

  fgets(p->adr.ort, 30, stdin);

 

  printf("Telefon:  ");

  scanf("1d", &(p->adr.tel)); //Ja, scanf() ist problematisch, doch hier geht es um das Verständnis der Adressierung
}
