#pragma once

#include "stdafx.h"
#include <string>

using namespace std;

/*class*/ struct Unitats{
//protected:

	int def, atack, exp, lvl, costRec, costMan;
	int bonusVsCav, bonusVsInf, bonusVsSpear, bonusVsArq, bonusVsBuild;
	string nom;

	virtual void setCostMan(int cost)
	{
		costMan = cost;
	}
	
	virtual void setNom(string n)
	{
		nom = n;
	}

	virtual void setCostRec(int cost)
	{
		costRec = cost;
	}

	virtual void setExp(int ex)
	{
		exp = ex;
	}

};

struct General :Unitats{
	int comandament;
};

struct Arquer :Unitats{
//private:
	int def = 10;
	int atack = 25, costRec = 50;
	int costMan = 15;
	int bonusVsCav = 10, bonusVsInf = 0, bonusVsSpear = 15, bonusVsArq = 10, bonusVsBuild = 15;

};