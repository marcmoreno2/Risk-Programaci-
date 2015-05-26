#pragma once

//#include "stdafx.h"
//#include "Console.h"
#include <string>
#include <list>
//#include "Util.h"
#include "Excercit.h"
#include "Console.h"

using namespace std;
//using namespace Util;


class Faction{
private:
	int or, ingressos, gastos, id, _or, _ingressos, _gastos, gMant, gRec, _gMant, _gRec;
	bool player, viva, tornAcabat;
	
	list <Excercit> excercits;
	list <Excercit>::iterator ite;
	string nom;
	int no_ter;
	int territoris[12];
	int id_capital;
	WORD color;
public:
	list<Excercit>::iterator getIterEx(int idEx);
	void setExcercit(Excercit e);
	void reclutar(Unitats* u, int idEx);
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
	bool getTorn();
	void setTorn(bool);
	void getFinances(int torn);
	WORD getColor();
	Faction();
	Faction(int idcap, int or, bool player, int id, string nom, WORD color);
	~Faction();

};


