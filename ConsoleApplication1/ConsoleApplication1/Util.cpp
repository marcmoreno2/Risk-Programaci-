#include "stdafx.h"
#include "Util.h"


namespace con = JadedHoboConsole;
using namespace con;
using namespace std;



int Util::posy = 5;

void Util::gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void Util::teclado(){
	if (_kbhit()){
		char tecla = _getch();
	}
}

void Util::printInterface(string frase, WORD color)
{
	Util::gotoxy(158, posy);
	console.SetColor(color, bgMask);
	cout << bg_black << frase;
	Util::posy++; //Util::posy++;
}
void Util::printInterface(string frase)
{
	Util::gotoxy(158, posy);
	//console.SetColor(color, fgMask);
	cout << bg_black << frase;
	Util::posy++; //Util::posy++;
}

void Util::resetPosY()
{
	Util::posy = 5;
}

void Util::flushInterface()
{
	system("pause>>NULL");
	for (int i = 2; i < 78; i++)
	{
		Util::gotoxy(158, i); cout << "                                                  ";
	}
}