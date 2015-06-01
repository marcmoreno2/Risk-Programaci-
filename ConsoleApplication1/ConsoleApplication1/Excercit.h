#pragma once

#include <string>
#include <list>
#include "Unitats.h"
#include <vector>
#include <memory>
#include "Util.h"
#include "time.h"
//#include "Territoris.h"
//#include "Mapa.h"
//#include "Main.h"

namespace con = JadedHoboConsole;
using namespace std;

class Excercit{
private:
	int territoriActual, mantenimentEx;
	list<Unitats *>units;
	list<Unitats *>::iterator itu;
	General general;
	float bonusOf[5], totalBonus[5];
	int noTypeUnits[5];
	int totalUnits, idPropietari, id;
	bool movimentD = true, castell, player;
	float fTotal, dTotal, bonusDef;
public:
	void calculaManteniment();
	int getManteniment();
	int getId();
	int getTerritoriAct();
	void setTerritoriAct(int idT);
	void setGeneral(General g);
	General getGeneral();
	list<Unitats *>* getUnitats();
	void setUnitats(list<Unitats *> u);
	int moure(vector<Excercit*> posEx);
	void afegirUnitat(Unitats* u);
	void afegirUnitats(list<Unitats *> u);
	void mostrarUnits();
	void desbandar();
	void desbandar(string, int);
	void calculaBonusDef();
	void calculaBonusOff();
	void calculaAtT();
	void calculaDeT();
	bool atacar(Excercit *e, Excercit *d);
	bool atacar(Excercit *e);
	void update();
	void setIdPropietari(int);
	void setCastell(bool);
	bool getCastell();
	int getIdPropietari();
	float getFTot();
	float getDTot();
	bool getPlayer();
	void setPlayer(bool);
	vector<float> getBonusOf();
	float getBonusDef();
	vector<int> getNoUnitTypes();
	Excercit();
	Excercit(General gen, list<Unitats *>uni, int ide);
	~Excercit();
};