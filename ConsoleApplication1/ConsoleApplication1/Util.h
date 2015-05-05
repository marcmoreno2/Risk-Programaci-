#pragma once

#include <stdio.h>  
#include <conio.h>
#include <windows.h>  
#include "Console.h"

namespace con = JadedHoboConsole;

namespace Util
{

	void gotoxy(int x, int y){
		HANDLE hcon;
		hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos);
	}

	void teclado(){
		if (_kbhit()){
			char tecla = _getch();
		}
	}

	void printInterface()
	{
		int posy = 5;
		for (int i = 0; i < 10; i++){
			gotoxy(158, posy);
			cout << con::fg_white << con::bg_black << "Interfaz placeholder: XXXXX"; posy++; posy++;
		}
	}
};

