// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include "Faction.h"

using namespace std;
//using namespace Util;
namespace con = JadedHoboConsole;
using namespace con;

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

Util U;

list<Faction> faccions;
list<Faction>::iterator itf;

//Creem un iterador predefinit per a cada faccio, ens estalviarà treball més tard

list<Faction>::iterator itf1;
list<Faction>::iterator itf2;
list<Faction>::iterator itf3;
list<Faction>::iterator itf4;
list<Faction>::iterator itf5;
list<Faction>::iterator itf6;
list<Faction>::iterator itf7;
list<Faction>::iterator itf8;

void inicialitzaFaccions()
{
	Faction p(1, 500, false, 2, "Portugal");
	Faction e(2, 500, true, 1, "Espanya");
	Faction f(3, 500, false, 3, "Francia");
	Faction i(4, 500, false, 4, "Italia");
	Faction a(5, 500, false, 5, "Alemania");
	Faction r(6, 500, false, 6, "Russia");
	Faction g(7, 500, false, 7, "Grecia");
	Faction t(8, 500, false, 8, "Turquia");
	faccions.push_back(p);
	faccions.push_back(e);
	faccions.push_back(f);
	faccions.push_back(i);
	faccions.push_back(a);
	faccions.push_back(r);
	faccions.push_back(g);
	faccions.push_back(t);

	for (itf = faccions.begin(); itf != faccions.end(); itf++)
	{
		switch (itf->getId())
		{
		case 1:
			itf1 = itf;
			break;
		case 2:
			itf2 = itf;
			break;
		case 3:
			itf3 = itf;
			break;
		case 4:
			itf4 = itf;
			break;
		case 5:
			itf5 = itf;
			break;
		case 6:
			itf6 = itf;
			break;
		case 7:
			itf7 = itf;
			break;
		case 8:
			itf8 = itf;
			break;
		}
	}
}

Unitats menuUnitats()
{
	U.flushInterface();
	U.resetPosY();
	U.printInterface("Reclutar unitat:", fgHiCyan);
	U.posyMas();
	int op = 1, opA, nO = 5;
	bool fiMenu = false;
	string op1 = "Arquer";
	string op2 = "Soldat";
	string op3 = "Llancer";
	string op4 = "Cavaller";
	string op5 = "Arma de setge";
	while (!fiMenu)
	{
		switch (op)
		{
		case 1:
			U.printInterfacebg(op1, fgBlack);
			U.posyMas();
			U.printInterface(op2, fgHiCyan);
			U.posyMas();
			U.printInterface(op3);
			U.posyMas();
			U.printInterface(op4);
			U.posyMas();
			U.printInterface(op5);
			U.posyMas();
			break;
		case 2:
			U.printInterface(op1, fgHiCyan);
			U.posyMas();
			U.printInterfacebg(op2, fgBlack);
			U.posyMas();
			U.printInterface(op3, fgHiCyan);
			U.posyMas();
			U.printInterface(op4);
			U.posyMas();
			U.printInterface(op5);
			U.posyMas();
			break;
		case 3:
			U.printInterface(op1, fgHiCyan);
			U.posyMas();
			U.printInterface(op2);
			U.posyMas();
			U.printInterfacebg(op3, fgBlack);
			U.posyMas();
			U.printInterface(op4, fgHiCyan);
			U.posyMas();
			U.printInterface(op5);
			U.posyMas();
			break;
		case 4:
			U.printInterface(op1, fgHiCyan);
			U.posyMas();
			U.printInterface(op2);
			U.posyMas();
			U.printInterface(op3);
			U.posyMas();
			U.printInterfacebg(op4, fgBlack);
			U.posyMas();
			U.printInterface(op5, fgHiCyan);
			U.posyMas();
			break;
		case 5:
			U.printInterface(op1, fgHiCyan);
			U.posyMas();
			U.printInterface(op2);
			U.posyMas();
			U.printInterface(op3);
			U.posyMas();
			U.printInterface(op4);
			U.posyMas();
			U.printInterfacebg(op5, fgBlack);
			U.posyMas();
			break;
		default:
			break;
		}
		opA = op;
		fiMenu = U.teclado(op, nO);
		U.resetPosY(2);
		U.flushMenu(nO);
	}

	Arquer arq;
	Soldat sol;
	Cavalleria cav;
	Llancer llan;
	Siege set;

	switch (opA) {
	case 1:
		return arq;
	case 2:
		return sol;
	case 3:
		return llan;
	case 4:
		return cav;
	case 5:
		return set;
	}
}

