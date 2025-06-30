#include <bits/stdc++.h>
#include <windows.h>
#include <ctype.h>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <ctime>
using namespace std;

/*NOTE: For better viewing do not maximize the console. Use Dev C++.*/

// Move cursor position
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
// Changing color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    //0-black 1-blue 2-green 3-aqua/cyan 4-red 5-purple 6-yellow 7-white
    //8-gray 9-ligth blue 10-light green 11-light cyan 12-light red 
    //13-pink/magenta 14-light yellow 15-bright white
}
//horizontal solid bar
void solidBar(){
	setColor(3);
	int length = 120;
	for(int i=0; i<length; i++){
		cout<<(char)219;
	}
}
// outer box
void drawBox(int x1, int y1, int x2, int y2) {
	setColor(15); 
    for (int y = y1; y <= y2; y++) {
        gotoxy(x1, y);
        for (int x = x1; x <= x2; x++) {
            cout << (char)219; // Solid block character
        }
    }
    setColor(7);
}
// red cross
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
//label CARETRACK within bar
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
//label CARETRACK
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
//label ADMIN
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
//label WELCOME
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
//label MENU
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
//label EDIT
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
//label ADD
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
//label VIEW
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
//label UPDATE
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
//label DELETE
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
//function declaration
void saveAdmin(), loadAdmin(), viewLogin(), login(), welcomePage(), CallPatient(), adminScreen(), adminMenu(), addPatient(), viewPatient(), updatePatient(),
delPatient(), loadPatient(), savePatient(), displayFormatID(int number), saveReceipt(), loadReceipt(), viewReceipt(), patientReceipt(), searchPatientByField(),
selectionSortStringField(int field), bubbleSortNumericField(int field), displayPatientList();

// Prototype for findPatientByID
struct PatientNode* findPatientByID(int searchID);

// Linked List Node for Patient
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

PatientNode* head = nullptr;
int patientCount = 0, receiptCount = 0, capacity = 1000;

// Admin credentials: admin[0] = username, admin[1] = password
char admin[2][100];

// Patient arrays for array-based sorting (capacity = 1000)
int id[1000], age[1000], priority[1000];
char name[1000][100], gender[1000][10], arrivalTime[1000][25], symptoms[1000][100];

