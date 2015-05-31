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

int Excercit::moure(vector<Excercit*> posEx)
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
	bool menuok = false, result;
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
		vector<Excercit *>defensor;

		for (int i = 0; i < posEx.size(); i++)
		{
			if (posEx[i]->getTerritoriAct() == idDe && posEx[i]->getIdPropietari() != idPropietari)
			{
				exPres = true;
				defensor.push_back(posEx[i]);
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

			int opAt = 1;
			while (!menuok){
				Util::resetPosY(14);
				switch (opAt)
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
				menuok = Util::teclado(opAt, 2);
			}


			if (opAt == 1)
			{
				result = atacar(defensor);
				movimentD = false;
			}
			else
			{
				Util::printInterface("L'excercit cancela el seu moviment", con::fgHiRed);
			}
			Util::posyMas();
			if (result)
			{
				Util::printInterface("L'excercit es mou al territori objectiu", con::fgHiGreen);
				Util::printInterface("Captures el territori");
				Util::resetPosY();
				territoriActual = idDe;
			}
			else {
				Util::printInterface("L'excercit es retira al territori d'origen despres de la derrota", con::fgHiRed);
				Util::resetPosY();
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
	if (result)
		return idDe;
	else return 0;

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
		Util::posyMas();
		Util::printInterface((*itu)->nom);
		Util::printInterface("Salut: " + to_string((*itu)->vida));
		Util::printInterface("Nivell: " + to_string((*itu)->lvl));
		Util::printInterface("Experiencia: " + to_string((*itu)->exp));
		Util::printInterface("Atac: " + to_string((*itu)->atack));
		Util::printInterface("Defensa: " + to_string((*itu)->def));

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
		bonusDef += 100;
	bonusDef += 100;
	bonusDef = bonusDef * (1 + general.comandament / 7) + 25*general.comandament;
}
void Excercit::calculaBonusOff()
{
	for each (float var in bonusOf)
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

	for each (float var in bonusOf)
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

float Excercit::getBonusDef()
{

	return bonusDef;
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

bool Excercit::atacar(vector<Excercit *>exe)
{
	//bool result = false;
	srand(time(NULL));



	vector<Unitats> perduesA;
	vector<Unitats> perduesE;
	Unitats *a;
	float bE = 0;
	int noE[5];
	list<Unitats *>* uE = getUnitats();
	uE->clear();
	list<Unitats *>::iterator ituE;
	float fTotE = 0;
	for (int i = 0; i < 5; i++)
		noE[i] = 0;
	for (int i = 0; i < exe.size(); i++)
	{
		exe[i]->update();
		bE += exe[i]->getBonusDef();

		vector<int> noEAux;
		noEAux = exe[i]->getNoUnitTypes();
		noE[0] += noEAux[0];
		noE[1] += noEAux[1];
		noE[2] += noEAux[2];
		noE[3] += noEAux[3];
		noE[4] += noEAux[4];
		fTotE += exe[i]->getFTot();
		list<Unitats *>* uEAux = exe[i]->getUnitats();
		for (ituE = uEAux->begin(); ituE != uEAux->end(); ituE++)
			uE->push_back(*ituE);
		
	}
	update();

	
	vector<float> bA = getBonusOf();
	vector<int> noA = getNoUnitTypes();
	

	
	//e->getUnitats();
	list<Unitats *>* uA = getUnitats();
	
	list<Unitats *>::iterator ituA;
	
	list<Unitats *> uEP = *uE;
	list<Unitats *> uAP = *uA;

	float puntuacioA = 0, puntuacioE = 0;
	float bonusATAvgA = 0;

	for (int i = 0; i < bA.size(); i++)
	{
		bonusATAvgA += noE[i] * bA[i];
	}
	
	bonusATAvgA /= (uE->size()/5);
	float fTotA = getFTot();
	int uESize = uE->size();
	
	int uASize = uA->size();
	for (ituE = uE->begin(); ituE != uE->end();)
	{
		float randA = rand() % 50 + 25;
		float randE = rand() % 50 + 50;

		float vidAnt = (*ituE)->vida;
		float vidaPost = (*ituE)->vida - (((fTotA + bonusATAvgA + randA) / uESize) - ((*ituE)->def + ((bE + randE) / (uASize))));

		if (vidaPost < vidAnt)
			(*ituE)->vida = vidaPost;

		
		if ((*ituE)->vida <= 0)
		{
			a = *ituE;
			perduesE.emplace_back(*a);
			ituE = uE->erase(ituE);
		}
		else { puntuacioE += (*ituE)->vida; ituE++; }
	}
	
	for (ituA = uA->begin(); ituA != uA->end();)
	{
		float randA = rand() % 50 + 25;
		float randE = rand() % 50 + 50;
		float vidAnt = (*ituA)->vida;
		float vidaPost = (*ituA)->vida - (((fTotE + bE + randE) / uASize) - ((*ituA)->def + ((randA) / (uESize))));

		if (vidaPost < vidAnt)
			(*ituA)->vida = vidaPost;
		

		if ((*ituA)->vida <= 0)
		{
			a = *ituA;
			perduesA.emplace_back(*a);
			ituA = uA->erase(ituA);
		}
		else { puntuacioA += (*ituA)->vida; ituA++; }
	}

	if (puntuacioA > puntuacioE)
	{
		if (player)
		{
			Util::posyMas();
			Util::printInterface("--------------------------------------------------------------", con::fgHiGreen);
			Util::printInterface("     L'excercit ha derrotat a l'excercit defensor enemic:");
			Util::printInterface("--------------------------------------------------------------");
			Util::posyMas();
			Util::printInterface("  Estadistiques:", con::fgHiCyan);
			Util::posyMas();
			Util::printInterface("     -Unitats perdudes:" + to_string(perduesA.size()));
			for each(Unitats uni in perduesA)
			{
				Util::printInterface("        " + uni.nom + " lvl: " + to_string(uni.lvl));
			}
			Util::posyMas();
			Util::printInterface("     -Unitats eliminades:" + to_string(perduesE.size()));
			for each(Unitats uni in perduesE)
			{
				Util::printInterface("        " + uni.nom + " lvl: " + to_string(uni.lvl));
			}
			Util::posyMas();
		}
		return true;
	}
	else
	{
		if (player)
		{
			Util::posyMas();
			Util::printInterface("---------------------------------------------------------------", con::fgHiRed);
			Util::printInterface("  L'excercit ha estat derrotat per l'excercit defensor enemic:");
			Util::printInterface("---------------------------------------------------------------");
			Util::posyMas();
			Util::printInterface("  Estadistiques:", con::fgHiCyan);
			Util::posyMas();
			Util::printInterface("     -Unitats perdudes:" + to_string(perduesA.size()));
			for each(Unitats uni in perduesA)
			{
				Util::printInterface("        " + uni.nom + " nivell: " + to_string(uni.lvl));
			}
			Util::posyMas();
			Util::printInterface("     -Unitats eliminades:" + to_string(perduesE.size()));
			for each(Unitats uni in perduesE)
			{
				Util::printInterface("        " + uni.nom + " nivell: " + to_string(uni.lvl));
			}
			Util::posyMas();
		}
		return false;
	}
	
	//return result;
}

bool Excercit::getPlayer()
{
	return player;
}

void Excercit::setPlayer(bool p)
{
	player = p;
}

void Excercit::update()
{
	noTypeUnits[5];
	//for each(int var in noTypeUnits)
	for (int elem : noTypeUnits)
	{
		elem = 0;
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