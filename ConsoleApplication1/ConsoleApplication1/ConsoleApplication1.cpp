// ConsoleApplication1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include "Console.h"
using namespace std;
namespace con = JadedHoboConsole;

struct Territoris{
	string nom, propietari;
	int posX_Ex1, posY_Ex1, posX_Ex2, posY_Ex2;
	int idPropietari;
	bool exPresent, castell;
};

class Mapa {
private:
	char mapa[130][200];
	list<Territoris> territoris;
	list<Territoris>::iterator it;
public:
	
	void initializeMap(){
	
		char mapa[130][200] = {
			"                                                                                                                                                                                                       ",
			" XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" X                                                                                                                                                                                                   X ",
			" XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX ",
			"                                                                                                                                                                                                       "
		};

	}
	void print(){
		for (int i = 0; i <= 80; i++){
			for (int j = 0; j <= 200; j++){
				/*if (i == 0 || i == 80)
				{
					cout << ' ';
				}
				else if (j == 1 || j == 199)
				{
					cout << 'X';
				}
				else if ((i == 1 || i == 79) && j != 0 && j!= 200)
				{
					cout << 'X';
				}
				else cout << ' ';*/

				switch (mapa[i][j])
				{
				case 'X':
					cout << 'X';
					break;
				default:
					cout << ' ';
					break;

				}
				cout << con::bg_black << con::fg_white << mapa[i][j];
			}
			cout << endl;
		}
	}
	Mapa(){};
	~Mapa(){};

};

int _tmain(int argc, _TCHAR* argv[])
{

	Mapa a;
	a.initializeMap();
	a.print();
	system("pause>>NULL");
	return 0;
}