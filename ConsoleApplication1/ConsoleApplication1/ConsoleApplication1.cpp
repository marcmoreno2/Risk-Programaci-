// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <array>
#include "Console.h"
#include <stdio.h>  
#include <windows.h>  
using namespace std;
namespace con = JadedHoboConsole;

char mapa[80][200] = {
	"                                                                                                                                                                                                     ",
	" XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	" X                                                                   X              X                                                                      X                                        X",
	" X                                                                XXX               X                                                                      X                                        X",
	" X                                                               X                  X                                                                      X                                        X",
	" X                                                             XX                   X                                                                      X                                        X",
	" X                                                            X                    X                                                                       X                                        X",
	" X                                 XX                        XX                    X                                                                       X                                        X",
	" X                                 X XXX              XXXX  X                      X                                                                       X                                        X",
	" X                                 X    XXXX         XX   XX                       X                                                                       X                                        X",
	" X                                 X        XXX      X      X                      X                                                                       X                                        X",
	" X                                 X           XX   XX      X                      X                                                                       X                                        X",
	" X                                 X             XXX         X                     XX                                                                      X                                        X",
	" X                                  X                         X                     X                                                                      X                                        X",
	" X                                   X                         X                     X                                                                     X                                        X",
	" X                                    X                         X                    XXX                                                                   X                                        X",
	" X                                    X                         X                      XX                                                                  X                                        X",
	" X                                     X                        X                       X                                                                  X                                        X",
	" X                                      X                      X                       XXX                                                                 X                                        X",
	" X                                       X                     X                      XX  XX                                                               X                                        X",
	" X                                       X                     X                     XX     XXX                                                            X                                        X",
	" X                                       X                     X                    XX         X                                                           X                                        X",
	" X                                       X                     X                  XX            XX                                                         X                                        X",
	" X                                      X                      X                  X              X                                                         X                                        X",
	" X                                      X                       XXXXXXX          X               X                                                         X                                        X",
	" X                                      X                       X     XX         X                X                                                        X                                        X",
	" X                                      X                      X        X        XX               XX                                                       X                                        X",
	" X                                      X                      X        X         XX               X                                                       X                                        X",
	" X                                      X                      X        X          X               X                                                       X                                        X",
	" X                                      X                      X XXXXX  X          X                X                                                      X                                        X",
	" X                                      X                     XXX     XXX          X                 X                                                     X                                        X",
	" X                                     X                     XX        X           X                 X                                                     X                                        X",
	" X                                     X                    XX         XX          X                  X                                                    X                                        X",
	" X                                     X                   XX           XX         X                   X                                                   X                                        X",
	" X          X XXX                      X                   X             XX        X                    XX                                                 X                                        X",
	" X         X X   XXXX                 X                    X               XXXXXXXX                       X                                                X                                        X",
	" X         X         XXXXX            X                    X                       XXX                    X                                                X                                        X",
	" X        X               XXX        X                    XX                         XX    XXXX            XX                                         XXXXXX                                        X",
	" X       X                  XXXX    XXX                  XX                           XXXXX    XX            X           XXXXXXXXX                   XX    X                                        X",
	" X       XXXX                   XXXX   XX               XX     XX                    XXX         XX           XXXXXXXXXXX        XX              XXXXX     X                                        X",
	" X       X  XXX                         XX              X   XXX X                  XX              X                               XX         XXX          X                                        X",
	" X        X    X                         XX             XXXX     XX                X               X                                XXXXXX   XX            X                                        X",
	" X        X    X                          XX      XXXXXX           XX             X                X                                     XXXXX             X                                        X",
	" X        X   XX                           XXXXXXX                   X           X                 X                      XXX               X              X                                        X",
	" X        X   X                                X                      X         XX                 X                    XXX  XXX           X               X                                        X",
	" X       X   X                                X                       X         X                 X                    XX       XXXX      X                X                                        X",
	" X       X   X                                X                       X        X                  X                    X            XXXXXX                 X                                        X",
	" X       X   X                               X                       X        XX                  X                    X                                   X                                        X",
	" X       X   X                               X                       X       X                    X                    X                                   X                                        X",
	" X       X   X                              X                        X       X                    X                    X                                   X                                        X",
	" X       X    X                             X                        X      X                    X                     X                                   X                                        X",
	" X      X     X                         XXXX                        X      X                     X                     X                                   X                                        X",
	" X      X     X                     XXXX                            X      X                     X                      XX                                 X                                        X",
	" X      X     X                     X                               X     X                      X                       X                                 X                                        X",
	" X     X      X                    X                                X     X                     X                         XX                               X                                        X",
	" X    X       X                    X                               X      X                     X                           X                              X                                        X",
	" X   X        X                    X                               X     X                     X                             X                             X                                        X",
	" X   X       X                    X                                X     X                    X                             X                              X                                        X",
	" X    XX     X                   XX                               X      X                    XX                X          X X         XXXXXX            XXX                                        X",
	" X   XX     XX                  X                                 X      X                      XX            XXX        XX    X      XX    XX        XXX  X                                        X",
	" X   XX    XX                   X                                X      X                         XX         X  X      XX       XXXXXXX      XXXXXXXXX     X                                        X",
	" X     XX XX                   X                                X       X                           XX     XX   X     X         X            XX            X                                        X",
	" X       XX                   X                                 X       X                             XX  X     X   XX          X            X             X                                        X",
	" X         XX                 X                                X       X                                XX      X   X           XX          XX             X                                        X",
	" X          X       XXXXXXXXXX                                X        X                                         X X             X         XX              X                                        X",
	" X           X    XX                                          X        X                                         X X             X         X               X                                        X",
	" X            X XX                                         XXX          X                                        X  X            X         X               X                                        X",
	" X            XX                                       XXXX             X                                     XX X   XX          X        X                X                                        X",
	" X                                                   XX             X   X                             XXX  XXX        X          X        X                X                                        X",
	" X                                                    XXXXXX      XX X X                             X   XX           X         XX        X                X                                        X",
	" X                                                          XXXXXX    X                              X                X         X         X                X                                        X",
	" X                                                                                                  XX                X        XX         X                X                                        X",
	" X                                                                                                  X                 X        X          X                X                                        X",
	" X                                                                                                  X               XX         X         XX                X                                        X",
	" X                                                                                                  X             XX           XX        X                 X                                        X",
	" X                                                                                                   X            X             XXX     XX                 X                                        X",
	" X                                                                                                   XX          X                 XXXXXX                  X                                        X",
	" X                                                                                                    XX         X                      XX                 X                                        X",
	" XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	"                                                                                                                                                                                                     "
};

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

