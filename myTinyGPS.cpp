#include "RPi_GPS.h"
using namespace std;

int main() {

	int maxY, maxX;

	USART_GPS myGPS;

   initscr(); // initialize Ncurses
   getmaxyx( stdscr, maxY, maxX );
   noecho();
   nodelay(stdscr, TRUE);
   curs_set(0);

   //printw("X: %i, Y: %i", maxX, maxY);

   while(getch() != 'q'){

	   // Window Size must be at least X=53, Y=20 for the numbers to fit
	   if(maxX >= 53 && maxY >= 20){

	   	   	if(myGPS.GPS_get() == 1){
	   	   		myGPS.GPSdata_showSpeed(myGPS.get_GndSpdKts(), Kts);
	   	   		myGPS.GPSdata_w_print();
	   	   		refresh();
	   	   		wmove(stdscr, 0, 0);
	   	   	}

	   }else{
		   printw("Window size too small...");
		   refresh();
	   	   wmove(stdscr, 0, 0);
	   }
   }//end while



   endwin();


return 0;
}







