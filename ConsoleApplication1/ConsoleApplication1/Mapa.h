#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include <array>


using namespace std;

struct Territoris{
	string nom;
	WORD color;
	int posX_Ex1, posY_Ex1, posX_Ex2, posY_Ex2, id;
	int idPropietari, idPropietariTornAnt;
	bool exPresent, castell;
};

class Mapa {
private:
	char mapa[80][210];
	list<Territoris> territoris;
	list<Territoris>::iterator itt;
public:

	void print();
	Mapa(char m[][210]);
	~Mapa();

	void iniciaTerritoris();
	void update();
	void pintaNoms();
};
