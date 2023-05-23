// THIS SCRIPT PLACE ALL THE BUTTONS ON THEIR PROPER PLACE

#include <ncurses.h>


void Chapters(); // DRAWS THE TITLE SCREEN
void Chapters_Handling( int curPosY, short *plevel, short *pchapter, char input ); // HANDLES BUTTON MOVEMENT ( same applies for all "Handling" funcs )

void Grasshopper_Courses(); // DRAWS THE GRASSHOPPER COURSES
bool Grasshopper_Courses_Handling( int curPosY, int curPosX, short *plevel, short *pchapter, char input );

void Journeyman_Courses(); // DRAWS THE JOURNEYMAN COURSES
bool Journeyman_Courses_Handling( int curPosY, int curPosX, short *plevel, short *pchapter, char input );

void Networking_Courses(); // DRAWS THE NETWORKING COURSES
bool Networking_Courses_Handling( int curPosY, int curPosX, short *plevel, short *pchapter, char input );


void Chapters()
{
    
   move( 5, 73 );
   printw( "%s", "CHAPTERS" );


   move( 15, 71 );
   printw( "%s", "GRASSHOPPER" );

   move( 20, 71 );
   printw( "%s", "JOURNEYMAN" );

   move( 25, 71 );
   printw( "%s", "NETWORKING" );    


   Draw_Bottom_Info();

}

void Chapters_Handling( int curPosY, short *plevel, short *pchapter, char input )
{
    
      if( curPosY == 15  &&  input == 'j' ) // GRASSHOPPER - JOURNEYMAN
         Draw_Button_Background( 15, 71, "GRASSHOPPER", 20, 71, "JOURNEYMAN" );

      else if( curPosY == 20  &&  input == 'j' ) // JOURNEYMAN - NETWORKING
         Draw_Button_Background( 20, 71, "JOURNEYMAN", 25, 71, "NETWORKING" );

      else if( curPosY == 20 && input == 'k' ) // JOURNEYMAN - GRASSHOPPER
         Draw_Button_Background( 20, 71, "JOURNEYMAN", 15, 71, "GRASSHOPPER" );

      else if( curPosY == 25  &&  input == 'k' ) // NETWORKING - JOURNEYMAN
         Draw_Button_Background( 25, 71, "NETWORKING", 20, 71, "JOURNEYMAN" );


      else if( curPosY == 15  &&  input == '\n' ) // USER CLICKS "GRASSHOPPER" BUTTON
      {
         *pchapter = 1;
         *plevel = 2;
      }

      else if( curPosY == 20  &&  input == '\n' ) // USER CLICKS ON "JOURNEYMAN" BUTTON
      {
         *pchapter = 2;
         *plevel = 2;     
      }

      else if( curPosY == 25  &&  input == '\n' ) // USER CLICKS ON "NETWORKING" BUTTON
      {
         *pchapter = 3;
         *plevel = 2;
      }    

}


void Grasshopper_Courses()
{
 
   clear();
   Draw_Corner_Lines();


   move( 5, 73 );
   printw( "%s", "COURSES" );


   move( 15, 50 );
   printw( "%s", "GETTING STARTED" );

   move( 18, 50 );
   printw( "%s", "COMMAND LINE" );

   move( 21, 50 );
   printw( "%s", "TEXT-FU" );   

   move( 24, 50 );
   printw( "%s", "ADVANCED TEXT-FU" );


   move( 15, 94 );
   printw( "%s", "USER MANAGEMENT" );

   move( 18, 94 );
   printw( "%s", "PERMISSIONS" );

   move( 21, 94 );
   printw( "%s", "PROCESSES" );

   move( 24, 94 );
   printw( "%s", "PACKAGES" );   
   
 
   Draw_Bottom_Info();  

}

