#pragma once

//#include "stdafx.h"
//#include "Console.h"
#include <string>
#include <list>
//#include "Util.h"
#include "Excercit.h"
//#include "Unitats.h"
//#include "Mapa.h"

using namespace std;
using namespace Util;


class Faction{
private:
	int or, ingressos, gastos, id;
	bool player, viva;
	list <Excercit> excercits;
	list <Excercit>::iterator ite;
	string nom;
	int no_ter;
	int territoris[12];
	int id_capital;
	string color;
public:
	list<Excercit>::iterator getIterEx(int idEx);
	void setExcercit(Excercit e);
	void reclutar(Unitats u, int idEx);
	void mostrarUnitats(int idEx);
	void setIdCap(int id);
	int getIdCap();
	string getNom();
	void setNom(string n);
	int getId();
	void setId(int id);
	void update();
	bool getPlayer();
	void setOr(int or);
	int getOr();
	void setIngressos(int ing);
	int getIngressos();
	void calculaIngressos();
	void setGastos(int gas);
	int getGastos();
	void calculaGastos();
	void calculaManteniment();
	Faction();
	Faction(int idcap, int or, bool player, int id, string nom);
	~Faction();

};


