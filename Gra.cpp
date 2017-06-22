#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Gra.h"
#include"Plansza.h"
using namespace std;


Gra::Gra()
{
}


Gra::~Gra()
{
}

void Gra::Graj()
{
	int x, y;

	for (int i = 0; i < 40; i++)
	{
		system("@cls");
		plansza2.Wyswietl();
		if (NaWodzie() == 1)
		{
			cout << "Bitwa Wygrana!!!";
				return;
		}
		cout << "Pdaj wspolrzedne celu" << endl << "x-> ";
		cin >> x;
		cout << "y-> ";
		cin >> y;
		if (x == 0 || y == 0) return ;
		plansza2.UstawStan(x - 1, y - 1, 2);
		plansza2.UstawTyp(x - 1, y - 1, '-');
		for (int a = 0; a < 4; a++)
		{
			tab[a].MojStan();
		}

	}
	cout << "Bitwa Przegrana!!!";
	return;





	plansza2.Wyswietl();

}

int Gra::NaWodzie()
{
	int l = 0;
	for (int a = 0; a < 4; a++)
	{
		if (tab[a].IleTrafien() == 4) l++;
	}
	if (l == 4) return 1;
	cout << "Zatopione Statki: " << l<<endl;
	cout << "Plywajace Statki: " << 4-l << endl;
	
	return 0;
}

void Gra::Organizuj()
{
	srand(time(NULL));
	int x, y, o;
	plansza2.NadWsp();
	
	for (int a = 0; a < 4; a++)
	{
		start:
		while (true)
		{
			x = (rand() % 10);
			y = (rand() % 10);
			o = rand() % 2;
			
			if (o == 1)
			{
				if (y > 6) continue;
				{
					
					for (int i = y; i < y + 4; i++)
						if (plansza2.DajStan(x, i) == 3) goto start;

					cout << x << "   " << y << endl;
					tab[a].Ustaw(plansza2.DajAdres(x, y), plansza2.DajAdres(x, y+1), plansza2.DajAdres(x, y+2), plansza2.DajAdres(x, y+3));
					//przypisanie adresu do do wskaŸników w statku
					break;
				}
			}
			else
			{
				if (x > 6) continue;
				{
					
					for (int i = x; i < x + 4; i++)
						if (plansza2.DajStan(i, y) == 3) goto start;
					cout << x << "   " << y << endl;
					tab[a].Ustaw(plansza2.DajAdres(x, y), plansza2.DajAdres(x+1, y), plansza2.DajAdres(x+2, y), plansza2.DajAdres(x+3,y));
					//przypisanie adresu do do wskaŸników w statku
					break;
				}
			}


		}
	}



}

void Gra::WspSta()
{
	for (int a = 0; a < 4; a++)
	{
		cout << endl<<tab[a].x << "   " << tab[a].y ;
	}
}
