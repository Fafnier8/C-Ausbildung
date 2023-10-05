#include<stdio.h>
#include<curses.h>
#include<stdlib.h>

//global variables
int width = 30;
int height = 30;
WINDOW *win1;
// Draws the boundarie of the game

void draw(){
    initscr();
    win1 = newwin(height, width, 0, 0);
    endwin();
}

// Setting fruit in between the barrier

void setup(){

}

//takes input from keyboard

void input(){

}

// set movement of snake

void logic(){

}


int main(){
    draw();
}