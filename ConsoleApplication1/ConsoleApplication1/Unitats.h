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

	virtual void Update()
	{
		if (exp >= (1500 + (500 * (lvl - 1))))
		{
			lvl += 1;
		}
	}

	virtual void lvlUp(int lvlup)
	{
		lvl += lvlup;
	}

};

struct General :Unitats{
	int comandament;
};

struct Arquer :Unitats{
//private:
	Arquer(int lvl) :Unitats()
	{
		nom = "Arquer";
		this->lvl = lvl;
		def = 10 + 1 * (lvl - 1);
		atack = 25 + 2 * (lvl - 1);
		costRec = 50 + 25 * (lvl - 1);
		costMan = 15 + 5 * (lvl - 1);
		bonusVsCav = 10 + 1 * (lvl - 1);
		bonusVsInf = 0;
		bonusVsSpear = 15 + 1 * (lvl - 1);
		bonusVsArq = 10 + 1 * (lvl - 1);
		bonusVsBuild = 15 + 1 * (lvl - 1);
	}

	void Update()
	{
		//Unitats::Update();
		if (exp >= (1500 + (500 * (lvl - 1))))
		{
			lvl += 1;
		}
		def = 10 + 1 * (lvl - 1);
		atack = 25 + 2 * (lvl - 1);
		costRec = 50 + 25 * (lvl - 1);
		costMan = 15 + 5 * (lvl - 1);
		bonusVsCav = 10 + 1 * (lvl - 1);
		bonusVsInf = 0;
		bonusVsSpear = 15 + 1 * (lvl - 1);
		bonusVsArq = 10 + 1 * (lvl - 1);
		bonusVsBuild = 15 + 1 * (lvl - 1);
	}

};