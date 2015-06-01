#include "stdafx.h"
#include "Excercit.h"

//using namespace Util;
using namespace std;
using namespace Utilitats;

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
		posTid[2] = 7;
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
		posTid[2] = 8;
		posTid[3] = 4;
		break;
	case 8:
		posTid[0] = 7;
		break;
	}

	int idDe = 1;
	bool menuok = false, result = false;
	resetPosY(6);
	printInterface("Selecciona el territori de desti de l'excercit:", fgHiCyan);
	while (!menuok){
		resetPosY(9);
		printInterface(to_string(idDe));
		menuok = teclado(idDe, 8);
	}
	posyMas();
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
		printInterface("L'excercit ja es troba al territori objectiu", fgHiRed);
		resetPosY();
	}
	else if (!this->movimentD)
	{
		printInterface("Aquest excercit ja s'ha mogut aquest torn", fgHiRed);
		resetPosY();
	}
	else if (corr)
	{
		bool exPres = false;
		vector<Excercit *>defensor;

		for (int i = 0; i < posEx.size(); i++)
		{
			if ((posEx[i]->getTerritoriAct() == idDe) && (posEx[i]->getIdPropietari() != this->idPropietari))
			{
				exPres = true;
				defensor.push_back(posEx[i]);
			}
		}


		if (!exPres)
		{
			printInterface("L'excercit es mou al territori objectiu", fgHiGreen);
			resetPosY();
			territoriActual = idDe;
			result = true;
			movimentD = false;
		}
		else
		{
			menuok = false;
			printInterface("Hi ha un excercit enemic al territori objectiu.", fgHiYellow);
			printInterface("Atacar?");

			int opAt = 1;
			while (!menuok){
				resetPosY(14);
				switch (opAt)
				{
				case 1:
					printInterfacebg("Si", fgBlack, bgHiYellow);
					posyMas();
					printInterface("No", fgHiYellow);
					break;
				case 2:
					printInterface("Si", fgHiYellow);
					posyMas();
					printInterfacebg("No", fgBlack, bgHiYellow);
					break;
				}
				menuok = teclado(opAt, 2);
			}


			if (opAt == 1)
			{
				if (defensor.size() == 2){
					result = this->atacar(defensor[0], defensor[1]);
				}
				else { result = this->atacar(defensor[0]); }
				movimentD = false;
			}
			else
			{
				printInterface("L'excercit cancela el seu moviment", fgHiRed);
			}
			posyMas();
			if (result)
			{
				printInterface("L'excercit es mou al territori objectiu", fgHiGreen);
				printInterface("Captures el territori");
				resetPosY();
				territoriActual = idDe;
			}
			else {
				printInterface("L'excercit es retira al territori d'origen despres de la derrota", fgHiRed);
				resetPosY();
			}

		resetPosY();
		}
	}
	else {
		printInterface("L'excercit no es pot moure al territori desitjat,", fgHiRed);
		printInterface("el territori de desti ha d'estar en contacte");
		printInterface("directe amb el d'origen");
		resetPosY();
	}

	/*cout << endl;
	for (int elem : posTid)
	cout << elem << endl;*/

	system("pause>>null");
	flushInterface();
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
	resetPosY(6);
	printInterface("Unitats de l'excercit " + to_string(id) + ":", fgHiCyan);

	for (itu = units.begin(); itu != units.end(); itu++)
	{
		posyMas();
		printInterface((*itu)->nom);
		printInterface("Salut: " + to_string((*itu)->vida));
		printInterface("Nivell: " + to_string((*itu)->lvl));
		printInterface("Experiencia: " + to_string((*itu)->exp));
		printInterface("Atac: " + to_string((*itu)->atack));
		printInterface("Defensa: " + to_string((*itu)->def));

	}
	system("pause>>null");
	resetPosY();
	flushInterface();
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
		printInterface("Eliminades " + to_string(i) + " unitat/s de " + u + ".", fgHiYellow);
	}
	else{
		printInterface("No s'ha trobat cap unitat del tipus desitjat a l'excercit en questio.", fgHiYellow);
	}
	system("pause>>null");
	flushInterface();
	resetPosY();
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