bool Grasshopper_Courses_Handling( int curPosY, int curPosX, short *plevel, short *pchapter, char input )
{

   input = getch();
   getsyx( curPosY, curPosX );


   if( curPosY == 15  &&  curPosX == 65  &&  input == 'j' ) // GETTING STARTED - COMMAND LINE
      Draw_Button_Background( 15, 50, "GETTING STARTED", 18, 50, "COMMAND LINE" );

   else if( curPosY == 18  &&  curPosX == 62  &&  input == 'k' ) // COMMAND LINE - GETTING STARTED
      Draw_Button_Background( 18, 50, "COMMAND LINE", 15, 50, "GETTING STARTED" );
      
   else if( curPosY == 18  &&  curPosX == 62  &&  input == 'j' ) // COMMAND LINE - TEXT-FU
      Draw_Button_Background( 18, 50, "COMMAND LINE", 21, 50, "TEXT-FU" );

   else if( curPosY == 21  &&  curPosX == 57  &&  input == 'k' ) // TEXT-FU - COMMAND LINE
      Draw_Button_Background( 21, 50, "TEXT-FU", 18, 50, "COMMAND LINE" );

   else if( curPosY == 21  &&  curPosX == 57  &&  input == 'j' ) // TEXT-FU - ADVANCED TEXT-FU
      Draw_Button_Background( 21, 50, "TEXT-FU", 24, 50, "ADVANCED TEXT-FU" );

   else if( curPosY == 24  &&  curPosX == 66  &&  input == 'k' ) // ADVANCED TEXT-FU - TEXT-FU
      Draw_Button_Background( 24, 50, "ADVANCED TEXT-FU", 21, 50, "TEXT-FU" );

   else if( curPosY == 15  &&  curPosX == 65  &&  input == 'l' ) // GETTING STARTED - USER MANAGEMENT
      Draw_Button_Background( 15, 50, "GETTING STARTED", 15, 94, "USER MANAGEMENT" );

   else if( curPosY == 18  &&  curPosX == 62  &&  input == 'l' ) // COMMAND LINE - PERMISSIONS
      Draw_Button_Background( 18, 50, "COMMAND LINE", 18, 94, "PERMISSIONS" );

   else if( curPosY == 21  &&  curPosX == 57  &&  input == 'l' ) // TEXT-FU - PROCESSES
      Draw_Button_Background( 21, 50, "TEXT-FU", 21, 94, "PROCESSES" );

   else if( curPosY == 24  &&  curPosX == 66  &&  input == 'l' ) // ADVANCED TEXT-FU - PACKAGES
      Draw_Button_Background( 24, 50, "ADVANCED TEXT-FU", 24, 94, "PACKAGES" );

   else if( curPosY == 15  &&  curPosX == 109  &&  input == 'j' ) // USER MANAGEMENT - PERMISSIONS
      Draw_Button_Background( 15, 94, "USER MANAGEMENT", 18, 94, "PERMISSIONS" );

   else if( curPosY == 18  &&  curPosX == 105  &&  input == 'k' ) // PERMISSIONS - USER MANAGEMENT
      Draw_Button_Background( 18, 94, "PERMISSIONS", 15, 94, "USER MANAGEMENT" );   

   else if( curPosY == 18  &&  curPosX == 105  &&  input == 'j' ) // PERMISSIONS - PROCESSES
      Draw_Button_Background( 18, 94, "PERMISSIONS", 21, 94, "PROCESSES" );

   else if( curPosY == 21  &&  curPosX == 103  &&  input == 'k' ) // PROCESSES - PERMISSIONS
      Draw_Button_Background( 21, 94, "PROCESSES", 18, 94, "PERMISSIONS" );

   else if( curPosY == 21  &&  curPosX == 103  &&  input == 'j' ) // PROCESSES - PACKAGES
      Draw_Button_Background( 21, 94, "PROCESSES", 24, 94, "PACKAGES" );

   else if( curPosY == 24  &&  curPosX == 102  &&  input == 'k' ) // PACKAGES - PROCESSES
      Draw_Button_Background( 24, 94, "PACKAGES", 21, 94, "PROCESSES" );

   else if( curPosY == 15  &&  curPosX == 109  &&  input == 'h' ) // USER MANAGEMENT - GETTING STARTED
      Draw_Button_Background( 15, 94, "USER MANAGEMENT", 15, 50, "GETTING STARTED" );

   else if( curPosY == 18  &&  curPosX == 105  &&  input == 'h' ) // PERMISSIONS - COMMAND LINE
      Draw_Button_Background( 18, 94, "PERMISSIONS", 18, 50, "COMMAND LINE" );

   else if( curPosY == 21  &&  curPosX == 103  &&  input == 'h' ) // PROCESSES - TEXT-FU
      Draw_Button_Background( 21, 94, "PROCESSES", 21, 50, "TEXT-FU" );

   else if( curPosY == 24  &&  curPosX == 102  &&  input == 'h' ) // PACKAGES - ADVANCED TEXT-FU
      Draw_Button_Background( 24, 94, "PACKAGES", 24, 50, "ADVANCED TEXT-FU" );   
         
         
   else if( input == 'z' ) // GO BACKS
   {
   
      *plevel = 1;
      *pchapter = 0;

      clear();
      Draw_Corner_Lines();
      Chapters();

      move( 15, 71 );
      attron( COLOR_PAIR(3) );
      printw( "%s", "GRASSHOPPER" );


      return true;

   }
 

}


