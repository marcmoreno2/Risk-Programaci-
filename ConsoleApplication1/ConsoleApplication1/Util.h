#pragma once

#include "stdafx.h"
#include <stdio.h>  
#include <conio.h>
#include <string>
//#include <windows.h>  
#include "Console.h"

using namespace std;
//namespace con = JadedHoboConsole;

	/*static*/ class Util
	{
	private:
		static int posy;

	public:
		//static bool fin;

		static void gotoxy(int x, int y);
		static void teclado();
		static void printInterface(string, WORD);
		static void printInterface(string);
		static void resetPosY();
		static void flushInterface();
		static void iniciaFi();
		static void flushInterface(bool f);
	};