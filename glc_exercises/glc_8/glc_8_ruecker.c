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

int main(){
    // test of sum28
    int test_arr_sum28_true[] = {2, 3, 2, 4, 2, 7, 8, 2};
    int test_arr_sum28_false[] = {2, 1, 6, 0, 2, 2, 2, 2};

    if(sum28(test_arr_sum28_false, sizeof(test_arr_sum28_false)/sizeof(int))){
        printf("True\n");
    } else {
        printf("False\n");
    }
}