/**
 * \file pliki.cpp
 * \brief Plik implementacji modu³u plansza
 *
 * Modu³ pliki ten s³u¿y do przeprowadzania operacji na plikach
 */

#include <iostream>
#include <fstream>
#include "pliki.h"
#include "lista.h"
#include <string>
#include "interfejs.h"
using namespace std;
void wyswietlTekstZPliku(string nazwa_pliku)
{
	czyscEkran();
	ifstream plik(nazwa_pliku.c_str());
	if (!plik.good()) 
	{
		komunikatBladOtwarciaPliku();
		menuGlowne();
	}
	else 
	{
		string linia;
		do
		{
			getline(plik, linia);
			cout << linia << "\n";
		} while (!plik.eof());
	}
	kliknijAbyPrzejscDalej();
	menuGlowne();
}
/*
void zapiszGreDoPliku(string nazwa_pliku, Tura* pierwsza_tura) 
{
	ofstream plik(nazwa_pliku.c_str(), ios::app);
	while (pierwsza_tura != NULL) {
		if (pierwsza_tura->plansza != NULL)
		{
			for (int i = 0; i < pierwsza_tura->rozmiar; i++)
			{
				for (int j = 0; j < pierwsza_tura->rozmiar; j++)
					plik << pierwsza_tura->plansza[i][j];
				cout << '\n';
			}
		}
		else
			plik << pierwsza_tura->x << ' ' << pierwsza_tura->y << ' ' << pierwsza_tura->gracz << '\n';
		Tura* tmp = pierwsza_tura;
		pierwsza_tura = pierwsza_tura->next;
		if (tmp->plansza != NULL)
			();
	}
}
*/
