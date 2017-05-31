#pragma once
#include"liczbaZespolona.h"

class Wektor : public liczbaZespolona
{
private:
	int size;
	liczbaZespolona *tab;
public:
	Wektor(void);
	Wektor(liczbaZespolona *liczby, int rozmiar);
	Wektor(int rozmiar);
	Wektor(Wektor &copy);
	~Wektor(void);
	liczbaZespolona &operator[](int a);
	Wektor &operator=(Wektor &w2);
	Wektor operator+(Wektor w2);
	Wektor operator-(Wektor w2);
	Wektor operator*(liczbaZespolona z2);
	Wektor operator/(liczbaZespolona z2);
	int zwroc_rozmiar(void);
	friend ostream &operator<<(ostream &out, Wektor &w);
	friend istream &operator>>(istream &in, Wektor &w);
	friend ofstream &operator<<(ofstream &out, Wektor &w);
	friend ifstream &operator >> (ifstream &in, Wektor &w);
};