#pragma once

#include "stdafx.h"
#include <iostream>
#include "Faction.h"

using namespace std;
//using namespace Util;
namespace con = JadedHoboConsole;
using namespace con;

void inicialitzaFaccions()
{
	Faction p(1, 500, false, 2, "Portugal");
	Faction e(2, 500, true, 1, "Espanya");
	Faction f(3, 500, false, 3, "Francia");
	Faction i(4, 500, false, 4, "Italia");
	Faction a(5, 500, false, 5, "Alemania");
	Faction r(6, 500, false, 6, "Russia");
	Faction g(7, 500, false, 7, "Grecia");
	Faction t(8, 500, false, 8, "Turquia");
	faccions.push_back(p);
	faccions.push_back(e);
	faccions.push_back(f);
	faccions.push_back(i);
	faccions.push_back(a);
	faccions.push_back(r);
	faccions.push_back(g);
	faccions.push_back(t);

	/*for (itf = faccions.begin(); itf != faccions.end(); itf++)
	{
	switch (itf->getId())
	{
	case 1:
	itf1 = itf;
	break;
	case 2:
	itf2 = itf;
	break;
	case 3:
	itf3 = itf;
	break;
	case 4:
	itf4 = itf;
	break;
	case 5:
	itf5 = itf;
	break;
	case 6:
	itf6 = itf;
	break;
	case 7:
	itf7 = itf;
	break;
	case 8:
	itf8 = itf;
	break;
	}
	}*/
}

void menuUnitats(list<Faction>::iterator itf, int numEx)
{
	U.flushInterface();
	U.resetPosY();
	U.printInterface("Reclutar unitat:", fgHiCyan);
	U.posyMas();
	int op = 1, opA, nO = 5;
	bool fiMenu = false;
	string op1 = "Arquer";
	string op2 = "Soldat";
	string op3 = "Llancer";
	string op4 = "Cavaller";
	string op5 = "Arma de setge";
	while (!fiMenu)
	{
		switch (op)
		{
		case 1:
			U.printInterfacebg(op1, fgBlack);
			U.posyMas();
			U.printInterface(op2, fgHiCyan);
			U.posyMas();
			U.printInterface(op3);
			U.posyMas();
			U.printInterface(op4);
			U.posyMas();
			U.printInterface(op5);
			U.posyMas();
			break;
		case 2:
			U.printInterface(op1, fgHiCyan);
			U.posyMas();
			U.printInterfacebg(op2, fgBlack);
			U.posyMas();
			U.printInterface(op3, fgHiCyan);
			U.posyMas();
			U.printInterface(op4);
			U.posyMas();
			U.printInterface(op5);
			U.posyMas();
			break;
		case 3:
			U.printInterface(op1, fgHiCyan);
			U.posyMas();
			U.printInterface(op2);
			U.posyMas();
			U.printInterfacebg(op3, fgBlack);
			U.posyMas();
			U.printInterface(op4, fgHiCyan);
			U.posyMas();
			U.printInterface(op5);
			U.posyMas();
			break;
		case 4:
			U.printInterface(op1, fgHiCyan);
			U.posyMas();
			U.printInterface(op2);
			U.posyMas();
			U.printInterface(op3);
			U.posyMas();
			U.printInterfacebg(op4, fgBlack);
			U.posyMas();
			U.printInterface(op5, fgHiCyan);
			U.posyMas();
			break;
		case 5:
			U.printInterface(op1, fgHiCyan);
			U.posyMas();
			U.printInterface(op2);
			U.posyMas();
			U.printInterface(op3);
			U.posyMas();
			U.printInterface(op4);
			U.posyMas();
			U.printInterfacebg(op5, fgBlack);
			U.posyMas();
			break;
		default:
			break;
		}
		opA = op;
		fiMenu = U.teclado(op, nO);
		U.resetPosY(2);
		U.flushMenu(nO);
	}

	switch (opA) {
	case 1:
		itf->reclutar(new Arquer, numEx);
		break;
	case 2:
		itf->reclutar(new Soldat, numEx);
		break;
	case 3:
		itf->reclutar(new Llancer, numEx);
		break;
	case 4:
		itf->reclutar(new Cavalleria, numEx);
		break;
	case 5:
		itf->reclutar(new Siege, numEx);
		break;
	}
}

