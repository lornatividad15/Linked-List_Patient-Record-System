#include <windows.h>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

/*Note: For better viewing do not maximize the console. Use Dev C++*/

// MOVE CURSOR POSITION
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
// SET TEXT COLOR
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    //0-black 1-blue 2-green 3-aqua/cyan 4-red 5-purple 6-yellow 7-white
    //8-gray 9-ligth blue 10-light green 11-light cyan 12-light red 
    //13-pink/magenta 14-light yellow 15-bright white
}
// HORIZONTAL SOLID BAR
void solidBar(){
	setColor(3);
	int length = 120;
	for(int i=0; i<length; i++){
		cout<<(char)219;
	}
}
// DRAW OUTER BOX
void drawBox(int x1, int y1, int x2, int y2) {
	setColor(15); 
    for (int y = y1; y <= y2; y++) {
        gotoxy(x1, y);
        for (int x = x1; x <= x2; x++) {
            cout << (char)219;
        }
    }
    setColor(7);
}
// DRAW RED CROSS
void drawRedCross(int x, int y) {
    setColor(4); 
    gotoxy(x + 8, y + 1); int alen=8; for(int i=0; i<alen; i++){cout<<(char)219;}
    gotoxy(x + 8, y + 2); int blen=8; for(int i=0; i<blen; i++){cout<<(char)219;}
    gotoxy(x + 8, y + 3); int clen=8; for(int i=0; i<clen; i++){cout<<(char)219;}
    gotoxy(x, y + 4); int dlen=24; for(int i=0; i<dlen; i++){cout<<(char)219;}
    gotoxy(x, y + 5); int elen=24; for(int i=0; i<elen; i++){cout<<(char)219;}
    gotoxy(x, y + 6); int flen=24; for(int i=0; i<flen; i++){cout<<(char)219;}
    gotoxy(x, y + 7); int glen=24; for(int i=0; i<glen; i++){cout<<(char)219;}
    gotoxy(x + 8, y + 8); int hlen=8; for(int i=0; i<hlen; i++){cout<<(char)219;}
    gotoxy(x + 8, y + 9); int ilen=8; for(int i=0; i<ilen; i++){cout<<(char)219;}
    gotoxy(x + 8, y + 10); int jlen=8; for(int i=0; i<jlen; i++){cout<<(char)219;}
    setColor(7); 
}
// LABEL CARETRACK WITHIN BAR
void mediBar(){
	setColor(15);
   	//C +11
	gotoxy(11,5); cout << "  " << string(6,(char)219) << "  ";
	gotoxy(11,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(11,7); cout << string(2,(char)219) << "        ";
	gotoxy(11,8); cout << string(2,(char)219) << "        ";
	gotoxy(11,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(11,10); cout << "  " << string(6,(char)219) << "  ";
	//A +11
	gotoxy(22,5); cout << "  " << string(6,(char)219) << "  ";
	gotoxy(22,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(22,7); cout << string(2,(char)219) << "      " << string(2,(char)219); 
	gotoxy(22,8); cout << string(10,(char)219); 
	gotoxy(22,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(22,10); cout << string(2,(char)219) << "      " << string(2,(char)219);
	//R +11
    gotoxy(33,5); cout << string(8,(char)219);
    gotoxy(33,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(33,7); cout << string(8,(char)219) << "  ";
    gotoxy(33,8); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(33,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(33,10); cout << string(2,(char)219) << "      " << string(2,(char)219);
    //E +11
   	gotoxy(44,5); cout << string(10,(char)219);
    gotoxy(44,6); cout << string(2,(char)219) << "        ";
    gotoxy(44,7); cout << string(7,(char)219); 
    gotoxy(44,8); cout << string(2,(char)219) << "        "; 
    gotoxy(44,9); cout << string(2,(char)219) << "        ";
    gotoxy(44,10); cout << string(10,(char)219);
    //T +11
	gotoxy(55, 5); cout << string(10,(char)219);
	gotoxy(55, 6); cout << "    " << string(2,(char)219) << "    ";
	gotoxy(55, 7); setColor(3); cout << string(4,(char)219); setColor(15); cout << string(2,(char)219); setColor(3); cout << string(4,(char)219); setColor(15);
	gotoxy(55, 8); cout << "    " << string(2,(char)219) << "    "; 
	gotoxy(55, 9); cout << "    " << string(2,(char)219) << "    "; 
	gotoxy(55, 10); cout << "    " << string(2,(char)219) << "    ";
	//R +11
	gotoxy(66, 5); cout << string(8,(char)219);
	gotoxy(66, 6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(66, 7); cout << string(8,(char)219) << "  ";
	gotoxy(66, 8); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(66, 9); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(66, 10); cout << string(2,(char)219) << "      " << string(2,(char)219);
	//A +11
	gotoxy(77,5); cout << "  " << string(6,(char)219) << "  ";
	gotoxy(77,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(77,7); cout << string(2,(char)219) << "      " << string(2,(char)219);  
	gotoxy(77,8); cout << string(10,(char)219);
	gotoxy(77,9); cout << string(2,(char)219) << "      " << string(2,(char)219); 
	gotoxy(77,10); cout << string(2,(char)219) << "      " << string(2,(char)219); 
	//C +11
	gotoxy(88, 5); cout << "  " << string(6,(char)219) << "  ";
	gotoxy(88, 6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(88, 7); cout << string(2,(char)219) << "        ";
	gotoxy(88, 8); cout << string(2,(char)219) << "        ";
	gotoxy(88, 9); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(88, 10); cout << "  " << string(6,(char)219) << "  ";
	//K +11
	gotoxy(99,5); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(99,6); cout << string(2,(char)219) << "   " << string(3,(char)219) << "  ";
	gotoxy(99,7); setColor(15); cout << string(5,(char)219); setColor(3); cout << string(5,(char)219); setColor(15);
	gotoxy(99,8); cout << string(2,(char)219) << "   " << string(3,(char)219) << "  ";
	gotoxy(99,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(99,10); cout << string(2,(char)219) << "      " << string(2,(char)219);
}
// LABEL CARETRACK
void medi(){
	setColor(15);
   	//C +11
	gotoxy(11,5); cout << "  " << string(6,(char)219) << "  ";
	gotoxy(11,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(11,7); cout << string(2,(char)219) << "        ";
	gotoxy(11,8); cout << string(2,(char)219) << "        ";
	gotoxy(11,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(11,10); cout << "  " << string(6,(char)219) << "  ";
	//A +11
	gotoxy(22,5); cout << "  " << string(6,(char)219) << "  ";
	gotoxy(22,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(22,7); cout << string(2,(char)219) << "      " << string(2,(char)219); 
	gotoxy(22,8); cout << string(10,(char)219); 
	gotoxy(22,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(22,10); cout << string(2,(char)219) << "      " << string(2,(char)219);
	//R +11
    gotoxy(33,5); cout << string(8,(char)219);
    gotoxy(33,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(33,7); cout << string(8,(char)219) << "  ";
    gotoxy(33,8); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(33,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(33,10); cout << string(2,(char)219) << "      " << string(2,(char)219);
    //E +11
   	gotoxy(44,5); cout << string(10,(char)219);
    gotoxy(44,6); cout << string(2,(char)219) << "        ";
    gotoxy(44,7); cout << string(7,(char)219); 
    gotoxy(44,8); cout << string(2,(char)219) << "        "; 
    gotoxy(44,9); cout << string(2,(char)219) << "        ";
    gotoxy(44,10); cout << string(10,(char)219);
    //T +11
	gotoxy(55, 5); cout << string(10,(char)219);
	gotoxy(55, 6); cout << "    " << string(2,(char)219) << "    ";
	gotoxy(55, 7); cout << "    " << string(2,(char)219) << "    ";
	gotoxy(55, 8); cout << "    " << string(2,(char)219) << "    "; 
	gotoxy(55, 9); cout << "    " << string(2,(char)219) << "    "; 
	gotoxy(55, 10); cout << "    " << string(2,(char)219) << "    ";
	//R +11
	gotoxy(66, 5); cout << string(8,(char)219);
	gotoxy(66, 6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(66, 7); cout << string(8,(char)219) << "  ";
	gotoxy(66, 8); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(66, 9); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(66, 10); cout << string(2,(char)219) << "      " << string(2,(char)219);
	//A +11
	gotoxy(77,5); cout << "  " << string(6,(char)219) << "  ";
	gotoxy(77,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(77,7); cout << string(2,(char)219) << "      " << string(2,(char)219);  
	gotoxy(77,8); cout << string(10,(char)219);
	gotoxy(77,9); cout << string(2,(char)219) << "      " << string(2,(char)219); 
	gotoxy(77,10); cout << string(2,(char)219) << "      " << string(2,(char)219); 
	//C +11
	gotoxy(88, 5); cout << "  " << string(6,(char)219) << "  ";
	gotoxy(88, 6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(88, 7); cout << string(2,(char)219) << "        ";
	gotoxy(88, 8); cout << string(2,(char)219) << "        ";
	gotoxy(88, 9); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(88, 10); cout << "  " << string(6,(char)219) << "  ";
	//K +11
	gotoxy(99,5); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(99,6); cout << string(2,(char)219) << "   " << string(3,(char)219) << "  ";
	gotoxy(99,7); cout << string(5,(char)219);
	gotoxy(99,8); cout << string(2,(char)219) << "   " << string(3,(char)219) << "  ";
	gotoxy(99,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(99,10); cout << string(2,(char)219) << "      " << string(2,(char)219);
}
// LABEL ADMIN
void ad(){
	setColor(15);
   	//A +11
   	gotoxy(33,5); cout << "  " << string(6,(char)219) << "  ";
   	gotoxy(33,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
  	gotoxy(33,7); cout << string(2,(char)219) << "      " << string(2,(char)219); 
    gotoxy(33,8); cout << string(10,(char)219);         
    gotoxy(33,9); cout << string(2,(char)219) << "      " << string(2,(char)219);    
	gotoxy(33,10); cout << string(2,(char)219) << "      " << string(2,(char)219);   
    //D +11
    gotoxy(44,5); cout << string(8,(char)219) << "  ";
    gotoxy(44,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(44,7); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(44,8); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(44,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(44,10); cout << string(8,(char)219) << "  ";
	//M +11
	gotoxy(55,5); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(55,6); cout << string(4,(char)219) << "  " << string(4,(char)219);
	gotoxy(55,7); cout << string(2,(char)219) << "  " << string(2,(char)219) << "  " << string(2,(char)219);
	gotoxy(55,8); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(55,9); cout << string(2,(char)219)<< "      " << string(2,(char)219);
	gotoxy(55,10); cout << string(2,(char)219)<< "      " << string(2,(char)219);
    //I +11
   	gotoxy(66,5); cout << string(10,(char)219);
    gotoxy(66,6); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(66,7); cout << "    " << string(2,(char)219) << "    ";
    gotoxy(66,8); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(66,9); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(66,10); cout << string(10,(char)219);
    //N +11
    gotoxy(77,5); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(77,6); cout << string(5,(char)219) << "   " << string(2,(char)219); 
    gotoxy(77,7); cout << string(2,(char)219) << "   " << string(5,(char)219);
    gotoxy(77,8); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(77,9); cout << string(2,(char)219) << "      " << string(2,(char)219);	
    gotoxy(77,10); cout << string(2,(char)219) << "      " << string(2,(char)219);	
}
// LABEL WELCOME
void wel(){
	setColor(15);
	//W +11
	gotoxy(22,5); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(22,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(22,7); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(22,8); cout << string(2,(char)219) << "  " << string(2,(char)219) << "  " << string(2,(char)219);
	gotoxy(22,9); cout << string(2,(char)219) << "  " << string(2,(char)219) << "  " << string(2,(char)219);
	gotoxy(22,10); cout << "  " << string(2,(char)219) << "  " << string(2,(char)219) << "  ";
	//E +11
	gotoxy(33,5); cout << string(10,(char)219);
	gotoxy(33,6); cout << string(2,(char)219) << "        ";
	gotoxy(33,7); cout << string(7,(char)219);
	gotoxy(33,8); cout << string(2,(char)219) << "        ";
	gotoxy(33,9); cout << string(2,(char)219) << "        ";
	gotoxy(33,10); cout << string(10,(char)219);
	//L +11
	gotoxy(44,5); cout << string(2,(char)219) << "        ";
	gotoxy(44,6); cout << string(2,(char)219) << "        ";
	gotoxy(44,7); cout << string(2,(char)219);
	gotoxy(44,8); cout << string(2,(char)219) << "        ";
	gotoxy(44,9); cout << string(2,(char)219) << "        ";
	gotoxy(44,10); cout << string(10,(char)219);
	//C +11
	gotoxy(55,5); cout << "  " << string(6,(char)219) << "  ";
	gotoxy(55,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(55,7); cout << string(2,(char)219) << "        ";
	gotoxy(55,8); cout << string(2,(char)219) << "        ";
	gotoxy(55,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(55,10); cout << "  " << string(6,(char)219) << "  ";
	//O +11
	gotoxy(66,5); cout << "  " << string(6,(char)219) << "  ";
	gotoxy(66,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(66,7); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(66,8); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(66,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(66,10); cout << "  " << string(6,(char)219) << "  ";
	//M +11
	gotoxy(77,5); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(77,6); cout << string(4,(char)219) << "  " << string(4,(char)219);
	gotoxy(77,7); cout << string(2,(char)219) << "  " << string(2,(char)219) << "  " << string(2,(char)219);
	gotoxy(77,8); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(77,9); cout << string(2,(char)219)<< "      " << string(2,(char)219);
	gotoxy(77,10); cout << string(2,(char)219)<< "      " << string(2,(char)219);
	//E +11
	gotoxy(88,5); cout << string(10,(char)219);
	gotoxy(88,6); cout << string(2,(char)219) << "        ";
	gotoxy(88,7); cout << string(7,(char)219);
	gotoxy(88,8); cout << string(2,(char)219) << "        ";
	gotoxy(88,9); cout << string(2,(char)219) << "        ";
	gotoxy(88,10); cout << string(10,(char)219);
}
// LABEL MENU
void menu(){
	setColor(15);
	//M +11
	gotoxy(38,5); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(38,6); cout << string(4,(char)219) << "  " << string(4,(char)219);
	gotoxy(38,7); cout << string(2,(char)219) << "  " << string(2,(char)219) << "  " << string(2,(char)219);
	gotoxy(38,8); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(38,9); cout << string(2,(char)219)<< "      " << string(2,(char)219);
	gotoxy(38,10); cout << string(2,(char)219)<< "      " << string(2,(char)219);
    //E +11
	gotoxy(49,5); cout << string(10,(char)219);
	gotoxy(49,6); cout << string(2,(char)219) << "        ";
	gotoxy(49,7); cout << string(7,(char)219);  
	gotoxy(49,8); cout << string(2,(char)219) << "        ";
	gotoxy(49,9); cout << string(2,(char)219) << "        ";
	gotoxy(49,10); cout << string(10,(char)219);
	//N +11
    gotoxy(60,5); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(60,6); cout << string(5,(char)219) << "   " << string(2,(char)219); 
    gotoxy(60,7); cout << string(2,(char)219) << "   " << string(5,(char)219);
    gotoxy(60,8); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(60,9); cout << string(2,(char)219) << "      " << string(2,(char)219);	
    gotoxy(60,10); cout << string(2,(char)219) << "      " << string(2,(char)219);
    //U +11
	gotoxy(71, 5); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(71, 6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(71, 7); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(71, 8); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(71, 9); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(71, 10); cout << "  " << string(6,(char)219) << "  ";
}
// LABEL EDIT
void edit(){
	setColor(15);
	//E +11
	gotoxy(38,5); cout << string(10,(char)219);
	gotoxy(38,6); cout << string(2,(char)219) << "        ";
	gotoxy(38,7); cout << string(7,(char)219);  
	gotoxy(38,8); cout << string(2,(char)219) << "        ";
	gotoxy(38,9); cout << string(2,(char)219) << "        ";
	gotoxy(38,10); cout << string(10,(char)219);
	//D +11
    gotoxy(49,5); cout << string(8,(char)219) << "  ";
    gotoxy(49,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(49,7); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(49,8); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(49,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(49,10); cout << string(8,(char)219) << "  ";
 	//I +11
   	gotoxy(60,5); cout << string(10,(char)219);
    gotoxy(60,6); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(60,7); cout << "    " << string(2,(char)219) << "    ";
    gotoxy(60,8); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(60,9); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(60,10); cout << string(10,(char)219);
    //T +11
   	gotoxy(71,5); cout << string(10,(char)219);
    gotoxy(71,6); cout << "    " << string(2,(char)219) << "    ";  
    gotoxy(71,7); cout << "    " << string(2,(char)219) << "    ";  
    gotoxy(71,8); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(71,9); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(71,10); cout << "    " << string(2,(char)219) << "    "; 
}
// LABEL ADD
void add(){
	setColor(15);
	//A +11
   	gotoxy(44,5); cout << "  " << string(6,(char)219) << "  ";
   	gotoxy(44,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
  	gotoxy(44,7); cout << string(2,(char)219) << "      " << string(2,(char)219); 
    gotoxy(44,8); cout << string(10,(char)219);         
    gotoxy(44,9); cout << string(2,(char)219) << "      " << string(2,(char)219);    
	gotoxy(44,10); cout << string(2,(char)219) << "      " << string(2,(char)219); 
   	//D +11
    gotoxy(55,5); cout << string(8,(char)219) << "  ";
    gotoxy(55,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(55,7); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(55,8); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(55,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(55,10); cout << string(8,(char)219) << "  ";
    //D +11
    gotoxy(66,5); cout << string(8,(char)219) << "  ";
    gotoxy(66,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(66,7); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(66,8); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(66,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(66,10); cout << string(8,(char)219) << "  ";
}
// LABEL VIEW
void viewLabel(){
	setColor(15);
	//V +11
	gotoxy(38, 5); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(38, 6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(38, 7); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(38, 8); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(38, 9); cout << "  " << string(2,(char)219) << "  " << string(2,(char)219) << "  " ;
	gotoxy(38, 10); cout << "    " << string(2,(char)219) << "    ";
	//I +11
   	gotoxy(49,5); cout << string(10,(char)219);
    gotoxy(49,6); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(49,7); cout << "    " << string(2,(char)219) << "    ";
    gotoxy(49,8); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(49,9); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(49,10); cout << string(10,(char)219);
   	//E +11
	gotoxy(60,5); cout << string(10,(char)219);
	gotoxy(60,6); cout << string(2,(char)219) << "        ";
	gotoxy(60,7); cout << string(7,(char)219);  
	gotoxy(60,8); cout << string(2,(char)219) << "        ";
	gotoxy(60,9); cout << string(2,(char)219) << "        ";
	gotoxy(60,10); cout << string(10,(char)219);
	//W +11
	gotoxy(71,5); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(71,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(71,7); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(71,8); cout << string(2,(char)219) << "  " << string(2,(char)219) << "  " << string(2,(char)219);
	gotoxy(71,9); cout << string(2,(char)219) << "  " << string(2,(char)219) << "  " << string(2,(char)219);
	gotoxy(71,10); cout << "  " << string(2,(char)219) << "  " << string(2,(char)219) << "  ";
}
// LABEL UPDATE
void upd(){
	setColor(15);
	//U +11
	gotoxy(27, 5); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(27, 6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(27, 7); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(27, 8); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(27, 9); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(27, 10); cout << "  " << string(6,(char)219) << "  ";
	//P +11
    gotoxy(38,5); cout << string(10,(char)219);
	gotoxy(38,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
	gotoxy(38,7); cout << string(10,(char)219);
	gotoxy(38,8); cout << string(2,(char)219);
   	gotoxy(38,9); cout << string(2,(char)219);
   	gotoxy(38,10); cout << string(2,(char)219);
	//D +11
    gotoxy(49,5); cout << string(8,(char)219) << "  ";
    gotoxy(49,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(49,7); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(49,8); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(49,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(49,10); cout << string(8,(char)219) << "  ";
	//A +11
   	gotoxy(60,5); cout << "  " << string(6,(char)219) << "  ";
   	gotoxy(60,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
  	gotoxy(60,7); cout << string(2,(char)219) << "      " << string(2,(char)219); 
    gotoxy(60,8); cout << string(10,(char)219);         
    gotoxy(60,9); cout << string(2,(char)219) << "      " << string(2,(char)219);    
	gotoxy(60,10); cout << string(2,(char)219) << "      " << string(2,(char)219);
	//T +11
   	gotoxy(71,5); cout << string(10,(char)219);
    gotoxy(71,6); cout << "    " << string(2,(char)219) << "    ";  
    gotoxy(71,7); cout << "    " << string(2,(char)219) << "    ";  
    gotoxy(71,8); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(71,9); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(71,10); cout << "    " << string(2,(char)219) << "    "; 
	//E +11
	gotoxy(82,5); cout << string(10,(char)219);
	gotoxy(82,6); cout << string(2,(char)219) << "        ";
	gotoxy(82,7); cout << string(7,(char)219);  
	gotoxy(82,8); cout << string(2,(char)219) << "        ";
	gotoxy(82,9); cout << string(2,(char)219) << "        ";
	gotoxy(82,10); cout << string(10,(char)219);
}
// LABEL DELETE
void delLabel(){
	setColor(15);
	//D +11
    gotoxy(27,5); cout << string(8,(char)219) << "  ";
    gotoxy(27,6); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(27,7); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(27,8); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(27,9); cout << string(2,(char)219) << "      " << string(2,(char)219);
    gotoxy(27,10); cout << string(8,(char)219) << "  ";
	//E +11
	gotoxy(38,5); cout << string(10,(char)219);
	gotoxy(38,6); cout << string(2,(char)219) << "        ";
	gotoxy(38,7); cout << string(7,(char)219);  
	gotoxy(38,8); cout << string(2,(char)219) << "        ";
	gotoxy(38,9); cout << string(2,(char)219) << "        ";
	gotoxy(38,10); cout << string(10,(char)219);
	//L +11
	gotoxy(49,5); cout << string(2,(char)219) << "        ";
	gotoxy(49,6); cout << string(2,(char)219) << "        ";
	gotoxy(49,7); cout << string(2,(char)219);
	gotoxy(49,8); cout << string(2,(char)219) << "        ";
	gotoxy(49,9); cout << string(2,(char)219) << "        ";
	gotoxy(49,10); cout << string(10,(char)219);
	//E +11
	gotoxy(60,5); cout << string(10,(char)219);
	gotoxy(60,6); cout << string(2,(char)219) << "        ";
	gotoxy(60,7); cout << string(7,(char)219);  
	gotoxy(60,8); cout << string(2,(char)219) << "        ";
	gotoxy(60,9); cout << string(2,(char)219) << "        ";
	gotoxy(60,10); cout << string(10,(char)219);
	//T +11
   	gotoxy(71,5); cout << string(10,(char)219);
    gotoxy(71,6); cout << "    " << string(2,(char)219) << "    ";  
    gotoxy(71,7); cout << "    " << string(2,(char)219) << "    ";  
    gotoxy(71,8); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(71,9); cout << "    " << string(2,(char)219) << "    "; 
    gotoxy(71,10); cout << "    " << string(2,(char)219) << "    "; 
	//E +11
	gotoxy(82,5); cout << string(10,(char)219);
	gotoxy(82,6); cout << string(2,(char)219) << "        ";
	gotoxy(82,7); cout << string(7,(char)219);  
	gotoxy(82,8); cout << string(2,(char)219) << "        ";
	gotoxy(82,9); cout << string(2,(char)219) << "        ";
	gotoxy(82,10); cout << string(10,(char)219);
}
// FUNCTION DECLARATION
void saveAdmin(), loadAdmin(), viewLogin(), login(), welcomePage(), adminScreen(), adminMenu(), addPatient(), viewPatient(), updatePatient(),
delPatient(), loadPatient(), savePatient(), displayFormatID(int number), searchPatientByField(), selectionSortStringField(int field), 
bubbleSortNumericField(int field), displayPatientList();

// PROTOTYPE FOR findPatientByID
struct PatientNode* findPatientByID(int searchID);

// LINKED LIST NODE FOR PATIENT
struct PatientNode {
    int id;
    char name[100];
    int age;
    char gender[10];
    char arrivalTime[25];
    char symptoms[100];
    int priority;
    PatientNode* next;
};

PatientNode* head = NULL;
int patientCount = 0, receiptCount = 0, capacity = 1000;

// ADMIN CREDENTIALS: admin[0] = USERNAME, admin[1] = PASSWORD
char admin[2][100];

// PATIENT ARRAYS FOR ARRAY-BASED SORTING (CAPACITY = 1000)
int id[1000], age[1000], priority[1000];
char name[1000][100], gender[1000][10], arrivalTime[1000][25], symptoms[1000][100];

// MAIN SCREEN
int main() {
	system("cls");
	while(1){
		setColor(7);
    	gotoxy(0,4); cout<<"<< EXIT";
    	gotoxy(112,4); cout<<"ENTER >>";
	
		gotoxy(0,7); solidBar();
		
		//LABEL CARETRACK WITH BAR
		mediBar();
    
    	setColor(7); 
    	int x1 = 43; //POSITION X
    	int y1 = 12; //POSITION Y
    	int x2 = x1 + 35; //NUMBER OF -
    	int y2 = y1 + 15; //NUMER OF |
	    drawBox(x1, y1, x2, y2);
    
   		// DRAW CROSS CENTERED INSIDE THE BOX
    	drawRedCross(x1 + 6, y1 + 2); // ADJUSTED POSITION FOR CENTER
    	
    	gotoxy(0, 29); cout<<"\n"; solidBar();
    
    	setColor(15);
    	string choice;
    	cout<<"\n\nEnter command(<< or >>): ";
    	cin>>choice;
    	cin.ignore();
    	if(choice == "<<"){
    		setColor(2);
    		cout<<"\nExiting...\n\n";
    		setColor(7);
    		exit(0);
		}
		else if(choice == ">>"){
			viewLogin();
		}
		else{
			setColor(12);
			cout<<"\nInvalid Command! ";
			cout<<" Please try again. \nPress [Enter] to proceed....";
			setColor(0); system("pause");
			system("cls");
			setColor(7);
		}
	}
}
// SAVE ADMIN USER AND PASS TO admin.txt FILE
void saveAdmin(){
	ofstream file("admin.txt");
	file << admin[0] << endl;
	file << admin[1] << endl;
	file.close();
}
// LOAD ADMIN USER AND PASS FROM admin.txt FILE
void loadAdmin(){
	ifstream file("admin.txt");
	if(file.is_open()){
		file.getline(admin[0],100);
		file.getline(admin[1],100);
		file.close();
	}else{
		strcpy(admin[0],"admin");
		strcpy(admin[1],"admin123");
		saveAdmin();
	}
}
// VIEW OR LOGIN PAGE
void viewLogin(){
	system("cls");
	while(1){
		//LABEL CARETRACK
    	medi();
	
		gotoxy(0, 12); solidBar();
	
		setColor(15);
		int y=15;
		gotoxy(30,y);
		char opt[3][100] = {"[1] View All Record/s", "[2] Login Admin", "[0] Exit"};
		int n = sizeof(opt)/sizeof(opt[0]);
		for(int i=0; i<n; i++){
			gotoxy(30, y + i);
			cout<<opt[i]<<endl;
		}
	
		gotoxy(30, y + n + 2);
		char choice;
		cout<<"Enter Option: ";
		cin>>choice;
		cin.ignore();
		if(choice == '1'){
			loadPatient();
			viewPatient();
		}
		else if(choice == '2'){
			login();
		}
		else if(choice == '0'){
			main();
		}	
		else{
			setColor(12);
			cout<<"\nInvalid Option! ";
			cout<<" Please try again. \nPress [Enter] to proceed....";
			setColor(0); system("pause");
			system("cls");
			setColor(7);
		}
	}
}
// LOGIN PAGE
void login(){
	system("cls");
	int attempts = 0;
 	while(attempts < 3){
 		//LABEL ADMIN
		ad();
    	
    	gotoxy(0, 12); solidBar();
    	
    	setColor(7);
    	char tuser[100], tpass[100];
    	loadAdmin();
   		gotoxy(30,15);
   		cout<<"Enter Username: ";
    	cin>>tuser;
    	gotoxy(30,16);
    	cout<<"Enter Password: ";
    	cin>>tpass;
    	
    	if(strcmp(admin[0], tuser)==0 && strcmp(admin[1], tpass)==0){	
    		welcomePage();
    		return;
		}
		else{
			attempts++;
			setColor(12);
			cout<<"\nAccess Denied. You have " << (3 - attempts) << " attempt(s) left. ";
			if(attempts < 3){
				cout<<" Please try again. \nPress [Enter] to proceed....";
				setColor(0); system("pause");
				setColor(7); system("cls");
			}
			else{
				setColor(12);
				cout<<"\nYou have exceeded the maximum number of attempts. \nPress [Enter] to proceed to main screen...";
				setColor(0); system("pause");
				setColor(7); system("cls");
			}
		}
	}
}
// WELCOME PAGE
void welcomePage(){
	system("cls");
	gotoxy(0,7); solidBar();
	
	//LABEL WELCOME
	wel();

    int x1 = 43; //POSITION X
    int y1 = 12; //POSITION Y
    int x2 = x1 + 35; //NUMBER OF -
    int y2 = y1 + 15; //NUMER OF |
    drawBox(x1, y1, x2, y2);
    
    // DRAW CROSS CENTERED INSIDE THE BOX
    drawRedCross(x1 + 6, y1 + 2); // ADJUSTED POSITION FOR CENTER
    
    setColor(15); 
    gotoxy(40,28);
    cout<<"CareTrack: Hospital  Patient Record System\n\n\n";
    setColor(7); 
    
    solidBar();
    
	cout<<"\n\n";
	cout<<"Press [Enter] to proceed....";
    setColor(0); system("pause");
    system("cls");
    adminScreen();
}
// MAIN MENU SCREEN
void adminScreen(){
	loadPatient();
    while(1){
		system("cls");
		//LABEL CARETRACK
    	medi();
		
		gotoxy(0, 12); solidBar();

		setColor(7);
		int y=15;
		gotoxy(30,y);
		char opt[10][100] = {"[1] Add New Record", "[2] Delete Record", "[3] Display All Record/s", "[4] Search Record/s", "[5] Sort by Selection Sort", 
		"[6] Sort by Bubble Sort", "[7] Update Record Information", "[8] Admin Menu",  "[0] Logout"};
		int n = sizeof(opt)/sizeof(opt[0]);
		for(int i=0; i<n; i++){
			gotoxy(30, y + i);
			cout<<opt[i]<<endl;
		}
		
		gotoxy(30, y + n);
		char choice;
		cout<<"Enter Option: ";
		cin>>choice;
		if(choice == '1'){
			addPatient();
		}
		else if(choice == '2'){
			delPatient();
		}
		else if(choice == '3'){
			viewPatient();
		}
		else if(choice == '4'){
			searchPatientByField();
		}
		else if(choice == '5'){
			// SORT BY SELECTION SORT
			while(1){
				system("cls");
				setColor(15);
				gotoxy(30,5);
				cout << "SELECTION SORT BY FIELD (String fields only):";
				int y=7;
				gotoxy(30,y);
				char opt[5][100] = {"[1] Name", "[2] Gender", "[3] Illness", "[4] Arrival", "[0] Back"};
				int n = sizeof(opt)/sizeof(opt[0]);
				for(int i=0; i<n; i++){
					gotoxy(30, y + i);
					cout<<opt[i]<<endl;
				}
				gotoxy(30, y + n);
				cout << "Enter your choice: ";
				char selChoice;
				cin >> selChoice;
				cin.ignore();
				if(selChoice == '1'){
					selectionSortStringField(1); // Name
					setColor(10);
					cout << "\nSelection Sort completed!\n\n";
					setColor(15);
					displayPatientList();
					setColor(1);
					cout << "\nPress [Enter] to return to sort menu...";
					setColor(0); system("pause");
				} else if(selChoice == '2'){
					selectionSortStringField(2); // Gender
					setColor(10);
					cout << "\nSelection Sort completed!\n\n";
					setColor(15);
					displayPatientList();
					setColor(1);
					cout << "\nPress [Enter] to return to sort menu...";
					setColor(0); system("pause");
				} else if(selChoice == '3'){
					selectionSortStringField(3); // Symptoms
					setColor(10);
					cout << "\nSelection Sort completed!\n\n";
					setColor(15);
					displayPatientList();
					setColor(1);
					cout << "\nPress [Enter] to return to sort menu...";
					setColor(0); system("pause");
				} else if(selChoice == '4'){
					selectionSortStringField(4); // Arrival
					setColor(10);
					cout << "\nSelection Sort completed!\n\n";
					setColor(15);
					displayPatientList();
					setColor(1);
					cout << "\nPress [Enter] to return to sort menu...";
					setColor(0); system("pause");
				} else if(selChoice == '0'){
    				break;
				} else {
					setColor(12);
					cout<<"\nInvalid Option! ";
					cout<<" Please try again. \nPress [Enter] to proceed....";
					setColor(0); system("pause");
					system("cls");
					setColor(7);
				}
			}
		}
		else if(choice == '6'){
			// SORT BY BUBBLE SORT
			while(1){
				system("cls");
				setColor(15);
				gotoxy(30,5);
				cout << "BUBBLE SORT BY FIELD (Numeric fields only):";
				int y=7;
				gotoxy(30,y);
				char opt[5][100] = {"[1] Age", "[2] Priority", "[3] ID", "[0] Back"};
				int n = sizeof(opt)/sizeof(opt[0]);
				for(int i=0; i<n; i++){
					gotoxy(30, y + i);
					cout<<opt[i]<<endl;
				}
				gotoxy(30, y + n);
				cout << "Enter your choice: ";
				char bubChoice;
				cin >> bubChoice;
				cin.ignore();
				if(bubChoice == '1'){
					bubbleSortNumericField(1); // Age
					setColor(10);
					cout << "\nBubble Sort completed!\n\n";
					setColor(15);
					displayPatientList();
					setColor(1);
					cout << "\nPress [Enter] to return to sort menu...";
					setColor(0); system("pause");
				} else if(bubChoice == '2'){
					bubbleSortNumericField(2); // Priority
					setColor(10);
					cout << "\nBubble Sort completed!\n\n";
					setColor(15);
					displayPatientList();
					setColor(1);
					cout << "\nPress [Enter] to return to sort menu...";
					setColor(0); system("pause");
				} else if(bubChoice == '3'){
					bubbleSortNumericField(3); // ID
					setColor(10);
					cout << "\nBubble Sort completed!\n\n";
					setColor(15);
					displayPatientList();
					setColor(1);
					cout << "\nPress [Enter] to return to sort menu...";
					setColor(0); system("pause");
				} else if(bubChoice == '0'){
    				break;
				} else {
					setColor(12);
					cout<<"\nInvalid Option! ";
					cout<<" Please try again. \nPress [Enter] to proceed....";
					setColor(0); system("pause");
					system("cls");
					setColor(7);
				}
			}
		}
		else if(choice == '7'){
			updatePatient();
		}
		else if(choice == '8'){
			adminMenu();
		}
		else if(choice == '0'){
			main();
		}
		else{
			setColor(12);
			cout<<"\nInvalid Option! ";
			cout<<" Please try again. \nPress [Enter] to proceed....";
			setColor(0); system("pause");
			system("cls");
		}
	}
}

// ADMIN MENU PAGE
void adminMenu(){
	system("cls");
	while(1){
		//LABEL MENU
		menu();
		
		gotoxy(0, 12); solidBar();
		
		setColor(15);
		int y=15;
		gotoxy(30,y);
		char opt[3][100] = {"1. Change Username", "2. Change Password", "0. Exit"};
		int n = sizeof(opt)/sizeof(opt[0]);
		for(int i=0; i<n; i++){
			gotoxy(30, y + i);
			cout<<opt[i]<<endl;
		}
		
		gotoxy(30, 20);
		char choice;
		cout<<"Enter Option: ";
		cin>>choice;
		cin.ignore();
		if(choice == '1'){
			system("cls");
			//LABEL EDIT
			edit();
    		
    		gotoxy(0, 12); solidBar();
    		
    		setColor(15);
    		gotoxy(30,15);
    		char newUser[100];
    		cout<<"Enter new Username: ";
    		cin>>newUser;
    		if(strcmp(admin[0], newUser)==0){
    			setColor(12);
    			cout<<"\nNew Username cannot be the same as Old Username.\n";
    			cout<<"Please try again. \nPress [Enter] to proceed to Exit....";
    			setColor(0); system("pause");
    			system("cls");
    			return;
			}
			strcpy(admin[0], newUser);
    		saveAdmin();
			setColor(1);
    		cout<<"\nUsername Updated! \nPress [Enter] to proceed to Exit....";
    		setColor(0); system("pause");
    		system("cls");
		}
		else if(choice == '2'){
			system("cls");
			//LABEL EDIT
			edit();
    		
    		gotoxy(0, 12); solidBar();
    		
    		setColor(15);
    		gotoxy(30,15);
    		char newPass[100];
    		cout<<"Enter new Password: ";
    		cin>>newPass;
    		if(strcmp(admin[1], newPass)==0){
    			setColor(12);
    			cout<<"\nNew Password cannot be the same as Old Password.\n";
    			cout<<"Please try again. \nPress [Enter] to proceed to Exit....";
    			setColor(0); system("pause");
    			system("cls");
    			return;
			}
			strcpy(admin[1], newPass);
    		saveAdmin();
			setColor(1);
    		cout<<"\nPassword Updated! \nPress [Enter] to proceed to Exit....";
    		setColor(0); system("pause");
    		system("cls");
		}
		else if(choice == '0'){
			adminScreen();
		}
		else{
			setColor(12);
			cout<<"\nInvalid Option! Please try again. \nPress [Enter] to proceed....";
			setColor(0); system("pause");
			system("cls");
		}
	}
}
// PATIENT LINKED LIST UTILITY FUNCTIONS

// FREE ALL PATIENT NODES
void freePatientList() {
    PatientNode* curr = head;
    while (curr) {
        PatientNode* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    patientCount = 0;
}

// SAVE ALL PATIENTS TO FILE
void savePatient() {
    ofstream file("patients.txt");
    PatientNode* curr = head;
    while (curr) {
        file << curr->id << endl;
        file << curr->name << endl;
        file << curr->age << endl;
        file << curr->gender << endl;
        file << curr->arrivalTime << endl;
        file << curr->symptoms << endl;
        file << curr->priority << endl;
        curr = curr->next;
    }
    file.close();
}

// LOAD ALL PATIENTS FROM FILE
void loadPatient() {
    freePatientList();
    ifstream file("patients.txt");
    if (!file) return;
    while (true) {
        PatientNode* newNode = new PatientNode();
        if (!(file >> newNode->id)) { delete newNode; break; }
        file.ignore();
        file.getline(newNode->name, 100);
        file >> newNode->age; file.ignore();
        file.getline(newNode->gender, 10);
        file.getline(newNode->arrivalTime, 25);
        file.getline(newNode->symptoms, 100);
        file >> newNode->priority; file.ignore();
        newNode->next = nullptr;
        if (!head) head = newNode;
        else {
            PatientNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        patientCount++;
    }
    file.close();
}

// GENERATE PATIENT ID
int generatePatientID(){
	ifstream file("patient_ID.txt");
	int lastPatientNum = 0;
	if(file.is_open()){
		file >> lastPatientNum; //READ LAST PATIENT ID
		file.close();
	}
	lastPatientNum++;
	
	ofstream outfile("patient_ID.txt");
	outfile << lastPatientNum; //SAVE PATIENT ID
	outfile.close();
	
	return lastPatientNum;
}
// FORMAT PATIENT ID NUMBER
void displayFormatID(int number){
	cout << "PAT-";
	if(number < 10){
		cout << "00" << number;
	}
	else if(number < 100){
		cout<< "0" << number;
	}
	else{
		cout << number;
	}
}
// ADD PATIENT INFO
void addPatient(){
    system("cls");
    add(); //LABEL ADD
    gotoxy(0, 12); solidBar();
    char confirm;
    setColor(15);
    cout << "Are you sure you want to add a new patient? (Y/N): ";
    cin >> confirm;
    cin.ignore();
    if (confirm != 'Y' && confirm != 'y') {
        setColor(12);
        cout << "\nAction cancelled. Press [Enter] to proceed to main menu...\n";
        setColor(0); system("pause");
        system("cls");
        adminScreen();
        return;
    }
    while(1){
        system("cls");
        add();
        gotoxy(0, 12); solidBar();
        setColor(12);
        if(patientCount >= capacity){
            cout<<"Maximum patient capacity reached!\n";
            cout<<"Please try again. \nPress [Enter] to proceed....";
            setColor(0); system("pause");
            system("cls");
            return;
        }
        setColor(15);
        PatientNode* newNode = new PatientNode();
        newNode->id = generatePatientID();
        cout<<"Patient ID\t\t\t\t\t: ";
        displayFormatID(newNode->id);
        cout<<endl;
        cout<<"Enter Fullname\t\t\t\t\t: ";
        cin.getline(newNode->name,100);
        cout<<"Enter Age\t\t\t\t\t: ";
        cin>>newNode->age;
        cin.ignore();
        while(1){
            cout<<"Enter Gender (M/F)\t\t\t\t: ";
            cin.getline(newNode->gender,10);
            if(strcmp(newNode->gender, "M")==0 || strcmp(newNode->gender, "F")==0){
                break;
            } else {
                setColor(12);
                cout<<"Invalid Gender. Please enter M or F.\nPress [Enter] to proceed....";
                setColor(0); system("pause");
                setColor(15);
            }
        }
        // AUTO-GENERATE ARRIVAL DATE/TIME
        time_t now = time(0);
        tm *ltm = localtime(&now);
        sprintf(newNode->arrivalTime, "%04d-%02d-%02d %02d:%02d:%02d",
            1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,
            ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
        cout<<"Arrival Date/Time\t\t\t\t: "<<newNode->arrivalTime<<endl;
        cout<<"Enter Illness\t\t\t\t\t: ";
        cin.getline(newNode->symptoms,100);
        char tprio[10];
        while(1){
            cout<<"Enter Priority";
            cout<<"\n(1-Normal, 2-Urgent, 3-Emergency)\t\t: ";
            cin.getline(tprio,10);
            if(strcmp(tprio, "1")==0){
                newNode->priority = 1;
                break;
            } else if(strcmp(tprio, "2")==0){
                newNode->priority = 2;
                break;
            } else if(strcmp(tprio, "3")==0){
                newNode->priority = 3;
                break;
            } else {
                setColor(12);
                cout<<"Invalid Priority. Please enter 1, 2, or 3.\nPress [Enter] to proceed....";
                setColor(0); system("pause");
                setColor(15);
            }
        }
        newNode->next = nullptr;
        // INSERT AT END
        if(head == nullptr) {
            head = newNode;
        } else {
            PatientNode* temp = head;
            while(temp->next) temp = temp->next;
            temp->next = newNode;
        }
        patientCount++;
        savePatient();
        setColor(1);
        cout<<"\nPatient record added successfully!\n\n";
        while(1){
            setColor(15);
            char choice;
            cout<<"Do you want to add another patient? (T/F): ";
            cin>>choice;
            cin.ignore();
            if(choice == 'T' || choice == 't'){
                break;
            } else if(choice == 'F' || choice == 'f'){
                system("cls");
                adminScreen();
                return;
            } else {
                setColor(12);
                cout<<"Invalid input. Please enter T or F.\nPress [Enter] to proceed....";
                setColor(0); system("pause");
                setColor(15);
            }
        }
    }
}
// SWAP
void swapPatient(int a, int b) {
    int tempID = id[a];
    id[a] = id[b];
    id[b] = tempID;

    char tempName[100];
    strcpy(tempName, name[a]);
    strcpy(name[a], name[b]);
    strcpy(name[b], tempName);

    int tempAge = age[a];
    age[a] = age[b];
    age[b] = tempAge;

    char tempGender[10];
    strcpy(tempGender, gender[a]);
    strcpy(gender[a], gender[b]);
    strcpy(gender[b], tempGender);

    char tempArrival[10];
    strcpy(tempArrival, arrivalTime[a]);
    strcpy(arrivalTime[a], arrivalTime[b]);
    strcpy(arrivalTime[b], tempArrival);

    char tempSymptoms[100];
    strcpy(tempSymptoms, symptoms[a]);
    strcpy(symptoms[a], symptoms[b]);
    strcpy(symptoms[b], tempSymptoms);

    int tempPriority = priority[a];
    priority[a] = priority[b];
    priority[b] = tempPriority;
}
// BUBBLE SORT
void bubbleSort(int field) {
    for (int i = 0; i < patientCount - 1; i++) {
        for (int j = 0; j < patientCount - i - 1; j++) {
            bool swapNeeded = false;

            if (field == 1) { // Name
                char name1[100], name2[100];
                              
                strcpy(name1, name[j]);
                strcpy(name2, name[j+1]);
                strlwr(name1);
                strlwr(name2);
                if (strcmp(name1, name2) > 0) swapNeeded = true;
            } else if (field == 3) { // Gender
                if (strcmp(gender[j], gender[j+1]) > 0) swapNeeded = true;
            } else if (field == 5) { // Symptoms
            	char temp1[100], temp2[100];
                strcpy(temp1, symptoms[j]);
                strcpy(temp2, symptoms[j+1]);
                strlwr(temp1);
                strlwr(temp2);
                if (strcmp(temp1, temp2) > 0) swapNeeded = true;
            }

            if (swapNeeded) {
                swapPatient(j, j+1);
            }
        }
    }
}
// SWAP TWO PATIENT NODES BY POINTER (FOR SORTING)
void swapPatientData(PatientNode* a, PatientNode* b) {
    if (!a || !b) return;
    std::swap(a->id, b->id);
    std::swap(a->age, b->age);
    std::swap(a->priority, b->priority);
    char tmpName[100], tmpGender[10], tmpArrival[25], tmpSymptoms[100];
    strcpy(tmpName, a->name); strcpy(a->name, b->name); strcpy(b->name, tmpName);
    strcpy(tmpGender, a->gender); strcpy(a->gender, b->gender); strcpy(b->gender, tmpGender);
    strcpy(tmpArrival, a->arrivalTime); strcpy(a->arrivalTime, b->arrivalTime); strcpy(b->arrivalTime, tmpArrival);
    strcpy(tmpSymptoms, a->symptoms); strcpy(a->symptoms, b->symptoms); strcpy(b->symptoms, tmpSymptoms);
}

// SELECTION SORT FOR STRING FIELDS (LINKED LIST)
void selectionSortStringField(int field) {
    for (PatientNode* i = head; i && i->next; i = i->next) {
        PatientNode* minNode = i;
        for (PatientNode* j = i->next; j; j = j->next) {
            bool swapNeeded = false;
            if (field == 1) { // Name
                char n1[100], n2[100];
                strcpy(n1, j->name); strcpy(n2, minNode->name);
                strlwr(n1); strlwr(n2);
                if (strcmp(n1, n2) < 0) swapNeeded = true;
            } else if (field == 2) { // Gender
                char g1[10], g2[10];
                strcpy(g1, j->gender); strcpy(g2, minNode->gender);
                strlwr(g1); strlwr(g2);
                if (strcmp(g1, g2) < 0) swapNeeded = true;
            } else if (field == 3) { // Symptoms
                char s1[100], s2[100];
                strcpy(s1, j->symptoms); strcpy(s2, minNode->symptoms);
                strlwr(s1); strlwr(s2);
                if (strcmp(s1, s2) < 0) swapNeeded = true;
            } else if (field == 4) { // Arrival
                char a1[25], a2[25];
                strcpy(a1, j->arrivalTime); strcpy(a2, minNode->arrivalTime);
                if (strcmp(a1, a2) < 0) swapNeeded = true;
            }
            if (swapNeeded) minNode = j;
        }
        if (minNode != i) swapPatientData(i, minNode);
    }
}

// BUBBLE SORT FOR NUMERIC FIELDS (LINKED LIST)
void bubbleSortNumericField(int field) {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        for (PatientNode* i = head; i && i->next; i = i->next) {
            bool swapNeeded = false;
            if (field == 1) { // Age
                if (i->age > i->next->age) swapNeeded = true;
            } else if (field == 2) { // Priority
                if (i->priority > i->next->priority) swapNeeded = true;
            } else if (field == 3) { // ID
                if (i->id > i->next->id) swapNeeded = true;
            }
            if (swapNeeded) {
                swapPatientData(i, i->next);
                swapped = true;
            }
        }
    } while (swapped);
}
// VIEW PATIENT INFO
void viewPatient() {
    while (1) {
        system("cls");
        viewLabel(); //LABEL VIEW
        gotoxy(0,12); solidBar();
        setColor(12);
        if (patientCount == 0) {
            cout << "No patient records found.\n";
            cout << "Please try again. \nPress [Enter] to proceed....";
            setColor(0); system("pause");
            system("cls");
            return;
        }
        setColor(15);
        displayPatientList();
        setColor(15);
        cout << "\n1. Sort\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        char choice;
        cin >> choice;
        if (choice == '1') {
            while (1) {
                system("cls");
                setColor(15);
                gotoxy(30,5); cout << "SORT OPTIONS:";
                gotoxy(30,6); cout << "1. Sort by Selection Sort (String fields)\n";
                gotoxy(30,7); cout << "2. Sort by Bubble Sort (Numeric fields)\n";
                gotoxy(30,8); cout << "0. Back\n";
                gotoxy(30,9); cout << "Enter your choice: ";
                char sortChoice;
                cin >> sortChoice;
                cin.ignore();
                if (sortChoice == '1') {
                    while (1) {
                        system("cls");
                        setColor(15);
                        gotoxy(30,5); cout << "SELECTION SORT BY FIELD (String fields only):";
                        gotoxy(30,6); cout << "1. Name\n";
                        gotoxy(30,7); cout << "2. Gender\n";
                        gotoxy(30,8); cout << "3. Illness\n";
                        gotoxy(30,9); cout << "4. Arrival Date/Time\n";
                        gotoxy(30,10); cout << "0. Back\n";
                        gotoxy(30,11); cout << "Enter your choice: ";
                        char selChoice;
                        cin >> selChoice;
                        cin.ignore();
                        if(selChoice == '1'){
                        	selectionSortStringField(1); // Name
                        	setColor(10);
		                    cout << "\nSelection Sort completed!\n\n";
		                    setColor(15);
		                    displayPatientList();
		                    setColor(1);
		                    cout << "\nPress [Enter] to return to sort menu..."; 
		                    setColor(0); system("pause");
						} else if(selChoice == '2'){
							selectionSortStringField(2); // Gender
							setColor(10);
		                    cout << "\nSelection Sort completed!\n\n";
		                    setColor(15);
		                    displayPatientList();
		                    setColor(1);
		                    cout << "\nPress [Enter] to return to sort menu..."; 
		                    setColor(0); system("pause");
						} else if(selChoice == '3'){
							selectionSortStringField(3); // Symptoms
							setColor(10);
		                    cout << "\nSelection Sort completed!\n\n";
		                    setColor(15);
		                    displayPatientList();
		                    setColor(1);
		                    cout << "\nPress [Enter] to return to sort menu..."; 
		                    setColor(0); system("pause");
						} else if(selChoice == '4'){
							selectionSortStringField(4); // Arrival
							setColor(10);
		                    cout << "\nSelection Sort completed!\n\n";
		                    setColor(15);
		                    displayPatientList();
		                    setColor(1);
		                    cout << "\nPress [Enter] to return to sort menu..."; 
		                    setColor(0); system("pause");
						} else if(selChoice == '0'){
							break;
						} else {
							setColor(12);
							cout<<"\nInvalid Option! Please try again. \nPress [Enter] to proceed....";
							setColor(0); system("pause");
						}
                    }
                } else if (sortChoice == '2') {
                    while (1) {
                        system("cls");
                        setColor(15);
                        gotoxy(30,5); cout << "BUBBLE SORT BY FIELD (Numeric fields only):";
                        gotoxy(30,6); cout << "1. Age\n";
                        gotoxy(30,7); cout << "2. Priority\n";
                        gotoxy(30,8); cout << "3. ID\n";
                        gotoxy(30,9); cout << "0. Back\n";
                        gotoxy(30,10); cout << "Enter your choice: ";
                        char bubChoice;
                        cin >> bubChoice;
                        cin.ignore();
                        if (bubChoice == '1'){
                        	bubbleSortNumericField(1); // Age
                        	setColor(10);
		                    cout << "\nBubble Sort completed!\n\n";
		                    setColor(15);
		                    displayPatientList();
		                    setColor(1);
		                    cout << "\nPress [Enter] to return to sort menu..."; 
		                    setColor(0); system("pause");
						} else if (bubChoice == '2'){
							bubbleSortNumericField(2); // Priority
							setColor(10);
		                    cout << "\nBubble Sort completed!\n\n";
		                    setColor(15);
		                    displayPatientList();
		                    setColor(1);
		                    cout << "\nPress [Enter] to return to sort menu..."; 
		                    setColor(0); system("pause");
						} else if (bubChoice == '3'){
							bubbleSortNumericField(3); // ID
							setColor(10);
		                    cout << "\nBubble Sort completed!\n\n";
		                    setColor(15);
		                    displayPatientList();
		                    setColor(1);
		                    cout << "\nPress [Enter] to return to sort menu..."; 
		                    setColor(0); system("pause");
						} else if(bubChoice == '0'){
							break;
						} else {
							setColor(12);
							cout<<"\nInvalid Option! Please try again. \nPress [Enter] to proceed....";
							setColor(0); system("pause");
						}
                    }
                } else if(sortChoice == '0'){
                	break;
				} else{
					setColor(12);
		            cout << "\nInvalid Option! Please try again. \nPress [Enter] to proceed....";
		            setColor(0); system("pause");
				}
            }
        } else if (choice == '2') {
			system("cls");
    		return;
        } else {
            setColor(12);
            cout << "\nInvalid Option! Please try again. \nPress [Enter] to proceed....";
            setColor(0); system("pause");
        }
    }
}

// CONFIRMATION OF USER AND PASS FOR UPDATE PAGE
void confirmAdmin(){
	char confirmuser[100], confirmpass[100];
	cout<<"\n\nConfirm Admin Username: ";
	cin.getline(confirmuser,100);
	cout<<"Confirm Admin Password: ";
	cin.getline(confirmpass,100);
	
	if(strcmp(confirmuser, admin[0])==0 && strcmp(confirmpass, admin[1])==0){
		savePatient();
		setColor(1);
		cout<<"\nPatient record updated successfully!\nPress [Enter] to proceed....";
		setColor(0); system("pause");
	}
	else{
		setColor(12);
		cout<<"\nAuthentication failed. Update not saved.\nPlease try again. Press [Enter] to proceed....";
		setColor(0); system("pause");
	}
}
// UPDATE PATIENT INFO
void updatePatient() {
    system("cls");
    //LABEL UPDATE
    upd();
    gotoxy(0,12); solidBar();
    setColor(15);
    gotoxy(30,15);
    int searchID;
    cout << "Enter Patient ID: ";
    cin >> searchID;
    cin.ignore();
    PatientNode* p = findPatientByID(searchID);
    if (!p) {
        setColor(12);
        cout << "\nPatient ID not found! Please try again. \nPress [Enter] to proceed....";
        setColor(0); system("pause");
        system("cls");
        return;
    }
    while (1) {
        system("cls");
        upd();
        gotoxy(0,12); solidBar();
        setColor(15);
        gotoxy(45, 15);
        cout << string(5,(char)205) << " UPDATE FOR "; displayFormatID(p->id); cout << " " << string(5,(char)205);
        int y=17;
        gotoxy(30,y);
        char opt[7][100] = {"[1] Name", "[2] Age", "[3] Gender",  "[4] Illness", "[5] Priority", "[0] Exit"};
        int n = sizeof(opt)/sizeof(opt[0]);
        for(int i=0; i<n; i++){
            gotoxy(30, y + i);
            cout<<opt[i]<<endl;
        }
        gotoxy(30, y + n + 1);
        char choice;
        cout<<"Enter Option: ";
        cin>>choice;
        cin.ignore();
        if(choice == '1'){
            system("cls"); edit(); gotoxy(0,12); solidBar(); setColor(15);
            cout << "Current Name: " << p->name << "\nEnter new Name (or press Enter to keep): ";
            char buf[100];
            cin.getline(buf, 100);
            if (strlen(buf) > 0) strcpy(p->name, buf);
        } else if(choice == '2'){
            system("cls"); edit(); gotoxy(0,12); solidBar(); setColor(15);
            cout << "Current Age: " << p->age << "\nEnter new Age (or 0 to keep): ";
            int newAge; cin >> newAge; cin.ignore();
            if (newAge > 0) p->age = newAge;
        } else if(choice == '3'){
            system("cls"); edit(); gotoxy(0,12); solidBar(); setColor(15);
            cout << "Current Gender: " << p->gender << "\nEnter new Gender (M/F or press Enter to keep): ";
            char buf[10];
            cin.getline(buf, 10);
            if (strlen(buf) > 0 && (strcmp(buf, "M") == 0 || strcmp(buf, "F") == 0)) strcpy(p->gender, buf);
        } else if(choice == '4'){
            system("cls"); edit(); gotoxy(0,12); solidBar(); setColor(15);
            cout << "Current Illness: " << p->symptoms << "\nEnter new Illness (or press Enter to keep): ";
            char buf[100];
            cin.getline(buf, 100);
            if (strlen(buf) > 0) strcpy(p->symptoms, buf);
        } else if(choice == '5'){
            system("cls"); edit(); gotoxy(0,12); solidBar(); setColor(15);
            cout << "Current Priority: " << p->priority << "\nEnter new Priority (1-Normal, 2-Urgent, 3-Emergency, 0 to keep): ";
            int newPrio; cin >> newPrio; cin.ignore();
            if (newPrio >= 1 && newPrio <= 3) p->priority = newPrio;
        } else if(choice == '0'){
            adminScreen();
        } else {
            setColor(12);
            cout << "\nInvalid Option! Please try again. \nPress [Enter] to proceed....";
            setColor(0); system("pause");
        }
        savePatient();
    }
    setColor(10);
	cout << "\nPatient record updated successfully!\nPress [Enter] to proceed....";
	setColor(0); system("pause");
}

void delPatient() {
    while (1) {
        system("cls");
        delLabel(); //LABEL DELETE
        gotoxy(0,12); solidBar();
        setColor(15);
        int y = 15;
        gotoxy(30, y);
        char opt[3][100] = {
            "[1] Delete ALL Patient Information",
            "[2] Delete Specific Patient by ID",
            "[0] Cancel"
        };
        int n = sizeof(opt)/sizeof(opt[0]);
        for (int i = 0; i < n; i++) {
            gotoxy(30, y + i);
            cout << opt[i] << endl;
        }
        gotoxy(30, y + n);
        char choice;
        cout << "Enter Option: ";
        cin >> choice;
        cin.ignore();
        if (choice == '1') {
            system("cls");
            delLabel();
            gotoxy(0,12); solidBar();
            setColor(15);
            gotoxy(30,17);
            char confirmuser[100], confirmpass[100];
            cout<<"Confirm Admin Username: ";
            cin.getline(confirmuser, 100);
            gotoxy(30,18);
            cout<<"Confirm Admin Password: ";
            cin.getline(confirmpass, 100);
            if(strcmp(confirmuser, admin[0])==0 && strcmp(confirmpass, admin[1])==0){
                freePatientList();
                savePatient();
                head = NULL;
                patientCount = 0;
                setColor(10);
                cout << "\nAll patient records deleted successfully!\nPress [Enter] to proceed....";
                setColor(0); system("pause");
            } else {
                setColor(12);
                cout << "\nAuthentication failed. No records deleted.\nPress [Enter] to proceed....";
                setColor(0); system("pause");
            }
        } else if (choice == '2') {
            system("cls");
            delLabel();
            gotoxy(0,12); solidBar();
            setColor(15);
            cout << "Enter Patient ID to delete: ";
            int delID;
            cin >> delID;
            cin.ignore();
            PatientNode* prev = NULL;
            PatientNode* curr = head;
            while (curr) {
                if (curr->id == delID) {
                    if (prev) prev->next = curr->next;
                    else head = curr->next;
                    delete curr;
                    patientCount--;
                    savePatient();
                    setColor(10);
                    cout << "\nPatient record deleted successfully!\nPress [Enter] to proceed....";
                    setColor(0); system("pause");
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
            if (!curr) {
                setColor(12);
                cout << "\nPatient ID not found.\nPress [Enter] to proceed....";
                setColor(0); system("pause");
            }
        } else if (choice == '0') {
            break;
        } else {
            setColor(12);
            cout << "\nInvalid Option! Please try again. \nPress [Enter] to proceed....";
            setColor(0); system("pause");
        }
    }
}

// FIND PATIENT BY ID (RETURNS POINTER)
PatientNode* findPatientByID(int searchID) {
    for (PatientNode* p = head; p; p = p->next) {
        if (p->id == searchID) return p;
    }
    return NULL;
}

// SEARCH RECORDS (LINKED LIST)
void searchPatientByField() {
    while (1) {
        system("cls");
        setColor(15);
        gotoxy(30,5); cout << "SEARCH PATIENT BY FIELD:";
        gotoxy(30,6); cout << "[1] Name";
        gotoxy(30,7); cout << "[2] Age";
        gotoxy(30,8); cout << "[3] Gender";
        gotoxy(30,9); cout << "[4] Illness";
        gotoxy(30,10); cout << "[5] Priority";
        gotoxy(30,11); cout << "[6] Patient ID";
        gotoxy(30,12); cout << "[7] Arrival";
        gotoxy(30,13); cout << "[0] Back";
        gotoxy(30,14); cout << "Enter your choice: ";
        char choice;
        cin >> choice;
        cin.ignore();
        if (choice == '0') break;
        bool found = false;
        if (choice == '1') {
            char searchName[100];
            cout << "\n\nEnter Name to search: ";
            cin.getline(searchName, 100);
            for (PatientNode* p = head; p; p = p->next) {
                if (strstr(p->name, searchName)) {
                    setColor(10);
                    cout << "\nFound: ";
                    displayFormatID(p->id);
                    cout << " | Name: " << p->name;
                    cout << " | Age: " << p->age;
                    cout << " | Gender: " << p->gender;
                    cout << " | Arrival: " << p->arrivalTime;
                    cout << " | Illness: " << p->symptoms;
                    cout << " | Priority: " << p->priority << endl;
                    found = true;
                }
            }
        } else if (choice == '2') {
            int searchAge;
            cout << "\n\nEnter Age to search: ";
            cin >> searchAge; cin.ignore();
            for (PatientNode* p = head; p; p = p->next) {
                if (p->age == searchAge) {
                    setColor(10);
                    cout << "\nFound: ";
                    displayFormatID(p->id);
                    cout << " | Name: " << p->name;
                    cout << " | Age: " << p->age;
                    cout << " | Gender: " << p->gender;
                    cout << " | Arrival: " << p->arrivalTime;
                    cout << " | Illness: " << p->symptoms;
                    cout << " | Priority: " << p->priority << endl;
                    found = true;
                }
            }
        } else if (choice == '3') {
            char searchGender[10];
            cout << "\n\nEnter Gender to search (M/F): ";
            cin.getline(searchGender, 10);
            for (PatientNode* p = head; p; p = p->next) {
                if (strcmp(p->gender, searchGender) == 0) {
                    setColor(10);
                    cout << "\nFound: ";
                    displayFormatID(p->id);
                    cout << " | Name: " << p->name;
                    cout << " | Age: " << p->age;
                    cout << " | Gender: " << p->gender;
                    cout << " | Arrival: " << p->arrivalTime;
                    cout << " | Illness: " << p->symptoms;
                    cout << " | Priority: " << p->priority << endl;
                    found = true;
                }
            }
        } else if (choice == '4') {
            char searchSymptoms[100];
            cout << "\n\nEnter Illness to search: ";
            cin.getline(searchSymptoms, 100);
            for (PatientNode* p = head; p; p = p->next) {
                if (strstr(p->symptoms, searchSymptoms)) {
                    setColor(10);
                    cout << "\nFound: ";
                    displayFormatID(p->id);
                    cout << " | Name: " << p->name;
                    cout << " | Age: " << p->age;
                    cout << " | Gender: " << p->gender;
                    cout << " | Arrival: " << p->arrivalTime;
                    cout << " | Illness: " << p->symptoms;
                    cout << " | Priority: " << p->priority << endl;
                    found = true;
                }
            }
        } else if (choice == '5') {
            int searchPriority;
            cout << "\n\nEnter Priority to search (1-Normal, 2-Urgent, 3-Emergency): ";
            cin >> searchPriority; cin.ignore();
            for (PatientNode* p = head; p; p = p->next) {
                if (p->priority == searchPriority) {
                    setColor(10);
                    cout << "\nFound: ";
                    displayFormatID(p->id);
                    cout << " | Name: " << p->name;
                    cout << " | Age: " << p->age;
                    cout << " | Gender: " << p->gender;
                    cout << " | Arrival: " << p->arrivalTime;
                    cout << " | Illness: " << p->symptoms;
                    cout << " | Priority: " << p->priority << endl;
                    found = true;
                }
            }
        } else if (choice == '6') {
            char seaID[50];
            cout << "Enter Patient ID to search: ";
            cin.getline(seaID, 50);
            int searchID = atoi(seaID);
            for (PatientNode* p = head; p; p = p->next) {
                if (p->id == searchID) {
                    setColor(10);
                    cout << "\nFound: ";
                    displayFormatID(p->id);
                    cout << " | Name: " << p->name;
                    cout << " | Age: " << p->age;
                    cout << " | Gender: " << p->gender;
                    cout << " | Arrival: " << p->arrivalTime;
                    cout << " | Illness: " << p->symptoms;
                    cout << " | Priority: " << p->priority << endl;
                    found = true;
                }
            }
        } else if (choice == '7') {
		    char searchDateTime[100];
		    cout << "Enter Arrival Time/Date to search (partial allowed): ";
		    cin.getline(searchDateTime, 100);
		    for (PatientNode* p = head; p; p = p->next) {
		        if (strstr(p->arrivalTime, searchDateTime)) {
		            setColor(10);
		            cout << "\nFound: ";
                    displayFormatID(p->id);
                    cout << " | Name: " << p->name;
                    cout << " | Age: " << p->age;
                    cout << " | Gender: " << p->gender;
                    cout << " | Arrival: " << p->arrivalTime;
                    cout << " | Illness: " << p->symptoms;
                    cout << " | Priority: " << p->priority << endl;
                    found = true;
		        }
		    }
		} else {
            setColor(12);
            cout << "\nInvalid Option! Please try again.\n";
        }
        if (!found) {
            setColor(12);
            cout << "\nNo matching patient found.\n";
        }
        setColor(0); system("pause");
    }
}
void displayPatientList() {
    setColor(15);
    for (PatientNode* p = head; p; p = p->next) {
        cout << "Patient ID         : "; displayFormatID(p->id);
        cout << "\nName               : " << p->name;
        cout << "\nAge                : " <<  p->age;
        cout << "\nGender             : " << p->gender;
        cout << "\nArrival            : " << p->arrivalTime;
        cout << "\nIllness            : " << p->symptoms;
        cout << "\nPriority Level     : ";
        switch (p->priority) {
            case 1: cout << "Normal"; break;
            case 2: cout << "Urgent"; break;
            case 3: cout << "Emergency"; break;
            default: cout << p->priority;
        }
        cout << endl;
        setColor(3);
        cout << string(120, (char)205);
        setColor(15);
    }
}
