#include<iostream>
#include "Punkt.h"
using namespace std;


Punkt::Punkt()
{
	typ = '.';
	stan = 1;
}


Punkt::~Punkt()
{
}

char Punkt::DajTyp()
{
	return typ;
}

int Punkt::DajStan()
{
	return stan;
}

void Punkt::UstawTyp(char x)
{
	typ = x;
}
void Punkt::UstawStan(int x)
{
	stan = x;
}

void Punkt::UstawWsp(int a, int b)
{
	x = a;
	y = b;
}
