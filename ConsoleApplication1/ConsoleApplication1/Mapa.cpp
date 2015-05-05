#include "stdafx.h"
#include "Mapa.h"
#include "Console.h"
#include "Util.h"
using namespace Util;


using namespace std;
namespace con = JadedHoboConsole;
using namespace con;


Mapa::Mapa(char m[][210])
{
	int cb = sizeof(char) * 80 * 210;
	memcpy(mapa, m, cb);
}


Mapa::~Mapa()
{
}


void Mapa::print(){
	WORD propietat1, propietat2, propietat3, propietat4, propietat5, propietat6, propietat7, propietat8;
	int i = 1;
	for (itt = territoris.begin(); itt != territoris.end(); itt++, i++)
	{
		switch (itt->idPropietari)
		{
		case 1:
			itt->color = bgHiYellow;
			break;
		case 2:
			itt->color = bgHiCyan;
			break;
		case 3:
			itt->color = bgHiBlue;
			break;
		case 4:
			itt->color = bgHiRed;
			break;
		case 5:
			itt->color = bgBlack;
			break;
		case 6:
			itt->color = bgHiWhite;
			break;
		case 7:
			itt->color = bgHiMagenta;
			break;
		case 8:
			itt->color = bgHiGreen;
			break;
		default:
			break;
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
				console.SetColor(propietat1, fgMask);
				cout << ' ';
				break;
			case 'p':
				console.SetColor(propietat2, fgMask);
				cout << ' ';
				break;
			case 'f':
				console.SetColor(propietat3, fgMask);
				cout << ' ';
				break;
			case 'i':
				console.SetColor(propietat4, fgMask);
				cout << ' ';
				break;
			case 'a':
				console.SetColor(propietat5, fgMask);
				cout << ' ';
				break;
			case 'r':
				console.SetColor(propietat6, fgMask);
				cout << ' ';
				break;
			case 'g':
				console.SetColor(propietat7, fgMask);
				cout << ' ';
				break;
			case 't':
				console.SetColor(propietat8, fgMask);
				cout << ' ';
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
	s.id = 1;
	s.color = bgHiYellow;
	s.posX_Ex1 = 28;
	s.posY_Ex1 = 50;
	s.posX_Ex2 = 40;
	s.posY_Ex2 = 50;

	Territoris p;
	p.nom = "Portugal";
	p.castell = false;
	p.exPresent = true;
	p.idPropietari = 2;
	p.id = 2;
	p.color = bgHiCyan;
	p.posX_Ex1 = 18;
	p.posY_Ex1 = 55;
	p.posX_Ex2 = 25;
	p.posY_Ex2 = 55;

	Territoris f;
	f.nom = "França";
	f.castell = true;
	f.exPresent = true;
	f.idPropietari = 3;
	f.id = 3;
	f.color = bgHiBlue;
	f.posX_Ex1 = 50;
	f.posY_Ex1 = 20;
	f.posX_Ex2 = 58;
	f.posY_Ex2 = 20;

	Territoris i;
	i.nom = "Italia";
	i.castell = false;
	i.exPresent = true;
	i.idPropietari = 4;
	i.id = 4;
	i.color = bgHiRed;
	i.posX_Ex1 = 72;
	i.posY_Ex1 = 40;
	i.posX_Ex2 = 78;
	i.posY_Ex2 = 40;

	Territoris a;
	a.nom = "Alemania";
	a.castell = true;
	a.exPresent = true;
	a.idPropietari = 5;
	a.id = 5;
	a.color = bgBlack;
	a.posX_Ex1 = 100;
	a.posY_Ex1 = 15;
	a.posX_Ex2 = 109;
	a.posY_Ex2 = 15;

	Territoris r;
	r.nom = "Russia";
	r.castell = true;
	r.exPresent = true;
	r.idPropietari = 6;
	r.id = 6;
	r.color = bgHiWhite;
	r.posX_Ex1 = 128;
	r.posY_Ex1 = 15;
	r.posX_Ex2 = 135;
	r.posY_Ex2 = 15;

	Territoris g;
	g.nom = "Grecia";
	g.castell = true;
	g.exPresent = true;
	g.idPropietari = 7;
	g.id = 7;
	g.color = bgHiMagenta;
	g.posX_Ex1 = 118;
	g.posY_Ex1 = 40;
	g.posX_Ex2 = 125;
	g.posY_Ex2 = 40;

	Territoris t;
	t.nom = "Turquia";
	t.castell = false;
	t.exPresent = true;
	t.idPropietari = 8;
	t.id = 8;
	t.color = bgHiGreen;
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