bool Excercit::atacar(Excercit *e, Excercit *d)
{
	srand(time(NULL));


	list<Unitats *>* uA = this->getUnitats();
	vector<Unitats> perduesA;
	vector<Unitats> perduesE;
	Unitats *a;
	float bE = 0;
	vector<float> bEAux;
	vector<int> noE;

	list<Unitats *>::iterator ituE;
	float fTotE = 0;
	list<Unitats *>* uE1 = e->getUnitats();
	list<Unitats *> uE1P = *uE1;
	list<Unitats *>* uE2 = d->getUnitats();
	list<Unitats *> uE2P = *uE2;

	/*e->update();
	d->update();
	this->update();*/

	bE += e->getBonusDef();
	bE += d->getBonusDef();
	
	vector<float>bEAux2;
	bEAux = e->getBonusOf();
	bEAux2 = d->getBonusOf();
	bEAux[0] += bEAux2[0];
	bEAux[1] += bEAux2[1];
	bEAux[2] += bEAux2[2];
	bEAux[3] += bEAux2[3];
	bEAux[4] += bEAux2[4];

	vector<int> noEAux;
	noE = e->getNoUnitTypes();
	noEAux = d->getNoUnitTypes();
	noE[0] += noEAux[0];
	noE[1] += noEAux[1];
	noE[2] += noEAux[2];
	noE[3] += noEAux[3];
	noE[4] += noEAux[4];

	fTotE += e->getFTot() + d->getFTot();
		
	
	
	
	
	vector<float> bA = getBonusOf();
	vector<int> noA = getNoUnitTypes();
	
	
	list<Unitats *>::iterator ituA;
	
	
	list<Unitats *> uAP = *uA;

	float puntuacioA = 0, puntuacioE = 0;
	float bonusATAvgA = 0;

	for (int i = 0; i < bA.size(); i++)
	{
		bE += noA[i] * bEAux[i];
		bonusATAvgA += noE[i] * bA[i];
	}
	
	int uESize = uE1->size() + uE2->size();
	int uASize = uA->size();

	bonusATAvgA /= (uESize);
	bE /= (uASize);
	float fTotA = getFTot();
	

	for (ituE = uE1->begin(); ituE != uE1->end();)
	{
		float randA = rand() % 50 + 50;
		float randE = rand() % 50;

		float vidAnt = (*ituE)->vida;
		float vidaPost = (*ituE)->vida - (((fTotA + bonusATAvgA + randA) / uESize) - ((*ituE)->def + ((bE + randE) / (2*uASize))));

		if (vidaPost < vidAnt)
			(*ituE)->vida = vidaPost;

		
		if ((*ituE)->vida <= 0)
		{
			a = *ituE;
			perduesE.emplace_back(*a);
			ituE = uE1->erase(ituE);
		}
		else { puntuacioE += (*ituE)->vida; ituE++; }
	}

	for (ituE = uE2->begin(); ituE != uE2->end();)
	{
		float randA = rand() % 50 + 50;
		float randE = rand() % 50;

		float vidAnt = (*ituE)->vida;
		float vidaPost = (*ituE)->vida - (((fTotA + bonusATAvgA + randA) / uESize) - ((*ituE)->def + ((bE + randE) / (2*uASize))));

		if (vidaPost < vidAnt)
			(*ituE)->vida = vidaPost;


		if ((*ituE)->vida <= 0)
		{
			a = *ituE;
			perduesE.emplace_back(*a);
			ituE = uE2->erase(ituE);
		}
		else { puntuacioE += (*ituE)->vida; ituE++; }
	}
	
	for (ituA = uA->begin(); ituA != uA->end();)
	{
		float randA = rand() % 75 + 50;
		float randE = rand() % 50;
		float vidAnt = (*ituA)->vida;
		float vidaPost = (*ituA)->vida - (((fTotE + bE + randE) / uASize) - ((*ituA)->def + ((bonusATAvgA + randA) / (2*uESize))));

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


	for each(Unitats *uni in *uE1)
	{
		uni->exp += (perduesA.size() * 100) + (perduesE.size() * 25);
		//uni->Update();
	}

	for each(Unitats *uni in *uE2)
	{
		uni->exp += (perduesA.size() * 100) + (perduesE.size() * 25);
		//uni->Update();
	}

	for each(Unitats *uni in *uA)
	{
		uni->exp += (perduesE.size() * 100) + (perduesA.size() * 25);
		//uni->Update();
	}


	bool result = resultat(puntuacioA, puntuacioE, perduesA, perduesE, noE, noA);

	return result;
}



bool Excercit::atacar(Excercit *e)
{
	//bool result = false;
	srand(time(NULL));


	list<Unitats *>* uA = this->getUnitats();
	vector<Unitats> perduesA;
	vector<Unitats> perduesE;
	Unitats *a;
	float bE = 0, fTotE = 0;
	vector<float> bEAux;
	vector<int> noE;

	list<Unitats *>::iterator ituE;
	list<Unitats *>* uE = e->getUnitats();
	list<Unitats *> uEP = *uE;
	
	/*e->update();
	update();*/

	bE = e->getBonusDef();
	bEAux = e->getBonusOf();
	fTotE = e->getFTot();
	noE = e->getNoUnitTypes();


	vector<float> bA = getBonusOf();
	vector<int> noA = getNoUnitTypes();
	list<Unitats *>::iterator ituA;
	list<Unitats *> uAP = *uA;

	float puntuacioA = 0, puntuacioE = 0;
	float bonusATAvgA = 0;

	for (int i = 0; i < bA.size(); i++)
	{
		bE += noA[i] * bEAux[i];
		bonusATAvgA += noE[i] * bA[i];
	}

	int uESize = uE->size();
	int uASize = uA->size();

	bonusATAvgA /= (uESize / 5);
	bE /= (uASize / 5);
	float fTotA = getFTot();


	for (ituE = uE->begin(); ituE != uE->end();)
	{
		float randA = rand() % 50 + 50;
		float randE = rand() % 50;

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
		float randA = rand() % 75 + 50;
		float randE = rand() % 50;
		float vidAnt = (*ituA)->vida;
		float vidaPost = (*ituA)->vida - (((fTotE + bE + randE) / uASize) - ((*ituA)->def + ((bonusATAvgA + randA) / (uESize))));

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

	bool result = resultat(puntuacioA, puntuacioE, perduesA, perduesE, noE, noA);

	for each(Unitats *uni in *uE)
	{
		uni->exp += (perduesA.size() * 100 + (perduesE.size() * 25));
		//uni->Update();
	}

	for each(Unitats *uni in *uA)
	{
		uni->exp += (perduesE.size() * 100) + (perduesA.size() * 25);
		//uni->Update();
	}

	return result;
}

bool Excercit::resultat(float PA, float PE, vector<Unitats> perduesA, vector<Unitats> perduesE, vector<int> noE, vector<int> noA)
{
	if (PA > PE)
	{
		if (player)
		{
			posyMas();
			printInterface("--------------------------------------------------------------", fgHiGreen);
			printInterface("     L'excercit ha derrotat a l'excercit defensor enemic:");
			printInterface("--------------------------------------------------------------");
			posyMas();
			printInterface("  Estadistiques:", fgHiCyan);
			posyMas();
			printInterface("     -Unitats desplegades:");
			posyMas();
			printInterface("	       -Arquers: " + to_string(noA[0]));
			posyMas();
			printInterface("	       -Soldats: " + to_string(noA[1]));
			posyMas();
			printInterface("	       -Llancers: " + to_string(noA[2]));
			posyMas();
			printInterface("	       -Cavallers: " + to_string(noA[3]));
			posyMas();
			printInterface("	       -Armes de setge: " + to_string(noA[4]));
			posyMas();
			printInterface("     -Unitats perdudes:" + to_string(perduesA.size()));
			for each(Unitats uni in perduesA)
			{
				printInterface("        " + uni.nom + " lvl: " + to_string(uni.lvl));
			}
			posyMas();
			printInterface("     -Unitats desplegades per l'enemic:");
			posyMas();
			printInterface("	       -Arquers: " + to_string(noE[0]));
			posyMas();
			printInterface("	       -Soldats: " + to_string(noE[1]));
			posyMas();
			printInterface("	       -Llancers: " + to_string(noE[2]));
			posyMas();
			printInterface("	       -Cavallers: " + to_string(noE[3]));
			posyMas();
			printInterface("	       -Armes de setge: " + to_string(noE[4]));
			posyMas();
			printInterface("     -Unitats eliminades:" + to_string(perduesE.size()));
			for each(Unitats uni in perduesE)
			{
				printInterface("        " + uni.nom + " lvl: " + to_string(uni.lvl));
			}
			posyMas();
		}
		return true;
	}
	else
	{
		if (player)
		{
			posyMas();
			printInterface("---------------------------------------------------------------", fgHiRed);
			printInterface("  L'excercit ha estat derrotat per l'excercit defensor enemic:");
			printInterface("---------------------------------------------------------------");
			posyMas();
			printInterface("  Estadistiques:", fgHiCyan);
			posyMas();
			printInterface("     -Unitats desplegades:");
			posyMas();
			printInterface("	       -Arquers: " + to_string(noA[0]));
			posyMas();
			printInterface("	       -Soldats: " + to_string(noA[1]));
			posyMas();
			printInterface("	       -Llancers: " + to_string(noA[2]));
			posyMas();
			printInterface("	       -Cavallers: " + to_string(noA[3]));
			posyMas();
			printInterface("	       -Armes de setge: " + to_string(noA[4]));
			posyMas();
			printInterface("     -Unitats perdudes:" + to_string(perduesA.size()));
			for each(Unitats uni in perduesA)
			{
				printInterface("        " + uni.nom + " lvl: " + to_string(uni.lvl));
			}
			posyMas();
			printInterface("     -Unitats desplegades per l'enemic:");
			posyMas();
			printInterface("	       -Arquers: " + to_string(noE[0]));
			posyMas();
			printInterface("	       -Soldats: " + to_string(noE[1]));
			posyMas();
			printInterface("	       -Llancers: " + to_string(noE[2]));
			posyMas();
			printInterface("	       -Cavallers: " + to_string(noE[3]));
			posyMas();
			printInterface("	       -Armes de setge: " + to_string(noE[4]));
			posyMas();
			printInterface("     -Unitats eliminades:" + to_string(perduesE.size()));
			for each(Unitats uni in perduesE)
			{
				printInterface("        " + uni.nom + " nivell: " + to_string(uni.lvl));
			}
			posyMas();
		}
		return false;
	}
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
	//noTypeUnits[5];
	//for each(int var in noTypeUnits)
	for (int elem : noTypeUnits)
	{
		elem = 0;
	}

	for (itu = units.begin(); itu != units.end(); itu++)
	{
		(*itu)->Update();
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
	this->movimentD = true;
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