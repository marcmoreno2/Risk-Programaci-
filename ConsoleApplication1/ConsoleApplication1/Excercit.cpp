#include "stdafx.h"
#include "Excercit.h"

//using namespace Util;
using namespace std;

Excercit::Excercit()
{
}


Excercit::Excercit(General gen, list<Unitats *>uni, int ide)
{
	general = gen;
	units = uni;
	id = ide;
}


Excercit::~Excercit()
{
}


void Excercit::calculaManteniment()
{
	mantenimentEx = 0;
	for (itu = units.begin(); itu != units.end(); itu++)
	{
		mantenimentEx += (*itu)->costMan;
	}
}

int Excercit::getId()
{
	return id;
}

int Excercit::getTerritoriAct()
{
	return territoriActual;
}

void Excercit::setTerritoriAct(int idT)
{
	territoriActual = idT;
}

void Excercit::setGeneral(General g)
{
	general = g;
}

General Excercit::getGeneral()
{
	return general;
}

list<Unitats *>* Excercit::getUnitats()
{
	return &units;
}

void Excercit::setUnitats(list<Unitats *> u)
{
	units = u;
}

void Excercit::moure(vector<Excercit*> posEx)
{
	int posTid[4];
	switch (territoriActual)
	{
	case 1:
		posTid[0] = 2;
		break;
	case 2:
		posTid[0] = 1;
		posTid[1] = 3;
		break;
	case 3:
		posTid[0] = 2;
		posTid[1] = 4;
		posTid[2] = 5;
		break;
	case 4:
		posTid[0] = 3;
		posTid[1] = 5;
		posTid[2] = 6;
		break;
	case 5:
		posTid[0] = 3;
		posTid[1] = 4;
		posTid[2] = 6;
		posTid[3] = 7;
		break;
	case 6:
		posTid[0] = 4;
		posTid[1] = 5;
		posTid[2] = 7;
		posTid[3] = 8;
		break;
	case 7:
		posTid[0] = 5;
		posTid[1] = 6;
		break;
	case 8:
		posTid[0] = 6;
		break;
	}

	int idDe = 1;
	bool menuok = false;
	Util::printInterface("Selecciona el territori de desti de l'excercit:", con::fgHiCyan);
	Util::posyMas();
	while (!menuok){
		Util::resetPosY(8);
		Util::printInterface(to_string(idDe));
		menuok = Util::teclado(idDe, 8);
	}
	Util::posyMas();
	bool act1 = false, corr = false;
	for (int i = 0; i < 4; i++)
	{
		if (idDe == territoriActual)
			act1 = true;
		else if (idDe == posTid[i])
			corr = true;
	}
	if (act1)
	{
		Util::printInterface("L'excercit ja es troba al territori objectiu", con::fgHiRed);
		Util::resetPosY();
	}
	else if (!movimentD)
	{
		Util::printInterface("Aquest excercit ja s'ha mogut aquest torn", con::fgHiRed);
		Util::resetPosY();
	}
	else if (corr)
	{
		bool exPres = false;
		Excercit *defensor;

		for (int i = 0; i < posEx.size(); i++)
		{
			if (posEx[i]->getTerritoriAct() == idDe && posEx[i]->getIdPropietari() != idPropietari)
			{
				exPres = true;
				defensor = posEx[1];
				break;
			}
		}


		if (!exPres)
		{
			Util::printInterface("L'excercit es mou al territori objectiu", con::fgHiGreen);
			Util::resetPosY();
			territoriActual = idDe;
			movimentD = false;
		}
		else
		{
			menuok = false;
			Util::printInterface("Hi ha un excercit enemic al territori objectiu.", con::fgHiYellow);
			Util::printInterface("Atacar?");

			while (!menuok){
				Util::resetPosY(14);
				switch (idDe)
				{
				case 1:
					Util::printInterfacebg("Si", con::fgBlack, con::bgHiYellow);
					Util::posyMas();
					Util::printInterface("No", con::fgHiYellow);
					break;
				case 2:
					Util::printInterface("Si", con::fgHiYellow);
					Util::posyMas();
					Util::printInterfacebg("No", con::fgBlack, con::bgHiYellow);
					break;
				}
				//Util::printInterface(to_string(idDe));
				menuok = Util::teclado(idDe, 2);
			}

			switch (idDe)
			{
			case 1:
				atacar(defensor);
				break;
			case 2:
				Util::printInterface("L'excercit cancela el seu moviment", con::fgHiRed);
				break;
			}

		Util::resetPosY();
		}
	}
	else {
		Util::printInterface("L'excercit no es pot moure al territori desitjat,", con::fgHiRed);
		Util::printInterface("el territori de desti ha d'estar en contacte");
		Util::printInterface("directe amb el d'origen");
		Util::resetPosY();
	}

	/*cout << endl;
	for (int elem : posTid)
	cout << elem << endl;*/

	system("pause>>null");
	Util::flushInterface();
}

void Excercit::afegirUnitat(Unitats* u)
{
	units.push_back(u);
}

void Excercit::afegirUnitats(list<Unitats *> u)
{
	for (list<Unitats *>::iterator it = u.begin(); it != u.end(); it++)
	{
		units.emplace_back(*it);
	}
}

