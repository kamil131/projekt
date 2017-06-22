#pragma once
#include"Punkt.h"
class Statek
{
public:
	Statek();
	~Statek();
	bool CzyPlywa();
	int IleTrafien();
	void Ustaw(Punkt* a, Punkt* b, Punkt* c, Punkt* d);
	void MojStan();
	int x;
	int y;
private:
	Punkt* tab[5];
	int trafienia;
};

