#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>

#ifdef _WIN32
#define c 219
#include <windows.h>
#else
#include <unistd.h>
#endif

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int mseconds)
{
#ifdef _WIN32
    Sleep(mseconds);
#else
    usleep(mseconds * 1000); // usleep takes microseconds
#endif
}

void getup()
{
    system("cls");
    gotoxy(10, 2);
    printf("Press X to Exit, Press Space to Jump");
    gotoxy(62, 2);
    printf("SCORE : ");
    gotoxy(1, 25);
    for (int x = 0; x < 79; x++)
        printf("%c", c);
}

int t, speed = 50;

void ds(int jump)
{
    static int a = 1;

    if (jump == 0)
        t = 0;
    else if (jump == 2)
        t--;
    else
        t++;

    gotoxy(2, 15 - t);
    printf("                 ");
    gotoxy(2, 16 - t);
    printf("        %c%c%c%c%c%c", c, c, c, c, c, c);

    gotoxy(2, 17 - t);
    printf("        %c%c%c%c%c%c%c%c", c, c, c, c, c, c, c, c);
    gotoxy(2, 18 - t);
    printf("        %c%c%c%c%c %c%c", c, c, c, c, c, c, c);
    gotoxy(2, 19 - t);
    printf(" %c      %c%c%c%c%c%c%c%c ", c, c, c, c, c, c, c, c, c);

    gotoxy(2, 20 - t);
    printf("%c%c%c   %c%c%c%c%c%c%c%c%c ", c, c, c, c, c, c, c, c, c, c, c, c);
    gotoxy(2, 21 - t);
    printf(" %c%c%c%c%c%c%c%c%c%c%c  ", c, c, c, c, c, c, c, c, c, c, c);

    gotoxy(2, 22 - t);
    printf("  %c%c%c%c%c%c%c   ", c, c, c, c, c, c, c);
    gotoxy(2, 23 - t);

    if (jump == 1 || jump == 2)
    {
        printf("    %c%c%c %c%c       ", c, c, c, c, c);
        gotoxy(2, 24 - t);
        printf("    %c%c   %c%c      ", c, c, c, c);
    }
    else if (a == 1)
    {
        printf("    %c%c%c%c  %c%c%c    ", c, c, c, c, c, c, c);
        gotoxy(2, 24 - t);
        printf("      %c%c         ", c, c);
        a = 2;
    }
    else if (a == 2)
    {
        printf("     %c%c%c%c %c%c      ", c, c, c, c, c, c);
        gotoxy(2, 24 - t);
        printf("          %c%c     ", c, c);
        a = 1;
    }

    gotoxy(2, 25 - t);

    if (jump != 0)
    {
        printf("                ");
    }
    else
    {
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", c, c, c, c, c, c, c, c, c, c, c, c, c, c);
    }

    delay(speed);
}

void obj()
{
    static int x = 0, scr = 0;

    if (x == 56 && t < 4)
    {
        scr = 0;
        speed = 40;
        gotoxy(36, 8);
        printf("Game Over");
        getch();
        gotoxy(36, 8);
        printf("         ");
    }

    gotoxy(74 - x, 20);
    printf("%c    %c ", c, c);
    gotoxy(74 - x, 21);
    printf("%c    %c ", c, c);
    gotoxy(74 - x, 22);
    printf("%c%c%c%c%c%c ", c, c, c, c, c, c);
    gotoxy(74 - x, 23);
    printf("  %c    ", c);
    gotoxy(74 - x, 24);
    printf("  %c  ", c);

    x++;

    if (x == 73)
    {
        x = 0;
        scr++;
        gotoxy(70, 2);
        printf("     ");
        gotoxy(70, 2);
        printf("%d", scr);

        if (speed > 20)
            speed--;
    }
}

int main()
{
    system("mode con: lines=29 cols=82");

    char ch;
    int i;
    getup();

    while (true)
    {
        while (!kbhit())
        {
            ds(0);
            obj();
        }

        ch = getch();

        if (ch == ' ')
        {
            for (i = 0; i < 10; i++)
            {
                ds(1);
                obj();
            }
            for (i = 0; i < 10; i++)
            {
                ds(2);
                obj();
            }
        }
        else if (ch == 'x')
            return 0;
    }

    return 0;
}
