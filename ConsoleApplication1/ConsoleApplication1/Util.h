#pragma once

#include "stdafx.h"
#include <stdio.h>  
#include <conio.h>
#include <string>
//#include <windows.h>  
#include "Console.h"

//using namespace std;
//namespace con = JadedHoboConsole;

	static class Util
	{
	private:
		static int Util::posy;

	public:
		static void Util::gotoxy(int x, int y);
		static void Util::teclado();
		static void Util::printInterface(string, WORD);
		static void Util::printInterface(string);
		static void Util::resetPosY();
		static void Util::flushInterface();
	};