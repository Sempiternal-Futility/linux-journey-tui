#include <stdio.h>
#include <curses.h>

// TODO:
// WRITE SOME LESSONS IN GRASSHOPPER



void SetColors(); // HANDLES THE COLORS OF THE TUI

void SetColors()
{
  
   init_pair( 2, COLOR_GREEN, COLOR_BLACK ); // GREEN FOREGROUND, BLACK BACKGROUND
   init_pair( 3, COLOR_BLACK, COLOR_GREEN ); // BLACK FOREGROUND, GREEN BACKGROUND

   bkgd( COLOR_PAIR(2) );

}


int main()
{

   initscr();
   noecho();
   start_color();

   SetColors(); // SET UP THE COLORS
   TUI(); // SET UP THE TUI


   endwin();


   return 0;

}