int menuPrinc()
{
	int op = 1, opA, nO = 4;
	bool fiMenu = false;
	string op1 = "Mostrar Unitats d'un excercit";
	string op2 = "Moure un excercit d'un territori a un altre";
	string op3 = "Reclutar unitats per a un excercit";
	string op4 = "Acabar el torn";
	while (!fiMenu)
	{
			switch (op)
			{
			case 1:
				U.printInterfacebg(op1, fgBlack);
				U.posyMas();
				U.printInterface(op2, fgHiWhite);
				U.posyMas();
				U.printInterface(op3);
				U.posyMas();
				U.printInterface(op4);
				U.posyMas();
				break;
			case 2:
				U.printInterface(op1, fgHiWhite);
				U.posyMas();
				U.printInterfacebg(op2, fgBlack);
				U.posyMas();
				U.printInterface(op3, fgHiWhite);
				U.posyMas();
				U.printInterface(op4);
				U.posyMas();
				break;
			case 3:
				U.printInterface(op1, fgHiWhite);
				U.posyMas();
				U.printInterface(op2);
				U.posyMas();
				U.printInterfacebg(op3, fgBlack);
				U.posyMas();
				U.printInterface(op4, fgHiWhite);
				U.posyMas();
				break;
			case 4:
				U.printInterface(op1, fgHiWhite);
				U.posyMas();
				U.printInterface(op2);
				U.posyMas();
				U.printInterface(op3);
				U.posyMas();
				U.printInterfacebg(op4, fgBlack);
				U.posyMas();
				break;
			case 5:
				break;
			default:
				break;
			}
			opA = op;
			fiMenu = U.teclado(op, nO);
			U.resetPosY();
			U.flushMenu(nO);
		}
	U.flushInterface();
	return opA;
}

bool tornJugador(int num)
{
	bool fi = false;
	int op;
	switch (num)
	{
	case 1:
		op = menuPrinc();
		break;
	case 2:
		op = menuPrinc();
		break;
	}
	Excercit ex;
	Arquer aa;
	Faction ff;
	int numEx = 1;
	bool menuok = false;
	switch (op)
	{
	case 1:
		U.printInterface("Selecciona l'excercit que vols mostrar:", con::fgHiCyan);
		U.posyMas();
		while (!menuok){
			U.resetPosY(3);
			U.printInterface(to_string(numEx));
			menuok = U.teclado(numEx, 2);
		}
		U.posyMas();
		switch (num){
		case 1:
			itf1->getIterEx(numEx)->mostrarUnits();
			break;
		case 2: 
			itf2->getIterEx(numEx)->mostrarUnits();
			break;
		default:
			break;
		}
		break;
	case 2:
		U.printInterface("Selecciona l'excercit que vols moure:", con::fgHiCyan);
		U.posyMas();
		while (!menuok){
			U.resetPosY(3);
			U.printInterface(to_string(numEx));
			menuok = U.teclado(numEx, 2);
		}
		U.posyMas();
		switch (num){
		case 1:
			itf1->getIterEx(numEx)->moure();
			break;
		case 2:
			itf2->getIterEx(numEx)->moure();
			break;
		}
		break;
	case 3:
		U.printInterface("Selecciona l'excercit per al que vols reclutar:", con::fgHiCyan);
		U.posyMas();
		while (!menuok){
			U.resetPosY(3);
			U.printInterface(to_string(numEx));
			menuok = U.teclado(numEx, 2);
		}
		U.posyMas();

		switch (num){
		case 1:
			//itf1->reclutar(menuUnitats(), numEx);
			//Afegir directament a la llista d'unitats a veure si ha sort
			ff = (*itf1);
			ex = (*ff.getIterEx(numEx));
			ex.afegirUnitat(aa);
			ff.setExcercit(ex);
			*itf1 = ff;

			/*ex = (*itf1->getIterEx(1));
			ex.afegirUnitat(aa);
			itf1->setExcercit(ex);*/
			break;
		case 2:
			itf2->reclutar(menuUnitats(), numEx);
			break;
		}
		break;
	case 4:
		fi = true;
		break;
	}
	return fi;
}







void update(Mapa &a, list<Faction> &l)
{
	list<Faction>::iterator it;
	for (it = l.begin(); it != l.end(); it++)
	{
		it->update();
		//if ()
		it->getIterEx(0)->getTerritoriAct();
	}
	a.update();
	a.print();
}

int _tmain(int argc, _TCHAR* argv[])
{

	U.fin = false;
	U.resetPosY();
	Mapa a(mapa);
	a.iniciaTerritoris();
	a.print();
	a.pintaNoms();
	U.printInterface("Inicialitzacio de mapa completa,", fgLoCyan);
	U.printInterface("inicialitzant faccions...");
	Sleep(700);
	U.flushInterface();
	U.resetPosY();
	inicialitzaFaccions();
	General g;
	list<Unitats *> u;
	Excercit e(1, g, u, 1);
	Excercit b(1, g, u, 2);
	Arquer arq;
	Soldat sol;
	Cavalleria cav;
	Llancer llan;
	Siege set;
	u.emplace_back(&arq);
	u.emplace_back(&sol);
	u.emplace_back(&cav);
	u.emplace_back(&llan);
	u.emplace_back(&set);
	e.afegirUnitats(u);
	u.emplace_back(&arq);
	u.emplace_back(&sol);
	b.afegirUnitats(u);
	itf1->setExcercit(e);
	itf1->setExcercit(b);
	itf2->setExcercit(e);
	itf2->setExcercit(b);
	U.flushInterface();
	bool torn_acabat;

	//menuPrinc();
	while (!U.fin)
	{
		//update(a, faccions);
		torn_acabat = false;
		while (!torn_acabat)
		{
			torn_acabat = tornJugador(1);
		}
		//tornJugador(2);




	}


	system("pause>>NULL");
	return 0;
}