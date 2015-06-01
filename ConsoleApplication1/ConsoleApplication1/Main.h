#pragma once

#include "stdafx.h"
#include <iostream>
#include "Faction.h"
#include "Mapa.h"

using namespace std;
//using namespace Util;
namespace cons = JadedHoboConsole;
using namespace cons;
using namespace Utilitats;


namespace main{

	char mapa[80][225] = {
		"YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
		"YXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"YX                                                                   XaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                                                XXXaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                                               XaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                                             XXaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                                            XaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                 XX                        XXaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                 XfXXX              XXXX  XaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                 XffffXXXX         XXfffXXaaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                 XffffffffXXX      XffffffXaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                 XfffffffffffXX   XXffffffXaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                 XfffffffffffffXXXfffffffffXaaaaaaaaaaaaaaaaaaaaaXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                  XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                   XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                    XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaXXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                    XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                     XffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                      XffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaaXXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaXXggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaXXgggggXXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaXXgggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaXXggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                      XffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaXggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                      XfffffffffffffffffffffffXXXaaaaaaaaaaaaaaXgggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                      XffffffffffffffffffffffffffXaaaaaaaaaaaaaXggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                      XffffffffffffffffffffffffffXaaaaaaaaaaaaaXXgggggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                      XfffffffffffffffffffffffffffXaaaaaaaaaaaaaXXgggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                      XfffffffffffffffffffffffXXXXiXaaaaaaaaaaaaaXgggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                      XffffffffffffffffffffffXiiiiiXXaaaaaaaaaaaaXggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                      XfffffffffffffffffffffXiiiiiiiXaaaaaaaaaaaaXgggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                     XfffffffffffffffffffffXXiiiiiiiiXaaaaaaaaaaaXgggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                     XffffffffffffffffffffXXiiiiiiiiiXXaaaaaaaaaaXggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX                                     XfffffffffffffffffffXXiiiiiiiiiiiXXaaaaaaaaaXgggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX          X XXX                      XfffffffffffffffffffXiiiiiiiiiiiiiXXaaaaaaaaXggggggggggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX         XsXsssXXXX                 XffffffffffffffffffffXiiiiiiiiiiiiiiiXXXXXXXXgggggggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX         XsssssssssXXXXX            XffffffffffffffffffffXiiiiiiiiiiiiiiiiiiiiiiiXXXggggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                                   X",
		"YX        XsssssssssssssssXXX        XffffffffffffffffffffXXiiiiiiiiiiiiiiiiiiiiiiiiiXXggggXXXXggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrXXXXXX                                                                   X",
		"YX       XssssssssssssssssssXXXX    XXXffffffffffffffffffXXiiiiiiiiiiiiiiiiiiiiiiiiiiiXXXXX    XXggggggggggggXrrrrrrrrrrrXXXXXXXXXrrrrrrrrrrrrrrrrrrrXX    X                                                                   X",
		"YX       XXXXsssssssssssssssssssXXXXsssXXfffffffffffffffXXiiiiiXXiiiiiiiiiiiiiiiiiiiiXXX         XXgggggggggggXXXXXXXXXXXggggggggXXrrrrrrrrrrrrrrXXXXX     X                                                                   X",
		"YX       XppXXXsssssssssssssssssssssssssXXffffffffffffffXiiiXXX XiiiiiiiiiiiiiiiiiiXX              XgggggggggggggggggggggggggggggggXXrrrrrrrrrXXX          X                                                                   X",
		"YX        XppppXsssssssssssssssssssssssssXXfffffffffffffXXXX     XXiiiiiiiiiiiiiiiiX               XggggggggggggggggggggggggggggggggXXXXXXrrrXX            X                                                                   X",
		"YX        XppppXssssssssssssssssssssssssssXXffffffXXXXXX           XXiiiiiiiiiiiiiX                XgggggggggggggggggggggggggggggggggggggXXXXX             X                                                                   X",
		"YX        XpppXXsssssssssssssssssssssssssssXXXXXXX                   XiiiiiiiiiiiX                 XggggggggggggggggggggggXXXgggggggggggggggX              X                                                                   X",
		"YX        XpppXssssssssssssssssssssssssssssssssX                      XiiiiiiiiiXX                 XggggggggggggggggggggXXX  XXXgggggggggggX               X                                                                   X",
		"YX       XpppXssssssssssssssssssssssssssssssssX              XX       XiiiiiiiiiX                 XggggggggggggggggggggXX       XXXXggggggX                X                                                                   X",
		"YX       XpppXssssssssssssssssssssssssssssssssX             XXXX      XiiiiiiiiX                  XggggggggggggggggggggX            XXXXXX                 X                                                                   X",
		"YX       XpppXsssssssssssssssssssssssssssssssX              XiiX     XiiiiiiiiXX                  XggggggggggggggggggggX                                   X                                                                   X",
		"YX       XpppXsssssssssssssssssssssssssssssssX              XiX      XiiiiiiiX                    XggggggggggggggggggggX                                   X                                                                   X",
		"YX       XpppXssssssssssssssssssssssssssssssX               XXX      XiiiiiiiX                    XggggggggggggggggggggX                                   X                                                                   X",
		"YX       XppppXsssssssssssssssssssssssssssssX               XX       XiiiiiiX                    XgggggggggggggggggggggX                                   X                                                                   X",
		"YX      XpppppXsssssssssssssssssssssssssXXXX                        XiiiiiiX                     XgggggggggggggggggggggX                                   X                                                                   X",
		"YX      XpppppXsssssssssssssssssssssXXXX                 XXX        XiiiiiiX                     XggggggggggggggggggggggXX                                 X                                                                   X",
		"YX      XpppppXsssssssssssssssssssssX          XX       XXiX        XiiiiiX                      XgggggggggggggggggggggggX                                 X                                                                   X",
		"YX     XppppppXssssssssssssssssssssX          XX        XiiX        XiiiiiX                     XgggggggggggggggggggggggggXX                               X                                                                   X",
		"YX    XpppppppXssssssssssssssssssssX      XX           XXiiX       XiiiiiiX                     XgggggggggggggggggggggggggggX                              X                                                                   X",
		"YX   XppppppppXssssssssssssssssssssX     XssX          XiiiX       XiiiiiX                     XgggggggggggggggggggggggggggggX                             X                                                                   X",
		"YX   XpppppppXssssssssssssssssssssX       XX           XiiiX       XiiiiiX                    XgggggggggggggggggggggggggggggX                              X                                                                   X",
		"YX    XXpppppXsssssssssssssssssssXX                   XXiiiX      XiiiiiiX                    XXggggggggggggggggXggggggggggX X         XXXXXX            XXX                                                                   X",
		"YX   XppppppXXssssssssssssssssssX      XX             XXiiX       XiiiiiiX                      XXggggggggggggXXXggggggggXX    X      XXggggXX        XXXttX                                                                   X",
		"YX   XXppppXXsssssssssssssssssssX       X              XXXX      XiiiiiiX                         XXgggggggggX  XggggggXX       XXXXXXXggggggXXXXXXXXXtttttX                                                                   X",
		"YX     XXpXXsssssssssssssssssssX       X                        XiiiiiiiX                           XXgggggXX   XgggggX         XggggggggggggXXttttttttttttX                                                                   X",
		"YX       XXsssssssssssssssssssX                                 XiiiiiiiX                             XXggX     XgggXX          XggggggggggggXtttttttttttttX                                                                   X",
		"YX         XXsssssssssssssssssX                                XiiiiiiiX                                XX      XgggX           XXggggggggggXXtttttttttttttX                                                                   X",
		"YX          XsssssssXXXXXXXXXX                                XiiiiiiiiX                                         XgX             XgggggggggXXttttttttttttttX                                                                   X",
		"YX           XssssXX                                          XiiiiiiiiX                                         XgX             XgggggggggXtttttttttttttttX                                                                   X",
		"YX            XsXX                                         XXXiiiiiiiiiiX                                        XggX            XgggggggggXtttttttttttttttX                                                                   X",
		"YX            XX                                       XXXXiiiiiiiiiiiiiX                                     XXXXgggXX          XggggggggXttttttttttttttttX                                                                   X",
		"YX                                                   XXiiiiiiiiiiiiiXiiiX                             XXX  XXXggggggggX          XggggggggXttttttttttttttttX                                                                   X",
		"YX                                                    XXXXXXiiiiiiXX XiX                             XgggXXgggggggggggX         XXggggggggXttttttttttttttttX                                                                   X",
		"YX                                                          XXXXXX    X                              XggggggggggggggggX         XgggggggggXttttttttttttttttX                                                                   X",
		"YX                                                                                                  XXggggggggggggggggX        XXgggggggggXttttttttttttttttX                                                                   X",
		"YX                                                                                                  XgggggggggggggggggX        XggggggggggXttttttttttttttttX                                                                   X",
		"YX                                                                                                  XgggggggggggggggXX         XgggggggggXXttttttttttttttttX                                                                   X",
		"YX                                                                                                  XgggggggggggggXX           XXggggggggXtttttttttttttttttX                                                                   X",
		"YX                                                                                                   XggggggggggggX             XXXgggggXXtttttttttttttttttX                                                                   X",
		"YX                                                                                                   XXggggggggggX                 XXXXXXttttttttttttttttttX                                                                   X",
		"YX                                                                                                    XXgggggggggX                      XXtttttttttttttttttX                                                                   X",
		"YXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
		"YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY"
	};

