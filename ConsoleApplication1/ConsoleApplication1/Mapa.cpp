#include "stdafx.h"
#include "Mapa.h"

//using namespace Util;


using namespace std;
namespace cons = JadedHoboConsole;
using namespace cons;
using namespace Utilitats;


Mapa::Mapa(char m[][225])
{
	int cb = sizeof(char) * 80 * 225;
	memcpy(mapa, m, cb);
}

Mapa::Mapa()
{

}


Mapa::~Mapa()
{
}


list<Territoris>::iterator Mapa::getIterTerr(int id)
{
	for (itt = territoris.begin(); itt != territoris.end(); itt++)
	{
		if (itt->id == id)
			return itt;
	}
}

void Mapa::print(){
	WORD propietat[8];
	int i = 0;
	for (itt = territoris.begin(); itt != territoris.end(); itt++, i++)
	{
		switch (itt->idPropietari)
		{
		case 1:
			itt->color = bgHiYellow;
			break;
		case 2:
			itt->color = bgHiRed;
			break;
		case 3:
			itt->color = bgLoBlue;
			break;
		case 4:
			itt->color = bgHiGreen;
			break;
		case 5:
			itt->color = bgLoRed;
			break;
		case 6:
			itt->color = bgHiWhite;
			break;
		case 7:
			itt->color = bgLoMagenta;
			break;
		case 8:
			itt->color = bgLoGreen;
			break;
		default:
			gotoxy(156, 50);
			cout << fg_red << "Fatal Error!";
			break;
		}
		propietat[i] = itt->color;
	}
	gotoxy(0, 0);
	for (int i = 0; i < 80; i++){
		for (int j = 0; j < 225; j++){
			switch (mapa[i][j])
			{
			case 'X':
				cout << bg_gray << ' ';
				break;
			case 's':
				console.SetColor(propietat[0], fgMask);
				cout << ' ';
				break;
			case 'p':
				console.SetColor(propietat[1], fgMask);
				cout << ' ';
				break;
			case 'f':
				console.SetColor(propietat[2], fgMask);
				cout << ' ';
				break;
			case 'i':
				console.SetColor(propietat[3], fgMask);
				cout << ' ';
				break;
			case 'a':
				console.SetColor(propietat[4], fgMask);
				cout << ' ';
				break;
			case 'r':
				console.SetColor(propietat[5], fgMask);
				cout << ' ';
				break;
			case 'g':
				console.SetColor(propietat[6], fgMask);
				cout << ' ';
				break;
			case 't':
				console.SetColor(propietat[7], fgMask);
				cout << ' ';
				break;
			case 'Y':
				cout << bg_black << ' ';
				break;

			default:
				if (j < 155)
				{
					console.SetColor(bgHiBlue, fgMask);
					cout << ' ';
				}
				else 
					cout << bg_black << ' ';
				break;
			}
		}
		cout << endl;
	}
}

void Mapa::iniciaTerritoris(){
	Territoris s;
	s.nom = "Espanya";
	s.castell = true;
	s.exPresent = true;
	s.idPropietari = 1;
	s.id = 2;
	s.color = bgHiYellow;
	s.posX_Ex1 = 20;
	s.posY_Ex1 = 50;
	s.posX_Ex2 = 23;
	s.posY_Ex2 = 52;

	Territoris p;
	p.nom = "Portugal";
	p.castell = false;
	p.exPresent = true;
	p.idPropietari = 2;
	p.id = 1;
	p.color = bgHiRed;
	p.posX_Ex1 = 7;
	p.posY_Ex1 = 57;
	p.posX_Ex2 = 10;
	p.posY_Ex2 = 55;

	Territoris f;
	f.nom = "Francia";
	f.castell = true;
	f.exPresent = true;
	f.idPropietari = 3;
	f.id = 3;
	f.color = bgLoBlue;
	f.posX_Ex1 = 50;
	f.posY_Ex1 = 20;
	f.posX_Ex2 = 53;
	f.posY_Ex2 = 22;

	Territoris i;
	i.nom = "Italia";
	i.castell = false;
	i.exPresent = true;
	i.idPropietari = 4;
	i.id = 4;
	i.color = bgHiGreen;
	i.posX_Ex1 = 72;
	i.posY_Ex1 = 40;
	i.posX_Ex2 = 75;
	i.posY_Ex2 = 42;

	Territoris a;
	a.nom = "Alemania";
	a.castell = true;
	a.exPresent = true;
	a.idPropietari = 5;
	a.id = 5;
	a.color = bgLoRed;
	a.posX_Ex1 = 70;
	a.posY_Ex1 = 15;
	a.posX_Ex2 = 74;
	a.posY_Ex2 = 17;

	Territoris r;
	r.nom = "Russia";
	r.castell = true;
	r.exPresent = true;
	r.idPropietari = 6;
	r.id = 6;
	r.color = bgHiWhite;
	r.posX_Ex1 = 128;
	r.posY_Ex1 = 15;
	r.posX_Ex2 = 130;
	r.posY_Ex2 = 17;

	Territoris g;
	g.nom = "Grecia";
	g.castell = true;
	g.exPresent = true;
	g.idPropietari = 7;
	g.id = 7;
	g.color = bgLoMagenta;
	g.posX_Ex1 = 108;
	g.posY_Ex1 = 50;
	g.posX_Ex2 = 110;
	g.posY_Ex2 = 52;

	Territoris t;
	t.nom = "Turquia";
	t.castell = false;
	t.exPresent = true;
	t.idPropietari = 8;
	t.id = 8;
	t.color = bgLoGreen;
	t.posX_Ex1 = 145;
	t.posY_Ex1 = 70;
	t.posX_Ex2 = 147;
	t.posY_Ex2 = 72;

	territoris.push_back(s);
	territoris.push_back(p);
	territoris.push_back(f);
	territoris.push_back(i);
	territoris.push_back(a);
	territoris.push_back(r);
	territoris.push_back(g);
	territoris.push_back(t);

}
int Mapa::update(int idTerr, int idFaccio)
{
	int idAnt;
	for (itt = territoris.begin(); itt != territoris.end(); itt++)
	{
		if (itt->id == idTerr && idTerr != 0)
		{
			idAnt = itt->idPropietari;
			itt->idPropietariTornAnt = itt->idPropietari;
			itt->idPropietari = idFaccio;
			break;
		}

	}
	return idAnt;
}

void Mapa::update(vector<Excercit*>posEx)
{
	for (itt = territoris.begin(); itt != territoris.end(); itt++)
	{
		for (int i = 0; i < posEx.size(); i++)
		{
			if (itt->id == posEx[i]->getTerritoriAct())
			{
				itt->exPresent = true;
				if (itt->castell)
					posEx[i]->setCastell(true);
			}
		}
	}
}
void Mapa::pintaNoms()
{
	for (itt = territoris.begin(); itt != territoris.end(); itt++)
	{
		if (itt->exPresent){
			gotoxy(itt->posX_Ex2, itt->posY_Ex2);
			cout << bg_black << ' ';
		}
		gotoxy(itt->posX_Ex1, itt->posY_Ex1);
		cout << fg_white << itt->nom << endl;
	}
}