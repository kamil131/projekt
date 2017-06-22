#pragma once
class Punkt
{
public:
	Punkt();
	~Punkt();
	char DajTyp();
	int DajStan();
	void UstawTyp(char);
	void UstawStan(int);
	void UstawWsp(int, int);

	int x;
	int y;
private:
	char typ;
	int stan;
	
};

