#pragma once

#include <iostream>
#include <list>
#include <vector>
#include "Excercit.h"
#include <array>
#include "Util.h"
#include "Territoris.h"

using namespace std;


class Mapa {
public:
	char mapa[80][225];
	list<Territoris> territoris;
	list<Territoris>::iterator itt;


	void print();
	Mapa(char m[][225]);
	Mapa();
	~Mapa();
	
	void iniciaTerritoris();
	list<Territoris>::iterator getIterTerr(int id);
	int update(int idTerr, int idFaccio);
	void update(vector<Excercit*>posEx);
	void pintaNoms();
};
