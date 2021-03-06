#pragma once

#include "stdafx.h"
#include <string>

using namespace std;

class Unitats{
public:

	float def, atack;
	int exp, costRec, costMan, lvl;
	float bonusVsCav, bonusVsInf, bonusVsSpear, bonusVsArq, bonusVsBuild, vida, vidaMax;
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
		if (vida < vidaMax)
			vida += (vidaMax*0.3);
		if (vida > vidaMax)
			vida = vidaMax;
		if (exp >= (1500 + (500 * (lvl - 1))))
		{
			lvl += 1;
			exp = 0;
			vida = vidaMax;
		}
	}

	virtual void lvlUp(int lvlup)
	{
		lvl += lvlup;
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

	void Update()
	{
		Unitats::Update();
		comandament = comandament + lvl - 1;
	}
};

class Arquer : public Unitats{
public:

	Arquer() :Unitats()
	{
		nom = "Arquer";
		def = 10;
		vida = 30;
		vidaMax = vida;
		atack = 25;
		costRec = 50;
		costMan = 15;
		bonusVsCav = 5;
		bonusVsInf = 0;
		bonusVsSpear = 10;
		bonusVsArq = 5;
		bonusVsBuild = 10;
	}

	Arquer(int lvl, int exp) :Unitats(lvl, exp)
	{
		nom = "Arquer";
		def = 10;
		vida = 30;
		vidaMax = vida;
		atack = 25;
		costRec = 50;
		costMan = 15;
		bonusVsCav = 5;
		bonusVsInf = 0;
		bonusVsSpear = 10;
		bonusVsArq = 5;
		bonusVsBuild = 10;
		Update();
	}

	void Update()
	{
		Unitats::Update();
		def += 0.5 * (lvl - 1);
		vidaMax += 5 * (lvl - 1);
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
		vida = 50;
		vidaMax = vida;
		atack = 10;
		costRec = 30;
		costMan = 10;
		bonusVsCav = 0;
		bonusVsInf = 0;
		bonusVsSpear = 10;
		bonusVsArq = 15;
		bonusVsBuild = 0;
	}
	Soldat(int lvl, int exp) :Unitats(lvl, exp)
	{
		nom = "Soldat";
		def = 20;
		vida = 50;
		vidaMax = vida;
		atack = 10;
		costRec = 30;
		costMan = 10;
		bonusVsCav = 0;
		bonusVsInf = 0;
		bonusVsSpear = 10;
		bonusVsArq = 15;
		bonusVsBuild = 0;
		Update();
	}

	void Update()
	{
		Unitats::Update();
		def += 1.5 * (lvl - 1);
		vidaMax += 10 * (lvl - 1);
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
		def = 25;
		vida = 70;
		vidaMax = vida;
		atack = 20;
		costRec = 100;
		costMan = 40;
		bonusVsCav = 5;
		bonusVsInf = 10;
		bonusVsSpear = 0;
		bonusVsArq = 5;
		bonusVsBuild = 0;
	}
	Cavalleria(int lvl, int exp) :Unitats(lvl, exp)
	{
		nom = "Cavaller";
		def = 25;
		vida = 70;
		vidaMax = vida;
		atack = 20;
		costRec = 100;
		costMan = 40;
		bonusVsCav = 5;
		bonusVsInf = 10;
		bonusVsSpear = 0;
		bonusVsArq = 5;
		bonusVsBuild = 0;
		Update();
	}

	void Update()
	{
		Unitats::Update();
		def += 1.5 * (lvl - 1);
		vidaMax += 15 * (lvl - 1);
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
		def = 15;
		vida = 35;
		vidaMax = vida;
		atack = 20;
		costRec = 25;
		costMan = 10;
		bonusVsCav = 15;
		bonusVsInf = 0;
		bonusVsSpear = 0;
		bonusVsArq = 0;
		bonusVsBuild = 0;
	}
	Llancer(int lvl, int exp) :Unitats(lvl, exp)
	{
		nom = "Llancer";
		def = 15;
		vida = 35;
		vidaMax = vida;
		atack = 20;
		costRec = 25;
		costMan = 10;
		bonusVsCav = 15;
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
		vidaMax += 7 * (lvl - 1);
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
		def = 5;
		vida = 50;
		vidaMax = vida;
		atack = 50;
		costRec = 150;
		costMan = 50;
		bonusVsCav = 0;
		bonusVsInf = 0;
		bonusVsSpear = 0;
		bonusVsArq = 10;
		bonusVsBuild = 50;
	}
	Siege(int lvl, int exp) :Unitats(lvl, exp)
	{
		nom = "Arma de setge";
		def = 5;
		vida = 50;
		vidaMax = vida;
		atack = 50;
		costRec = 150;
		costMan = 50;
		bonusVsCav = 0;
		bonusVsInf = 0;
		bonusVsSpear = 0;
		bonusVsArq = 10;
		bonusVsBuild = 50;
		Update();
	}

	void Update()
	{
		Unitats::Update();
		def += 0.5 * (lvl - 1);
		vidaMax += 2 * (lvl - 1);
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