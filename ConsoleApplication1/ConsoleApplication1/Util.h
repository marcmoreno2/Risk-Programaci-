#pragma once

#include "stdafx.h"
#include <stdio.h>  
#include <conio.h>
#include <string>
//#include <windows.h>  
#include "Console.h"

using namespace std;
//namespace con = JadedHoboConsole;

	class Util
	{
	private:
		static int posy;

	public:
		bool fin;

		static void gotoxy(int x, int y);
		static bool teclado(int &ord, int nO);
		static void printInterface(string, WORD);
		static void printInterface(string);
		static void printInterfacebg(string, WORD);
		static void printMenu(int);
		static void resetPosY();
		static void resetPosY(int);
		static void posyMas();
		static void flushInterface();
		static void flushMenu(int L);
		static void flushMenu(int O, int L);
		static void iniciaFi();
		static void flushInterface(bool f);
	};