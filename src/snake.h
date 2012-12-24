#include<ncurses.h>
#include<string.h>
#include<signal.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>

#define LEVEL 2
#define GOT_FOOD 1
#define ALIVE 0
#define DEAD -1

struct st{
	int row;
	int col;
	struct st*next;
};
enum prev{
	left,right,up,down
};
typedef enum prev prev;
typedef struct st st;

void printscr();
void print();
void initializeyx();
void getsnakeready(int);
void printsnake();
int checksnake();
void printfood();
void getfood();
void sig(int);
void menu();
