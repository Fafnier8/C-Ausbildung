#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
    Coding Bat exercise Array-2 Sum28

    Given an array of ints, return true if the sum of all the 2's in the array is exactly 8.


    sum28([2, 3, 2, 2, 4, 2]) → true
    sum28([2, 3, 2, 2, 4, 2, 2]) → false
    sum28([1, 2, 3, 4]) → false
*/

/*
    Function definition for Sum28
*/

bool sum28(int nums[], int arr_length){
    int counter = 0;
    for(int i = 0; i < arr_length; ++i){
        if(nums[i] == 2) counter++;
    }
    if(counter == 4) return true;
    return false;
}

/*
    Coding Bat exercise Array-3 squareUp

    Given n>=0, create an array length n*n with the following pattern, 
    shown here for n=3 : {0, 0, 1,    0, 2, 1,    3, 2, 1} (spaces added to show the 3 groups).

    squareUp(3) → [0, 0, 1, 0, 2, 1, 3, 2, 1]
    squareUp(2) → [0, 1, 2, 1]
    squareUp(4) → [0, 0, 0, 1, 0, 0, 2, 1, 0, 3, 2, 1, 4, 3, 2, 1]
*/
void squareUp(unsigned int n){
    int arr[n*n]={0};
    for(int i = 1; i<n=; ++i){
        // the array is filled with 0 so only the numbers need to be added
        // first the smallest number will be added everywhere it belongs then the next bigger number
        // n-i causes the second for loop to run one less with one higher iteration of i
        for(int j = 0; j <= n-i; ++j){
            // the array fills the numbers from back to front
            // n*n is the full size of our array. We subtract i to get to the right position wheere the first 
            // i of the loop will be placed and then go back the size of one group times the iteration value j to
            // place all numbers at their places
            arr[((n*n)-i)-n*j] = i;
        }
    }
    
    for(int i = 0; i < n*n; ++i){
        printf("%d\n", arr[i]);
    }
    
}

/*
    CodingBat exercise String-1 make_abba

    Given two strings, a and b, return the result of putting them together in the order abba, e.g. "Hi" and "Bye" returns "HiByeByeHi".


    make_abba('Hi', 'Bye') → 'HiByeByeHi'
    make_abba('Yo', 'Alice') → 'YoAliceAliceYo'
    make_abba('What', 'Up') → 'WhatUpUpWhat'
*/

void make_abba(char str1[], char str2[], char abba[], int abbalen){
    strcat(abba, str1);
    strcat(abba, str2);
    strcat(abba, str2);
    strcat(abba, str1);
}

int main(){
    // test of sum28
    int test_arr_sum28_true[] = {2, 3, 2, 4, 2, 7, 8, 2};
    int test_arr_sum28_false[] = {2, 1, 6, 0, 2, 2, 2, 2};

    if(sum28(test_arr_sum28_false, sizeof(test_arr_sum28_false)/sizeof(int))){
        printf("True\n");
    } else {
        printf("False\n");
    }

    // test of squareUp
    squareUp(5);


    //test of make_abba
    char str1[] = "What";
    char str2[] = "Up";
    char abba[((strlen(str1)+ strlen(str2))*2+1)]={'\0'};
    int abba_len = (strlen(str1)+ strlen(str2))*2+1;
    make_abba(str1, str2, abba, abba_len);
    printf("%s\n", abba);
}