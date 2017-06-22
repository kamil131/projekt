#pragma once
#include"Statek.h"
#include"Plansza.h"

class Gra
{
public:
	Gra();
	~Gra();
	void Graj();
	void Organizuj();
	void WspSta();
	int NaWodzie();

private:
	Plansza plansza2;
	Statek tab[4];
	int plywajace;
	int strzaly;
	



};

