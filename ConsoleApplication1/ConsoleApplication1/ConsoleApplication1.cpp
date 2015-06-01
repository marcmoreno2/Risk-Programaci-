// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include "Main.h"

using namespace std;
//using namespace Util;
namespace con = JadedHoboConsole;
using namespace con;
using namespace main;
int torn;


int _tmain(int argc, _TCHAR* argv[])
{
	torn = 0;
	U.fin = false;
	inicialitzaMapa();
	a.iniciaTerritoris();
	a.print();
	a.pintaNoms();
	U.resetPosY();
	U.printInterface("Inicialitzacio de mapa completa,", fgLoCyan);
	U.printInterface("inicialitzant faccions...");
	Sleep(500);
	U.flushInterface();
	U.resetPosY();
	inicialitzaFaccions();
	inicialitzaExcercits();
	U.flushInterface();
	bool torn_acabat = false;
	//menuPrinc();
	while (!U.fin)
	{
		torn++;

		while (!torn_acabat)
		{
			torn_acabat = tornJugador(1, torn);
		}
		torn_acabat = false;
		while (!torn_acabat)
		{
			torn_acabat = tornJugador(7, torn);
		}
		//tornJugador(2);
		update(torn_acabat);
		torn_acabat = false;




	}


	system("pause>>NULL");
	return 0;
}