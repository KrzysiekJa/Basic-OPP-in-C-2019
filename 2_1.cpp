// 1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class panstwaMiasta{
private:
	string	   miasto;
	string	   panstwo;
	string     stolica;
	string	   region;
public:
	static int licznik;
	panstwaMiasta    ();
	panstwaMiasta    (string Nmiasto, string Npanstwo, string Nstolica, string Nregion);
	~panstwaMiasta   ();
	panstwaMiasta    (const panstwaMiasta& skopiowaneDane);
	bool czyWpolsce  (string);
	void czytaj_dane () {
		cin >> miasto;
		cin >> panstwo;
		cin >> stolica;
		cin >> region;
	}
	void wyswietl_wynik () {cout << "I czy " << miasto << " lezy w Polsce : " << czyWpolsce (panstwo) << endl;}
	void wyswietl_dane  ();
};

panstwaMiasta::panstwaMiasta ()
{
	miasto  = "";
	panstwo = "";
	stolica = "";
	region  = "";
	++licznik;
	cout << "Stworzono domyslny obiekt." << endl;
}

panstwaMiasta::panstwaMiasta (string Nmiasto, string Npanstwo, string Nstolica, string Nregion):
	miasto (Nmiasto), panstwo (Npanstwo), stolica (Nstolica),region (Nregion)
{
	++licznik;
	cout << "Stworzono sparametryzowany obiekt: " << Nmiasto <<endl;
}

panstwaMiasta::panstwaMiasta (const panstwaMiasta& skopiowaneDane)
{
	miasto  = skopiowaneDane.miasto;
	panstwo = skopiowaneDane.panstwo;
	stolica = skopiowaneDane.stolica;
	region  = skopiowaneDane.region;
	++licznik;
	cout << "Skopiowano obiekt: " << skopiowaneDane.miasto << endl;
}

panstwaMiasta::~panstwaMiasta()
{
	--licznik;
	cout << "Usunieto obiekt. " << endl;
}

bool panstwaMiasta::czyWpolsce (string panstwo)
{
	if (panstwo == "Polska") {
		return true;
	}
	else {
		return false;
	}
}

void panstwaMiasta::wyswietl_dane ()
{
	cout << miasto << " " << panstwo << " " << stolica << " " << region << endl;
}

int panstwaMiasta::licznik = 0;



int main()
{
	panstwaMiasta Obiekt_A;
	panstwaMiasta Obiekt_B ("New York", "USA", "Washington", "North America");
	panstwaMiasta Obiekt_C = Obiekt_B;
	int ilosc = panstwaMiasta::licznik;
	cout << "Licznik po deklaracjach : " << ilosc << endl << endl;
	
	Obiekt_B = panstwaMiasta ("Toronto", "Kanada", "Ottawa", "North America");
	cout << "Licznik po kolejnej deklaracji : " << ilosc << endl << endl;
	
	cout << "Wyswitlamy obieky:" << endl;
	Obiekt_B.wyswietl_dane();
	Obiekt_C.wyswietl_dane();
	cout << endl;
	
	Obiekt_A.~panstwaMiasta();
	Obiekt_B.~panstwaMiasta();
	Obiekt_C.~panstwaMiasta();
	
	ilosc = panstwaMiasta::licznik;
	cout << "Licznik po usunieciu : " << ilosc << endl << endl;
	
	
	panstwaMiasta  nNazwa;
	panstwaMiasta* wPanstwo = new panstwaMiasta;
	cout << "Prosze podac kolejno miasto, panstwo, w ktorym lezy, jej stolice i region swiata (potwierdzenie - ENTER): ";
	nNazwa.czytaj_dane ();
	nNazwa.wyswietl_wynik ();
	cout << endl;
	
	cout << "Prosze podac kolejne miasto, rowniez panstwo, w ktorym lezy, jej stolice i region swiata: ";
	wPanstwo -> czytaj_dane();
	wPanstwo -> wyswietl_wynik();
	
	delete wPanstwo;

    return 0;
}