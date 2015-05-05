#include "stdafx.h"
#include "Mapa.h"
#include "Console.h"
#include "Util.h"
using namespace Util;


using namespace std;
namespace con = JadedHoboConsole;


Mapa::Mapa(char m[][210])
{
	int cb = sizeof(char) * 80 * 210;
	memcpy(mapa, m, cb);
}


Mapa::~Mapa()
{
}


void Mapa::print(){
	int propietat1, propietat2, propietat3, propietat4, propietat5, propietat6, propietat7, propietat8;
	for (itt = territoris.begin(); itt != territoris.end(); itt++)
	{
		if (itt->idPropietari != itt->idPropietariTornAnt)
		{
			if (itt->id == 1)
			{
				gy
			}
		}
	}
	for (int i = 0; i < 80; i++){
		for (int j = 0; j < 210; j++){
			/*if (i == 0 || i == 80)
			{
			cout << ' ';
			}
			else if (j == 1 || j == 199)
			{
			cout << con::fg_red << 'X';
			}
			else if ((i == 1 || i == 79) && j != 0 && j!= 200)
			{
			cout << con::fg_red << 'X';
			}
			else cout << ' ';*/
			switch (mapa[i][j])
			{
			case 'X':
				cout << con::bg_gray << ' ';
				break;
			case 's':
				if ()
					cout << con::bg_yellow << ' ';
				break;
			case 'p':
				cout << con::bg_cyan << ' ';
				break;
			case 'f':
				cout << con::bg_blue << ' ';
				break;
			case 'i':
				cout << con::bg_red << ' ';
				break;
			case 'a':
				cout << con::bg_black << ' ';
				break;
			case 'r':
				cout << con::bg_white << ' ';
				break;
			case 'g':
				cout << con::bg_magenta << ' ';
				break;
			case 't':
				cout << con::bg_green << ' ';
				break;
			default:
				cout << con::bg_black << ' ';
				break;

			}
			//cout << con::bg_black << con::fg_white << mapa[i][j];
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
	s.posX_Ex1 = 28;
	s.posY_Ex1 = 50;
	s.posX_Ex2 = 40;
	s.posY_Ex2 = 50;

	Territoris p;
	p.nom = "Portugal";
	p.castell = false;
	p.exPresent = true;
	p.idPropietari = 2;
	p.posX_Ex1 = 18;
	p.posY_Ex1 = 55;
	p.posX_Ex2 = 25;
	p.posY_Ex2 = 55;

	Territoris f;
	f.nom = "França";
	f.castell = true;
	f.exPresent = true;
	f.idPropietari = 3;
	f.posX_Ex1 = 50;
	f.posY_Ex1 = 20;
	f.posX_Ex2 = 58;
	f.posY_Ex2 = 20;

	Territoris i;
	i.nom = "Italia";
	i.castell = false;
	i.exPresent = true;
	i.idPropietari = 4;
	i.posX_Ex1 = 72;
	i.posY_Ex1 = 40;
	i.posX_Ex2 = 78;
	i.posY_Ex2 = 40;

	Territoris a;
	a.nom = "Alemania";
	a.castell = true;
	a.exPresent = true;
	a.idPropietari = 5;
	a.posX_Ex1 = 100;
	a.posY_Ex1 = 15;
	a.posX_Ex2 = 109;
	a.posY_Ex2 = 15;

	Territoris r;
	r.nom = "Russia";
	r.castell = true;
	r.exPresent = true;
	r.idPropietari = 6;
	r.posX_Ex1 = 128;
	r.posY_Ex1 = 15;
	r.posX_Ex2 = 135;
	r.posY_Ex2 = 15;

	Territoris g;
	g.nom = "Grecia";
	g.castell = true;
	g.exPresent = true;
	g.idPropietari = 7;
	g.posX_Ex1 = 118;
	g.posY_Ex1 = 40;
	g.posX_Ex2 = 125;
	g.posY_Ex2 = 40;

	Territoris t;
	t.nom = "Turquia";
	t.castell = false;
	t.exPresent = true;
	t.idPropietari = 8;
	t.posX_Ex1 = 145;
	t.posY_Ex1 = 60;
	t.posX_Ex2 = 150;
	t.posY_Ex2 = 60;

	territoris.push_back(s);
	territoris.push_back(p);
	territoris.push_back(f);
	territoris.push_back(i);
	territoris.push_back(a);
	territoris.push_back(r);
	territoris.push_back(g);
	territoris.push_back(t);

}
void Mapa::update()
{
	for (itt = territoris.begin(); itt != territoris.end(); itt++)
	{

	}
}
void Mapa::pintaNoms()
{
	for (itt = territoris.begin(); itt != territoris.end(); itt++)
	{
		if (itt->exPresent){
			gotoxy(itt->posX_Ex1, itt->posY_Ex1);
			cout << con::bg_green << ' ';
		}
		cout << con::fg_white << itt->nom << endl;
	}
}