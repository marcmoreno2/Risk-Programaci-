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

bool Util::teclado(int ord){
	//if (_kbhit()){
	bool fiM = false;
		char tecla = _getch();
		if (tecla == 'H' && ord > 1)
		{
			ord--;
		}
		else if (tecla == 'P' && ord < 3)
		{
			ord++;
		}
		else if (tecla == 13)
			fiM = true;
		return fiM;
	//}
}

void Util::printInterface(string frase, WORD color)
{
	Util::gotoxy(158, posy);
	console.SetColor(bgBlack, fgMask);
	console.SetColor(color, bgMask);
	cout << bg_black << frase;
	Util::posy++; //Util::posy++;
}
void Util::printInterfacebg(string frase, WORD color)
{
	Util::gotoxy(158, posy);
	console.SetColor(bgHiWhite, fgMask);
	//cout << bg_white;
	console.SetColor(color, bgMask);
	cout << frase;
	Util::posy++; //Util::posy++;
}
void Util::printInterface(string frase)
{
	Util::gotoxy(158, posy);
	//console.SetColor(color, fgMask);
	cout << bg_black << frase;
	Util::posy++; //Util::posy++;
}

/*void Util::printMenu(int op)
{
	bool fiMenu = false;
	char tecla;
	while (!fiMenu)
	{
		switch (op)
		{
		case 1:
			Util::printInterfacebg("Opcio 1", fgBlack);
			Util::posyMas();
			Util::printInterface("Opcio 2", fgHiWhite);
			Util::posyMas();
			Util::printInterface("Opcio 3");
			Util::posyMas();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
		}
		op = Util::teclado(op);
		//system("PAUSE>>NULL");
		//Util::printInterface(to_string(tecla));
		cout << tecla;
	}
}*/

void Util::resetPosY()
{
	posy = 5;
}

void Util::posyMas()
{
	posy += 1;
}

void Util::flushInterface()
{
	//system("pause>>NULL");
	console.SetColor(bgBlack, fgMask);
	for (int i = 2; i < 78; i++)
	{
		Util::gotoxy(158, i); cout << "                                                  ";
	}
}

void Util::flushInterface(bool f)
{
	for (int i = 2; i < 78; i++)
	{
		Util::gotoxy(158, i); cout << "                                                  ";
	}
}

/*void Util::iniciaFi()
{
	fin = false;
}*/