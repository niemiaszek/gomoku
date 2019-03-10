#include <iostream>
#include <fstream>
#include "pliki.h"
#include <string>
#include "interfejs.h"
using namespace std;
void wyswietlTekstZPliku(string nazwa_pliku)
{
	czyscEkran();
	ifstream plik(nazwa_pliku.c_str());
	if (!plik.good()) 
	{
		cout << "Blad otworzenia pliku " << endl;
		return;
	}
	else 
	{
		string linia;
		do
		{
			getline(plik, linia);
			cout << linia << endl;
		} while (!plik.eof());
	}
	kliknijAbyPrzejscDalej();
	menuGlowne();
}