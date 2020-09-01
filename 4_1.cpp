// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;



class produkt {
public:
	produkt ();
	produkt (string Nnazwa, float Ncena);
	produkt (produkt& skopiowany);
	void wypisz();
private:
	string nazwa;
	float  cena;
};

produkt::produkt()
{
	nazwa = "produkt";
	cena  = (rand() % 350 + 50) / 10.;
}

produkt::produkt (string Nnazwa, float Ncena)
{
	nazwa = Nnazwa;
	cena  = Ncena;
}

produkt::produkt (produkt& skopiowany)
{
	nazwa = skopiowany.nazwa;
	cena  = skopiowany.cena;
}

void produkt::wypisz ()
{
	cout << "Nazwa: " << nazwa << " ,cena: " << cena << endl;
}



class koszyk {
public:
	int static licznik;
	koszyk (): limit (5), iloscProduktow (1)
	{
		tablica[0];
		cout << "Wywolany konstruktor klasy koszyk." << endl;
		++licznik;
	}
	~koszyk ()
	{
		cout << "Wywolany destruktor klasy koszyk." << endl;
		--licznik;
	}
	void uzupelnij (int noweProdukty);
	void wypisz ();
private:
	int const limit;
	int iloscProduktow;
	produkt tablica[5];
};

void koszyk::uzupelnij (int noweProdukty)
{
	int staraWart = iloscProduktow;
	iloscProduktow += noweProdukty;
	
	if (iloscProduktow > limit) {
		iloscProduktow -= abs (iloscProduktow - 5);
		cout << "Nie mozna wprowadzic 6 produktu." << endl;
	}
	for (int i = staraWart; i < iloscProduktow; ++i){
		tablica[i];
	}
	++licznik;
}

void koszyk::wypisz ()
{
	cout << "Koszyk: " << endl;
	for (int i = 0; i < iloscProduktow; ++i){
		cout << " produkt: ";
		tablica[i].wypisz();
	}
	cout << endl;
}




int koszyk::licznik = 0;

int main (void)
{
	srand (time (NULL));
	
	produkt obiekt_A;
	obiekt_A.wypisz ();
	
	koszyk obiekt_B;
	obiekt_B.wypisz();
	
	koszyk * obiekt_C [3];
	for (int i = 0; i < 3; ++i){
		obiekt_C [i] = new koszyk;
		obiekt_C [i] -> wypisz();
	}
	
	produkt obiekt_D = obiekt_A;
	obiekt_A = produkt ("jablko", 2);
	obiekt_A.wypisz ();
	obiekt_D.wypisz ();
	
	obiekt_A.~produkt ();
	obiekt_B.~koszyk ();
	obiekt_D.~produkt ();
	
	for (int i = 0; i < 3; ++i){
		delete obiekt_C [i];
	}
	cout << "\nLicznik = " << koszyk::licznik << endl;
	system("pause");
	
	
	cin.get();
	int limes = 5;
	koszyk * duzeZakupy [limes][limes];
	
	
	for (int i = 0; i < limes; ++i){
		for (int j = 0; j < limes; ++j){
			duzeZakupy[i][j] = new koszyk;
		}
	}
	cout << "\nLicznik = " << koszyk::licznik << endl;
	
	for (int i = 0; i < limes; ++i){
		for (int j = 0; j < limes; ++j){
			delete duzeZakupy[i][j];
		}
	}
	
	cout << "\nLicznik = " << koszyk::licznik << endl;
	
    return 0;
}