	Mapa a;

	list<Faction> faccions;
	list<Faction>::iterator itf;
	vector<Excercit*> posEx;

	void inicialitzaMapa()
	{
		Mapa I(mapa);
		a = I;
	}


	void inicialitzaFaccions()
	{
		Faction p(1, 500, false, 2, "Portugal", bgHiRed);
		Faction e(2, 500, true, 1, "Espanya", bgHiYellow);
		Faction f(3, 500, false, 3, "Francia", bgLoBlue);
		Faction i(4, 500, false, 4, "Italia", bgHiGreen);
		Faction a(5, 500, false, 5, "Alemania", bgLoRed);
		Faction r(6, 500, false, 6, "Russia", bgHiWhite);
		Faction g(7, 500, true, 7, "Grecia", bgLoMagenta);
		Faction t(8, 500, false, 8, "Turquia", bgLoGreen);
		faccions.push_back(p);
		faccions.push_back(e);
		faccions.push_back(f);
		faccions.push_back(i);
		faccions.push_back(a);
		faccions.push_back(r);
		faccions.push_back(g);
		faccions.push_back(t);
	}

	void menuUnitats(list<Faction>::iterator itf, int numEx)
	{
		flushInterface();
		
		
		int op = 1, opA = 0, nO = 6;
		bool fiMenu = false;
		Arquer a;
		Soldat s;
		Llancer l;
		Cavalleria c;
		Siege si;

		string op1 = "Arquer - Reclutament: " + to_string(a.costRec) + " Manteniment: " + to_string(a.costMan);
		string op2 = "Soldat - Reclutament: " + to_string(s.costRec) + " Manteniment: " + to_string(s.costMan);
		string op3 = "Llancer - Reclutament: " + to_string(l.costRec) + " Manteniment: " + to_string(l.costMan);
		string op4 = "Cavaller - Reclutament: " + to_string(c.costRec) + " Manteniment: " + to_string(c.costMan);
		string op5 = "Arma de setge - Reclutament: " + to_string(si.costRec) + " Manteniment: " + to_string(si.costMan);
		string op6 = "Cancelar";
		while (opA != 6)
		{
			resetPosY();
			printInterface("Reclutar unitats:                          Or disponible: " + to_string(itf->getOr()), fgHiCyan);
			posyMas();
			fiMenu = false;
			while (!fiMenu)
			{
				posyMas();
				switch (op)
				{
				case 1:
					printInterfacebg(op1, fgBlack, bgHiWhite);
					posyMas();
					printInterface(op2, fgHiCyan);
					posyMas();
					printInterface(op3);
					posyMas();
					printInterface(op4);
					posyMas();
					printInterface(op5);
					posyMas();
					printInterface(op6);
					posyMas();
					break;
				case 2:
					printInterface(op1, fgHiCyan);
					posyMas();
					printInterfacebg(op2, fgBlack, bgHiWhite);
					posyMas();
					printInterface(op3, fgHiCyan);
					posyMas();
					printInterface(op4);
					posyMas();
					printInterface(op5);
					posyMas();
					printInterface(op6);
					posyMas();
					break;
				case 3:
					printInterface(op1, fgHiCyan);
					posyMas();
					printInterface(op2);
					posyMas();
					printInterfacebg(op3, fgBlack, bgHiWhite);
					posyMas();
					printInterface(op4, fgHiCyan);
					posyMas();
					printInterface(op5);
					posyMas();
					printInterface(op6);
					posyMas();
					break;
				case 4:
					printInterface(op1, fgHiCyan);
					posyMas();
					printInterface(op2);
					posyMas();
					printInterface(op3);
					posyMas();
					printInterfacebg(op4, fgBlack, bgHiWhite);
					posyMas();
					printInterface(op5, fgHiCyan);
					posyMas();
					printInterface(op6);
					posyMas();
					break;
				case 5:
					printInterface(op1, fgHiCyan);
					posyMas();
					printInterface(op2);
					posyMas();
					printInterface(op3);
					posyMas();
					printInterface(op4);
					posyMas();
					printInterfacebg(op5, fgBlack, bgHiWhite);
					posyMas();
					printInterface(op6, fgHiCyan);
					posyMas();
					break;
				case 6:
					printInterface(op1, fgHiCyan);
					posyMas();
					printInterface(op2);
					posyMas();
					printInterface(op3);
					posyMas();
					printInterface(op4);
					posyMas();
					printInterface(op5);
					posyMas();
					printInterfacebg(op6, fgBlack, bgHiWhite);
					posyMas();
					break;
				default:
					break;
				}
				opA = op;
				fiMenu = teclado(op, nO);
				resetPosY(2);
				//flushMenu(nO);
			}

			switch (opA) {
			case 1:
				itf->reclutar(new Arquer, numEx);
				break;
			case 2:
				itf->reclutar(new Soldat, numEx);
				break;
			case 3:
				itf->reclutar(new Llancer, numEx);
				break;
			case 4:
				itf->reclutar(new Cavalleria, numEx);
				break;
			case 5:
				itf->reclutar(new Siege, numEx);
				break;
			default:
				break;
			}
		}
	}

