#include "stdafx.h"
#include "Faction.h"


Faction::Faction()
{
}


Faction::Faction(int idcap, int or, bool player, int id, string nom, WORD color)
{
	this->id = id; this->or = or;
	this->player = player; this->nom = nom;
	id_capital = idcap;
	this->color = color;

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

void Faction::reclutar(Unitats* u, int idEx)
{
	//list<Unitats *> un;
	Util::resetPosY(13);
	if (or >= u->costRec)
	{
		for (ite = excercits.begin(); ite != excercits.end(); ite++)
		{
			if (ite->getId() == idEx)
				break;
		}
		//un.push_back(&u);
		ite->afegirUnitat(u);
		or -= u->costRec;
		gRec += u->costRec;

		if (player)
		{
			Util::printInterface("Unitat reclutada correctament!", con::fgLoGreen);
		}
	}
	else if (or < u->costRec)
	{
		if (player){
			Util::printInterface("No tens prou or per a reclutar la unitat!", con::fgLoRed);
		}
	}
	system("pause>>null");
	Util::resetPosY();
	Util::flushInterface();
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

void Faction::update()
{
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
	}

	calculaManteniment();
	calculaGastos();
	calculaIngressos();

}

void Faction::getFinances( int torn)
{
	update();
	Util::posyMas();
	Util::printInterface("Or total: " + to_string(or));
	Util::posyMas();
	Util::printInterface("Or total previst el torn seguent: " + to_string(or - gastos + ingressos));
	Util::posyMas();
	if (torn > 1)
	{
		Util::printInterface("Despeses el torn anterior: " + to_string(_gastos));
		Util::posyMas();
		Util::printInterface("	- Reclutament: " + to_string(_gRec));
		Util::posyMas();
		Util::printInterface("	- Manteniment: " + to_string(_gMant));
		Util::posyMas();
		Util::printInterface("Ingressos el torn anterior: " + to_string(_ingressos));
	}
	Util::posyMas();
	Util::printInterface("Despeses previstes aqest torn: " + to_string(gastos));
	Util::posyMas();
	Util::printInterface("	- Reclutament: " + to_string(gRec));
	Util::posyMas();
	Util::printInterface("	- Manteniment: " + to_string(gMant));
	Util::posyMas();
	Util::printInterface("Ingressos previstos aquest torn: " + to_string(gRec));
	Util::posyMas();

	system("pause>null");
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

void Faction::calculaIngressos()
{
	ingressos = 250 * no_ter;
}

void Faction::setGastos(int gas)
{
	gastos = gas;
}

int Faction::getGastos()
{
	return gastos;
}

void Faction::calculaGastos()
{
	
	gastos = gMant + gRec;

}

void Faction::calculaManteniment()
{
	int gMant = 0;
	for (ite = excercits.begin(); ite != excercits.end(); ite++)
	{
		ite->calculaManteniment();
		gMant += ite->getManteniment();
	}

}

WORD Faction::getColor()
{
	return color;
}

