// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include <array>
#include "Console.h"
#include "Mapa.h"
#include "Util.h"
#include "Excercit.h"
#include "Faction.h"

using namespace std;
using namespace Util;
namespace con = JadedHoboConsole;


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