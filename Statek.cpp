#include "Statek.h"
#include"Punkt.h"



Statek::Statek()
{
}


Statek::~Statek()
{
}

bool Statek::CzyPlywa()
{
	if (trafienia == 4) return 0;
	else
		return 1;
}

int Statek::IleTrafien()
{
	return trafienia;
}

void Statek::Ustaw(Punkt* a, Punkt* b, Punkt* c, Punkt* d)
{
	tab[0] = a;
	tab[1] = b;
	tab[2] = c;
	tab[3] = d;

	x = (*tab[0]).x;
	y = (*tab[0]).y;


	for (int i = 0; i < 4; i++)
	{
		tab[i]->UstawStan(3);
	}
	
}

void Statek::MojStan()
{
	trafienia = 0;
	for (int i = 0; i < 4; i++)
	{
		if (tab[i]->DajStan() == 2)
		{
			trafienia++;
			tab[i]->UstawTyp('o');
		}
	}

	if (trafienia == 4)
	{
		for (int i = 0; i < 4; i++)
			tab[i]->UstawTyp('x');
	}
	
}
