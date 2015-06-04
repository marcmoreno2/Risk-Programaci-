#pragma once

#include "stdafx.h"
#include <stdio.h>  
#include <conio.h>
#include <string>
//#include <windows.h>  
#include "Console.h"
namespace con = JadedHoboConsole;
using namespace con;
using namespace std;

namespace Utilitats
{
		//creem una classe estàtica anomenada util on tenim variables globals que fem servir per tot el programa
	static class Util{
	public:
		int posy;				//linia de la interfaç menú
		int idPerdedor;			//no s'utilitza actualment
		bool fin;				//marca la fi del joc
	} util;

		static void gotoxy(int x, int y){
			HANDLE hcon;
			hcon = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD dwPos;
			dwPos.X = x;
			dwPos.Y = y;
			SetConsoleCursorPosition(hcon, dwPos);
		}
			//agafem input de teclat (amunt i avall). Els paràmetres de la funció són la opció que sel·leccionem i el nombre d'opcions del menú des del qual s'ha cridat la funció
		static bool teclado(int &ord, int nO){
			bool fiM = false;
			char tecla = _getch();
			if (tecla == 'H' && ord > 1)
				ord--;
			else if (tecla == 'P' && ord < nO)
				ord++;
			else if (tecla == 'H' && ord == 1)
				ord = nO;
			else if (tecla == 'P' && ord == nO)
				ord = 1;
			else if (tecla == 13)
				fiM = true;
			return fiM;
		}
			//imprimeix a la linia de la interfaç menú marcada per resetPosY o posYmas amb el color escollit
		static void printInterface(string frase, WORD color)
		{
			gotoxy(158, util.posy);
			console.SetColor(bgBlack, fgMask);
			console.SetColor(color, bgMask);
			cout << frase;
			util.posy++;
		}
			//imprimeix a la linia de la interfaç menú marcada per resetPosY o posYmas fent servir el color definit anteriorment
		static void printInterface(string frase)
		{
			gotoxy(158, util.posy);
			cout << bg_black << frase;
			util.posy++;
		}
			//imprimeix a la linia de la interfaç menú marcada per resetPosY o posYmas amb el color escollit i el color de fons escollit
		static void printInterfacebg(string frase, WORD color, WORD colorbg)
		{
			gotoxy(158, util.posy);
			console.SetColor(colorbg, fgMask);
			console.SetColor(color, bgMask);
			cout << frase;
			util.posy++;
		}
			//retorna a la primera linia de la interfaç menú més el nombre de linies especificat en el paràmetre
		static void resetPosY(int pos)
		{
			util.posy = 5 + pos;
		}
			//retorna a la primera linia de la interfaç menú
		static void resetPosY()
		{
			util.posy = 5;
		}
			//baixa en una posició la linia de escriptura de la interfaç menú
		static void posyMas()
		{
			util.posy += 1;
		}
			//Esborra la interfaç menú
		static void flushInterface()
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = 2; i < 78; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
			}
		}
			//Esborra la interfaç menú desde la linia especificada per paràmetre
		static void flushInterface(int Origen)
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = Origen; i < 78; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
			}
		}
			//Esborra la interfaç menú desde la linia especificada per paràmetre fins a la linia especificada per paràmtre
		static void flushInterface(int Origen, int Desti)
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = Origen; i < Desti; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
			}
		}
			//Esborra el menú fins al punt especificat per paràmtre
		static void flushMenu(int L)
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = 6; i < L * 2; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
				i++;
			}
		}
			//Esborra el menú des del punt especificat per paràmtre fins al punt especificat per paràmtre
		static void flushMenu(int O, int L)
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = O; i < (O + (L * 2)); i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
				i++;
			}
		}
			//En desús
		/*static void flushInterface(bool f)
		{
			for (int i = 2; i < 78; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
			}
		}*/
			//En desús
		/*static void iniciaFi()
		{
			util.fin = false;
		}*/

	//};
}