/*
Erstellen Sie eine Funktion dreiSort(). Diese erhält 3 Pointer pZ1, pZ2, pZ3 auf ganze Zahlen als Parameter.
Die Funktion ändert die Originale der drei Zahlen so, dass gilt:
Die erste Zahl ist größer oder gleich wie die zweite Zahl
Die zweite Zahl ist größer oder gleich wie die dritte Zahl 

Falls alle drei Zahlen gleich sind, gibt die Funktion true zurück, ansonsten false. 

Die Main-Funktion ruft dreiSort() auf und gibt das Ergebnis auf der Konsole aus.
Gibt die Funktion true zurück, erfolgt die Ausgabe: “Die Zahlen sind gleich.”

Überlegen Sie sich auch verschiedene Testfälle. z.B. zwei Zahlen sind gleich oder alle 3 Zahlen sind gleich.
Bsp: 
int z1 = 5;
int z2 = 12;
int z3 = 111;
Nach dem Aufruf der Funktion dreiSort() sind die Zahlen wie folgt:
z1 ist 111, z2 ist 12 und z3 ist 5. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>


bool dreiSort(int *pZ1, int *pZ2, int *pZ3){
    if((*pZ1 == *pZ2) && (*pZ1 == *pZ3)){
        return true;
    }
    int arr[] = {*pZ1, *pZ2, *pZ3};
    int temp;
    
    // Sort algorithm for arrays of any size

    for(int i = 0; i < (sizeof(arr)/sizeof(arr[0]))-1;){
        if(arr[i]>arr[i+1]){
            for(;;++i){
                if(i == sizeof(arr)/sizeof(arr[0])-1){
                    i = 0;
                    break;
                } 
                
                if(arr[i]<=arr[i+1]){
                    i = 0;
                    break;
                }
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        } else{
            i++;
        }
    }
    
    *pZ1 = arr[0];
    *pZ2 = arr[1];
    *pZ3 = arr[2];
    return false;
}


int main(){
    int z1 = 12;
    int z2 = 5;
    int z3 = 111;

    int *pZ1 = &z1;
    int *pZ2 = &z2;
    int *pZ3 = &z3;

    if(dreiSort(pZ1, pZ2, pZ3)){
        printf("Die Zahlen sind gleich.\n");
    } else {
        printf("z1 ist %d, z2 ist %d und z3 ist %d.\n", z1, z2, z3);
    }


}