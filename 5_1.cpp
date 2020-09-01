#include <iostream>
#include <string>
//#include "stdafx.h"

using namespace std;



class lokalizacja;

class panstwaMiasta {
public:
	panstwaMiasta  ();
	panstwaMiasta  (string Nmiasto);
	~panstwaMiasta ();
	panstwaMiasta  (const panstwaMiasta& stareDane);
	void wyswietl  ();
	void zmien_dane(lokalizacja lok);
private:
	// most important data for class
	string miasto;
};


class lokalizacja {
	friend void panstwaMiasta::zmien_dane (lokalizacja lok);
public:
	lokalizacja (string Npanstwo = "") {
		panstwo = Npanstwo;
	}
	lokalizacja (const lokalizacja& nowaLokalizacja)
	{
		panstwo = nowaLokalizacja.panstwo;
	}
	void wypisz ();
private:
	string panstwo;
};


panstwaMiasta::panstwaMiasta ()
{
	miasto = "";
	cout << "Stworzono domyslnie obiekt." << endl;
}

panstwaMiasta::panstwaMiasta (string Nmiasto): miasto(Nmiasto)
{
	cout << "Stworzono sparametryzowany obiekt: " << Nmiasto << endl;
}

panstwaMiasta::~panstwaMiasta ()
{
	cout << "Usunieto obiekt. " << endl;
}

panstwaMiasta::panstwaMiasta (const panstwaMiasta& stareDane)
{
	miasto = stareDane.miasto;
	cout << "Skopiowano obiekt: " << stareDane.miasto << endl;
}

void panstwaMiasta::wyswietl ()
{
	cout << miasto << endl;
}

void panstwaMiasta::zmien_dane(lokalizacja lok)
{
	lok.panstwo = "Polska";
}


void lokalizacja::wypisz ()
{
	cout << panstwo << endl;
}




int main (void)
{
	lokalizacja panstwo_A("USA");
	panstwo_A.wypisz();
	panstwaMiasta miasto_A ("New York");
	miasto_A.wyswietl();
	miasto_A.zmien_dane(panstwo_A);
	panstwo_A.wypisz();
	
	cout << "\nWyswitlamy obieky:" << endl;
	cout << endl;
	
	
	int dlugosc = 10;
	panstwaMiasta * tab[dlugosc];
	
	for (int i = 0; i < dlugosc; ++i){
		tab[i] = new panstwaMiasta;
	}
	
	for (int i = 0; i < dlugosc; ++i){
		delete tab[i];
	}
	
	miasto_A.~panstwaMiasta ();
	panstwo_A.~lokalizacja();
	
	return 0;
}