void Journeyman_Courses()
{

   clear();
   Draw_Corner_Lines();


   move( 5, 73 );
   printw( "%s", "COURSES" );


   move( 15, 50 );
   printw( "%s", "DEVICES" );

   move( 18, 50 );
   printw( "%s", "THE FILESYSTEM" );

   move( 21, 50 );
   printw( "%s", "BOOT THE SYSTEM" );


   move( 15, 94 );
   printw( "%s", "KERNEL" );

   move( 18, 94 );
   printw( "%s", "INIT" );

   move( 21, 94 );
   printw( "%s", "PROCESS UTILIZATION" );


   move( 24, 73 );
   printw( "%s", "LOGGING" );


   Draw_Bottom_Info();

}

bool Journeyman_Courses_Handling( int curPosY, int curPosX, short *plevel, short *pchapter, char input )
{

   input = getch();
   getsyx( curPosY, curPosX );


   if( curPosY == 15  &&  curPosX == 57  &&  input == 'j' ) // DEVICES - THE FILESYSTEM
      Draw_Button_Background( 15, 50, "DEVICES", 18, 50, "THE FILESYSTEM");

   else if( curPosY == 18  &&  curPosX == 64  &&  input == 'k' ) // THE FILESYSTEM - DEVICES
      Draw_Button_Background( 18, 50, "THE FILESYSTEM", 15, 50, "DEVICES" );

   else if( curPosY == 18  &&  curPosX == 64  &&  input == 'j' ) // THE FILESYSTEM - BOOT THE SYSTEM
      Draw_Button_Background( 18, 50, "THE FILESYSTEM", 21, 50, "BOOT THE SYSTEM" );

   else if( curPosY == 21  &&  curPosX == 65  &&  input == 'k' ) // BOOT THE SYSTEM - THE FILESYSTEM
      Draw_Button_Background( 21, 50, "BOOT THE SYSTEM", 18, 50, "THE FILESYSTEM" );

   else if( curPosY == 15  &&  curPosX == 57  &&  input == 'l' ) // DEVICES - KERNEL
      Draw_Button_Background( 15, 50, "DEVICES", 15, 94, "KERNEL" );

   else if( curPosY == 18  &&  curPosX == 64  &&  input == 'l' ) // THE FILESYSTEM - INIT
      Draw_Button_Background( 18, 50, "THE FILESYSTEM", 18, 94, "INIT" );

   else if( curPosY == 21  &&  curPosX == 65  &&  input == 'l' ) // BOOT THE SYSTEM - PROCESS UTILIZATION
      Draw_Button_Background( 21, 50, "BOOT THE SYSTEM", 21, 94, "PROCESS UTILIZATION" );

   else if( curPosY == 15  &&  curPosX == 100  &&  input == 'j' ) // KERNEL - INIT
      Draw_Button_Background( 15, 94, "KERNEL", 18, 94, "INIT" );

   else if( curPosY == 18  &&  curPosX == 98  &&  input == 'k' ) // INIT - KERNEL
      Draw_Button_Background( 18, 94, "INIT", 15, 94, "KERNEL" );

   else if( curPosY == 18  &&  curPosX == 98  &&  input == 'j' ) // INIT - PROCESS UTILIZATOIN
      Draw_Button_Background( 18, 94, "INIT", 21, 94, "PROCESS UTILIZATION" );

   else if( curPosY == 21  &&  curPosX == 113  &&  input == 'k' ) // PROCESS UTILIZATION - INIT
      Draw_Button_Background( 21, 94, "PROCESS UTILIZATION", 18, 94, "INIT" );

   else if( curPosY == 15  &&  curPosX == 100  &&  input == 'h' ) // KERNEL - DEVICES
      Draw_Button_Background( 15, 94, "KERNEL", 15, 50, "DEVICES" );

   else if( curPosY == 18  &&  curPosX == 98  &&  input == 'h' ) // INIT - THE FILESYSTEM
      Draw_Button_Background( 18, 94, "INIT", 18, 50, "THE FILESYSTEM" );

   else if( curPosY == 21  &&  curPosX == 113  &&  input == 'h' ) // PROCESS UTILIZATION - BOOT THE SYSTEM
      Draw_Button_Background( 21, 94, "PROCESS UTILIZATION", 21, 50, "BOOT THE SYSTEM" );

   else if( curPosY == 21  &&  curPosX == 65  &&  input == 'j' ) // BOOT THE SYSTEM - LOGGING
      Draw_Button_Background( 21, 50, "BOOT THE SYSTEM", 24, 73, "LOGGING" );

   else if( curPosY == 21  &&  curPosX == 113  &&  input == 'j' ) // PROCESS UTILIZATION - LOGGING
      Draw_Button_Background( 21, 94, "PROCESS UTILIZATION", 24, 73, "LOGGING" );

   else if( curPosY == 24  &&  input == 'h' ) // LOGGING - BOOT THE SYSTEM
      Draw_Button_Background( 24, 73, "LOGGING", 21, 50, "BOOT THE SYSTEM" );   
   
   else if( curPosY == 24  &&  input == 'l' ) // LOGGING - BOOT THE SYSTEM
      Draw_Button_Background( 24, 73, "LOGGING", 21, 94, "PROCESS UTILIZATION" );      
   
   
   else if( input == 'z' ) // GO BACKS
   {
   
      *plevel = 1;
      *pchapter = 0;

      clear();
      Draw_Corner_Lines();
      Chapters();

      move( 15, 71 );
      attron( COLOR_PAIR(3) );
      printw( "%s", "GRASSHOPPER" );


      return true;

   }
 

}


