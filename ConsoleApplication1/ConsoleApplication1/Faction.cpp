#include "stdafx.h"
#include "Faction.h"

using namespace Utilitats;

Faction::Faction()
{
}


Faction::Faction(int idcap, int or, bool player, int id, string nom, WORD color)
{
	this->id = id; this->or = or;
	this->player = player; this->nom = nom;
	id_capital = idcap;
	this->color = color;
	viva = true;
	territoris.push_back(idcap);
}


Faction::~Faction()
{
}


list<Excercit>::iterator Faction::getIterEx(int idEx)
{
	for (ite = excercits.begin(); ite != excercits.end(); ite++)
	{
		if (ite->getId() == idEx)
			break;
	}
	return ite;
}

void Faction::setExcercit(Excercit e)
{
	for (ite = excercits.begin(); ite != excercits.end();)
	{
		if (ite->getId() == e.getId())
			ite = excercits.erase(ite);
		else ite++;
	}
	excercits.push_back(e);
}

	//Update de la facci� cridada per l'update general
void Faction::update(bool t)
{
	tornAcabat = t;

	if (tornAcabat)
	{
		_or = or;
		or = or - gMant + ingressos;
		_ingressos = ingressos;
		_gastos = gastos;
		_gMant = gMant;
		_gRec = gRec;
		gRec = 0;
		tornAcabat = false;
		getIterEx(1)->update(territoris);
		getIterEx(2)->update(territoris);
		if (or < 0)
		{
			util.fin = true;
			util.idPerdedor = id;
		}		
	}

	no_ter = 0;
	for each(int t in territoris)
		no_ter++;

	calculaManteniment();
	calculaGastos();
	calculaIngressos();
	
}

int Faction::getNoTerr()
{
	return this->no_ter;
}

void Faction::setNoTerr(int s)
{
	this->no_ter += s;
}

void Faction::muerte()
{
	viva = false;
}

bool Faction::getViva()
{
	return viva;
}

void Faction::updateTerr(int idT)
{
	vector<int>::iterator it;
	no_ter = 0;
	for (it = territoris.begin(); it != territoris.end();)
	{
		
		if (*it == idT)
			it = territoris.erase(it);
		else { no_ter++; it++; }
	}
}

void Faction::addTErr(int t)
{
	territoris.push_back(t);
}

void Faction::calculaGastos()
{

	this->gastos = gMant + gRec;

}

void Faction::calculaManteniment()
{
	gMant = 0;
	for (ite = excercits.begin(); ite != excercits.end(); ite++)
	{
		ite->calculaManteniment();
		gMant += ite->getManteniment();
	}

}

void Faction::calculaIngressos()
{
	this->ingressos = 0;
	for (no_ter = 1; no_ter <= territoris.size(); no_ter++)
	{
		this->ingressos += 500;
	}
}
	//Imprimeix per pantalla la 'situaci� financera' de la facci�
void Faction::getFinances(int torn)
{
	update(false);
	resetPosY(3);
	printInterface("Or total: " + to_string(or));
	posyMas();
	printInterface("Or total previst el torn seguent: " + to_string(or - gastos + ingressos));
	posyMas();
	if (torn > 1)
	{
		printInterface("Despeses el torn anterior: " + to_string(_gastos));
		posyMas();
		printInterface("	- Reclutament: " + to_string(_gRec));
		posyMas();
		printInterface("	- Manteniment: " + to_string(_gMant));
		posyMas();
		printInterface("Ingressos el torn anterior: " + to_string(_ingressos));
		posyMas();
	}
	printInterface("Despeses previstes aqest torn: " + to_string(gastos));
	posyMas();
	printInterface("	- Reclutament: " + to_string(gRec));
	posyMas();
	printInterface("	- Manteniment: " + to_string(gMant));
	posyMas();
	printInterface("Ingressos previstos aquest torn: " + to_string(ingressos));
	posyMas();
	resetPosY();

	system("pause>null");
}
	//Funci� que comprova el reclutament d'una unitat cap a un exc�rcit en concret
void Faction::reclutar(Unitats* u, int idEx)
{
	resetPosY(15);
	printInterface("                                                                 ");
	resetPosY(15);
	if (or >= u->costRec)
	{
		for (ite = excercits.begin(); ite != excercits.end(); ite++)
		{
			if (ite->getId() == idEx)
				break;
		}

		ite->afegirUnitat(u);
		or -= u->costRec;
		gRec += u->costRec;

		if (player)
		{
			printInterface("Unitat reclutada correctament!", fgLoGreen);
		}
	}
	else if (or < u->costRec)
	{
		if (player){
			printInterface("No tens prou or per a reclutar la unitat!", fgLoRed);
		}
	}
	resetPosY();
}

void Faction::mostrarUnitats(int idEx)
{
	for (ite = excercits.begin(); ite != excercits.end(); ite++)
	{
		if (ite->getId() == idEx)
			break;
	}
	ite->mostrarUnits();
}

void Faction::setIdCap(int id)
{
	id_capital = id;
}

int Faction::getIdCap()
{
	return id_capital;
}

string Faction::getNom()
{
	return nom;
}

void Faction::setNom(string n)
{
	nom = n;
}

int Faction::getId()
{
	return id;
}

void Faction::setId(int id)
{
	this->id = id;
}

bool Faction::getTorn()
{
	return tornAcabat;
}

void Faction::setTorn(bool t)
{
	tornAcabat = t;
}

bool Faction::getPlayer()
{
	return player;
}

void Faction::setOr(int or)
{
	this->or = or;
}

int Faction::getOr()
{
	return or;
}

void Faction::setIngressos(int ing)
{
	ingressos = ing;
}

int Faction::getIngressos()
{
	return ingressos;
}

void Faction::setGastos(int gas)
{
	gastos = gas;
}

int Faction::getGastos()
{
	return gastos;
}

WORD Faction::getColor()
{
	return color;
}

void Faction::imprPropEx()
{
	for (ite = excercits.begin(); ite != excercits.end(); ite++)
	{
		ite->setIdPropietari(id);
		ite->setTerritoriAct(id_capital);
		ite->setPlayer(player);
	}
}
