#pragma once

#include "stdafx.h"
#include <stdio.h>  
#include <conio.h>
//#include <windows.h>  
#include "Console.h"

using namespace std;
namespace con = JadedHoboConsole;

static class Util
{
public:
	static void Util::gotoxy(int x, int y){
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos);
	}

	static void Util::teclado(){
		if (_kbhit()){
			char tecla = _getch();
		}
	}

	static void Util::printInterface()
	{
		int posy = 5;
		for (int i = 0; i < 10; i++){
			gotoxy(158, posy);
			cout << con::fg_white << con::bg_black << "Interfaz placeholder: XXXXX"; posy++; posy++;
		}
	}

	static void Util::flushInterface()
	{
		system("pause>>NULL");
		for (int i = 2; i < 78; i++)
		{
			Util::gotoxy(158, i); cout << "                                                 ";
		}
	}
};

