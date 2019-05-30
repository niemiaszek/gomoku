/**
 * \file plansza.cpp
 * \brief Plik implementacji modu³u plansza
 *
 * Modu³ plansza zawiera metody wykorzystywane do operowania plansz¹ (tablic¹ dwuwymiarow¹ typu char **)
 */

#include "plansza.h"
#include "interfejs.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "lista.h"
#include <windows.h>
#include "rozgrywka.h"
#include <vector>

using namespace std;

void utworzPlansze(char **&tab, int rozmiar)
{
	tab = new char*[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tab[i] = new  char[rozmiar];
	}
	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++)
			tab[i][j] = ' ';
}
void utworzPomocznicza(char **tab, char **&pomocnicza, int rozmiar) 
{
	pomocnicza = new char*[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		pomocnicza[i] = new  char[rozmiar];
	}
	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++)
			pomocnicza[i][j] = tab[i][j];
}
void kasujPlansze(char **tab, int rozmiar) 
{
	for (int i = 0; i < rozmiar; i++)
		delete[]tab[i];
	delete[]tab;
	tab = NULL;
}
