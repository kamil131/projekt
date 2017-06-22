#pragma once
#include"Punkt.h"
class Plansza
{
public:
	Plansza();
	~Plansza();
	void Wyswietl();
	int DajStan(int, int);
	void UstawStan(int, int, int);
	void UstawTyp(int, int, char);
	Punkt* DajAdres(int, int);
	void NadWsp();


private:
	Punkt plansza1[10][10];

};

