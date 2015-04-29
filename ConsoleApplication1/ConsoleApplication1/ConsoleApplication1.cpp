// ConsoleApplication1.cpp: define el punto de entrada de la aplicaci�n de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>
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


char mapa[80][210] = {
	"                                                                                                                                                                                                                 ",
	" XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	" X                                                                   XaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                                                XXXaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                                               XaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                                             XXaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                                            XaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                 XX                        XXaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                 XfXXX              XXXX  XaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                 XffffXXXX         XXfffXXaaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                 XffffffffXXX      XffffffXaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                 XfffffffffffXX   XXffffffXaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                 XfffffffffffffXXXfffffffffXaaaaaaaaaaaaaaaaaaaaaXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                  XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                   XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                    XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaXXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                    XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                     XffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                      XffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaaXXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaXXggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaXXgggggXXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaXXgggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaXXggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                      XffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaXggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                      XfffffffffffffffffffffffXXXaaaaaaaaaaaaaaXgggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                      XffffffffffffffffffffffffffXaaaaaaaaaaaaaXggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                      XffffffffffffffffffffffffffXaaaaaaaaaaaaaXXgggggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                      XfffffffffffffffffffffffffffXaaaaaaaaaaaaaXXgggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                      XfffffffffffffffffffffffXXXXiXaaaaaaaaaaaaaXgggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                      XffffffffffffffffffffffXiiiiiXXaaaaaaaaaaaaXggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                      XfffffffffffffffffffffXiiiiiiiXaaaaaaaaaaaaXgggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                     XfffffffffffffffffffffXXiiiiiiiiXaaaaaaaaaaaXgggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                     XffffffffffffffffffffXXiiiiiiiiiXXaaaaaaaaaaXggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X                                     XfffffffffffffffffffXXiiiiiiiiiiiXXaaaaaaaaaXgggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X          X XXX                      XfffffffffffffffffffXiiiiiiiiiiiiiXXaaaaaaaaXggggggggggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X         XsXsssXXXX                 XffffffffffffffffffffXiiiiiiiiiiiiiiiXXXXXXXXgggggggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X         XsssssssssXXXXX            XffffffffffffffffffffXiiiiiiiiiiiiiiiiiiiiiiiXXXggggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	" X        XsssssssssssssssXXX        XffffffffffffffffffffXXiiiiiiiiiiiiiiiiiiiiiiiiiXXggggXXXXggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrXXXXXX                                                    X",
	" X       XssssssssssssssssssXXXX    XXXffffffffffffffffffXXiiiiiiiiiiiiiiiiiiiiiiiiiiiXXXXX    XXggggggggggggXrrrrrrrrrrrXXXXXXXXXrrrrrrrrrrrrrrrrrrrXX    X                                                    X",
	" X       XXXXsssssssssssssssssssXXXXsssXXfffffffffffffffXXiiiiiXXiiiiiiiiiiiiiiiiiiiiXXX         XXgggggggggggXXXXXXXXXXXggggggggXXrrrrrrrrrrrrrrXXXXX     X                                                    X",
	" X       XppXXXsssssssssssssssssssssssssXXffffffffffffffXiiiXXX XiiiiiiiiiiiiiiiiiiXX              XgggggggggggggggggggggggggggggggXXrrrrrrrrrXXX          X                                                    X",
	" X        XppppXsssssssssssssssssssssssssXXfffffffffffffXXXX     XXiiiiiiiiiiiiiiiiX               XggggggggggggggggggggggggggggggggXXXXXXrrrXX            X                                                    X",
	" X        XppppXssssssssssssssssssssssssssXXffffffXXXXXX           XXiiiiiiiiiiiiiX                XgggggggggggggggggggggggggggggggggggggXXXXX             X                                                    X",
	" X        XpppXXsssssssssssssssssssssssssssXXXXXXX                   XiiiiiiiiiiiX                 XggggggggggggggggggggggXXXgggggggggggggggX              X                                                    X",
	" X        XpppXssssssssssssssssssssssssssssssssX                      XiiiiiiiiiXX                 XggggggggggggggggggggXXX  XXXgggggggggggX               X                                                    X",
	" X       XpppXssssssssssssssssssssssssssssssssX              XX       XiiiiiiiiiX                 XggggggggggggggggggggXX       XXXXggggggX                X                                                    X",
	" X       XpppXssssssssssssssssssssssssssssssssX             XXXX      XiiiiiiiiX                  XggggggggggggggggggggX            XXXXXX                 X                                                    X",
	" X       XpppXsssssssssssssssssssssssssssssssX              XiiX     XiiiiiiiiXX                  XggggggggggggggggggggX                                   X                                                    X",
	" X       XpppXsssssssssssssssssssssssssssssssX              XiX      XiiiiiiiX                    XggggggggggggggggggggX                                   X                                                    X",
	" X       XpppXssssssssssssssssssssssssssssssX               XXX      XiiiiiiiX                    XggggggggggggggggggggX                                   X                                                    X",
	" X       XppppXsssssssssssssssssssssssssssssX               XX       XiiiiiiX                    XgggggggggggggggggggggX                                   X                                                    X",
	" X      XpppppXsssssssssssssssssssssssssXXXX                        XiiiiiiX                     XgggggggggggggggggggggX                                   X                                                    X",
	" X      XpppppXsssssssssssssssssssssXXXX                 XXX        XiiiiiiX                     XggggggggggggggggggggggXX                                 X                                                    X",
	" X      XpppppXsssssssssssssssssssssX          XX       XXiX        XiiiiiX                      XgggggggggggggggggggggggX                                 X                                                    X",
	" X     XppppppXssssssssssssssssssssX          XX        XiiX        XiiiiiX                     XgggggggggggggggggggggggggXX                               X                                                    X",
	" X    XpppppppXssssssssssssssssssssX      XX           XXiiX       XiiiiiiX                     XgggggggggggggggggggggggggggX                              X                                                    X",
	" X   XppppppppXssssssssssssssssssssX     XssX          XiiiX       XiiiiiX                     XgggggggggggggggggggggggggggggX                             X                                                    X",
	" X   XpppppppXssssssssssssssssssssX       XX           XiiiX       XiiiiiX                    XgggggggggggggggggggggggggggggX                              X                                                    X",
	" X    XXpppppXsssssssssssssssssssXX                   XXiiiX      XiiiiiiX                    XXggggggggggggggggXggggggggggX X         XXXXXX            XXX                                                    X",
	" X   XppppppXXssssssssssssssssssX      XX             XXiiX       XiiiiiiX                      XXggggggggggggXXXggggggggXX    X      XXggggXX        XXXttX                                                    X",
	" X   XXppppXXsssssssssssssssssssX       X              XXXX      XiiiiiiX                         XXgggggggggX  XggggggXX       XXXXXXXggggggXXXXXXXXXtttttX                                                    X",
	" X     XXpXXsssssssssssssssssssX       X                        XiiiiiiiX                           XXgggggXX   XgggggX         XggggggggggggXXttttttttttttX                                                    X",
	" X       XXsssssssssssssssssssX                                 XiiiiiiiX                             XXggX     XgggXX          XggggggggggggXtttttttttttttX                                                    X",
	" X         XXsssssssssssssssssX                                XiiiiiiiX                                XX      XgggX           XXggggggggggXXtttttttttttttX                                                    X",
	" X          XsssssssXXXXXXXXXX                                XiiiiiiiiX                                         XgX             XgggggggggXXttttttttttttttX                                                    X",
	" X           XssssXX                                          XiiiiiiiiX                                         XgX             XgggggggggXtttttttttttttttX                                                    X",
	" X            XsXX                                         XXXiiiiiiiiiiX                                        XggX            XgggggggggXtttttttttttttttX                                                    X",
	" X            XX                                       XXXXiiiiiiiiiiiiiX                                     XXXXgggXX          XggggggggXttttttttttttttttX                                                    X",
	" X                                                   XXiiiiiiiiiiiiiXiiiX                             XXX  XXXggggggggX          XggggggggXttttttttttttttttX                                                    X",
	" X                                                    XXXXXXiiiiiiXX XiX                             XgggXXgggggggggggX         XXggggggggXttttttttttttttttX                                                    X",
	" X                                                          XXXXXX    X                              XggggggggggggggggX         XgggggggggXttttttttttttttttX                                                    X",
	" X                                                                                                  XXggggggggggggggggX        XXgggggggggXttttttttttttttttX                                                    X",
	" X                                                                                                  XgggggggggggggggggX        XggggggggggXttttttttttttttttX                                                    X",
	" X                                                                                                  XgggggggggggggggXX         XgggggggggXXttttttttttttttttX                                                    X",
	" X                                                                                                  XgggggggggggggXX           XXggggggggXtttttttttttttttttX                                                    X",
	" X                                                                                                   XggggggggggggX             XXXgggggXXtttttttttttttttttX                                                    X",
	" X                                                                                                   XXggggggggggX                 XXXXXXttttttttttttttttttX                                                    X",
	" X                                                                                                    XXgggggggggX                      XXtttttttttttttttttX                                                    X",
	" XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	"                                                                                                                                                                                                                 "
};

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void printInterface()
{
	int posy = 5;
	for (int i = 0; i < 10; i++){ gotoxy(158, posy); cout << con::fg_white << con::bg_black << "Interfaz placeholder: XXXXX"; posy++; posy++; }
}

