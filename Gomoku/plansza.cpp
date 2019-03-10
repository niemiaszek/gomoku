#include "plansza.h"
#include "interfejs.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "lista.h"
#include <windows.h>
#include "rozgrywka.h"
using namespace std;

void utworzPlansze(char **&tab, int rozmiar) // funkcja do tworzenia tablicy dynamicznej
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

void wyswietlPlansze(char **tab, int rozmiar)
{
	//SetConsoleTextAttribute(Kolor, 4);
	for (int i = 0; i < rozmiar + 2; i++)
		cout << setw(2) << '#';
	cout << endl;
	for (int i = 0; i < rozmiar; i++) 
	{
		cout << setw(2) << '#';
		//SetConsoleTextAttribute(Kolor, 6);
		for (int j = 0; j < rozmiar; j++) 
		{
			cout << setw(2) <<tab[i][j];
		}
		//SetConsoleTextAttribute(Kolor, 4);
		cout << setw(2) <<'#' << endl;
	}
	for (int i = 0; i < rozmiar + 2; i++)
		cout << setw(2) << '#';
	cout << endl;
}
void kasujPlansze(char **tab, int rozmiar) 
{
	for (int i = 0; i < rozmiar; i++)
		delete[]tab[i];
	delete[]tab;
	tab = NULL;
}
char ruchGracza(char **&tab, int rozmiar, char gracz) 
{
	int aktx = 0, akty = 0;
	char opcja=poruszaniePoPlanszy(tab, rozmiar, aktx, akty, gracz);
	return opcja;
}
char poruszaniePoPlanszy(char **&tab, int rozmiar, int &aktx, int &akty, char gracz) 
{
	czyscEkran();
	char **pomocnicza;
	utworzPomocznicza(tab, pomocnicza, rozmiar);
	if (tab[aktx][akty] == ' ')
		pomocnicza[aktx][akty] = gracz;
	if (tab[aktx][akty] == 'x' || tab[aktx][akty] == 'o')
		pomocnicza[aktx][akty] = '#';
	wyswietlPlansze(pomocnicza, rozmiar);
	//SetConsoleTextAttribute(Kolor, 2);
	cout << endl << "Sterowanie:" << setw(3) << ' ' << "Esc - Zakoncz rozgrywke" << setw(3) << ' ' << "Strzalki - Poruszanie kursora" << setw(3) << ' ' << "Enter - Zatwierdz ruch" << endl;
	kasujPlansze(pomocnicza, rozmiar);
	int polecenie = _getch();
	if (polecenie == 27)
		return 'E';
	if (polecenie == 0 || polecenie == 224) 
	{
		switch (_getch())
		{
		case 72: //strza³ka w gore
			if (aktx > 0)
				aktx--;
			break;
		case 80: //strza³ka w dol
			if (aktx < rozmiar-1)
				aktx++;
			break;
		case 77: //strza³ka w prawo
			if (akty < rozmiar-1)
				akty++;
			break;
		case 75: //strza³ka w lewo
			if (akty > 0)
				akty--;
			break;
		}
		poruszaniePoPlanszy(tab, rozmiar, aktx, akty, gracz);
	}
	else if (polecenie == 13) 
	{
		if (tab[aktx][akty] == ' ')
			tab[aktx][akty] = gracz;
		else 
			poruszaniePoPlanszy(tab, rozmiar, aktx, akty, gracz);
	}
}