void Excercit::mostrarUnits()
{
	Util::printInterface("Unitats de l'excercit " + to_string(id) + ":", con::fgHiCyan);
	for (itu = units.begin(); itu != units.end(); itu++)
	{
		Util::printInterface((*itu)->nom);
		Util::printInterface("Nivell: " + to_string((*itu)->lvl));
		Util::printInterface("Experiencia: " + to_string((*itu)->exp));
		Util::printInterface("Atac: " + to_string((*itu)->atack));
		Util::printInterface("Defensa: " + to_string((*itu)->def));
		Util::printInterface("                                              ");
	}
	system("pause>>null");
	Util::resetPosY();
	Util::flushInterface();
}
void Excercit::desbandar(string u, int q)
{
	bool elim = false;
	int i = 0;
	for (itu = units.begin(); itu != units.end();)
	{
		if ((*itu)->nom == u && i < q)
		{
			elim = true;
			itu = units.erase(itu);
			i++;
		}
		else
		{
			itu++;
		}
	}
	if (elim){
		Util::printInterface("Eliminades " + to_string(i) + " unitat/s de " + u + ".", con::fgHiYellow);
	}
	else{
		Util::printInterface("No s'ha trobat cap unitat del tipus desitjat a l'excercit en questio.", con::fgHiYellow);
	}
	system("pause>>null");
	Util::flushInterface();
	Util::resetPosY();
}
void Excercit::desbandar(){}

void Excercit::setCastell(bool c){	castell = c; }
bool Excercit::getCastell(){ return castell; }

void Excercit::calculaBonusDef()
{ 
	bonusDef = 0;
	if (castell)
		bonusDef = 100;
	bonusDef *= (1 + general.comandament / 7);
}
void Excercit::calculaBonusOff()
{
	for each (int var in bonusOf)
	{
		var = 0;
	}

	for (itu = units.begin(); itu != units.end(); itu++)
	{
		bonusOf[0] += (*itu)->bonusVsArq;
		bonusOf[1] += (*itu)->bonusVsInf;
		bonusOf[2] += (*itu)->bonusVsSpear;
		bonusOf[3] += (*itu)->bonusVsCav;
		bonusOf[4] += (*itu)->bonusVsBuild;
	}

	for each (int var in bonusOf)
	{
		var *= (1 + general.comandament/10);
	}
}

vector<float> Excercit::getBonusOf()
{
	vector<float> bonus;

	for each(int var in bonusOf)
	{
		bonus.push_back(var);
	}

	return bonus;
}

vector<float> Excercit::getBonusDef()
{
	vector<float> bonus;

	for each (int var in bonusOf)
	{
		bonus.push_back(var);
	}

	return bonus;
}

float Excercit::getFTot()
{
	return fTotal;
}

float Excercit::getDTot()
{
	return dTotal;
}

vector<int> Excercit::getNoUnitTypes()
{
	vector<int> noUnits;

	for each (int var in noTypeUnits)
	{
		noUnits.push_back(var);
	}

	return noUnits;
}

bool Excercit::atacar(Excercit *e)
{
	bool result = false;
	

	e->update();
	update();

	vector<float> bE = e->getBonusDef();
	vector<float> bA = getBonusOf();
	vector<int> noE = e->getNoUnitTypes();
	vector<int> noA = getNoUnitTypes();
	
	list<Unitats *>* uE = e->getUnitats();
	list<Unitats *>* uA = getUnitats();
	list<Unitats *>::iterator itu;
	
	for (itu = uE->begin(); itu != uE->end(); itu++)
	{

	}

	for (itu = uE->begin(); itu != uE->end(); itu++)
	{

	}




	return result;
}

void Excercit::update()
{
	int noTypeUnits[5];
	for each(int var in noTypeUnits)
	{
		var = 0;
	}

	for (itu = units.begin(); itu != units.end(); itu++)
	{
		if ((*itu)->nom == "Arquer")
			noTypeUnits[0] += 1;
		else if ((*itu)->nom == "Soldat")
			noTypeUnits[1] += 1;
		else if ((*itu)->nom == "Llancer")
			noTypeUnits[2] += 1;
		else if ((*itu)->nom == "Cavaller")
			noTypeUnits[3] += 1;
		else if ((*itu)->nom == "Arma de setge")
			noTypeUnits[4] += 1;
	}

	calculaBonusDef();
	calculaBonusOff();
	calculaAtT();
	calculaDeT();
	//
}

void Excercit::calculaAtT()
{
	fTotal = 0;
	for (itu = units.begin(); itu != units.end(); itu++)
	{
		fTotal += (*itu)->atack;
	}
}

void Excercit::calculaDeT()
{
	dTotal = 0;
	for (itu = units.begin(); itu != units.end(); itu++)
	{
		dTotal += (*itu)->def;
	}
}

void Excercit::setIdPropietari(int id)
{
	idPropietari = id;
}

int Excercit::getIdPropietari()
{
	return idPropietari;
}

int Excercit::getManteniment()
{
	calculaManteniment();
	//Util::printInterface(to_string(mantenimentEx));
	return mantenimentEx;
}