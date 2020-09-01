// 1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

namespace geopolit {
	class panstwaMiasta {
	public:
		class lokalizacja {
		public:
			lokalizacja (string Npanstwo = "", string Nstolica = "", string Nregion = "") {
				panstwo = Npanstwo;
				stolica = Nstolica;
				region  = Nregion;
			}
			lokalizacja (const lokalizacja& nowaLokalizacja)
			{
				panstwo = nowaLokalizacja.panstwo;
				stolica = nowaLokalizacja.stolica;
				region  = nowaLokalizacja.region;
			}
			void wypisz_dane ();
		private:
			string panstwo;
			string stolica;
			string region;
		};

		panstwaMiasta  ();
		panstwaMiasta  (string Nmiasto, lokalizacja Ndane_miasta);
		~panstwaMiasta ();
		panstwaMiasta  (const panstwaMiasta& stareDane);
		void wyswietl_info ();
	private:
		// most important data for class
		string 		miasto;
		lokalizacja dane_miasta;
	};
	
	panstwaMiasta::panstwaMiasta ()
	{
		miasto      = "";
		dane_miasta = lokalizacja ();
		cout << "Stworzono domyslnie obiekt." << endl;
	}
	
	panstwaMiasta::panstwaMiasta (string Nmiasto, lokalizacja Ndane_miasta) :
		miasto(Nmiasto), dane_miasta(Ndane_miasta)
	{
		cout << "Stworzono sparametryzowany obiekt: " << Nmiasto << endl;
	}
	
	panstwaMiasta::~panstwaMiasta ()
	{
		cout << "Usunieto obiekt. " << endl;
	}
	
	panstwaMiasta::panstwaMiasta (const panstwaMiasta& stareDane)
	{
		miasto  	= stareDane.miasto;
		dane_miasta = stareDane.dane_miasta;
		cout << "Skopiowano obiekt: " << stareDane.miasto << endl;
	}
	
	void panstwaMiasta::wyswietl_info ()
	{
		cout << miasto << " ";
		dane_miasta.wypisz_dane();
	}
	
	void panstwaMiasta::lokalizacja::wypisz_dane ()
	{
		cout << panstwo << " " << stolica << " " << region << endl;
	}
}



int main (void)
{
	geopolit::panstwaMiasta miasto_A;
	geopolit::panstwaMiasta miasto_B ("New York", 
										geopolit::panstwaMiasta::lokalizacja ("USA", "Washington", "North America"));
	geopolit::panstwaMiasta miasto_C = miasto_B;
	miasto_B = geopolit::panstwaMiasta ("Toronto", 
										geopolit::panstwaMiasta::lokalizacja("Kanada", "Ottawa", "North America"));
	
	cout << "Wyswitlamy obieky:" << endl;
	miasto_B.wyswietl_info ();
	miasto_C.wyswietl_info ();
	cout << endl;
	
	miasto_A.~panstwaMiasta ();
	miasto_B.~panstwaMiasta ();
	miasto_C.~panstwaMiasta ();
	
	return 0;
}