	int menuPrinc(list<Faction>::iterator itf)
	{
		int op = 1, opA, nO = 5;
		bool fiMenu = false;
		string op1 = "Mostrar Unitats d'un excercit";
		string op2 = "Moure un excercit / atacar un territori";
		string op3 = "Reclutar unitats per a un excercit";
		string op4 = "Revisa les finances";
		string op5 = "Acabar el torn";
		flushInterface();
		resetPosY();


		
		while (!fiMenu)
		{
			printInterfacebg("                          " + itf->getNom() + "                            ", fgBlack, bgHiWhite);
			posyMas();
			switch (op)
			{
			case 1:
				printInterfacebg(op1, fgBlack, bgHiWhite);
				posyMas();
				printInterface(op2, fgHiWhite);
				posyMas();
				printInterface(op3);
				posyMas();
				printInterface(op4);
				posyMas();
				printInterface(op5);
				posyMas();
				break;
			case 2:
				printInterface(op1, fgHiWhite);
				posyMas();
				printInterfacebg(op2, fgBlack, bgHiWhite);
				posyMas();
				printInterface(op3, fgHiWhite);
				posyMas();
				printInterface(op4);
				posyMas();
				printInterface(op5);
				posyMas();
				break;
			case 3:
				printInterface(op1, fgHiWhite);
				posyMas();
				printInterface(op2);
				posyMas();
				printInterfacebg(op3, fgBlack, bgHiWhite);
				posyMas();
				printInterface(op4, fgHiWhite);
				posyMas();
				printInterface(op5);
				posyMas();
				break;
			case 4:
				printInterface(op1, fgHiWhite);
				posyMas();
				printInterface(op2);
				posyMas();
				printInterface(op3);
				posyMas();
				printInterfacebg(op4, fgBlack, bgHiWhite);
				posyMas();
				printInterface(op5, fgHiWhite);
				posyMas();
				break;
			case 5:
				printInterface(op1, fgHiWhite);
				posyMas();
				printInterface(op2);
				posyMas();
				printInterface(op3);
				posyMas();
				printInterface(op4);
				posyMas();
				printInterfacebg(op5, fgBlack, bgHiWhite);
				posyMas();
				break;
			default:
				break;
			}
			opA = op;
			fiMenu = teclado(op, nO);
			resetPosY();
			flushMenu(nO);
		}
		flushInterface();
		return opA;
	}