struct Territoris{
	string nom;
	int posX_Ex1, posY_Ex1, posX_Ex2, posY_Ex2, id;
	int idPropietari;
	bool exPresent, castell;
};

class Mapa {
private:
	char mapa[80][210];
	list<Territoris> territoris;
	list<Territoris>::iterator itt;
public:
	
	void print(){
		for (int i = 0; i < 80; i++){
			for (int j = 0; j < 210; j++){
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
	Mapa(char m[][210])
	{
		int cb = sizeof(char)* 80 * 210;
		memcpy(mapa, m, cb);
	}
	~Mapa(){}

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
		p.nom = "Portugal";
		p.castell = false;
		p.exPresent = true;
		p.idPropietari = 2;
		p.posX_Ex1 = 18;
		p.posY_Ex1 = 55;
		p.posX_Ex2 = 25;
		p.posY_Ex2 = 55;

		Territoris f;
		f.nom = "Fran�a";
		f.castell = true;
		f.exPresent = true;
		f.idPropietari = 3;
		f.posX_Ex1 = 50;
		f.posY_Ex1 = 20;
		f.posX_Ex2 = 58;
		f.posY_Ex2 = 20;

		Territoris i;
		i.nom = "Italia";
		i.castell = false;
		i.exPresent = true;
		i.idPropietari = 4;
		i.posX_Ex1 = 72;
		i.posY_Ex1 = 40;
		i.posX_Ex2 = 78;
		i.posY_Ex2 = 40;

		Territoris a;
		a.nom = "Alemania";
		a.castell = true;
		a.exPresent = true;
		a.idPropietari = 5;
		a.posX_Ex1 = 100;
		a.posY_Ex1 = 15;
		a.posX_Ex2 = 109;
		a.posY_Ex2 = 15;

		Territoris r;
		r.nom = "Russia";
		r.castell = true;
		r.exPresent = true;
		r.idPropietari = 6;
		r.posX_Ex1 = 128;
		r.posY_Ex1 = 15;
		r.posX_Ex2 = 135;
		r.posY_Ex2 = 15;

		Territoris g;
		g.nom = "Grecia";
		g.castell = true;
		g.exPresent = true;
		g.idPropietari = 7;
		g.posX_Ex1 = 118;
		g.posY_Ex1 = 40;
		g.posX_Ex2 = 125;
		g.posY_Ex2 = 40;

		Territoris t;
		t.nom = "Turquia";
		t.castell = false;
		t.exPresent = true;
		t.idPropietari = 8;
		t.posX_Ex1 = 145;
		t.posY_Ex1 = 60;
		t.posX_Ex2 = 150;
		t.posY_Ex2 = 60;

		territoris.push_back(s);
		territoris.push_back(p);
		territoris.push_back(f);
		territoris.push_back(i);
		territoris.push_back(a);
		territoris.push_back(r);
		territoris.push_back(g);
		territoris.push_back(t);

	}
	void update()
	{
		for ()
	}
	void pintaNoms()
	{
		for (itt = territoris.begin(); itt != territoris.end(); itt++)
		{
			if (itt->exPresent){
				gotoxy(itt->posX_Ex1, itt->posY_Ex1);
				cout << con::bg_green << ' ';
			}
			cout << con::fg_white << itt->nom << endl;
		}
	}
};

struct Unitats{
	int def, atack, exp, lvl, costRec, costMan;
	int bonusVsCav, bonusVsInf, bonusVsSpear, bonusVsArq, bonusVsBuild;
	string nom;
};

struct General :Unitats{
	int comandament;
};

struct Arquer :Unitats{
	static const int def = 10, atack = 25, costRec = 50, costMan = 15, bonusVsCav = 10, bonusVsInf = 0, bonusVsSpear = 15, bonusVsArq = 10, bonusVsBuild = 15;
};

class Excercit{
private:
	int territoriActual, mantenimentEx;
	list<Unitats>units;
	list<Unitats>::iterator itu;
	General general;
	float bonus;
	int totalUnits, idPropietari, id;
	bool movimentD = true;
	float fTotal, dTotal;
public:
	void calculaManteniment()
	{
		for (itu = units.begin(); itu != units.end(); itu++)
		{
			if (itu->)
		}
	}
	int getId()
	{
		return id;
	}
	int getTerritoriAct()
	{
		return territoriActual;
	}
	void setTerritoriAct(int idT)
	{
		territoriActual = idT;
	}
	void setGeneral(General g)
	{
		general = g;
	}
	General getGeneral()
	{
		return general;
	}
	list<Unitats> getUnitats()
	{
		return units;
	}
	void setUnitats(list<Unitats> u)
	{
		units = u;
	}
	void moure(int idDe)
	{
		int posTid[4];
		//posTid.fill(NULL);
		//bool ok = posTid.empty();
		//cout << endl << ok << endl;

		switch (territoriActual)
		{
		case 1:
			posTid[0] = 2;
			break;
		case 2:
			posTid[0] = 1;
			posTid[1] = 3;
			break;
		case 3:
			posTid[0] = 2;
			posTid[1] = 4;
			posTid[2] = 5;
			break;
		case 4:
			posTid[0] = 3;
			posTid[1] = 5;
			posTid[2] = 6;
			break;
		case 5:
			posTid[0] = 3;
			posTid[1] = 4;
			posTid[2] = 6;
			posTid[3] = 7;
			break;
		case 6:
			posTid[0] = 4;
			posTid[1] = 5;
			posTid[2] = 7;
			posTid[3] = 8;
			break;
		case 7:
			posTid[0] = 5;
			posTid[1] = 6;
			break;
		case 8:
			posTid[0] = 6;
			break;
		}
		bool act1 = false, corr = false;
		for (int i = 0; i < 4; i++)
		{
			if (idDe == territoriActual)
				act1 = true;
			else if (idDe == posTid[i])
				corr = true;
		}
		if (act1)
		{
			gotoxy(158, 25); cout << con::fg_red << "L'excercit ja es troba al territori objectiu";
		}
		else if (corr)
		{
			if (movimentD)
			{
				gotoxy(158, 25); cout << con::fg_green << "L'excercit es mou al territori objectiu";
				territoriActual = idDe;
				movimentD = false;
			}
			else
			{
				gotoxy(158, 25); cout << con::fg_red << "Aquest excercit ja s'ha mogut aquest torn";
			}
		}
		else if (!movimentD){ gotoxy(158, 25); cout << con::fg_red << "Aquest excercit ja s'ha mogut aquest torn"; }
		else { gotoxy(158, 25); cout << con::fg_red << "L'excercit no es pot moure al territori desitjat,";
		gotoxy(158, 26); cout << "el territori de desti ha d'estar en contacte";
		gotoxy(158, 27); cout << "directe amb el d'origen";
		}

		system("Pause>>NULL");
		gotoxy(158, 25); cout << con::fg_red << "                                                 ";
		gotoxy(158, 26); cout << "                                                 ";
		gotoxy(158, 27); cout << "                                  ";
		/*cout << endl;
		for (int elem : posTid)
			cout << elem << endl;*/
	}
	void afegirUnitat(Unitats u)
	{
		units.push_back(u);
	}
	void mostrarUnits()
	{
		gotoxy(158, 25);
		cout << con::fg_cyan << "Unitats de l'excercit " << id << ":";
		int i = 0;
		for (itu = units.begin(); itu != units.end(); itu++)
		{
			gotoxy(158, 26 + i);
			i++;
			cout << itu->nom;
		}
	}
	void desbandar(){}
	void calculaBonusDef(){}
	void calculaBonusOff(){}
	bool atacar(Excercit e){}
	void update(){}
	Excercit(){}
	Excercit(int terAct, General gen, list<Unitats>uni, int ide)
	{
		territoriActual = terAct;
		general = gen;
		units = uni;
		id = ide;
	}
	~Excercit(){}
};

class Faction{
private:
	int or, ingressos, gastos, id;
	bool player, viva;
	list <Excercit> excercits;
	list <Excercit>::iterator ite;
	string nom;
	int no_ter;
	int territoris[12];
	int id_capital;
public:
	list<Excercit>::iterator getIterEx(int idEx)
	{
		for (ite = excercits.begin(); ite != excercits.end(); ite++)
		{
			if (ite->getId() == idEx)
				break;
		}
		return ite;
	}
	void setExcercit(Excercit e)
	{
		/*for (ite = excercits.begin(); ite != excercits.end(); ite++)
		{
			if (ite->getId() == e.getId())
			{
				excercits.erase(ite);
				excercits.push_back(e);
			}
		}*/
		excercits.push_back(e);
	}
	void reclutar(Unitats u, int idEx)
	{

		if (or >= u.costRec)
		{
			for (ite = excercits.begin(); ite != excercits.end(); ite++)
			{
				if (ite->getId() == idEx)
					break;
			}
			ite->afegirUnitat(u);
			if (player){
				gotoxy(158, 25); cout << con::fg_green << "Unitat reclutada correctament";
			}
		}
		else if (or < u.costRec)
		{
			if (player){
				gotoxy(158, 25); cout << con::fg_red << "No tens prou or per a reclutar la unitat!";
			}
		}
	}
	void mostrarUnitats(int idEx)
	{
		for (ite = excercits.begin(); ite != excercits.end(); ite++)
		{
			if (ite->getId() == idEx)
				break;
		}
		ite->mostrarUnits();
	}
	void setIdCap(int id)
	{
		id_capital = id;
	}
	int getIdCap()
	{
		return id_capital;
	}
	string getNom()
	{
		return nom;
	}
	void setNom(string n)
	{
		nom = n;
	}
	int getId()
	{
		return id;
	}
	void setId(int id)
	{
		this->id = id;
	}
	void update()
	{
		calculaManteniment();
		calculaGastos();
		calculaIngressos();
	

		


	}
	bool getPlayer()
	{
		return player;
	}
	void setOr(int or)
	{
		this->or = or;
	}
	int getOr()
	{
		return or;
	}
	void setIngressos(int ing)
	{
		ingressos = ing;
	}
	int getIngressos()
	{
		return ingressos;
	}
	void calculaIngressos()
	{
		
	}
	void setGastos(int gas)
	{
		gastos = gas;
	}
	int getGastos()
	{
		return gastos;
	}
	void calculaGastos(){}
	void calculaManteniment()
	{
		
	}
	Faction(){}
	Faction(int idcap, int or, bool player, int id, string nom)
	{
		this->id = id; this->or = or;
		this->player = player; this->nom = nom;
		id_capital = idcap;

	}
	~Faction(){}

};

void update(Mapa &a, list<Faction> &l)
{
	list<Faction>::iterator it;
	for (it = l.begin(); it != l.end(); it++)
	{
		//if ()
		it->getIterEx(0)->getTerritoriAct();
	}
	a.update();
}

int _tmain(int argc, _TCHAR* argv[])
{

	Mapa a(mapa);
	a.print();
	a.iniciaTerritoris();
	printInterface();
	//a.pintaNoms();
	list<Faction> faccions;
	list<Faction>::iterator itf;
	Faction f(1,500,true,1,"Portugal");
	faccions.push_back(f);
	itf = faccions.begin();
	General g;
	g.atack = 10;
	g.def = 5;
	g.costMan = 50;
	g.costRec = 250;
	g.nom = "General1";
	g.lvl = 7;
	g.comandament = 4;
	g.exp = 1200;
	list<Unitats> u;
	Excercit e(1,g,u,1);
	Arquer uni;
	uni.exp = 1500;
	uni.lvl = 2;
	uni.nom = "Arquer";
	e.afegirUnitat(uni);
	//e.mostrarUnits();
	f.setExcercit(e);
	update();
	f.reclutar(uni, 1);
	//e.moure(2);
	//e.reclutar(g, itf);
	//e.setTerritoriAct(1);
	f.getIterEx(1)->moure(2);
	system("pause>>NULL");
	return 0;
}