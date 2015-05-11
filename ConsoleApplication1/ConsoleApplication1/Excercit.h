#pragma once

//#include "stdafx.h"
//#include "Util.h"
#include <string>
#include <list>
#include "Unitats.h"
//#include "Console.h"
#include "Unitats.h"
#include "Mapa.h"

namespace con = JadedHoboConsole;
//using namespace Util;
using namespace std;

class Excercit{
private:
	int territoriActual, mantenimentEx;
	list<Unitats>units;
	list<Unitats>::iterator itu;
	General general;
	float bonus;
	int totalUnits, idPropietari, id;
	bool movimentD = true;
	float fTotal, dTotal;
public:
	void calculaManteniment();
	int getId();
	int getTerritoriAct();
	void setTerritoriAct(int idT);
	void setGeneral(General g);
	General getGeneral();
	list<Unitats> getUnitats();
	void setUnitats(list<Unitats> u);
	void moure(int idDe);
	void afegirUnitat(Unitats u);
	void mostrarUnits();
	void desbandar();
	void desbandar(string, int);
	void calculaBonusDef();
	void calculaBonusOff();
	bool atacar(Excercit e);
	void update();
	Excercit();
	Excercit(int terAct, General gen, list<Unitats>uni, int ide);
	~Excercit();
};