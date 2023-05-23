// THIS SCRIPT HANDLES ALL THE TUI

#include<ncurses.h>

void TUI(); // HANDLES THE TUI ( text user-interface )
void Navigate( short *plevel, short *pchapter, char input ); // ALLOWS THE USER TO BROWSE THE BUTTONS WITH THE ARROW KEYS
void Draw_Button_Background( int posOneY, int posOneX, char buttonOne[], int posTwoY, int posTwoX, char buttonTwo[] ); // DRAWS THE BACKGROUND COLOR ON THE SELECTED BUTTON
void Draw_Corner_Lines(); // DRAWS THE BOX THAT DELIMITS THE LIMITS/CORNERS
void Draw_Bottom_Info(); // DRAWS THE MOVING INSTRUCTIONS ON THE BOTTOM


void TUI()
{

   char input;
   short chapter = 0; // THIS IS HERE BECAUSE WITHOUT IT, A SEGMENTATION FAULT TAKES PLACE, IDK WHY LMAO
   short *pchapter = &chapter; // THIS IS WHICH CHAPTER THE USER IS IN ( 1 - grasshopper, 2 - journeyman or 3 - networking )
   short *plevel; *plevel = 1;

   Draw_Corner_Lines();
   Chapters(); 
      
   attron( COLOR_PAIR(3) ); // SELECTS THE "SPECIAL" COLOR, SINCE THIS IS THE SELECT BUTTON BY DEFAULT
   move( 15, 71 ); // PLACES THE CURSORS ON TOP OF THE "GRASSHOPPER" BUTTON
   printw( "%s", "GRASSHOPPER" ); // REWRITES THE "GRASHOPPER" BUTTON WITH THE SPECIAL COLORS


   while( 1 > 0 )
   {
      input = getch();
      Navigate( plevel, pchapter, input );
   }

}


void Navigate( short *plevel, short *pchapter, char input )
{

   int curPosY;
   int curPosX;

   getsyx( curPosY, curPosX );

   if( *plevel == 1 ) // IF THE USER IS ON "CHAPTERS"
      Chapters_Handling( curPosY, plevel, pchapter, input );


   
   if( *plevel == 2  &&  *pchapter == 1 ) // GRASSHOPPER BUTTONS
   {

      Grasshopper_Courses();   

      attron( COLOR_PAIR(3) );
      move( 15, 50 );
      printw( "%s", "GETTING STARTED" );


      bool quit = false;

      while( quit == false ) 
         quit = Grasshopper_Courses_Handling( curPosY, curPosX, plevel, pchapter, input );

   }

   else if( *plevel == 2  &&  *pchapter == 2 )
   {

      Journeyman_Courses();      
   
      attron( COLOR_PAIR(3) );
      move( 15, 50 );
      printw( "%s", "DEVICES" );


      bool quit = false;

      while( quit == false )
         quit = Journeyman_Courses_Handling( curPosY, curPosX, plevel, pchapter, input );

   }



   else if( *plevel == 2  &&  *pchapter == 3 )
   {

      Networking_Courses();
 
      attron( COLOR_PAIR(3) );
      move( 15, 50 );
      printw( "%s", "NETWORK SHARING" );


      bool quit = false;

      while( quit == false )
         quit = Networking_Courses_Handling( curPosY, curPosX, plevel, pchapter, input );

   }

}


void Draw_Button_Background( int posOneY, int posOneX, char buttonOne[], int posTwoY, int posTwoX, char buttonTwo[] )
{

   attron( COLOR_PAIR(2) ); // SETS THE COLOR TO THE DEFAULT ONE
   move( posOneY, posOneX ); // PUTS THE CURSOR ON THE BEGINNING OF THE WORD
   printw( "%s", buttonOne ); // REWRITES THE WORD TO THE DEFAULTS COLOR, SINCE THE USER IS NO LONGER SELECTING THIS BUTTON

   attron( COLOR_PAIR(3) ); // SETS THE COLOR TO THE SPECIAL ONE
   move( posTwoY, posTwoX ); // MOVE TO THE NEWLY SELECTED BUTTON
   printw( "%s", buttonTwo ); // REWRITES IN THE SPECIAL COLOR


   attron( COLOR_PAIR(2) ); // SETS THE COLOR TO THE DEFAULT ONE ONCE AGAIN

}


void Draw_Corner_Lines()
{
   
   attron( COLOR_PAIR(2) ); // SETS THE COLOR TO THE DEFAULT ONE


   // DRAWS THE TOP HORIZONTAL LINE
   for( short i = 1; i < 156; i++ )
   {
      move( 0, i );
      printw( "%c", '-' ); 
   }

   // DRAWS THE LEFT VERTICAL LINE
   for( short i = 1; i < 41; i++ )
   {
      move( i, 0 );
      printw( "%c", '|' );
   }

   // DRAWS THE RIGHT VERTICAL LINE
   for( short i = 1; i < 41; i++ )
   {
      move( i, 156 );
      printw( "%c", '|' );
   }

   // DRAWS THE BOTTOM HORIZONTAL LINE
   for( short i = 1; i < 156; i++ )
   {
      move( 41, i );
      printw( "%c", '-' ); 
   }

}

void Draw_Bottom_Info()
{

   move( 40, 36 );
   printw( "%s", "GO BACK: Z" );

   move( 40, 60 );
   printw( "%s", "MOVEMENT: VIM KEYBINDS (H, J, K, L)" );

   move( 40, 109 );
   printw( "%s", "SELECT: ENTER" );

}
