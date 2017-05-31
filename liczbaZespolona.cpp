#pragma once
#include<iostream>
#include <fstream>
#include"liczbaZespolona.h"
using namespace std;

liczbaZespolona::liczbaZespolona(void)
{
	ReZ = 0;
	ImZ = 0;
}

liczbaZespolona::liczbaZespolona(float a)
{
	ReZ = a;
	ImZ = 0;
}

liczbaZespolona::liczbaZespolona(float a, float b)
{
	ReZ=a;
	ImZ=b;
}

liczbaZespolona::liczbaZespolona(liczbaZespolona &copy)
{
	if (&copy == NULL) 
		return;
	else
	{
		ReZ = copy.ReZ;
		ImZ = copy.ImZ;
	}
}

liczbaZespolona::~liczbaZespolona(void){}

void liczbaZespolona::drukuj(void)
{
	cout << "Nasza liczba zespolona to " << ReZ << "+" << ImZ << "j" << endl;
}

float liczbaZespolona::modul(void)
{
	float m;
	m=sqrt(ReZ*ReZ+ImZ*ImZ);
	return m;
}

float liczbaZespolona::argument(void)
{
	float arg;
	arg=atan(ImZ/ReZ);
	return arg;
}

void liczbaZespolona::ustaw_re(float a)
{
	ReZ = a;
}

void liczbaZespolona::ustaw_im(float a)
{
	ImZ = a;
}

liczbaZespolona liczbaZespolona::operator+(liczbaZespolona &Arg2)
{
	liczbaZespolona wynik;
	wynik.ReZ = this->ReZ + Arg2.ReZ;
	wynik.ImZ = this->ImZ + Arg2.ImZ;
	return wynik;
}

liczbaZespolona liczbaZespolona::operator+(float Arg2)
{
	liczbaZespolona wynik;
	wynik.ReZ = this->ReZ + Arg2;
	wynik.ImZ = this->ImZ;
	return wynik;
}

liczbaZespolona liczbaZespolona::operator-(liczbaZespolona &Arg2)
{
	liczbaZespolona wynik;
	wynik.ReZ = this->ReZ - Arg2.ReZ;
	wynik.ImZ = this->ImZ - Arg2.ImZ;
	return wynik;
}

liczbaZespolona liczbaZespolona::operator-(float Arg2)
{
	liczbaZespolona wynik;
	wynik.ReZ = this->ReZ - Arg2;
	wynik.ImZ = this->ImZ;
	return wynik;
}


liczbaZespolona liczbaZespolona::operator*(liczbaZespolona &Arg2)
{
	liczbaZespolona wynik;
	wynik.ReZ = this->ReZ*Arg2.ReZ - this->ImZ*Arg2.ImZ;
	wynik.ImZ = this->ReZ*Arg2.ImZ + this->ImZ*Arg2.ReZ;
	return wynik;
}

liczbaZespolona liczbaZespolona::operator*(float Arg2)
{
	liczbaZespolona wynik;
	wynik.ReZ = this->ReZ*Arg2;
	wynik.ImZ = this->ImZ*Arg2;
	return wynik;
}


liczbaZespolona liczbaZespolona::operator/(liczbaZespolona &Arg2)
{
	liczbaZespolona wynik;
	if (Arg2.ReZ == 0 && Arg2.ImZ == 0)
	{
		cout << "Nie mo¿na dzieliæ przez zero, jako wynik zwrócono dzieln¹" << endl;
		wynik = *this;
		return wynik;
	}
	wynik.ReZ = (this->ReZ*Arg2.ReZ + this->ImZ*Arg2.ImZ) / (Arg2.ReZ*Arg2.ReZ + Arg2.ImZ*Arg2.ImZ);
	wynik.ImZ = (this->ImZ*Arg2.ReZ - this->ReZ*Arg2.ImZ) / (Arg2.ReZ*Arg2.ReZ + Arg2.ImZ*Arg2.ImZ);
	return wynik;
}

