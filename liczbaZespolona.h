#pragma once
#include<iostream>
using namespace std;

class liczbaZespolona
{
private:
	float ReZ;
	float ImZ;
public:
	liczbaZespolona(void);
	liczbaZespolona(float a);
	liczbaZespolona(float a, float b);
	liczbaZespolona(liczbaZespolona &copy);
	~liczbaZespolona();
	void drukuj(void);
	float modul(void);
	float argument(void);
	void ustaw_re(float a);
	void ustaw_im(float a);
	float pobierz_re();
	float pobierz_im();
	liczbaZespolona operator+(liczbaZespolona &Arg2);
	liczbaZespolona operator+(float Arg2);
	liczbaZespolona operator-(liczbaZespolona &Arg2);
	liczbaZespolona operator-(float Arg2);
	liczbaZespolona operator*(liczbaZespolona &Arg2);
	liczbaZespolona operator*(float Arg2);
	liczbaZespolona operator/(liczbaZespolona &Arg2);
	liczbaZespolona operator/(float Arg2);
	liczbaZespolona &operator=(liczbaZespolona &Arg2);
	liczbaZespolona &operator=(float Arg2);
	liczbaZespolona &operator+=(liczbaZespolona &Arg2);
	liczbaZespolona &operator+=(float Arg2);
	liczbaZespolona &operator-=(liczbaZespolona &Arg2);
	liczbaZespolona &operator-=(float Arg2);
	liczbaZespolona &operator*=(liczbaZespolona &Arg2);
	liczbaZespolona &operator*=(float Arg2);
	liczbaZespolona &operator/=(liczbaZespolona &Arg2);
	liczbaZespolona &operator/=(float Arg2);
	liczbaZespolona &operator-(void);
	bool operator>(liczbaZespolona &Arg2);
	bool operator<(liczbaZespolona &Arg2);
	bool operator>=(liczbaZespolona &Arg2);
	bool operator<=(liczbaZespolona &Arg2);
	bool operator==(liczbaZespolona &Arg2);
	bool operator!=(liczbaZespolona &Arg2);
	friend ostream &operator<<(ostream &out, liczbaZespolona &Arg);
	friend istream &operator>>(istream &in, liczbaZespolona &Arg);
};