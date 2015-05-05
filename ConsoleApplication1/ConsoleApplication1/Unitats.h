#pragma once

#include "stdafx.h"
#include <string>

using namespace std;

struct Unitats{
	int def, atack, exp, lvl, costRec, costMan;
	int bonusVsCav, bonusVsInf, bonusVsSpear, bonusVsArq, bonusVsBuild;
	string nom;
};

struct General :Unitats{
	int comandament;
};

struct Arquer :Unitats{
	static const int def = 10, atack = 25, costRec = 50, costMan = 15, bonusVsCav = 10, bonusVsInf = 0, bonusVsSpear = 15, bonusVsArq = 10, bonusVsBuild = 15;
};