liczbaZespolona liczbaZespolona::operator/(float Arg2)
{
	liczbaZespolona wynik;
	if (Arg2 == 0)
	{
		cout << "Nie mo¿na dzieliæ przez zero, jako wynik zwrócono dzieln¹" << endl;
		wynik = *this;
		return wynik;
	}
	wynik.ReZ = this->ReZ / Arg2;
	wynik.ImZ = this->ImZ / Arg2;
	return wynik;
}


liczbaZespolona &liczbaZespolona::operator=(liczbaZespolona &Arg2)
{
	ReZ = Arg2.ReZ;
	ImZ = Arg2.ImZ;
	return *this;
}

liczbaZespolona &liczbaZespolona::operator=(float Arg2)
{
	ReZ = Arg2;
	ImZ = 0;
	return *this;
}

liczbaZespolona &liczbaZespolona::operator+=(liczbaZespolona &Arg2)
{
	ReZ = this->ReZ + Arg2.ReZ;
	ImZ = this->ImZ + Arg2.ImZ;
	return *this;
}

liczbaZespolona &liczbaZespolona::operator+=(float Arg2)
{
	ReZ = this->ReZ + Arg2;
	return *this;
}

liczbaZespolona &liczbaZespolona::operator-=(liczbaZespolona &Arg2)
{
	ReZ = this->ReZ - Arg2.ReZ;
	ImZ = this->ImZ - Arg2.ImZ;
	return *this;
}

liczbaZespolona &liczbaZespolona::operator-=(float Arg2)
{
	ReZ = this->ReZ - Arg2;
	return *this;
}

liczbaZespolona &liczbaZespolona::operator*=(liczbaZespolona &Arg2)
{
	ReZ = this->ReZ*Arg2.ReZ - this->ImZ*Arg2.ImZ;
	ImZ = this->ReZ*Arg2.ImZ + this->ImZ*Arg2.ReZ;
	return *this;
}

liczbaZespolona &liczbaZespolona::operator*=(float Arg2)
{
	ReZ = this->ReZ * Arg2;
	ImZ = this->ImZ * Arg2;
	return *this;
}

liczbaZespolona &liczbaZespolona::operator/=(liczbaZespolona &Arg2)
{
	if (Arg2.ReZ == 0 && Arg2.ImZ == 0)
	{
		cout << "Nie mo¿na dzieliæ przez zero, jako wynik zwrócono dzieln¹" << endl;
		return *this;
	}
	ReZ = (this->ReZ*Arg2.ReZ + this->ImZ*Arg2.ImZ) / (Arg2.ReZ*Arg2.ReZ + Arg2.ImZ*Arg2.ImZ);
	ImZ = (this->ImZ*Arg2.ReZ - this->ReZ*Arg2.ImZ) / (Arg2.ReZ*Arg2.ReZ + Arg2.ImZ*Arg2.ImZ);
	return *this;
}

liczbaZespolona &liczbaZespolona::operator/=(float Arg2)
{
	if (Arg2 == 0 )
	{
		cout << "Nie mo¿na dzieliæ przez zero, jako wynik zwrócono dzieln¹" << endl;
		return *this;
	}
	ReZ = this->ReZ / Arg2;
	ImZ = this->ImZ / Arg2;
	return *this;
}

liczbaZespolona &liczbaZespolona::operator-(void)
{
	ReZ = -(this->ReZ);
	ImZ = -(this->ImZ);
	return *this;
}

bool liczbaZespolona::operator>(liczbaZespolona &Arg2)
{
	float z1, z2;
	z1 = this->modul();
	z2 = Arg2.modul();
	if (z1 > z2)
		return true;
	else
		return false;
}

bool liczbaZespolona::operator<(liczbaZespolona &Arg2)
{
	float z1, z2;
	z1 = this->modul();
	z2 = Arg2.modul();
	if (z1 < z2)
		return true;
	else
		return false;
}

bool liczbaZespolona::operator>=(liczbaZespolona &Arg2)
{
	float z1, z2;
	z1 = this->modul();
	z2 = Arg2.modul();
	if (z1 >= z2)
		return true;
	else
		return false;
}

bool liczbaZespolona::operator<=(liczbaZespolona &Arg2)
{
	float z1, z2;
	z1 = this->modul();
	z2 = Arg2.modul();
	if (z1 <= z2)
		return true;
	else
		return false;
}

