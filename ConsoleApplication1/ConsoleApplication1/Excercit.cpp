#include "stdafx.h"
#include "Excercit.h"

//using namespace Util;
using namespace std;

Excercit::Excercit()
{
}


Excercit::Excercit(int terAct, General gen, list<Unitats *>uni, int ide)
{
	territoriActual = terAct;
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
		//Util::printInterface(to_string((*itu)->nom, con::fgHiWhite));
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

list<Unitats *> Excercit::getUnitats()
{
	return units;
}

void Excercit::setUnitats(list<Unitats *> u)
{
	units = u;
}

void Excercit::moure(int idDe)
{
	int posTid[4];
	//posTid.fill(NULL);
	//bool ok = posTid.empty();
	//cout << endl << ok << endl;

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
		//Util::gotoxy(158, 27); cout << con::fg_red << "L'excercit ja es troba al territori objectiu";
		Util::printInterface("L'excercit ja es troba al territori objectiu", con::fgHiRed);
		Util::resetPosY();
	}
	else if (!movimentD)
	{
		//Util::gotoxy(158, 25); cout << con::fg_red << "Aquest excercit ja s'ha mogut aquest torn";
		Util::printInterface("Aquest excercit ja s'ha mogut aquest torn", con::fgHiRed);
		Util::resetPosY();
	}
	else if (corr)
	{
			//Util::gotoxy(158, 27); cout << con::fg_green << "L'excercit es mou al territori objectiu";
			Util::printInterface("L'excercit es mou al territori objectiu", con::fgHiGreen);
			Util::resetPosY();
			territoriActual = idDe;
			movimentD = false;
	}
	else {
		//Util::gotoxy(158, 27); cout << con::fg_red << "L'excercit no es pot moure al territori desitjat,";
		//Util::gotoxy(158, 28); cout << "el territori de desti ha d'estar en contacte";
		//Util::gotoxy(158, 29); cout << "directe amb el d'origen";

		Util::printInterface("L'excercit no es pot moure al territori desitjat,", con::fgHiRed);
		Util::printInterface("el territori de desti ha d'estar en contacte");
		Util::printInterface("directe amb el d'origen");
		Util::resetPosY();
	}

	/*Util::gotoxy(158, 25); cout << con::fg_red << "                                                 ";
	Util::gotoxy(158, 26); cout << "                                                 ";
	Util::gotoxy(158, 27); cout << "                                  ";*/
	/*cout << endl;
	for (int elem : posTid)
	cout << elem << endl;*/
	Util::flushInterface();
}

void Excercit::afegirUnitat(Unitats *u)
{
	units.emplace_back(u);
	//units.push_back(u);
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
	Util::resetPosY();
	Util::flushInterface();
}
void Excercit::desbandar(string u, int q)
{
	//Util::printInterface(to_string(units.size()), con::fgHiYellow);
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
	//Util::printInterface(to_string(units.size()), con::fgHiYellow);
	Util::flushInterface();
	Util::resetPosY();
}
void Excercit::desbandar(){}
void Excercit::calculaBonusDef(){}
void Excercit::calculaBonusOff(){}
bool Excercit::atacar(Excercit e)
{
	bool result = false;
	return result;
}
void Excercit::update(){}

int Excercit::getManteniment()
{
	//Util::printInterface(to_string(mantenimentEx));
	return mantenimentEx;
}