int menuPrinc()
{
	int op = 1, opA, nO = 4;
	bool fiMenu = false;
	string op1 = "Mostrar Unitats d'un excercit";
	string op2 = "Moure un excercit d'un territori a un altre";
	string op3 = "Reclutar unitats per a un excercit";
	string op4 = "Acabar el torn";
	while (!fiMenu)
	{
		switch (op)
		{
		case 1:
			U.printInterfacebg(op1, fgBlack);
			U.posyMas();
			U.printInterface(op2, fgHiWhite);
			U.posyMas();
			U.printInterface(op3);
			U.posyMas();
			U.printInterface(op4);
			U.posyMas();
			break;
		case 2:
			U.printInterface(op1, fgHiWhite);
			U.posyMas();
			U.printInterfacebg(op2, fgBlack);
			U.posyMas();
			U.printInterface(op3, fgHiWhite);
			U.posyMas();
			U.printInterface(op4);
			U.posyMas();
			break;
		case 3:
			U.printInterface(op1, fgHiWhite);
			U.posyMas();
			U.printInterface(op2);
			U.posyMas();
			U.printInterfacebg(op3, fgBlack);
			U.posyMas();
			U.printInterface(op4, fgHiWhite);
			U.posyMas();
			break;
		case 4:
			U.printInterface(op1, fgHiWhite);
			U.posyMas();
			U.printInterface(op2);
			U.posyMas();
			U.printInterface(op3);
			U.posyMas();
			U.printInterfacebg(op4, fgBlack);
			U.posyMas();
			break;
		case 5:
			break;
		default:
			break;
		}
		opA = op;
		fiMenu = U.teclado(op, nO);
		U.resetPosY();
		U.flushMenu(nO);
	}
	U.flushInterface();
	return opA;
}

bool tornJugador(int num)
{
	bool fi = false;
	int op;
	switch (num)
	{
	case 1:
		op = menuPrinc();
		break;
	case 2:
		op = menuPrinc();
		break;
	}
	/*Excercit ex;
	Unitats aa;
	Faction ff;
	list<Unitats *> ut = ex.getUnitats();*/
	int numEx = 1;
	bool menuok = false;
	switch (op)
	{
	case 1:
		U.printInterface("Selecciona l'excercit que vols mostrar:", con::fgHiCyan);
		U.posyMas();
		while (!menuok){
			U.resetPosY(3);
			U.printInterface(to_string(numEx));
			menuok = U.teclado(numEx, 2);
		}
		U.posyMas();
		for (itf = faccions.begin(); itf != faccions.end(); itf++)
		{
			if (itf->getId() == num)
				break;
		}

		itf->getIterEx(numEx)->mostrarUnits();

		break;
	case 2:
		U.printInterface("Selecciona l'excercit que vols moure:", con::fgHiCyan);
		U.posyMas();
		while (!menuok){
			U.resetPosY(3);
			U.printInterface(to_string(numEx));
			menuok = U.teclado(numEx, 2);
		}
		U.posyMas();
		for (itf = faccions.begin(); itf != faccions.end(); itf++)
		{
			if (itf->getId() == num)
				break;
		}

		itf->getIterEx(numEx)->moure();

		break;
	case 3:
		U.printInterface("Selecciona l'excercit per al que vols reclutar:", con::fgHiCyan);
		U.posyMas();
		while (!menuok){
			U.resetPosY(3);
			U.printInterface(to_string(numEx));
			menuok = U.teclado(numEx, 2);
		}
		U.posyMas();

		for (itf = faccions.begin(); itf != faccions.end(); itf++)
		{
			if (itf->getId() == num)
				break;
		}

		menuUnitats(itf, numEx);
		break;
	case 4:
		fi = true;
		break;
	}
	return fi;
}


void inicialitzaExcercits()
{
	General g;
	list<Unitats *> u;
	Excercit e(1, g, u, 1);
	Excercit b(1, g, u, 2);
	Arquer arq;
	Soldat sol;
	Cavalleria cav;
	Llancer llan;
	Siege set;
	u.push_back(&arq);
	u.push_back(&arq);
	u.emplace_back(&sol);
	u.emplace_back(&cav);
	u.emplace_back(&llan);
	u.emplace_back(&llan);
	e.afegirUnitats(u);
	u.clear();
	u.push_back(&llan);
	u.emplace_back(&set);
	u.emplace_back(&arq);
	u.emplace_back(&sol);
	b.afegirUnitats(u);
}

void update(Mapa &a, list<Faction> &l)
{
	list<Faction>::iterator it;
	for (it = l.begin(); it != l.end(); it++)
	{
		it->update();
		//if ()
		it->getIterEx(0)->getTerritoriAct();
	}
	a.update();
	a.print();
}