#include"snake.h"
extern st* beg;
extern int foodrow,foodcol,length;
void print(){
	clear();
	printscr();
	printsnake();
	printfood();
	mvprintw(0,2,"SCORE: %d",length);

}
int maxrow,maxcol;
void printscr(){
	move(1,1);
	int i;
	for(i=2;i<maxcol;i++){
		printw("#");
	}
	for(i=2;i<maxrow;i++){
		mvprintw(i,1,"#");
		mvprintw(i,(maxcol-1),"#");
	}
	move((maxrow-1),1);
	for(i=2;i<maxcol;i++){
		printw("#");
	}
	mvprintw(maxrow,0,"Press ESC for pause");
}
void initializeyx(){
	int row,col;
	maxrow=15,maxcol=20;
	getmaxyx(stdscr,row,col);
	maxrow= (row<maxrow)? row:maxrow;
	maxcol= (col<maxcol)? col:maxcol;
	maxrow--;
	maxcol--;
}
void printsnake(){
	st* p=beg;
	while(p!=NULL){
		mvprintw(p->row,p->col,"$");
		p=p->next;
	}
}
void printfood(){
	mvprintw(foodrow,foodcol,"@");
}



