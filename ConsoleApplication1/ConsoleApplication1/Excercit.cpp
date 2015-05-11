#include "stdafx.h"
#include "Excercit.h"

//using namespace Util;
using namespace std;

Excercit::Excercit()
{
}


Excercit::Excercit(int terAct, General gen, list<Unitats>uni, int ide)
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
	for (itu = units.begin(); itu != units.end(); itu++)
	{
		//if (itu->)
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

list<Unitats> Excercit::getUnitats()
{
	return units;
}

void Excercit::setUnitats(list<Unitats> u)
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
			Util::printInterface("L'excercit es mou al territori objectiu");
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
}

void Excercit::afegirUnitat(Unitats u)
{
	units.push_back(u);
}

void Excercit::mostrarUnits()
{
	Util::gotoxy(158, 25);
	cout << con::fg_cyan << "Unitats de l'excercit " << id << ":";
	int i = 0;
	for (itu = units.begin(); itu != units.end(); itu++)
	{
		Util::gotoxy(158, 26 + i);
		i++;
		cout << itu->nom;
	}
}
void Excercit::desbandar(string u, int q)
{
	int i = 0;
	for (itu = units.begin(); itu != units.end(); itu++)
	{
		if (itu->nom == u && i < q)
		{
			units.erase(itu);
			i++;
		}
		//else 
	}
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

