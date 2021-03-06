#pragma once

#include "stdafx.h"
//#include "Console.h"
#include <string>
#include <list>
#include <vector>
#include <iostream>
//#include "Util.h"
//#include "Excercit.h"
//#include "Console.h"
#include "Mapa.h"

using namespace std;



class Faction{
private:
	int or, ingressos, gastos, id, _or, _ingressos, _gastos, gMant, gRec, _gMant, _gRec;
	bool player, viva, tornAcabat;
	
	list <Excercit> excercits;
	list <Excercit>::iterator ite;
	string nom;
	int no_ter;
	vector<int> territoris;
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
	void update(bool);
	bool getPlayer();
	void setOr(int or);
	int getOr();
	void setIngressos(int ing);
	int getIngressos();
	void calculaIngressos();
	void setGastos(int gas);
	int getGastos();
	void calculaGastos();
	void addTErr(int);
	void updateTerr(int);
	void calculaManteniment();
	bool getTorn();
	int getNoTerr();
	void setNoTerr(int);
	void setTorn(bool);
	void muerte();
	bool getViva();
	void getFinances(int torn);
	WORD getColor();
	void imprPropEx();
	Faction();
	Faction(int idcap, int or, bool player, int id, string nom, WORD color);
	~Faction();

};


