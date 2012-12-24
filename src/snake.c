#include"snake.h"

st *beg;
int flag=1;
prev pre=right;
extern int maxrow,maxcol;
int lastrow,lastcol;
int length=1,cheat=0;
int foodrow,foodcol;
int main(){
	srand(time(NULL));
	signal(SIGINT,sig);
	char ans='y';
	int status;
	char ch;
	while(ans=='y'){
		length=1;
		beg=(st*)malloc(sizeof(st));
		initscr();
		keypad(stdscr,TRUE);
		initializeyx();
		foodrow=maxrow/2,foodcol=maxcol/2;
		beg->row=maxrow/2;
		beg->col=2;
		beg->next=NULL;
		print();
		mvprintw(0,0,"press a key to start");
		cbreak();
		move(maxrow,maxcol);
		noecho();
		getch();
		while(1){
			move(maxrow,maxcol);
			fflush(stdin);
			halfdelay(LEVEL);
			ch=getch();
			if(ch==27){
				menu();
				print();
				continue;
			}
			getsnakeready(ch);
			status=checksnake();
			if(status==DEAD) break;
			if(status==GOT_FOOD) getfood();
			print();
		}
		move(0,0);
		halfdelay(100);
		printw("you are dead. Press a key to exit \n");
		printw("Or press 'y' to restart the game.");
		refresh();
		ans=getch();
		st* next=beg;
		while(beg!=NULL){
			next=beg->next;
			free(beg);
			beg=next;
		}
	}
	clear();
	endwin();
	return 0;
}

void getsnakeready(int ch){
	st* p;
	p=beg->next;
	st temp1,temp2;
	temp1=*(beg);
	lastrow=beg->row;
	lastcol=beg->col;
	while(p!=NULL){
		lastcol=p->col;
		lastrow=p->row;
		temp2=*(p);
		p->row=temp1.row;
		p->col=temp1.col;
		p=p->next;
		temp1=temp2;
	}
	if(cheat){
		switch (ch){
			case 5://right
				{
					if(pre==up || pre==down){
						pre=right;
						beg->col++;
						flag=1;
					}
					else flag=0;
					break;
				};
			case 3://up
				{
					if(pre==left || pre==right){
						pre=up;
						beg->row--;
						flag=1;
					}
					else flag=0;
					break;
				};
			case 2://down
				{
					if(pre==left || pre==right){
						beg->row++;
						flag=1;
						pre=down;
					}
					else flag=0;
					break;
				};
			case 4://left
				{
					if(pre==up || pre==down){
						pre=left;
						flag=1;
						beg->col--;
					}
					else flag=0;
					break;
				};
			default:
				{
					flag=1;
					if(pre==right){
						beg->col++;
					}
					if(pre==left){
						beg->col--;
					}
					if(pre==down){
						beg->row++;
					}
					if(pre==up){
						beg->row--;
					}
					break;
				}
		};
	}
	else{

		flag=1;
		if(ch==5 &&(pre==up || pre==down)){//right
			pre=right;
			beg->col++;
		}
		else if(ch==3&&(pre==left || pre==right)){//up
			pre=up;
			beg->row--;
		}
		else if(ch==2&&(pre==left || pre==right)){//down
			beg->row++;
			pre=down;
		}
		else if(ch==4&&(pre==up || pre==down)){//left
			pre=left;
			beg->col--;
		}
		else{
			if(pre==right){
				beg->col++;
			}
			if(pre==left){
				beg->col--;
			}
			if(pre==down){
				beg->row++;
			}
			if(pre==up){
				beg->row--;
			}
		}
	}
	return;
}
int checksnake(){
	if(flag==0) return ALIVE;
	if(beg->col==(maxcol-1) || beg->col==1||beg->row==(maxrow-1)||beg->row==1){
		return DEAD;
	}
	st* p=beg->next;
	while(p!=NULL){
		if(p->row==beg->row){
			if(p->col==beg->col) return DEAD;
		}
		p=p->next;
	}
	if(beg->row==foodrow && beg->col==foodcol){
		return GOT_FOOD;
	}
	return ALIVE;
}
void getfood(){
	st* p=beg;
	while(p->next!=NULL) p=p->next;
	st* temp;
	temp=(st*)malloc(sizeof(st));
	p->next=temp;
	temp->row=lastrow;
	temp->col=lastcol;
	temp->next=NULL;
	int flag2=1;
	while(flag2){
		flag2=0;
		foodrow=rand()%(maxrow-3)+2;
		foodcol=rand()%(maxcol-3)+2;
		p=beg;
		while(p!=NULL){
			if(p->row==foodrow && p->col==foodcol){
				flag2=1;
				break;
			}
			p=p->next;
		}
	}
	length++;
}
void sig(int s){
	clear();
	char msg[]="Wanna Quit?";
	int len=strlen(msg);
	mvprintw((maxrow)/2,(maxcol-len)/2,"Wanna Quit?");
	mvprintw((maxrow)/2+1,(maxcol-len)/2,"Press 'n' to resume with game ");
	mvprintw((maxrow)/2+2,(maxcol-len)/2,"Or Any other key to Quit");
	halfdelay(100);
	char ch=getch();
	nocbreak();
	if(ch!='n'){
		endwin();
		exit(1);
	}
}
void menu(){
	clear();
	mvprintw(0,0,"Game Paused !!");
	mvprintw(1,0,"Press 'c' to cheat with holes:");
	mvprintw(2,0,"Pressing direction button for a continously will make ur snake short for that moment by holding it on one particular cell thus giving you more time to decide the direction to move. ");
	mvprintw(6,0,"Press 'q' to quit ");
	mvprintw(7,0,"Press any other key to resume with the game. ");
	cbreak();
	noecho();
	char command=getch();
	nocbreak();
	echo();
	if(command=='c') cheat=1;
	if(command=='q') { 
	  sig(0);
	}
}

