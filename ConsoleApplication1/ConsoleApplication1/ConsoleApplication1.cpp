// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include "Main.h"

using namespace std;
//using namespace Util;
namespace con = JadedHoboConsole;
using namespace con;

char mapa[80][210] = {
	"YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
	"YXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	"YX                                                                   XaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                                                XXXaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                                               XaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                                             XXaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                                            XaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                 XX                        XXaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                 XfXXX              XXXX  XaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                 XffffXXXX         XXfffXXaaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                 XffffffffXXX      XffffffXaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                 XfffffffffffXX   XXffffffXaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                 XfffffffffffffXXXfffffffffXaaaaaaaaaaaaaaaaaaaaaXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                  XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                   XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                    XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaXXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                    XfffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                     XffffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaaXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                      XffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaaXXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaaXXggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaaXXgggggXXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaaaXXgggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                       XfffffffffffffffffffffXaaaaaaaaaaaaaaaaaaXXggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                      XffffffffffffffffffffffXaaaaaaaaaaaaaaaaaaXggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                      XfffffffffffffffffffffffXXXaaaaaaaaaaaaaaXgggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                      XffffffffffffffffffffffffffXaaaaaaaaaaaaaXggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                      XffffffffffffffffffffffffffXaaaaaaaaaaaaaXXgggggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                      XfffffffffffffffffffffffffffXaaaaaaaaaaaaaXXgggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                      XfffffffffffffffffffffffXXXXiXaaaaaaaaaaaaaXgggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                      XffffffffffffffffffffffXiiiiiXXaaaaaaaaaaaaXggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                      XfffffffffffffffffffffXiiiiiiiXaaaaaaaaaaaaXgggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                     XfffffffffffffffffffffXXiiiiiiiiXaaaaaaaaaaaXgggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                     XffffffffffffffffffffXXiiiiiiiiiXXaaaaaaaaaaXggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX                                     XfffffffffffffffffffXXiiiiiiiiiiiXXaaaaaaaaaXgggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX          X XXX                      XfffffffffffffffffffXiiiiiiiiiiiiiXXaaaaaaaaXggggggggggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX         XsXsssXXXX                 XffffffffffffffffffffXiiiiiiiiiiiiiiiXXXXXXXXgggggggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX         XsssssssssXXXXX            XffffffffffffffffffffXiiiiiiiiiiiiiiiiiiiiiiiXXXggggggggggggggggggggXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrX                                                    X",
	"YX        XsssssssssssssssXXX        XffffffffffffffffffffXXiiiiiiiiiiiiiiiiiiiiiiiiiXXggggXXXXggggggggggggXXrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrXXXXXX                                                    X",
	"YX       XssssssssssssssssssXXXX    XXXffffffffffffffffffXXiiiiiiiiiiiiiiiiiiiiiiiiiiiXXXXX    XXggggggggggggXrrrrrrrrrrrXXXXXXXXXrrrrrrrrrrrrrrrrrrrXX    X                                                    X",
	"YX       XXXXsssssssssssssssssssXXXXsssXXfffffffffffffffXXiiiiiXXiiiiiiiiiiiiiiiiiiiiXXX         XXgggggggggggXXXXXXXXXXXggggggggXXrrrrrrrrrrrrrrXXXXX     X                                                    X",
	"YX       XppXXXsssssssssssssssssssssssssXXffffffffffffffXiiiXXX XiiiiiiiiiiiiiiiiiiXX              XgggggggggggggggggggggggggggggggXXrrrrrrrrrXXX          X                                                    X",
	"YX        XppppXsssssssssssssssssssssssssXXfffffffffffffXXXX     XXiiiiiiiiiiiiiiiiX               XggggggggggggggggggggggggggggggggXXXXXXrrrXX            X                                                    X",
	"YX        XppppXssssssssssssssssssssssssssXXffffffXXXXXX           XXiiiiiiiiiiiiiX                XgggggggggggggggggggggggggggggggggggggXXXXX             X                                                    X",
	"YX        XpppXXsssssssssssssssssssssssssssXXXXXXX                   XiiiiiiiiiiiX                 XggggggggggggggggggggggXXXgggggggggggggggX              X                                                    X",
	"YX        XpppXssssssssssssssssssssssssssssssssX                      XiiiiiiiiiXX                 XggggggggggggggggggggXXX  XXXgggggggggggX               X                                                    X",
	"YX       XpppXssssssssssssssssssssssssssssssssX              XX       XiiiiiiiiiX                 XggggggggggggggggggggXX       XXXXggggggX                X                                                    X",
	"YX       XpppXssssssssssssssssssssssssssssssssX             XXXX      XiiiiiiiiX                  XggggggggggggggggggggX            XXXXXX                 X                                                    X",
	"YX       XpppXsssssssssssssssssssssssssssssssX              XiiX     XiiiiiiiiXX                  XggggggggggggggggggggX                                   X                                                    X",
	"YX       XpppXsssssssssssssssssssssssssssssssX              XiX      XiiiiiiiX                    XggggggggggggggggggggX                                   X                                                    X",
	"YX       XpppXssssssssssssssssssssssssssssssX               XXX      XiiiiiiiX                    XggggggggggggggggggggX                                   X                                                    X",
	"YX       XppppXsssssssssssssssssssssssssssssX               XX       XiiiiiiX                    XgggggggggggggggggggggX                                   X                                                    X",
	"YX      XpppppXsssssssssssssssssssssssssXXXX                        XiiiiiiX                     XgggggggggggggggggggggX                                   X                                                    X",
	"YX      XpppppXsssssssssssssssssssssXXXX                 XXX        XiiiiiiX                     XggggggggggggggggggggggXX                                 X                                                    X",
	"YX      XpppppXsssssssssssssssssssssX          XX       XXiX        XiiiiiX                      XgggggggggggggggggggggggX                                 X                                                    X",
	"YX     XppppppXssssssssssssssssssssX          XX        XiiX        XiiiiiX                     XgggggggggggggggggggggggggXX                               X                                                    X",
	"YX    XpppppppXssssssssssssssssssssX      XX           XXiiX       XiiiiiiX                     XgggggggggggggggggggggggggggX                              X                                                    X",
	"YX   XppppppppXssssssssssssssssssssX     XssX          XiiiX       XiiiiiX                     XgggggggggggggggggggggggggggggX                             X                                                    X",
	"YX   XpppppppXssssssssssssssssssssX       XX           XiiiX       XiiiiiX                    XgggggggggggggggggggggggggggggX                              X                                                    X",
	"YX    XXpppppXsssssssssssssssssssXX                   XXiiiX      XiiiiiiX                    XXggggggggggggggggXggggggggggX X         XXXXXX            XXX                                                    X",
	"YX   XppppppXXssssssssssssssssssX      XX             XXiiX       XiiiiiiX                      XXggggggggggggXXXggggggggXX    X      XXggggXX        XXXttX                                                    X",
	"YX   XXppppXXsssssssssssssssssssX       X              XXXX      XiiiiiiX                         XXgggggggggX  XggggggXX       XXXXXXXggggggXXXXXXXXXtttttX                                                    X",
	"YX     XXpXXsssssssssssssssssssX       X                        XiiiiiiiX                           XXgggggXX   XgggggX         XggggggggggggXXttttttttttttX                                                    X",
	"YX       XXsssssssssssssssssssX                                 XiiiiiiiX                             XXggX     XgggXX          XggggggggggggXtttttttttttttX                                                    X",
	"YX         XXsssssssssssssssssX                                XiiiiiiiX                                XX      XgggX           XXggggggggggXXtttttttttttttX                                                    X",
	"YX          XsssssssXXXXXXXXXX                                XiiiiiiiiX                                         XgX             XgggggggggXXttttttttttttttX                                                    X",
	"YX           XssssXX                                          XiiiiiiiiX                                         XgX             XgggggggggXtttttttttttttttX                                                    X",
	"YX            XsXX                                         XXXiiiiiiiiiiX                                        XggX            XgggggggggXtttttttttttttttX                                                    X",
	"YX            XX                                       XXXXiiiiiiiiiiiiiX                                     XXXXgggXX          XggggggggXttttttttttttttttX                                                    X",
	"YX                                                   XXiiiiiiiiiiiiiXiiiX                             XXX  XXXggggggggX          XggggggggXttttttttttttttttX                                                    X",
	"YX                                                    XXXXXXiiiiiiXX XiX                             XgggXXgggggggggggX         XXggggggggXttttttttttttttttX                                                    X",
	"YX                                                          XXXXXX    X                              XggggggggggggggggX         XgggggggggXttttttttttttttttX                                                    X",
	"YX                                                                                                  XXggggggggggggggggX        XXgggggggggXttttttttttttttttX                                                    X",
	"YX                                                                                                  XgggggggggggggggggX        XggggggggggXttttttttttttttttX                                                    X",
	"YX                                                                                                  XgggggggggggggggXX         XgggggggggXXttttttttttttttttX                                                    X",
	"YX                                                                                                  XgggggggggggggXX           XXggggggggXtttttttttttttttttX                                                    X",
	"YX                                                                                                   XggggggggggggX             XXXgggggXXtttttttttttttttttX                                                    X",
	"YX                                                                                                   XXggggggggggX                 XXXXXXttttttttttttttttttX                                                    X",
	"YX                                                                                                    XXgggggggggX                      XXtttttttttttttttttX                                                    X",
	"YXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	"YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY"
};

Util U;

list<Faction> faccions;
list<Faction>::iterator itf;

/*Creem un iterador predefinit per a cada faccio, ens estalviarà treball més tard

list<Faction>::iterator itf1;
list<Faction>::iterator itf2;
list<Faction>::iterator itf3;
list<Faction>::iterator itf4;
list<Faction>::iterator itf5;
list<Faction>::iterator itf6;
list<Faction>::iterator itf7;
list<Faction>::iterator itf8;*/



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
	inicialitzaExcercits();
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