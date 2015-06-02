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
		//inicialització del programa

	torn = 0;																//marca el torn en el que estem
	util.fin = false;														//booleà que controla el bucle principal
		//mapa
	inicialitzaMapa();
	main.a.iniciaTerritoris();
	main.a.print();
	main.a.pintaNoms();
		//funcions relacionades amb la interfaç gràfica del programa:
	resetPosY();															//retorna a la primera linia de la interfaç
	printInterface("Inicialitzacio de mapa completa,", fgLoCyan);			//imprimeix a la linia de la interfaç menu marcada per resetPosY o posYmas amb el color escollit
	printInterface("inicialitzant faccions...");							//imprimeix a la linia de la interfaç menu marcada per resetPosY o posYmas fent servir el color definit anteriorment
	Sleep(500);
	flushInterface();														//Esborra la interfaç menu
	resetPosY();
		//faccions
	inicialitzaFaccions();
		//excercits
	inicialitzaExcercits();
	flushInterface();
	bool torn_acabat = false;												//booleà que senyala el fi del torn del jugador
		//bucle principal
	while (!util.fin)
	{
		torn++;																//canvia de torn
		update(torn_acabat);												//realitza un update de tots els objectes del programa. Passem un booleà que ens permet saber si el torn que 
		torn_acabat = false;
		while (!torn_acabat)
		{
			torn_acabat = tornJugador(1, torn);								//torn del jugador amb id 1, es pasa el torn per a realitzar comprovacions
		}
		torn_acabat = false;
		while (!torn_acabat)
		{
			torn_acabat = tornJugador(7, torn);								//torn del jugador amb id 7, es pasa el torn per a realitzar comprovacions
		}
	}


	system("pause>>NULL");
	return 0;
}