//mainScreen
int main() {
	system("cls");
	while(1){
		setColor(7);
    	gotoxy(0,4); cout<<"<< EXIT";
    	gotoxy(112,4); cout<<"ENTER >>";
	
		gotoxy(0,7); solidBar();
		
		//Label CARETRACK with bar
		mediBar();
    
    	setColor(7); 
    	int x1 = 43; //position x
    	int y1 = 12; //position y
    	int x2 = x1 + 35; //number of -
    	int y2 = y1 + 15; //numer of |
	    drawBox(x1, y1, x2, y2);
    
   		// Draw cross centered inside the box
    	drawRedCross(x1 + 6, y1 + 2); // Adjusted position for center
    	
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
//save admin user and pass to admin.txt file
void saveAdmin(){
	ofstream file("admin.txt");
	file << admin[0] << endl;
	file << admin[1] << endl;
	file.close();
}
//load admin user and pass from admin.txt file
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
//view or login page
void viewLogin(){
	system("cls");
	while(1){
		//Label CARETRACK
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
//login page
void login(){
	system("cls");
	int attempts = 0;
 	while(attempts < 3){
 		//label ADMIN
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
//welcome page
void welcomePage(){
	system("cls");
	gotoxy(0,7); solidBar();
	
	//label WELCOME
	wel();

    int x1 = 43; //position x
    int y1 = 12; //position y
    int x2 = x1 + 35; //number of -
    int y2 = y1 + 15; //numer of |
    drawBox(x1, y1, x2, y2);
    
    // Draw cross centered inside the box
    drawRedCross(x1 + 6, y1 + 2); // Adjusted position for center
    
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
//main menu screen
void adminScreen(){
	loadPatient();
    while(1){
		system("cls");
		//Label CARETRACK
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
				cout << "\nSELECTION SORT BY FIELD (String fields only):\n";
				cout << "1. Name\n";
				cout << "2. Gender\n";
				cout << "3. Symptoms\n";
				cout << "4. Arrival Date/Time\n";
				cout << "0. Back\n";
				cout << "Enter your choice: ";
				char selChoice;
				cin >> selChoice;
				cin.ignore();
				if(selChoice == '0') break;
				if(selChoice == '1') selectionSortStringField(1); // Name
				else if(selChoice == '2') selectionSortStringField(2); // Gender
				else if(selChoice == '3') selectionSortStringField(3); // Symptoms
				else if(selChoice == '4') selectionSortStringField(4); // Arrival
				setColor(10);
				cout << "\nSelection Sort completed!\n";
				setColor(15);
				displayPatientList();
				setColor(0); cout << "\nPress [Enter] to return to sort menu..."; system("pause");
			}
		}
		else if(choice == '6'){
			// SORT BY BUBBLE SORT
			while(1){
				system("cls");
				setColor(15);
				cout << "\nBUBBLE SORT BY FIELD (Numeric fields only):\n";
				cout << "1. Age\n";
				cout << "2. Priority\n";
				cout << "3. ID\n";
				cout << "0. Back\n";
				cout << "Enter your choice: ";
				char bubChoice;
				cin >> bubChoice;
				cin.ignore();
				if(bubChoice == '0') break;
				if(bubChoice == '1') bubbleSortNumericField(1); // Age
				else if(bubChoice == '2') bubbleSortNumericField(2); // Priority
				else if(bubChoice == '3') bubbleSortNumericField(3); // ID
				setColor(10);
				cout << "\nBubble Sort completed!\n";
				setColor(15);
				displayPatientList();
				setColor(0); cout << "\nPress [Enter] to return to sort menu..."; system("pause");
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

// admin menu page
void adminMenu(){
	system("cls");
	while(1){
		//label MENU
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
			//label EDIT
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
			//label EDIT
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
// Patient Linked List utility functions

// Free all patient nodes
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

// Save all patients to file
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

// Load all patients from file
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

//generate patient ID
int generatePatientID(){
	ifstream file("patient_ID.txt");
	int lastPatientNum = 0;
	if(file.is_open()){
		file >> lastPatientNum; //read last patient ID
		file.close();
	}
	lastPatientNum++;
	
	ofstream outfile("patient_ID.txt");
	outfile << lastPatientNum; //save patient ID
	outfile.close();
	
	return lastPatientNum;
}
//format patient ID number
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
//add patient info
void addPatient(){
    system("cls");
    add(); //label ADD
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
        // Auto-generate Arrival Date/Time
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
        // Insert at end
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
//swap
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
//bubble sort
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
// Swap two patient nodes by pointer (for sorting)
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

// Selection Sort for string fields (linked list)
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

// Bubble Sort for numeric fields (linked list)
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
//mergesort
void merge(int left, int mid, int right, int field) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int tempID[100], tempAge[100], tempPriority[100];
    char tempName[100][100], tempGender[100][10], tempArrival[100][10], tempSymptoms[100][100];

    for (int i = 0; i < n1; i++) {
        tempID[i] = id[left + i];
        strcpy(tempName[i], name[left + i]);
        tempAge[i] = age[left + i];
        strcpy(tempGender[i], gender[left + i]);
        strcpy(tempArrival[i], arrivalTime[left + i]);
        strcpy(tempSymptoms[i], symptoms[left + i]);
        tempPriority[i] = priority[left + i];
    }
    for (int j = 0; j < n2; j++) {
        tempID[n1 + j] = id[mid + 1 + j];
        strcpy(tempName[n1 + j], name[mid + 1 + j]);
        tempAge[n1 + j] = age[mid + 1 + j];
        strcpy(tempGender[n1 + j], gender[mid + 1 + j]);
        strcpy(tempArrival[n1 + j], arrivalTime[mid + 1 + j]);
        strcpy(tempSymptoms[n1 + j], symptoms[mid + 1 + j]);
        tempPriority[n1 + j] = priority[mid + 1 + j];
    }

    int i = 0, j = n1, k = left;

    while (i < n1 && j < n1 + n2) {
        bool condition = false;
        
        if (field == 2) { // Age
            if (tempAge[i] <= tempAge[j]) condition = true;
        } else if (field == 4) { // Arrival Time
            if (strcmp(tempArrival[i], tempArrival[j]) <= 0) condition = true;
        } else if (field == 6) { // Priority (Descending Order: Emergency > Urgent > Normal)
            if (tempPriority[i] >= tempPriority[j]) condition = true;
        }

        if (condition) {
            id[k] = tempID[i];
            strcpy(name[k], tempName[i]);
            age[k] = tempAge[i];
            strcpy(gender[k], tempGender[i]);
            strcpy(arrivalTime[k], tempArrival[i]);
            strcpy(symptoms[k], tempSymptoms[i]);
            priority[k] = tempPriority[i];
            i++;
        } else {
            id[k] = tempID[j];
            strcpy(name[k], tempName[j]);
            age[k] = tempAge[j];
            strcpy(gender[k], tempGender[j]);
            strcpy(arrivalTime[k], tempArrival[j]);
            strcpy(symptoms[k], tempSymptoms[j]);
            priority[k] = tempPriority[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        id[k] = tempID[i];
        strcpy(name[k], tempName[i]);
        age[k] = tempAge[i];
        strcpy(gender[k], tempGender[i]);
        strcpy(arrivalTime[k], tempArrival[i]);
        strcpy(symptoms[k], tempSymptoms[i]);
        priority[k] = tempPriority[i];
        i++;
        k++;
    }

    while (j < n1 + n2) {
        id[k] = tempID[j];
        strcpy(name[k], tempName[j]);
        age[k] = tempAge[j];
        strcpy(gender[k], tempGender[j]);
        strcpy(arrivalTime[k], tempArrival[j]);
        strcpy(symptoms[k], tempSymptoms[j]);
        priority[k] = tempPriority[j];
        j++;
        k++;
    }
}
void mergeSortByField(int left, int right, int field) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortByField(left, mid, field);
        mergeSortByField(mid+1, right, field);
        merge(left, mid, right, field);
    }
}
 // merge sort patient id asc/des
void mergeByID(int left, int mid, int right, bool ascending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int tempID[100];
    char tempName[100][100], tempGender[100][10], tempArrival[100][10], tempSymptoms[100][100];
    int tempAge[100], tempPriority[100];

    for (int i = 0; i < n1; i++) {
        tempID[i] = id[left + i];
        strcpy(tempName[i], name[left + i]);
        tempAge[i] = age[left + i];
        strcpy(tempGender[i], gender[left + i]);
        strcpy(tempArrival[i], arrivalTime[left + i]);
        strcpy(tempSymptoms[i], symptoms[left + i]);
        tempPriority[i] = priority[left + i];
    }
    for (int j = 0; j < n2; j++) {
        tempID[n1 + j] = id[mid + 1 + j];
        strcpy(tempName[n1 + j], name[mid + 1 + j]);
        tempAge[n1 + j] = age[mid + 1 + j];
        strcpy(tempGender[n1 + j], gender[mid + 1 + j]);
        strcpy(tempArrival[n1 + j], arrivalTime[mid + 1 + j]);
        strcpy(tempSymptoms[n1 + j], symptoms[mid + 1 + j]);
        tempPriority[n1 + j] = priority[mid + 1 + j];
    }

    int i = 0, j = n1, k = left;
    while (i < n1 && j < n1 + n2) {
        bool condition = ascending ? tempID[i] <= tempID[j] : tempID[i] > tempID[j];

        if (condition) {
            id[k] = tempID[i];
            strcpy(name[k], tempName[i]);
            age[k] = tempAge[i];
            strcpy(gender[k], tempGender[i]);
            strcpy(arrivalTime[k], tempArrival[i]);
            strcpy(symptoms[k], tempSymptoms[i]);
            priority[k] = tempPriority[i];
            i++;
        } else {
            id[k] = tempID[j];
            strcpy(name[k], tempName[j]);
            age[k] = tempAge[j];
            strcpy(gender[k], tempGender[j]);
            strcpy(arrivalTime[k], tempArrival[j]);
            strcpy(symptoms[k], tempSymptoms[j]);
            priority[k] = tempPriority[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        id[k] = tempID[i];
        strcpy(name[k], tempName[i]);
        age[k] = tempAge[i];
        strcpy(gender[k], tempGender[i]);
        strcpy(arrivalTime[k], tempArrival[i]);
        strcpy(symptoms[k], tempSymptoms[i]);
        priority[k] = tempPriority[i];
        i++;
        k++;
    }

    while (j < n1 + n2) {
        id[k] = tempID[j];
        strcpy(name[k], tempName[j]);
        age[k] = tempAge[j];
        strcpy(gender[k], tempGender[j]);
        strcpy(arrivalTime[k], tempArrival[j]);
        strcpy(symptoms[k], tempSymptoms[j]);
        priority[k] = tempPriority[j];
        j++;
        k++;
    }
}
// merge sort patient id asc/des
void mergeSortByID(int left, int right, bool ascending) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortByID(left, mid, ascending);
        mergeSortByID(mid + 1, right, ascending);
        mergeByID(left, mid, right, ascending);
    }
}
//view patient info
void viewPatient() {
    while (1) {
        system("cls");
        viewLabel(); //Label VIEW
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
            // --- Added submenu for sort options ---
            while (1) {
                system("cls");
                setColor(15);
                cout << "\nSORT OPTIONS:\n";
                cout << "1. Sort by Selection Sort (String fields)\n";
                cout << "2. Sort by Bubble Sort (Numeric fields)\n";
                cout << "0. Back\n";
                cout << "Enter your choice: ";
                char sortChoice;
                cin >> sortChoice;
                cin.ignore();
                if (sortChoice == '0') break;
                if (sortChoice == '1') {
                    // Selection Sort submenu
                    while (1) {
                        system("cls");
                        setColor(15);
                        cout << "\nSELECTION SORT BY FIELD (String fields only):\n";
                        cout << "1. Name\n";
                        cout << "2. Gender\n";
                        cout << "3. Symptoms\n";
                        cout << "4. Arrival Date/Time\n";
                        cout << "0. Back\n";
                        cout << "Enter your choice: ";
                        char selChoice;
                        cin >> selChoice;
                        cin.ignore();
                        if(selChoice == '0') break;
                        if(selChoice == '1') selectionSortStringField(1); // Name
                        else if(selChoice == '2') selectionSortStringField(2); // Gender
                        else if(selChoice == '3') selectionSortStringField(3); // Symptoms
                        else if(selChoice == '4') selectionSortStringField(4); // Arrival
                        setColor(10);
                        cout << "\nSelection Sort completed!\n";
                        setColor(15);
                        displayPatientList();
                        setColor(0); cout << "\nPress [Enter] to return to sort menu..."; system("pause");
                    }
                } else if (sortChoice == '2') {
                    // Bubble Sort submenu
                    while (1) {
                        system("cls");
                        setColor(15);
                        cout << "\nBUBBLE SORT BY FIELD (Numeric fields only):\n";
                        cout << "1. Age\n";
                        cout << "2. Priority\n";
                        cout << "3. ID\n";
                        cout << "0. Back\n";
                        cout << "Enter your choice: ";
                        char bubChoice;
                        cin >> bubChoice;
                        cin.ignore();
                        if (bubChoice == '0') break;
                        if (bubChoice == '1') bubbleSortNumericField(1); // Age
                        else if (bubChoice == '2') bubbleSortNumericField(2); // Priority
                        else if (bubChoice == '3') bubbleSortNumericField(3); // ID
                        setColor(10);
                        cout << "\nBubble Sort completed!\n";
                        setColor(15);
                        displayPatientList();
                        setColor(0); cout << "\nPress [Enter] to return to sort menu..."; system("pause");
                    }
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

//confirmation of user and pass for update page
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
//update patient info
void updatePatient() {
    system("cls");
    //label UPDATE
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
        char opt[7][100] = {"1. Name", "2. Age", "3. Gender", "4. Arrival Time", "5. Symptoms", "6. Priority", "0. Exit"};
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
            system("cls"); upd(); gotoxy(0,12); solidBar(); setColor(15);
            cout << "Current Name: " << p->name << "\nEnter new Name (or press Enter to keep): ";
            char buf[100];
            cin.getline(buf, 100);
            if (strlen(buf) > 0) strcpy(p->name, buf);
        } else if(choice == '2'){
            system("cls"); upd(); gotoxy(0,12); solidBar(); setColor(15);
            cout << "Current Age: " << p->age << "\nEnter new Age (or 0 to keep): ";
            int newAge; cin >> newAge; cin.ignore();
            if (newAge > 0) p->age = newAge;
        } else if(choice == '3'){
            system("cls"); upd(); gotoxy(0,12); solidBar(); setColor(15);
            cout << "Current Gender: " << p->gender << "\nEnter new Gender (M/F or press Enter to keep): ";
            char buf[10];
            cin.getline(buf, 10);
            if (strlen(buf) > 0 && (strcmp(buf, "M") == 0 || strcmp(buf, "F") == 0)) strcpy(p->gender, buf);
        } else if(choice == '4'){
            system("cls"); upd(); gotoxy(0,12); solidBar(); setColor(15);
            cout << "Current Arrival Time: " << p->arrivalTime << "\nEnter new Arrival Time (or press Enter to keep): ";
            char buf[25];
            cin.getline(buf, 25);
            if (strlen(buf) > 0) strcpy(p->arrivalTime, buf);
        } else if(choice == '5'){
            system("cls"); upd(); gotoxy(0,12); solidBar(); setColor(15);
            cout << "Current Symptoms: " << p->symptoms << "\nEnter new Symptoms (or press Enter to keep): ";
            char buf[100];
            cin.getline(buf, 100);
            if (strlen(buf) > 0) strcpy(p->symptoms, buf);
        } else if(choice == '6'){
            system("cls"); upd(); gotoxy(0,12); solidBar(); setColor(15);
            cout << "Current Priority: " << p->priority << "\nEnter new Priority (1-Normal, 2-Urgent, 3-Emergency, 0 to keep): ";
            int newPrio; cin >> newPrio; cin.ignore();
            if (newPrio >= 1 && newPrio <= 3) p->priority = newPrio;
        } else if(choice == '0'){
            break;
        } else {
            setColor(12);
            cout << "\nInvalid Option! Please try again. \nPress [Enter] to proceed....";
            setColor(0); system("pause");
        }
        savePatient();
        setColor(10);
        cout << "\nPatient record updated successfully!\nPress [Enter] to proceed....";
        setColor(0); system("pause");
    }
}

void delPatient() {
    while (1) {
        system("cls");
        delLabel(); //label DELETE
        gotoxy(0,12); solidBar();
        setColor(15);
        int y = 15;
        gotoxy(30, y);
        char opt[3][100] = {
            "1. Delete ALL Patient Information",
            "2. Delete Specific Patient by ID",
            "0. Cancel"
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
            PatientNode* prev = nullptr;
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

// Find patient by ID (returns pointer)
PatientNode* findPatientByID(int searchID) {
    for (PatientNode* p = head; p; p = p->next) {
        if (p->id == searchID) return p;
    }
    return nullptr;
}

// SEARCH RECORDS (linked list)
void searchPatientByField() {
    while (1) {
        system("cls");
        setColor(15);
        cout << "\nSEARCH PATIENT BY FIELD:\n";
        cout << "1. Name\n";
        cout << "2. Age\n";
        cout << "3. Gender\n";
        cout << "4. Symptoms\n";
        cout << "5. Priority\n";
        cout << "0. Back\n";
        cout << "Enter your choice: ";
        char choice;
        cin >> choice;
        cin.ignore();
        if (choice == '0') break;
        bool found = false;
        if (choice == '1') {
            char searchName[100];
            cout << "Enter Name to search: ";
            cin.getline(searchName, 100);
            for (PatientNode* p = head; p; p = p->next) {
                if (strstr(p->name, searchName)) {
                    setColor(10);
                    cout << "\nFound: "; displayFormatID(p->id); cout << " | Name: " << p->name << " | Age: " << p->age << " | Gender: " << p->gender << " | Symptoms: " << p->symptoms << " | Priority: " << p->priority << endl;
                    found = true;
                }
            }
        } else if (choice == '2') {
            int searchAge;
            cout << "Enter Age to search: ";
            cin >> searchAge; cin.ignore();
            for (PatientNode* p = head; p; p = p->next) {
                if (p->age == searchAge) {
                    setColor(10);
                    cout << "\nFound: "; displayFormatID(p->id); cout << " | Name: " << p->name << " | Age: " << p->age << " | Gender: " << p->gender << " | Symptoms: " << p->symptoms << " | Priority: " << p->priority << endl;
                    found = true;
                }
            }
        } else if (choice == '3') {
            char searchGender[10];
            cout << "Enter Gender to search (M/F): ";
            cin.getline(searchGender, 10);
            for (PatientNode* p = head; p; p = p->next) {
                if (strcmp(p->gender, searchGender) == 0) {
                    setColor(10);
                    cout << "\nFound: "; displayFormatID(p->id); cout << " | Name: " << p->name << " | Age: " << p->age << " | Gender: " << p->gender << " | Symptoms: " << p->symptoms << " | Priority: " << p->priority << endl;
                    found = true;
                }
            }
        } else if (choice == '4') {
            char searchSymptoms[100];
            cout << "Enter Symptoms to search: ";
            cin.getline(searchSymptoms, 100);
            for (PatientNode* p = head; p; p = p->next) {
                if (strstr(p->symptoms, searchSymptoms)) {
                    setColor(10);
                    cout << "\nFound: "; displayFormatID(p->id); cout << " | Name: " << p->name << " | Age: " << p->age << " | Gender: " << p->gender << " | Symptoms: " << p->symptoms << " | Priority: " << p->priority << endl;
                    found = true;
                }
            }
        } else if (choice == '5') {
            int searchPriority;
            cout << "Enter Priority to search (1-Normal, 2-Urgent, 3-Emergency): ";
            cin >> searchPriority; cin.ignore();
            for (PatientNode* p = head; p; p = p->next) {
                if (p->priority == searchPriority) {
                    setColor(10);
                    cout << "\nFound: "; displayFormatID(p->id); cout << " | Name: " << p->name << " | Age: " << p->age << " | Gender: " << p->gender << " | Symptoms: " << p->symptoms << " | Priority: " << p->priority << endl;
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
        cout << "\nIllness             : " << p->symptoms;
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
