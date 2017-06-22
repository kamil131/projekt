#include<iostream>
#include<iomanip>
#include "Plansza.h"
#include"Punkt.h"
using namespace std;


Plansza::Plansza()
{
}

Plansza::~Plansza()
{
}

int Plansza::DajStan(int x, int y)
{
	return plansza1[x][y].DajStan();
}

void Plansza::UstawStan(int x, int y, int s)
{
	plansza1[x][y].UstawStan(s);
}

void Plansza::UstawTyp(int x, int y, char t)
{
	plansza1[x][y].UstawTyp(t);
}

Punkt* Plansza::DajAdres(int x, int y)
{
	return &plansza1[x][y];
}

void Plansza::Wyswietl()
{
	for (int i = 0; i < 10; i++)
	{
		cout <<setw(2) << i + 1;

		for (int j = 0; j < 10; j++)
			cout << setw(2) << plansza1[j][i].DajTyp();

		switch (i)
		{
		case 1:
			cout << "      Legenda: ";
			break;
		case 2:
			cout << "      .  Pole puste nieostrzelane";
			break;
		case 3:
			cout << "      x  Maszt zatopiony";
			break;
		case 4:
			cout << "      o  Maszt ostrzelany";
			break;
		case 5:
			cout << "      -  Pudlo";
			break;
		case 7:
			cout << "      Nacisnij zero aby zakonczyc gre";
			break;
		}

		cout << endl;
	}
	cout << "  ";
	for (int i = 0; i < 10; i++)
		cout << setw(2) << i+1;
	cout << endl;

}

void Plansza::NadWsp()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			plansza1[j][i].UstawWsp(j, i);
	}
}
