// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <array>
#include "Console.h"
#include <stdio.h>  
#include <conio.h>
#include <windows.h>  
using namespace std;
namespace con = JadedHoboConsole;

void teclado(){
	if (_kbhit()){
		char tecla = _getch();
	}
}


char mapa[80][200] = {
	"                                                                                                                                                                                                     ",
	" XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	" X                                                                   XaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                                                XXXaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                                               XaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                                             XXaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                                            XaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                 XX                        XXaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                 XfXXX              XXXX  XaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                 XffffXXXX         XXfffXXaaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                 XffffffffXXX      XffffffXaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                 XfffffffffffXX   XXffffffXaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                 XfffffffffffffXXXfffffffffXaaaaaaaaaaaaaaaaaaaaaXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                  XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                   XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                    XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaXXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                    XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                     XffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                      XffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaaXXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaXXggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaXXgggggXXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaXXgggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaXXggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                      XffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaXggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                      XfffffffffffffffffffffffXXXaaaaaaaaaaaaaaXgggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                      XffffffffffffffffffffffffffXaaaaaaaaaaaaaXggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                      XffffffffffffffffffffffffffXaaaaaaaaaaaaaXXgggggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                      XfffffffffffffffffffffffffffXaaaaaaaaaaaaaXXgggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                      XfffffffffffffffffffffffXXXXiXaaaaaaaaaaaaaXgggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                      XffffffffffffffffffffffXiiiiiXXaaaaaaaaaaaaXggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                      XfffffffffffffffffffffXiiiiiiiXaaaaaaaaaaaaXgggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                     XfffffffffffffffffffffXXiiiiiiiiXaaaaaaaaaaaXgggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                     XffffffffffffffffffffXXiiiiiiiiiXXaaaaaaaaaaXggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X                                     XfffffffffffffffffffXXiiiiiiiiiiiXXaaaaaaaaaXgggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X          X XXX                      XfffffffffffffffffffXiiiiiiiiiiiiiXXaaaaaaaaXggggggggggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X         XsXsssXXXX                 XffffffffffffffffffffXiiiiiiiiiiiiiiiXXXXXXXXgggggggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X         XsssssssssXXXXX            XffffffffffffffffffffXiiiiiiiiiiiiiiiiiiiiiiiXXXggggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                        X",
	" X        XsssssssssssssssXXX        XffffffffffffffffffffXXiiiiiiiiiiiiiiiiiiiiiiiiiXXggggXXXXggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrXXXXXX                                        X",
	" X       XssssssssssssssssssXXXX    XXXffffffffffffffffffXXiiiiiiiiiiiiiiiiiiiiiiiiiiiXXXXX    XXggggggggggggXrrrrrrrrrrrXXXXXXXXXrrrrrrrrrrrrrrrrrrrXX    X                                        X",
	" X       XXXXsssssssssssssssssssXXXXsssXXfffffffffffffffXXiiiiiXXiiiiiiiiiiiiiiiiiiiiXXX         XXgggggggggggXXXXXXXXXXXggggggggXXrrrrrrrrrrrrrrXXXXX     X                                        X",
	" X       XppXXXsssssssssssssssssssssssssXXffffffffffffffXiiiXXX XiiiiiiiiiiiiiiiiiiXX              XgggggggggggggggggggggggggggggggXXrrrrrrrrrXXX          X                                        X",
	" X        XppppXsssssssssssssssssssssssssXXfffffffffffffXXXX     XXiiiiiiiiiiiiiiiiX               XggggggggggggggggggggggggggggggggXXXXXXrrrXX            X                                        X",
	" X        XppppXssssssssssssssssssssssssssXXffffffXXXXXX           XXiiiiiiiiiiiiiX                XgggggggggggggggggggggggggggggggggggggXXXXX             X                                        X",
	" X        XpppXXsssssssssssssssssssssssssssXXXXXXX                   XiiiiiiiiiiiX                 XggggggggggggggggggggggXXXgggggggggggggggX              X                                        X",
	" X        XpppXssssssssssssssssssssssssssssssssX                      XiiiiiiiiiXX                 XggggggggggggggggggggXXX  XXXgggggggggggX               X                                        X",
	" X       XpppXssssssssssssssssssssssssssssssssX              XX       XiiiiiiiiiX                 XggggggggggggggggggggXX       XXXXggggggX                X                                        X",
	" X       XpppXssssssssssssssssssssssssssssssssX             XXXX      XiiiiiiiiX                  XggggggggggggggggggggX            XXXXXX                 X                                        X",
	" X       XpppXsssssssssssssssssssssssssssssssX              XiiX     XiiiiiiiiXX                  XggggggggggggggggggggX                                   X                                        X",
	" X       XpppXsssssssssssssssssssssssssssssssX              XiX      XiiiiiiiX                    XggggggggggggggggggggX                                   X                                        X",
	" X       XpppXssssssssssssssssssssssssssssssX               XXX      XiiiiiiiX                    XggggggggggggggggggggX                                   X                                        X",
	" X       XppppXsssssssssssssssssssssssssssssX               XX       XiiiiiiX                    XgggggggggggggggggggggX                                   X                                        X",
	" X      XpppppXsssssssssssssssssssssssssXXXX                        XiiiiiiX                     XgggggggggggggggggggggX                                   X                                        X",
	" X      XpppppXsssssssssssssssssssssXXXX                 XXX        XiiiiiiX                     XggggggggggggggggggggggXX                                 X                                        X",
	" X      XpppppXsssssssssssssssssssssX          XX       XXiX        XiiiiiX                      XgggggggggggggggggggggggX                                 X                                        X",
	" X     XppppppXssssssssssssssssssssX          XX        XiiX        XiiiiiX                     XgggggggggggggggggggggggggXX                               X                                        X",
	" X    XpppppppXssssssssssssssssssssX     XXXX          XXiiX       XiiiiiiX                     XgggggggggggggggggggggggggggX                              X                                        X",
	" X   XppppppppXssssssssssssssssssssX     XssX          XiiiX       XiiiiiX                     XgggggggggggggggggggggggggggggX                             X                                        X",
	" X   XpppppppXssssssssssssssssssssX      XXXX          XiiiX       XiiiiiX                    XgggggggggggggggggggggggggggggX                              X                                        X",
	" X    XXpppppXsssssssssssssssssssXX                   XXiiiX      XiiiiiiX                    XXggggggggggggggggXggggggggggX X         XXXXXX            XXX                                        X",
	" X   XXpppppXXssssssssssssssssssX      XX             XXiiX       XiiiiiiX                      XXggggggggggggXXXggggggggXX    X      XXggggXX        XXXttX                                        X",
	" X   XXppppXXsssssssssssssssssssX       X              XXXX      XiiiiiiX                         XXgggggggggX  XggggggXX       XXXXXXXggggggXXXXXXXXXtttttX                                        X",
	" X     XXpXXsssssssssssssssssssX       X                        XiiiiiiiX                           XXgggggXX   XgggggX         XggggggggggggXXttttttttttttX                                        X",
	" X       XXsssssssssssssssssssX                                 XiiiiiiiX                             XXggX     XgggXX          XggggggggggggXtttttttttttttX                                        X",
	" X         XXsssssssssssssssssX                                XiiiiiiiX                                XX      XgggX           XXggggggggggXXtttttttttttttX                                        X",
	" X          XsssssssXXXXXXXXXX                                XiiiiiiiiX                                         XgX             XgggggggggXXttttttttttttttX                                        X",
	" X           XssssXX                                          XiiiiiiiiX                                         XgX             XgggggggggXtttttttttttttttX                                        X",
	" X            XsXX                                         XXXiiiiiiiiiiX                                        XggX            XgggggggggXtttttttttttttttX                                        X",
	" X            XX                                       XXXXiiiiiiiiiiiiiX                                     XXXXgggXX          XggggggggXttttttttttttttttX                                        X",
	" X                                                   XXiiiiiiiiiiiiiXiiiX                             XXX  XXXggggggggX          XggggggggXttttttttttttttttX                                        X",
	" X                                                    XXXXXXiiiiiiXX XiX                             XgggXXgggggggggggX         XXggggggggXttttttttttttttttX                                        X",
	" X                                                          XXXXXX    X                              XggggggggggggggggX         XgggggggggXttttttttttttttttX                                        X",
	" X                                                                                                  XXggggggggggggggggX        XXgggggggggXttttttttttttttttX                                        X",
	" X                                                                                                  XgggggggggggggggggX        XggggggggggXttttttttttttttttX                                        X",
	" X                                                                                                  XgggggggggggggggXX         XgggggggggXXttttttttttttttttX                                        X",
	" X                                                                                                  XgggggggggggggXX           XXggggggggXtttttttttttttttttX                                        X",
	" X                                                                                                   XggggggggggggX             XXXgggggXXtttttttttttttttttX                                        X",
	" X                                                                                                   XXggggggggggX                 XXXXXXttttttttttttttttttX                                        X",
	" X                                                                                                    XXgggggggggX                      XXtttttttttttttttttX                                        X",
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
	string nom;
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
	
	void print(){
		for (int i = 0; i <= 79; i++){
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
				switch (mapa[i][j])
				{
				case 'X':
					cout << con::bg_gray << ' ';
					break;
				case 's':
					cout << con::bg_yellow  << ' ';
					break;
				case 'p':
					cout << con::bg_cyan << ' ';
					break;
				case 'f':
					cout << con::bg_blue << ' ';
					break;
				case 'i':
					cout << con::bg_red << ' ';
					break;
				case 'a':
					cout << con::bg_black  << ' ';
					break;
				case 'r':
					cout << con::bg_white << ' ';
					break;
				case 'g':
					cout << con::bg_magenta << ' ';
					break;
				case 't':
					cout << con::bg_green << ' ';
					break;
				default:
					cout << con::bg_black << ' ';
					break;

				}
				//cout << con::bg_black << con::fg_white << mapa[i][j];
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

	void iniciaTerritoris(){
		Territoris s;
		s.nom = "Espanya";
		s.castell = true;
		s.exPresent = true;
		s.idPropietari = 1;
		s.posX_Ex1 = 28;
		s.posY_Ex1 = 50;
		s.posX_Ex2 = 40;
		s.posY_Ex2 = 50;

		Territoris p;
		s.nom = "Portugal";
		s.castell = false;
		s.exPresent = true;
		s.idPropietari = 2;
		s.posX_Ex1 = 18;
		s.posY_Ex1 = 55;
		s.posX_Ex2 = 25;
		s.posY_Ex2 = 55;

		Territoris f;
		s.nom = "França";
		s.castell = true;
		s.exPresent = true;
		s.idPropietari = 3;
		s.posX_Ex1 = 50;
		s.posY_Ex1 = 20;
		s.posX_Ex2 = 58;
		s.posY_Ex2 = 20;

		Territoris i;
		s.nom = "Italia";
		s.castell = false;
		s.exPresent = true;
		s.idPropietari = 4;
		s.posX_Ex1 = 72;
		s.posY_Ex1 = 40;
		s.posX_Ex2 = 78;
		s.posY_Ex2 = 40;

		Territoris a;
		s.nom = "Alemania";
		s.castell = true;
		s.exPresent = true;
		s.idPropietari = 5;
		s.posX_Ex1 = 100;
		s.posY_Ex1 = 15;
		s.posX_Ex2 = 109;
		s.posY_Ex2 = 15;

		Territoris r;
		s.nom = "Russia";
		s.castell = true;
		s.exPresent = true;
		s.idPropietari = 6;
		s.posX_Ex1 = 128;
		s.posY_Ex1 = 15;
		s.posX_Ex2 = 135;
		s.posY_Ex2 = 15;

		Territoris g;
		s.nom = "Grecia";
		s.castell = true;
		s.exPresent = true;
		s.idPropietari = 7;
		s.posX_Ex1 = 118;
		s.posY_Ex1 = 40;
		s.posX_Ex2 = 125;
		s.posY_Ex2 = 40;

		Territoris t;
		s.nom = "Turquia";
		s.castell = false;
		s.exPresent = true;
		s.idPropietari = 8;
		s.posX_Ex1 = 145;
		s.posY_Ex1 = 60;
		s.posX_Ex2 = 150;
		s.posY_Ex2 = 60;

		territoris.push_back(s);
		territoris.push_back(p);
		territoris.push_back(f);
		territoris.push_back(i);
		territoris.push_back(a);
		territoris.push_back(r);
		territoris.push_back(g);
		territoris.push_back(t);

	}

};

class Factions{
private:
	int or, ingressos, gastos, id;
	bool player, viva;
	string nom;
	list<Territoris> territoris;
	list<Territoris>::iterator it;
	Territoris capital;
public:
	string getNom();
	void setNom();
	int getId();
	void setId();

};

int _tmain(int argc, _TCHAR* argv[])
{

	Mapa a(mapa);
	a.iniciaTerritoris();
	a.print();
	system("pause>>NULL");
	return 0;
}