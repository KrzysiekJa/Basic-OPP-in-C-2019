#include <iostream>
#include <string>

using namespace std;




class Pracownik
{
public:
	static int STAWKA;
	static int licznik_prac;
	
	void sparametryzowanie(void)
	{
		cin >> imie >> nazwisko >> id;
	}
	
	Pracownik()
	{
		imie     = "Jan";
		nazwisko = "Kowalski";
		id 		 = 55055;
		stawka_pracownika = STAWKA;
		++licznik_prac;
		cout << "Mamy nowego domyślengo pracownika! " << imie << " "<< nazwisko << " " << id << endl;
	}
	
	Pracownik(string Nimie, string Nnazwisko, int Nid): imie(Nimie), nazwisko(Nnazwisko), id(Nid)
	{
		stawka_pracownika = STAWKA;
		++licznik_prac;
		cout << "Mamy nowego pracownika! " << imie << " "<< nazwisko << " " << id << endl;
	}
	
	Pracownik(const Pracownik & wzorzec)
	{
		imie 	 = wzorzec.imie;
		nazwisko = wzorzec.nazwisko;
		id 		 = wzorzec.id;
		stawka_pracownika = wzorzec.stawka_pracownika;
		
		cout << "Mamy nowego pracownika - prawdziwą kopię " << wzorzec.imie << "! " << imie << " "<< nazwisko << " " << id << endl;
		++licznik_prac;
	}
	
	~Pracownik()
	{
		cout << "Żegnamy pracownika." << endl;
		--licznik_prac;
	}
	
	void wyswietl_dane()
	{
		cout << imie << " "<< nazwisko << " id:" << id << " , stawka: " << stawka_pracownika << endl;
	}
	
protected:
	string imie, nazwisko;
	int id, stawka_pracownika;
};



class Informatyk: public Pracownik
{
public:
	Informatyk()
	{
		stawka_pracownika = static_cast<int>(3.5 * STAWKA);
	}
	
	Informatyk(string Nimie, string Nnazwisko, int Nid): Pracownik(Nimie, Nnazwisko, Nid)
	{
		stawka_pracownika = static_cast<int>(3.5 * STAWKA);
	}
	
	Informatyk(const Informatyk & wzorzec)
	{
		stawka_pracownika = static_cast<int>(3.5 * STAWKA);;
	}
	
	~Informatyk(){}
};



class Kierownik: public Pracownik
{
public:
	Kierownik()
	{
		stawka_pracownika = static_cast<int>(5.2 * STAWKA);
	}
	
	Kierownik(string Nimie, string Nnazwisko, int Nid): Pracownik(Nimie, Nnazwisko, Nid)
	{
		stawka_pracownika = static_cast<int>(5.2 * STAWKA);
	}
	
	Kierownik(const Kierownik & wzorzec)
	{
		stawka_pracownika = static_cast<int>(5.2 * STAWKA);
	}
	
	~Kierownik(){}
};





int Pracownik::STAWKA       = 20;
int Pracownik::licznik_prac = 0;

int main (void)
{
	cout << Pracownik::licznik_prac << endl << endl;
	Pracownik pierwszy;
	Pracownik pan_Marek;
	pan_Marek.sparametryzowanie();
	
	Informatyk primus;
	Informatyk secundus = primus;
	Kierownik  maximus("Szef", "Twój", 007);
	
	cout << Pracownik::licznik_prac << endl << endl;
	
	
	Kierownik  wzor_pracownik("Maciek", "Maciek", 34251);
	wzor_pracownik.wyswietl_dane();
	
	Pracownik * zespol[3];
	zespol[0] = new Kierownik;
	zespol[1] = new Informatyk;
	zespol[2] = new Pracownik;
	
	for(int i=0; i > sizeof(zespol)/sizeof(*zespol); ++i){
		zespol[i] -> wyswietl_dane();
	}
	
	cout << Pracownik::licznik_prac << endl << endl;
	
	return 0;
}