void Networking_Courses()
{

   clear();
   Draw_Corner_Lines();


   move( 5, 73 );
   printw( "%s", "COURSES" );


   move( 15, 50 );
   printw( "%s", "NETWORK SHARING" );

   move( 18, 50 );
   printw( "%s", "NETWORK BASICS" );

   move( 21, 50 );
   printw( "%s", "SUBNETTING" );


   move( 15, 94 );
   printw( "%s", "ROUTING" );

   move( 18, 94 );
   printw( "%s", "NETWORK CONFIG" );

   move( 21, 94 );
   printw( "%s", "TROUBLESHOOTING" );

   
   move( 24, 75 );
   printw( "%s", "DNS" );


   Draw_Bottom_Info();

}

bool Networking_Courses_Handling( int curPosY, int curPosX, short *plevel, short *pchapter, char input )
{

   input = getch();
   getsyx( curPosY, curPosX );

 
   if( curPosY == 15  &&  curPosX == 65  &&  input == 'j' ) // NETWORK SHARING - NETWORK BASICS
      Draw_Button_Background( 15, 50, "NETWORK SHARING", 18, 50, "NETWORK BASICS" );

   else if( curPosY == 18  &&  curPosX == 64  &&  input == 'k' ) // NETWORK BASICS - NETWORK SHARING
      Draw_Button_Background( 18, 50, "NETWORK BASICS", 15, 50, "NETWORK SHARING" );

   else if( curPosY == 18  &&  curPosX == 64  &&  input == 'j' ) // NETWORK BASICS - SUBNETTING
      Draw_Button_Background( 18, 50, "NETWORK BASICS", 21, 50, "SUBNETTING" );

   else if( curPosY == 21  &&  curPosX == 60  &&  input == 'k' ) // SUBNETTING - NETWORK BASICS
      Draw_Button_Background( 21, 50, "SUBNETTING", 18, 50, "NETWORK BASICS" );

   else if( curPosY == 15  &&  curPosX == 65  &&  input == 'l' ) // NETWORK SHARING - ROUTING
      Draw_Button_Background( 15, 50, "NETWORK SHARING", 15, 94, "ROUTING" );

   else if( curPosY == 18  &&  curPosX == 64  &&  input == 'l' ) // NETWORK BASICS - NETWORK CONFIG
      Draw_Button_Background( 18, 50, "NETWORK BASICS", 18, 94, "NETWORK CONFIG" );

   else if( curPosY == 21  &&  curPosX == 60  &&  input == 'l' ) // SUBNETTING - TROUBLESHOOTING
      Draw_Button_Background( 21, 50, "SUBNETTING", 21, 94, "TROUBLESHOOTING" );

   else if( curPosY == 15  &&  curPosX == 101  &&  input == 'h' ) // ROUTING - NETWORK SHARING
      Draw_Button_Background( 15, 94, "ROUTING", 15, 50, "NETWORK SHARING" );

   else if( curPosY == 18  &&  curPosX == 108  &&  input == 'h' ) // NETWORK CONFIG - NETWORK BASICS
      Draw_Button_Background( 18, 94, "NETWORK CONFIG", 18, 50, "NETWORK BASICS" );

   else if( curPosY == 21  &&  curPosX == 109  &&  input == 'h' ) // TROUBLESHOOTING - SUBNETTING
      Draw_Button_Background( 21, 94, "TROUBLESHOOTING", 21, 50, "SUBNETTING" );

   else if( curPosY == 15  &&  curPosX == 101  &&  input == 'j' ) // ROUTING - NETWORK CONFIG
      Draw_Button_Background( 15, 94, "ROUTING", 18, 94, "NETWORK CONFIG" );

   else if( curPosY == 18  &&  curPosX == 108  &&  input == 'k' ) // NETWORK CONFIG - ROUTING
      Draw_Button_Background( 18, 94, "NETWORK CONFIG", 15, 94, "ROUTING" );

   else if( curPosY == 18  &&  curPosX == 108  &&  input == 'j' ) // NETWORK CONFIG - TROUBLESHOOTING
      Draw_Button_Background( 18, 94, "NETWORK CONFIG", 21, 94, "TROUBLESHOOTING" );

   else if( curPosY == 21  &&  curPosX == 109  &&  input == 'k' ) // TROUBLESHOOTING - NETWORK CONFIG
      Draw_Button_Background( 21, 94, "TROUBLESHOOTING", 18, 94, "NETWORK CONFIG" );

   else if( curPosY == 21  &&  curPosX == 60  &&  input == 'j' ) // SUBNETTING - DNS
      Draw_Button_Background( 21, 50, "SUBNETTING", 24, 75, "DNS" );

   else if( curPosY == 21  &&  curPosX == 109  &&  input == 'j' ) // TROUBLESHOOTING - DNS
      Draw_Button_Background( 21, 94, "TROUBLESHOOTING", 24, 75, "DNS" );

   else if( curPosY == 24  &&  input == 'h' ) // DNS - SUBNETTING
      Draw_Button_Background( 24, 75, "DNS", 21, 50, "SUBNETTING" );

   else if( curPosY == 24  &&  input == 'l' ) // DNS - TROUBLESHOOTING
      Draw_Button_Background( 24, 75, "DNS", 21, 94, "TROUBLESHOOTING" );

   
   else if( input == 'z' ) // GO BACKS
   {
   
      *plevel = 1;
      *pchapter = 0;

      clear();
      Draw_Corner_Lines();
      Chapters();

      move( 15, 71 );
      attron( COLOR_PAIR(3) );
      printw( "%s", "GRASSHOPPER" );


      return true;

   }
      

}