struct Territoris{
	string nom, propietari;
	int posX_Ex1, posY_Ex1, posX_Ex2, posY_Ex2;
	int idPropietari;
	bool exPresent, castell;
};

class Mapa {
private:
	char mapa[80][200];
	list<Territoris> territoris;
	list<Territoris>::iterator it;
public:
	
	/*void initializeMap(){
	
		mapa[130][200] = {
			"                                                                                                                                                                                                       ",
			" XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ",
			"                                                                                                                                                                                                       "
		};

	}*/
	void print(){
		for (int i = 0; i <= 78; i++){
			for (int j = 0; j <= 200; j++){
				/*if (i == 0 || i == 80)
				{
					cout << ' ';
				}
				else if (j == 1 || j == 199)
				{
					cout << con::fg_red << 'X';
				}
				else if ((i == 1 || i == 79) && j != 0 && j!= 200)
				{
					cout << con::fg_red << 'X';
				}
				else cout << ' ';*/
				/*switch (mapa[i][j])
				{
				case 'X':
					cout << con::fg_yellow << 'X';
					break;
				default:
					cout << con::fg_white << ' ';
					break;

				}*/
				cout << con::bg_black << con::fg_white << mapa[i][j];
			}
			cout << endl;
		}
	}
	Mapa(char m[][200])
	{
		int cb = sizeof(char)* 80 * 200;
		memcpy(mapa, m, cb);
	};
	~Mapa(){};

};

int _tmain(int argc, _TCHAR* argv[])
{

	Mapa a(mapa);
	//a.initialiseMap();
	a.print();
	system("pause>>NULL");
	return 0;
}