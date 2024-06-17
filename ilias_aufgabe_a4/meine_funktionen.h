// 3 Auslagern von Funktionen

int testfunktion(){
    int i = 5;
    int f = 3;
    printf("\nHallo aus der Testfunktion!");
    printf("\nAddiert man die Werte i und f, so erhält man eine %i\n", i+f);
   
    printf("\nDie Testfunktion verabschiedet sich jetzt... \n");
    return 0;
}

// 4 Rückgabewert einer Funktion nutzen

int addiere(){
   int zahl_1 = 5;
   int zahl_2 = 3;
   int ergebnis;
 
   ergebnis = zahl_1 + zahl_2;
   
   return ergebnis;
}


// 5 Übergabewert an Funktion übermitteln

int uebergabetest( int zahl_1, int zahl_2){

  int ergebnis = 0;

  ergebnis = zahl_1 + zahl_2;

  return ergebnis;
}

// 6 Taschenrechner für vier Grundrechenarten

int multiply(int zahl_1, int zahl_2){
  return zahl_1 * zahl_2;
}

int add(int zahl_1, int zahl_2){
  return zahl_1 + zahl_2;
}

int divide(int zahl_1, int zahl_2){
  return zahl_1 / zahl_2;
}

int subtract(int zahl_1, int zahl_2){
  return zahl_1 - zahl_2;
}