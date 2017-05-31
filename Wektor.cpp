#pragma once
#include<iostream>
#include<fstream>
#include"Wektor.h"
using namespace std;

Wektor::Wektor(void)
{
	size = 2;
	tab = new liczbaZespolona[size];
	tab[0] = liczbaZespolona(0, 0);
	tab[1] = liczbaZespolona(1, 1);
}

Wektor::Wektor(liczbaZespolona *liczby, int rozmiar)
{
	size = rozmiar;
	tab = new liczbaZespolona[size];
	for (int i = 0; i < size; i++)
	{
		tab[i] = liczbaZespolona(liczby[i]);
	}
}

Wektor::Wektor(int rozmiar)
{
	size = rozmiar;
	tab = new liczbaZespolona[size];
	for (int i= 0; i < size; i++)
	{
		tab[i] = liczbaZespolona();
	}
}

Wektor::Wektor(Wektor &copy)
{
	if (&copy == NULL)
		return;
	else
	{
		size = copy.size;
		tab = new liczbaZespolona[size];
		for (int i = 0; i < size; i++)
		{
			tab[i] = liczbaZespolona(copy.tab[i]);
		}
	}
}


Wektor::~Wektor(void)
{
	if (tab != NULL)
	{
		delete[]tab;
	}
}


liczbaZespolona &Wektor::operator[](int a)
{
	return tab[a];
}


Wektor &Wektor::operator=(Wektor &w2)
{
	size = w2.size;
	if(tab!=NULL)
		delete[]tab;
	tab = new liczbaZespolona[size];
	for (int i = 0; i < this->size; i++)
	{
		tab[i] = w2[i];
	}
	return *this;
}


Wektor Wektor::operator+(Wektor w2)
{
	Wektor wynik(size);
	for (int i = 0; i < size; i++)
	{
		wynik[i] = tab[i] + w2[i];
	}
	return wynik;
}


Wektor Wektor::operator-(Wektor w2)
{
	Wektor wynik(size);
	for (int i = 0; i < size; i++)
	{
		wynik[i] = tab[i] - w2[i];
	}
	return wynik;
}


Wektor Wektor::operator*(liczbaZespolona z2)
{
	Wektor wynik(size);
	for (int i = 0; i < size; i++)
	{
		wynik[i] = tab[i] * z2;
	}
	return wynik;
}


Wektor Wektor::operator/(liczbaZespolona z2)
{
	Wektor wynik(size);
	for (int i = 0; i < size; i++)
	{
		wynik[i] = tab[i] / z2;
	}
	return wynik;
}


int Wektor::zwroc_rozmiar(void)
{
	return size;
}


ostream &operator<<(ostream &out, Wektor &w)
{
	out << "[";
	for (int i = 0; i < w.size; i++)
	{
		if (i != 0)
			out << '\t';
		out << w[i];
	}
	out << ']';
	return out;
}


istream &operator >> (istream &in, Wektor &w)
{
	liczbaZespolona *wynik, *temp;
	int i = 0;
	wynik = new liczbaZespolona[1];
	while (1)
	{
		temp = wynik;
		wynik = new liczbaZespolona[i + 1];
		for (int j = 0; j < i; j++)
		{
			wynik[j] = temp[j];
		}
		in >> wynik[i];
		if (in.peek() == '\n')
			break;
		i++;
	}
	Wektor wek(wynik, i + 1);
	w = wek;
	return in;
}


ofstream& operator<< (ofstream& out, Wektor &W)
{
	for (int i = 0; i < W.size; i++)
	{
		if (i != 0)
			out << '\t';
		out << W[i];
	}
	return out;
}

ifstream &operator >> (ifstream &in, Wektor &W)
{
	liczbaZespolona *wynik, *temp;
	int i = 0;
	wynik = new liczbaZespolona[1];
	while (1)
	{
		temp = wynik;
		wynik = new liczbaZespolona[i + 1];
		for (int j = 0; j < i; j++)
		{
			wynik[j] = temp[j];
		}
		in >> wynik[i];
		if (in.peek() == '\n')
			break;
		i++;
	}
	Wektor wek(wynik, i + 1);
	W = wek;
	return in;
}