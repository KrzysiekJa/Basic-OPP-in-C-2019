// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>



using namespace std;

class panstwaMiasta {
private:
	string	   miasto;
	string	   panstwo;
	string     stolica;
	string	   region;
	int		   poludnik;
	int		   rownoleznik;
public:
	static int licznik;
	panstwaMiasta();
	panstwaMiasta(string Nmiasto, string Npanstwo, string Nstolica, string Nregion, int Npoludnik, int Nrownoleznik);
	~panstwaMiasta();
	void wyswietl_dane();

	panstwaMiasta & operator=(const panstwaMiasta & bazowy) {
		if (this != &bazowy) {
			miasto  	= bazowy.miasto;
			panstwo 	= bazowy.panstwo;
			stolica 	= bazowy.stolica;
			region  	= bazowy.region;
			poludnik    = bazowy.poludnik;
			rownoleznik = bazowy.rownoleznik;
			++licznik;
		}

		return * this;
	}
	panstwaMiasta & operator-(const int & odejmij) {
		poludnik	-= odejmij;
		rownoleznik -= odejmij;
		++licznik;

		return * this;
	}
	panstwaMiasta & operator+(const int & dodaj) {
		poludnik	+= dodaj;
		rownoleznik += dodaj;
		++licznik;

		return * this;
	}
	panstwaMiasta & operator/(const int & dzielnik) {
		poludnik	/= dzielnik;
		rownoleznik /= dzielnik;
		++licznik;
		
		return * this;
	}	
	panstwaMiasta & operator-=(const panstwaMiasta & inne){
		poludnik    -= inne.poludnik;
		rownoleznik -= inne.rownoleznik;
		++licznik;
		
		return * this;
	}
	panstwaMiasta & operator+=(const panstwaMiasta & inne) {
		poludnik	+= inne.poludnik;
		rownoleznik += inne.rownoleznik;
		++licznik;
		
		return * this;
	}
	bool operator==(const panstwaMiasta inne) const {
		
		return (poludnik == inne.poludnik && rownoleznik == inne.rownoleznik && miasto == inne.miasto && region == inne.region);
	}
	bool operator!=(const panstwaMiasta inne) const {
		
		return !(poludnik == inne.poludnik && rownoleznik == inne.rownoleznik && miasto == inne.miasto && region == inne.region);
	}
	panstwaMiasta & operator++() {
		// preinkrementacja
		poludnik	+= 5;
		rownoleznik += 5;

		return * this;
	}
	panstwaMiasta & operator++(int) {
		// postinkrementacja
		panstwaMiasta kopia = (* this);
		poludnik	+= 5;
		rownoleznik += 5;
		++licznik;

		return kopia;
	}
	void * operator new (size_t rozmiar) {
		cout << "Dokonano dynamicznej allokacji " << rozmiar << " bajtow." << endl;
		return malloc(rozmiar);
	}
	friend ostream & operator << (ostream & stream, panstwaMiasta & PM) {
		stream << "Miasto " << PM.miasto << " ma polozenie: " << PM.poludnik << ", " << PM.rownoleznik << endl;
		
		return stream;
	}
	friend istream & operator >> (istream & stream, panstwaMiasta & PM) {
		stream >> PM.miasto >> PM.panstwo >> PM.stolica >> PM.region >> PM.poludnik >> PM.rownoleznik;
		
		return stream;
	}
};

panstwaMiasta::panstwaMiasta()
{
	miasto  = "Jerozolima";
	panstwo = "Izrael";
	stolica = "";
	region  = "";
	poludnik    = 30;
	rownoleznik = 35;
	++licznik;
	
	cout << "Stworzono domyslny obiekt." << endl;
}

panstwaMiasta::panstwaMiasta(string Nmiasto, string Npanstwo, string Nstolica, string Nregion, int Npoludnik, int Nrownoleznik) :
	miasto(Nmiasto), panstwo(Npanstwo), stolica(Nstolica), region(Nregion), poludnik(Npoludnik), rownoleznik(Nrownoleznik)
{
	++licznik;
	cout << "Stworzono sparametryzowany obiekt: " << Nmiasto << endl;
}

panstwaMiasta::~panstwaMiasta()
{
	--licznik;
	cout << "Usunieto obiekt. " << endl;
}

void panstwaMiasta::wyswietl_dane()
{
	cout << miasto << " " << panstwo << " " << stolica << " " << region << endl;
	cout << poludnik << " " << rownoleznik << endl;
}





int panstwaMiasta::licznik = 0;

int main ()
{
	panstwaMiasta miasto_A("New York", "USA", "Washington", "North America", 30, 35);
	cout << miasto_A;
	panstwaMiasta miasto_B = miasto_A / 3;
	cout << miasto_B << endl;
	
	panstwaMiasta miasto_C = miasto_A + 10;
	cout << miasto_C;
	miasto_C = miasto_A - 15;
	cout << miasto_C << endl;
	
	
	panstwaMiasta miasto_D;
	cout << miasto_D;
	miasto_D += miasto_A;
	cout << miasto_D;
	miasto_D -= miasto_A;
	cout << miasto_D;
	
	panstwaMiasta miasto_E;
	cout << "Wprowadz dane: " << endl;
	cin >> miasto_E;
	panstwaMiasta miasto_F = miasto_E;
	cout<< miasto_F;
	
	panstwaMiasta miasto_G = miasto_E;
	cout << miasto_G;
	(++miasto_G)++;
	miasto_G.wyswietl_dane();
	
	
	panstwaMiasta miasto1("Rome", "Imperium Romanum", "Roma", "Europa", 12, 41);
	panstwaMiasta miasto2("Rome", "Italia", "Roma", "Europa", 12, 41);
	cout << endl << "miato1 jest tozsame z miasto2: " << (miasto1==miasto2) << endl;
	cout << "miato1 nie jest tozsame z miasto_B: " << (miasto1!=miasto2) << endl;
	
	cout << "\nLicznik : " << panstwaMiasta::licznik << endl << endl;
	
	int limes = 10;
	panstwaMiasta * tablica[limes];
	
	
	
	for (int i = 0; i < limes; ++i) {
		tablica[i] = new panstwaMiasta;
	}
	
	cout << "\nLicznik : " << panstwaMiasta::licznik << endl << endl;
	
	for (int i = 0; i < limes; ++i) {
		delete tablica[i];
	}
	
	
	cout << "\nLicznik : " << panstwaMiasta::licznik << endl << endl;
	
	return 0;
}