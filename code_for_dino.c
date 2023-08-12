#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#define c 219

void clear_screen() {
    system("cls");
}
int run_dino();//declaration for run_dino:
void hideCursor()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
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
//    for (int x = 0; x < 79; x++)
//        printf("%c", c);
}

int t, dx=15,speed = 50;
int a =1;
void ds(int jump)
{
   // static int a = 1;

    if (jump == 0)
        t = 0;
    else if (jump == 2)
        t--;
    else
        t++;
     int i=20;
    gotoxy(dx, i - t);
    printf("                 ");
    i++;
    gotoxy(dx, i - t);
    printf("        %c%c%c%c%c%c    ", c, c, c, c, c, c);
    i++;
    gotoxy(dx, i - t);
    printf("        %c%c%c%c%c%c%c%c     ", c, c, c, c, c, c, c, c);
   i++;
    gotoxy(dx, i - t);
    printf("        %c%c%c%c%c %c%c    ", c, c, c, c, c, c, c);
    i++;
	gotoxy(dx, i - t);
    printf(" %c      %c%c%c%c%c%c%c%c    ", c, c, c, c, c, c, c, c, c);
    i++;
    gotoxy(dx, i - t);
    printf("%c%c%c   %c%c%c%c%c%c%c%c%c  ", c, c, c, c, c, c, c, c, c, c, c, c);
    i++;
    gotoxy(dx, i - t);
    printf(" %c%c%c%c%c%c%c%c%c%c%c     ", c, c, c, c, c, c, c, c, c, c, c);
     i++;
    gotoxy(dx, i - t);
    printf("  %c%c%c%c%c%c%c       ", c, c, c, c, c, c, c);
    i++;
    gotoxy(dx, i - t);
    i++;
    if (jump == 1 || jump == 2)
    {   
        printf("    %c%c%c %c%c       ", c, c, c, c, c);
        gotoxy(dx, i - t);
        printf("    %c%c   %c%c      ", c, c, c, c);
    }
    else if (a == 1)
    {   
        printf("    %c%c%c%c  %c%c%c    ", c, c, c, c, c, c, c);
        gotoxy(dx, i - t);
        printf("      %c%c         ", c, c);
        a = 2;
    }
    else if (a == 2)
    {
        printf("     %c%c%c%c %c%c      ", c, c, c, c, c, c);
        gotoxy(dx, i - t);
        printf("          %c%c     ", c, c);
        a = 1;
    }
    i++;
    gotoxy(dx, i - t);

    if (jump != 0)
    {
        printf("                ");
    }
    else
    {
      //  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", c, c, c, c, c, c, c, c, c, c, c, c, c, c);
    }

    delay(speed);
}
int obx = 80,scr=0,oby = 25;
bool game_over =false;
void restart(){
	 obx = 80,scr=0;
	 getup();
}

int obj()
{
   // static int scr = 0;
  //  int oby=25; static int obx=80;
     if (((obx <= dx + 12) && (obx>=dx) &&(t<=5)) ||(obx<=(dx+15)&& obx >=dx && t<=2)){
        scr = 0;
        speed = 40;
        gotoxy(36, 8);
        printf("Game Over");
        getch();
        gotoxy(36, 8);
        printf("         ");
        game_over = true;
        restart();
        run_dino();
    }
    gotoxy(obx, oby);  
    printf("%c    %c   ", c, c);
    gotoxy(obx, oby+1); 
    printf("%c    %c   ", c, c);
    gotoxy(obx, oby+2);
    printf("%c%c%c%c%c%c    ", c, c, c, c, c, c);
    gotoxy(obx,oby+3);
    printf("  %c    ", c);
    gotoxy(obx, oby+4);
    printf("  %c    ", c);
    if(obx <2){
    gotoxy(0,oby);printf("                   ");
    gotoxy(0,oby+1);printf("                 ");
    gotoxy(0,oby+2);printf("                 ");
    gotoxy(0,oby+3);printf("                 ");
    gotoxy(0,oby+4);printf("               ");
    gotoxy(0,oby+5);printf("         ");
}
   // printf("%d",obx);
    // to increase obstacle speed as it goes down the dino:
    if(obx<(dx+14)){
    	obx-=2;
	}else{
		obx-=2;
	}
    //x++;

    if (obx <0)
    {
        obx = 80;
        scr++;
        gotoxy(70, 2);
        printf("     ");
        gotoxy(70, 2);
        printf("%d", scr);

        if (speed > 20)
            speed--;
    }
    return scr;
}

int run_dino(){
	
    char ch;
    int i;
    getup();
    hideCursor();
    while (true)
    {   hideCursor();
       // getup();
        while (!kbhit())
        {
            ds(0);
            obj();
        }

        ch = getch();

        if (ch == ' ')
        {
            for (i = 0; i < 13; i++)
            {
                ds(1);
                obj();
            }
            for (i = 0; i < 13; i++)
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

int main()
{
    //system("mode con: lines=29 cols=82");
    int e=run_dino();
    if(e==0){
    	gotoxy(30,30);
    	printf("score:%d",scr);
    	printf("Game End ");
	}
    return 0;
}

