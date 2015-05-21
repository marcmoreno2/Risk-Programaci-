#pragma once

#include "stdafx.h"
#include <string>

using namespace std;

class Unitats{
public:

	float def, atack;
	int exp, costRec, costMan, lvl;
	float bonusVsCav, bonusVsInf, bonusVsSpear, bonusVsArq, bonusVsBuild;
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
		//Update();
	}

	Unitats(int lvl, int exp)
	{
		this->lvl = lvl;
		this->exp = exp;		
	}
	Unitats()
	{
		lvl = 1;
		exp = 0;
	}
	
};

class General : public Unitats{
public:
	int comandament;

	General() : Unitats()
	{
		nom = "General";
		comandament = (rand() % 2 + (1 * (lvl - 1)));
		costMan = 0;
		costRec = 0;
	}

	General(int lvl, int exp) :Unitats(lvl, exp)
	{
		nom = "General";
		comandament = (rand() % 2 + (1 * (lvl - 1)));
		costMan = 0;
		costRec = 0;
		Update();
	}
};

class Arquer : public Unitats{
public:

	Arquer() :Unitats()
	{
		nom = "Arquer";
		def = 10;
		atack = 25;
		costRec = 50;
		costMan = 15;
		bonusVsCav = 10;
		bonusVsInf = 0;
		bonusVsSpear = 15;
		bonusVsArq = 10;
		bonusVsBuild = 15;
	}

	Arquer(int lvl, int exp) :Unitats(lvl, exp)
	{
		nom = "Arquer";
		def = 10;
		atack = 25;
		costRec = 50;
		costMan = 15;
		bonusVsCav = 10;
		bonusVsInf = 0;
		bonusVsSpear = 15;
		bonusVsArq = 10;
		bonusVsBuild = 15;
		Update();
	}

	void Update()
	{
		Unitats::Update();
		def += 0.5 * (lvl - 1);
		atack += 1.5 * (lvl - 1);
		costRec += 25 * (lvl - 1);
		costMan += 5 * (lvl - 1);
		bonusVsCav += 1 * (lvl - 1);
		bonusVsInf += 0 * (lvl - 1);
		bonusVsSpear += 1 * (lvl - 1);
		bonusVsArq += 1 * (lvl - 1);
		bonusVsBuild += 1 * (lvl - 1);
	}

};

class Soldat : public Unitats{
public:
	Soldat() :Unitats()
	{
		nom = "Soldat";
		def = 20;
		atack = 10;
		costRec = 30;
		costMan = 10;
		bonusVsCav = 0;
		bonusVsInf = 0;
		bonusVsSpear = 20;
		bonusVsArq = 20;
		bonusVsBuild = 0;
	}
	Soldat(int lvl, int exp) :Unitats(lvl, exp)
	{
		nom = "Soldat";
		def = 20;
		atack = 10;
		costRec = 30;
		costMan = 10;
		bonusVsCav = 0;
		bonusVsInf = 0;
		bonusVsSpear = 20;
		bonusVsArq = 20;
		bonusVsBuild = 0;
		Update();
	}

	void Update()
	{
		Unitats::Update();
		def += 1.5 * (lvl - 1);
		atack += 0.5 * (lvl - 1);
		costRec += 15 * (lvl - 1);
		costMan += 5 * (lvl - 1);
		bonusVsCav += 0.5 * (lvl - 1);
		bonusVsInf += 0 * (lvl - 1);
		bonusVsSpear += 1 * (lvl - 1);
		bonusVsArq += 1 * (lvl - 1);
		bonusVsBuild += 0 * (lvl - 1);
	}

};

class Cavalleria : public Unitats{
public:
	Cavalleria() :Unitats()
	{
		nom = "Cavaller";
		def = 30;
		atack = 20;
		costRec = 100;
		costMan = 40;
		bonusVsCav = 10;
		bonusVsInf = 20;
		bonusVsSpear = 0;
		bonusVsArq = 10;
		bonusVsBuild = 0;
	}
	Cavalleria(int lvl, int exp) :Unitats(lvl, exp)
	{
		nom = "Cavaller";
		def = 30;
		atack = 20;
		costRec = 100;
		costMan = 40;
		bonusVsCav = 10;
		bonusVsInf = 20;
		bonusVsSpear = 0;
		bonusVsArq = 10;
		bonusVsBuild = 0;
		Update();
	}

	void Update()
	{
		Unitats::Update();
		def += 1.5 * (lvl - 1);
		atack += 1.5 * (lvl - 1);
		costRec += 40 * (lvl - 1);
		costMan += 10 * (lvl - 1);
		bonusVsCav += 1 * (lvl - 1);
		bonusVsInf += 1.5 * (lvl - 1);
		bonusVsSpear += 0.2 * (lvl - 1);
		bonusVsArq += 1 * (lvl - 1);
		bonusVsBuild += 0 * (lvl - 1);
	}

};

class Llancer : public Unitats{
public:
	Llancer() :Unitats()
	{
		nom = "Llancer";
		def = 10;
		atack = 20;
		costRec = 25;
		costMan = 7;
		bonusVsCav = 50;
		bonusVsInf = 0;
		bonusVsSpear = 0;
		bonusVsArq = 0;
		bonusVsBuild = 0;
	}
	Llancer(int lvl, int exp) :Unitats(lvl, exp)
	{
		nom = "Llancer";
		def = 10;
		atack = 20;
		costRec = 25;
		costMan = 7;
		bonusVsCav = 50;
		bonusVsInf = 0;
		bonusVsSpear = 0;
		bonusVsArq = 0;
		bonusVsBuild = 0;
		Update();
	}

	void Update()
	{
		Unitats::Update();
		def += 1 * (lvl - 1);
		atack += 1.5 * (lvl - 1);
		costRec += 5 * (lvl - 1);
		costMan += 3 * (lvl - 1);
		bonusVsCav += 5 * (lvl - 1);
		bonusVsInf += 0.5 * (lvl - 1);
		bonusVsSpear += 0.2 * (lvl - 1);
		bonusVsArq += 0.1 * (lvl - 1);
		bonusVsBuild += 0 * (lvl - 1);
	}

};

class Siege : public Unitats{
public:
	Siege() :Unitats()
	{
		nom = "Arma de setge";
		def = 2;
		atack = 50;
		costRec = 150;
		costMan = 50;
		bonusVsCav = 0;
		bonusVsInf = 0;
		bonusVsSpear = 0;
		bonusVsArq = 10;
		bonusVsBuild = 200;
	}
	Siege(int lvl, int exp) :Unitats(lvl, exp)
	{
		nom = "Arma de setge";
		def = 2;
		atack = 50;
		costRec = 150;
		costMan = 50;
		bonusVsCav = 0;
		bonusVsInf = 0;
		bonusVsSpear = 0;
		bonusVsArq = 10;
		bonusVsBuild = 200;
		Update();
	}

	void Update()
	{
		Unitats::Update();
		def += 0.5 * (lvl - 1);
		atack += 3 * (lvl - 1);
		costRec += 35 * (lvl - 1);
		costMan += 10 * (lvl - 1);
		bonusVsCav += 0 * (lvl - 1);
		bonusVsInf += 0.2 * (lvl - 1);
		bonusVsSpear += 0.3 * (lvl - 1);
		bonusVsArq += 0.5 * (lvl - 1);
		bonusVsBuild += 20 * (lvl - 1);
	}

};