bool liczbaZespolona::operator==(liczbaZespolona &Arg2)
{
	if (this->ReZ == Arg2.ReZ && this->ImZ == Arg2.ImZ)
		return true;
	else
		return false;
}

bool liczbaZespolona::operator!=(liczbaZespolona &Arg2)
{
	if (this->ReZ == Arg2.ReZ && this->ImZ == Arg2.ImZ)
		return false;
	else
		return true;
}

ostream &operator<<(ostream &out, liczbaZespolona &Arg)
{
	if (Arg.ImZ >= 0)
	{
		out << Arg.ReZ << "+" << Arg.ImZ << "i";
	}
	else
	{
		out << Arg.ReZ << Arg.ImZ << "i";
	}
	return out;
}

istream &operator>>(istream &in, liczbaZespolona &Arg)
{
	char c;
	if (in.peek() == ' ')
		in.get();
	in >> Arg.ReZ;
	if (in.peek() == '\n')
	{
		Arg.ImZ = 0;
		return in;
	}
	c = in.get();
	if (c == 'i' || c == 'j')
	{
		Arg.ImZ = Arg.ReZ;
		Arg.ReZ = 0;
		return in;
	}
	else if (c == ' ')
	{
		Arg.ImZ = 0;
		return in;
	}
	else if (c == '-')
	{
		in >> Arg.ImZ;
		Arg.ImZ = -Arg.ImZ;
		c = in.get();
		if (c != 'j' && c != 'i')
		{
			Arg.ImZ = 0;
			cout << "le wpisana liczba, brak 'i' lub 'j' na koñcu, ImZ ustawione na 0" << endl;
		}
		return in;
	}
	else if (c == '+')
	{
		in >> Arg.ImZ;
		c = in.get();
		if (c != 'j' && c != 'i')
		{
			Arg.ImZ = 0;
			cout << "le wpisana liczba, brak 'i' lub 'j' na koñcu, ImZ ustawione na 0" << endl;
		}
		return in;
	}
	else
	{
		cout << "le okreœlony znak, ImZ ustawione na 0" << endl;
		Arg.ImZ = 0;
		return in;
	}
}

float liczbaZespolona::pobierz_re()
{
	return ReZ;
}

float liczbaZespolona::pobierz_im()
{
	return ImZ;
}

ofstream &operator<<(ofstream &out, liczbaZespolona &Arg)
{
	if (Arg.pobierz_im() >= 0)
	{
		out << Arg.pobierz_re() << "+" << Arg.pobierz_im() << "i";
	}
	else
	{
		out << Arg.pobierz_re() << Arg.pobierz_im() << "i";
	}
	return out;
}

ifstream &operator >> (ifstream &in, liczbaZespolona &Arg)
{
	char c;
	float re, im;
	if (in.peek() == ' ')
		in.get();
	in >> re;
	Arg.ustaw_re(re);
	if (in.peek() == '\n')
	{
		im = 0;
		Arg.ustaw_im(im);
		return in;
	}
	c = in.get();
	if (c == 'i' || c == 'j')
	{
		im = re;
		Arg.ustaw_im(im);
		re = 0;
		Arg.ustaw_re(re);
		return in;
	}
	else if (c == ' ')
	{
		im = 0;
		Arg.ustaw_im(im);
		return in;
	}
	else if (c == '-')
	{
		in >> im;
		im = -im;
		Arg.ustaw_im(im);
		c = in.get();
		if (c != 'j' && c != 'i')
		{
			im = 0;
			Arg.ustaw_im(im);
			cout << "le wpisana liczba, brak 'i' lub 'j' na koñcu, ImZ ustawione na 0" << endl;
		}
		return in;
	}
	else if (c == '+')
	{
		in >> im;
		Arg.ustaw_im(im);
		c = in.get();
		if (c != 'j' && c != 'i')
		{
			im = 0;
			Arg.ustaw_im(im);
			cout << "le wpisana liczba, brak 'i' lub 'j' na koñcu, ImZ ustawione na 0" << endl;
		}
		return in;
	}
	else
	{
		cout << "le okreœlony znak, ImZ ustawione na 0" << endl;
		im = 0;
		Arg.ustaw_im(im);
		return in;
	}
}