	bool tornJugador(int num, int torn)
	{
		bool fi = false;
		int op;

		for (itf = faccions.begin(); itf != faccions.end(); itf++)
		{
			if (itf->getId() == num)
				break;
		}


		op = menuPrinc(itf);
		int numEx = 1, conquerit = 0;
		bool menuok = false;
		switch (op)
		{
		case 1:
			printInterface("Selecciona l'excercit que vols mostrar:", fgHiCyan);
			posyMas();
			while (!menuok){
				resetPosY(3);
				printInterface(to_string(numEx));
				menuok = teclado(numEx, 2);
			}
			posyMas();

			itf->getIterEx(numEx)->mostrarUnits();

			break;
		case 2:
			printInterface("Selecciona l'excercit que vols moure:", fgHiCyan);

			while (!menuok){
				resetPosY(3);
				printInterface(to_string(numEx));
				menuok = teclado(numEx, 2);
			}
			posyMas();
			
			conquerit = itf->getIterEx(numEx)->moure(posEx);

			if (conquerit != 0){
				a.update(conquerit, itf->getId());
				a.print();
				a.pintaNoms();
			}


			break;
		case 3:
			printInterface("Selecciona l'excercit per al que vols reclutar:", fgHiCyan);
			posyMas();
			while (!menuok){
				resetPosY(3);
				printInterface(to_string(numEx));
				menuok = teclado(numEx, 2);
			}
			posyMas();

			menuUnitats(itf, numEx);
			break;
		case 4:
			
			printInterface("Les finances de la teva faccio son les seguents:", fgHiCyan);
			posyMas();

			itf->getFinances(torn);
			break;
		case 5:
			fi = true;
			break;
		}
		return fi;
	}

