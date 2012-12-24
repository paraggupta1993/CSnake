## SNAKE GAME :

Author : Parag Gupta 
Contact : paraggupta1993@gmail.com

## Requirements : 

Ncurses library-

Open terminal and type the following command for linux :

Debain/Ubuntu users:
$ sudo apt-get install libncurses5-dev libncursesw5-dev

RHEL / Fedora / CentOS users:
$ sudo yum install ncurses-devel ncurses

## Description of files :
 * src/snake.h : Contains header files, prototypes of functions to be used and some defined macros.
 * src/snake.c : Contains main code for the game.
 * src/print.c : prints the surface for the game.
 * Snake :  ELF 32-bit LSB executable 

## Compliling from source :
  $ gcc -o Snake src/print.c src/snake.c -lncurses

## How-to-Play :

 * Start the Game : In linux terminal type the following
  $./Snake
 
 * Play : 
  ** A string of "$" represent your Snake.(You have to figure out where his head is and tail is ;-) ). 
  ** A char '@' represent your food. You have to collect it with your head to gain score.
  ** Colliding with wall or yourself means "GAME-OVER"

 * Pause:
   Press 'ESC' to pause.
 
 * Menu: 
   Press 'ESC' for Menu.
 
## CHEAT CODES :
  
  * Press 'ESC' then 'c' to get into cheat mode.
  * While in cheat mode, the snake will dig a hole where its head is and gets inside it,if you keep direction button pressed. After releasing, the snake will come out of the hole again. This gives you more time. (EFFECTS WILL BE SEEN WITH A LONG SNAKE).

----THANK-YOU----
Bye,
Horcrux


