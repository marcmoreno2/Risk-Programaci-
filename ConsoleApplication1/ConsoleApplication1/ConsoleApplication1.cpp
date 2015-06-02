// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//
#include "stdafx.h"
#include "Main.h"

using namespace std;
//using namespace Util;
namespace cons = JadedHoboConsole;
using namespace cons;
using namespace maine;
using namespace Utilitats;
int torn;


int _tmain(int argc, _TCHAR* argv[])
{
	torn = 0;
	util.fin = false;
	inicialitzaMapa();
	main.a.iniciaTerritoris();
	main.a.print();
	main.a.pintaNoms();
	resetPosY();
	printInterface("Inicialitzacio de mapa completa,", fgLoCyan);
	printInterface("inicialitzant faccions...");
	Sleep(500);
	flushInterface();
	resetPosY();
	inicialitzaFaccions();
	inicialitzaExcercits();
	flushInterface();
	bool torn_acabat = false;
	//menuPrinc();
	while (!util.fin)
	{
		torn++;
		update(torn_acabat);
		torn_acabat = false;
		while (!torn_acabat)
		{
			torn_acabat = tornJugador(1, torn);
		}
		torn_acabat = false;
		while (!torn_acabat)
		{
			torn_acabat = tornJugador(7, torn);
		}
	}


	system("pause>>NULL");
	return 0;
}