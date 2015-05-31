#pragma once

#include "stdafx.h"
#include <string>

static struct Territoris{
	string nom;
	WORD color;
	int posX_Ex1, posY_Ex1, posX_Ex2, posY_Ex2, id;
	int idPropietari, idPropietariTornAnt;
	bool exPresent = false, castell;
};

