// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include "Main.h"

using namespace std;
//using namespace Util;
namespace con = JadedHoboConsole;
using namespace con;

int torn;


int _tmain(int argc, _TCHAR* argv[])
{
	torn = 0;
	U.fin = false;
	U.resetPosY();
	Mapa a(mapa);
	a.iniciaTerritoris();
	a.print();
	a.pintaNoms();
	U.printInterface("Inicialitzacio de mapa completa,", fgLoCyan);
	U.printInterface("inicialitzant faccions...");
	Sleep(600);
	U.flushInterface();
	U.resetPosY();
	inicialitzaFaccions();
	inicialitzaExcercits();
	U.flushInterface();
	bool torn_acabat;

	//menuPrinc();
	while (!U.fin)
	{
		torn++;
		//update(a, faccions);
		torn_acabat = false;
		while (!torn_acabat)
		{
			torn_acabat = tornJugador(1, torn);
		}
		//tornJugador(2);




	}


	system("pause>>NULL");
	return 0;
}