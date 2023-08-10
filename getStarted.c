#include <stdio.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

    
void getStarted(){
    system("cls");
    gotoxy(35, 10);
    printf("3");
    delay(1000);
    system("cls");
    gotoxy(35, 10);
    printf("2");
    delay(1000);
    system("cls");
    gotoxy(35, 10);
    printf("1");
    delay(1000);
    system("cls");
    gotoxy(30, 10);
    printf("GET SET GO!");
    delay(1000);
    system("cls");
}

