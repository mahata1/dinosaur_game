#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include "auth.c"
#define c 219
int p=60,x=60,score=0;
BOOLEAN var_game_end = FALSE;
void clear_screen() {
    system("cls");
}
void delay(unsigned int mseconds) {
    Sleep(mseconds);
}
//  gotoxy function to move cursor to specific point
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
    printf("GET");
    gotoxy(30, 10);
    printf("SET");
    gotoxy(30, 10);
    printf("GO!");
    delay(1000);
    system("cls");
}

int getHighScore(const char *username) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        return 0;
    }

    char storedUsername[50];
    int storedScore;

    while (fscanf(file, "%s %d", storedUsername, &storedScore) != EOF) {
        if (strcmp(storedUsername, username) == 0) {
            fclose(file);
            return storedScore;
        }
    }

    fclose(file);
    return 0;
}

void updateScore(const char *username, int score) {
    FILE *file = fopen("data.txt", "a");
    if (file == NULL) {
        printf("Error opening data file.\n");
        return;
    }

    fprintf(file, "%s %d\n", username, score);
    fclose(file);
}
//print_obstacle function displays obstacle
int print_obstacle(){
	//printf("obstacle%d",n_obstacle);
   	static int y=14;
	   if(x<=1 || var_game_end == TRUE)	{
   	x = 60;
   	var_game_end =FALSE;  	
   }
	 gotoxy(40,10);
    printf("score::%d",score);
    gotoxy(20,3);
    printf("Press X to exit:..");
    gotoxy(41,3);
    printf("Press J to jump:..");
	gotoxy(x,y);
	printf("%c   %c",c,c);
	gotoxy(x,y+1);
	printf("%c%c%c%c%c",c,c,c,c,c);
	gotoxy(x,y+2);
	printf("%c",c);
	//speed can be controlled by settind differene decrement value for x
//printf("%d",x);
//	return x;
    p = x;
	if(x>=3 && x<=22){
		x-=3;
	}else {
		x-=2;
	}
	
    //x -=2;

   if (x<=10){
   	score++;
   }
   return x;
}

void print_dinosaur1(){
    printf("\n");
    printf("                   __      \n");
    printf("                  / ._)     \n");
    printf("          _.-----'  /      \n");
    printf("         /         )  \n");
    printf("      __/ (\\      /     \n");
    printf("     /__.-' /_/-/_/ \n");
    print_obstacle();
    Sleep(30);
}
void print_dinosaur2() {
    printf("\n");
    printf("                   __      \n");
    printf("                  / ._)     \n");
    printf("          _.-----'  /      \n");
    printf("         /         )  \n");
    printf("      __/ (\\      /     \n");
    printf("     /__.-' |_|-|_| \n");
    print_obstacle();
    Sleep(30);
}

void print_dinosaur3() {
    printf("\n");
    printf("                   __      \n");
    printf("                  / ._)     \n");
    printf("          _.-----'  /      \n");
    printf("         /         )  \n");
    printf("      __/ (\\      /     \n");
    printf("     /__.-' \\_\\-\\_\\ \n");
    print_obstacle();
	Sleep(30);
}
void print_dinosaur(){
	static int a=1;
	if(a%3==0){
		print_dinosaur1();
		
	} else if(a%3 == 1){
		print_dinosaur2();
	}else{
		print_dinosaur3();
	}
	a++;
}
void end_game(){
	printf("game end!");
}
void dino_ground(int ground_position) {
    int i = ground_position;
    	//gotoxy(0,13);
      //  print_ground();
       gotoxy(0,0);
    for (i = 1; i <= ground_position; i++) {
     printf("\n");
    }
    print_dinosaur();
    Sleep(10);
}

void dino_jump(int dinosaur_ground_position, int dinosaur_upper_position) {
    // code to move dinosaur upward
    
    int k, kk;
    for (k = dinosaur_ground_position; k >= dinosaur_upper_position; k--) {
        kk = k;
  //      gotoxy(0,13);
//        print_ground();
        gotoxy(0,0);
        while (kk > 1) {
            printf("\n");
            kk--;
        }
        print_dinosaur2();
        Sleep(10);
        clear_screen();
    }  
    
    // move dino downward
    for (k = dinosaur_upper_position; k <= dinosaur_ground_position; k++) {
        kk = k;
       // gotoxy(0,13);
        //print_ground();
        gotoxy(0,0);
        while (kk > 0) {
            printf("\n");
            kk--;
        }
        print_dinosaur2();
        Sleep(10);
        clear_screen();
    }
}
// ... (Other parts of your code)

void run_dinosaur() {
    int dinosaur_ground_position = 10;
    int dinosaur_upper_position = 4;
    int jump_flag = 0; // Variable to track if the jump has been initiated
    int j;
    char ch;

    clear_screen(); // Clear the screen at the beginning

    while (1) {
        BOOLEAN dino_jumped = FALSE;

        if (_kbhit()) {
            ch = _getch();
            if (ch == 'j' && !jump_flag) {
                jump_flag = 1;
                dino_jump(dinosaur_ground_position, dinosaur_upper_position);
                jump_flag = 0;
            }
            dino_jumped = TRUE;
        }

        if (ch == 'x') {
            gotoxy(40, 5);
            end_game();
            gotoxy(50, 5);
            printf("total score:%d ", score);
            break;
        }

        // Only clear the screen here
        clear_screen();

        // Display in ground position
        dino_ground(dinosaur_ground_position);

        // Update the score and other information
        if (p <= 23 && dino_jumped == FALSE) {
            gotoxy(40, 10);
            end_game();
            gotoxy(50, 10);
            printf("total score %d ", score);
            var_game_end = TRUE;
            
            // Wait for user input
            while (!_kbhit()) {
                int a = 1;
            }
            
            score = 0;
        }
    }
}

int main() {
    auth();
    getStarted();
    run_dinosaur();
    return 0;
}
