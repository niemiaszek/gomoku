#include <iostream>
#include <fstream>
#include "pliki.h"
#include <string>
#include "interfejs.h"
using namespace std;
void wyswietlZPliku(string nazwa_pliku) 
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
		getline(plik, linia);
		while (!plik.eof())
		{
			cout << linia << endl;
			getline(plik, linia);
		}
	}
	cout << "Wcisnij dowolny przycisk, aby przejsc dalej..." << endl;
	kliknijAbyPrzejscDalej();
	menuGlowne();
}