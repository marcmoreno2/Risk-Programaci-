// ConsoleApplication1.cpp: define el punto de entrada de la aplicaci�n de consola.
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
		//inicialitzaci� del programa

	torn = 0;																//marca el torn en el que estem
	util.fin = false;														//boole� que controla el bucle principal
		//mapa
	inicialitzaMapa();
	main.a.iniciaTerritoris();
	main.a.print();
	main.a.pintaNoms();
		//funcions relacionades amb la interfa� gr�fica del programa:
	resetPosY();															//retorna a la primera linia de la interfa�
	printInterface("Inicialitzacio de mapa completa,", fgLoCyan);			//imprimeix a la linia de la interfa� menu marcada per resetPosY o posYmas amb el color escollit
	printInterface("inicialitzant faccions...");							//imprimeix a la linia de la interfa� menu marcada per resetPosY o posYmas fent servir el color definit anteriorment
	Sleep(500);
	flushInterface();														//Esborra la interfa� menu
	resetPosY();
		//faccions
	inicialitzaFaccions();
		//excercits
	inicialitzaExcercits();
	flushInterface();
	bool torn_acabat = false;												//boole� que senyala el fi del torn del jugador
		//bucle principal
	while (!util.fin)
	{
		torn++;																//canvia de torn
		update(torn_acabat);												//realitza un update de tots els objectes del programa. Passem un boole� que ens permet saber si el torn que 
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