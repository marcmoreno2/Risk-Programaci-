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
	static class Util{
	public:
		int posy;
		int idPerdedor;
		bool fin;
	} util;
		/*void gotoxy(int x, int y);
		bool teclado(int &ord, int nO);
		void printInterface(string, WORD);
		void printInterface(string);
		void printInterfacebg(string, WORD, WORD);
		void printMenu(int);
		void resetPosY();
		void resetPosY(int);
		void posyMas();
		void flushInterface();
		void flushInterface(int);
		void flushInterface(int, int);
		void flushMenu(int L);
		void flushMenu(int O, int L);
		void iniciaFi();
		void flushInterface(bool f);*/

		static void gotoxy(int x, int y){
			HANDLE hcon;
			hcon = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD dwPos;
			dwPos.X = x;
			dwPos.Y = y;
			SetConsoleCursorPosition(hcon, dwPos);
		}

		static bool teclado(int &ord, int nO){
			bool fiM = false;
			char tecla = _getch();
			if (tecla == 'H' && ord > 1)
			{
				ord--;
			}
			else if (tecla == 'P' && ord < nO)
			{
				ord++;
			}
			else if (tecla == 13)
				fiM = true;
			return fiM;
		}

		static void printInterface(string frase, WORD color)
		{
			gotoxy(158, util.posy);
			console.SetColor(bgBlack, fgMask);
			console.SetColor(color, bgMask);
			cout << frase;
			util.posy++;
		}
		static void printInterfacebg(string frase, WORD color, WORD colorbg)
		{
			gotoxy(158, util.posy);
			console.SetColor(colorbg, fgMask);
			console.SetColor(color, bgMask);
			cout << frase;
			util.posy++;
		}
		static void printInterface(string frase)
		{
			gotoxy(158, util.posy);
			cout << bg_black << frase;
			util.posy++;
		}

		static void resetPosY(int pos)
		{
			util.posy = 5 + pos;
		}

		static void resetPosY()
		{
			util.posy = 5;
		}


		static void posyMas()
		{
			util.posy += 1;
		}

		static void flushInterface()
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = 2; i < 78; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
			}
		}

		static void flushInterface(int Origen)
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = Origen; i < 78; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
			}
		}

		static void flushInterface(int Origen, int Desti)
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = Origen; i < Desti; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
			}
		}

		static void flushMenu(int L)
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = 6; i < L * 2; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
				i++;
			}
		}

		static void flushMenu(int O, int L)
		{
			console.SetColor(bgBlack, fgMask);
			for (int i = O; i < (O + (L * 2)); i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
				i++;
			}
		}

		static void flushInterface(bool f)
		{
			for (int i = 2; i < 78; i++)
			{
				gotoxy(158, i); cout << "                                                                 ";
			}
		}

		static void iniciaFi()
		{
			util.fin = false;
		}

	//};
}