	void inicialitzaExcercits()
	{
		for (itf = faccions.begin(); itf != faccions.end(); itf++)
		{
			General g;
			list<Unitats *> u;
			Excercit e(g, u, 1);
			Excercit b(g, u, 2);
			u.emplace_back(new Arquer);
			u.emplace_back(new Arquer);
			u.emplace_back(new Soldat);
			u.emplace_back(new Cavalleria);
			u.emplace_back(new Llancer);
			u.emplace_back(new Llancer);
			e.afegirUnitats(u);
			u.clear();
			u.emplace_back(new Llancer);
			u.emplace_back(new Siege);
			u.emplace_back(new Arquer);
			u.emplace_back(new Soldat);
			b.afegirUnitats(u);
		
			itf->setExcercit(e);
			itf->setExcercit(b);
			itf->imprPropEx();
			itf->getIterEx(1)->update();
			itf->getIterEx(2)->update();
			posEx.push_back(&(*itf->getIterEx(1)));
			posEx.push_back(&(*itf->getIterEx(2)));
		}

	}

	bool otherExPresent(int terrAt, int idFac)
	{
		list<Faction>::iterator itf;
		for (itf = faccions.begin(); itf != faccions.end(); itf++)
		{
			if (itf->getId() != idFac)
			{
				if (itf->getIterEx(1)->getTerritoriAct() == terrAt || itf->getIterEx(2)->getTerritoriAct() == terrAt)
				{
					return true;
				}
			}
		}
		return false;
	}

	void update(bool t)
	{
		posEx.clear();
		for (itf = faccions.begin(); itf != faccions.end(); itf++)
		{
			itf->update(t);
			posEx.push_back(&(*itf->getIterEx(1)));
			posEx.push_back(&(*itf->getIterEx(2)));
		}
		//otherExPresent();
		a.update(posEx);
		a.print();
		a.pintaNoms();
	}
};