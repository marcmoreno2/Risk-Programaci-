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
		//creem una classe est�tica anomenada util on tenim variables globals que fem servir per tot el programa
	static class Util{
	public:
		int posy;				//linia de la interfa� men�
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
			//agafem input de teclat (amunt i avall). Els par�metres de la funci� s�n la opci� que sel�leccionem i el nombre d'opcions del men� des del qual s'ha cridat la funci�
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
			//imprimeix a la linia de la interfa� men� marcada per resetPosY o posYmas amb el color escollit
		static void printInterface(string frase, WORD color)
		{
			gotoxy(158, util.posy);
			console.SetColor(bgBlack, fgMask);
			console.SetColor(color, bgMask);
			cout << frase;
			util.posy++;
		}
			//imprimeix a la linia de la interfa� men� marcada per resetPosY o posYmas fent servir el color definit anteriorment
		static void printInterface(string frase)
		{
			gotoxy(158, util.posy);
			cout << bg_black << frase;
			util.posy++;
		}
			//imprimeix a la linia de la interfa� men� marcada per resetPosY o posYmas amb el color escollit i el color de fons escollit
		static void printInterfacebg(string frase, WORD color, WORD colorbg)
		{
			gotoxy(158, util.posy);
			console.SetColor(colorbg, fgMask);
			console.SetColor(color, bgMask);
			cout << frase;
			util.posy++;
		}
			//retorna a la primera linia de la interfa� men� m�s el nombre de linies especificat en el par�metre
		static void resetPosY(int pos)
		{
			util.posy = 5 + pos;
		}
			//retorna a la primera linia de la interfa� men�
		static void resetPosY()
		{
			util.posy = 5;
		}
			//baixa en una posici� la linia de escriptura de la interfa� men�
		static void posyMas()
		{
			util.posy += 1;
		}
			//Esborra la interfa� men�
		static void flushInterface()
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = 2; i < 78; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
			}
		}
			//Esborra la interfa� men� desde la linia especificada per par�metre
		static void flushInterface(int Origen)
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = Origen; i < 78; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
			}
		}
			//Esborra la interfa� men� desde la linia especificada per par�metre fins a la linia especificada per par�mtre
		static void flushInterface(int Origen, int Desti)
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = Origen; i < Desti; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
			}
		}
			//Esborra el men� fins al punt especificat per par�mtre
		static void flushMenu(int L)
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = 6; i < L * 2; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
				i++;
			}
		}
			//Esborra el men� des del punt especificat per par�mtre fins al punt especificat per par�mtre
		static void flushMenu(int O, int L)
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = O; i < (O + (L * 2)); i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
				i++;
			}
		}
			//En des�s
		/*static void flushInterface(bool f)
		{
			for (int i = 2; i < 78; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
			}
		}*/
			//En des�s
		/*static void iniciaFi()
		{
			util.fin = false;
		}*/

	//};
}