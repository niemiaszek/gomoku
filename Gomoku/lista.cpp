/**
 * \file lista.cpp
 * \brief Plik implementacji modu³u lista
 *
 * Modu³ lista zawiera definicje struktur u¿ywanych jako elementy list oraz metod wykorzystywanych na listach
 */

#include <iostream>
#include "lista.h"
#include "stan.h"
#include "plansza.h"
using namespace std;

/*void dodajDoListy(Tura *&aktualna_tura, char **tab) 
{
	if (aktualna_tura == NULL)
	{
		aktualna_tura = new Tura;
		aktualna_tura->next = NULL;
		aktualna_tura->plansza = tab;
	}
	else
	{
		Tura *akt = aktualna_tura;
		while (akt->next != NULL)
			akt = akt->next;
		Tura *nowy = new Tura;
		akt->next = nowy;
		nowy->next = NULL;
		nowy->plansza = tab;
	}
}

void usunListe(Tura *&pierwsza_tura) 
{
	while(pierwsza_tura != NULL)
	{
		Tura *tmp = pierwsza_tura;
		pierwsza_tura = pierwsza_tura ->next;
		delete tmp;
	}
}*/
void usunListe(Ruch *&wykonywalne_ruchy)
{	
	if (wykonywalne_ruchy == NULL)
		return;
	if (wykonywalne_ruchy->next == NULL)
	{
		delete wykonywalne_ruchy;
		wykonywalne_ruchy = NULL;
		return;
	}
	while (true)
	{
		//cout << "tu" << "\n";
		//wypiszWykonywalneRuchy(wykonywalne_ruchy);
		//cout << wykonywalne_ruchy;
		if (wykonywalne_ruchy == NULL)
			break;
		Ruch *tmp = wykonywalne_ruchy->next;
		delete wykonywalne_ruchy;
		wykonywalne_ruchy = tmp;
		//cout << wykonywalne_ruchy;;
	}
}

void pobierzWykonywalneRuchy(Ruch *&wykonywalne_ruchy, char **tab, int rozmiar)
{
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			if (tab[i][j] == ' ') {
				if (wykonywalne_ruchy == NULL)
				{
					wykonywalne_ruchy = new Ruch;
					wykonywalne_ruchy->next = NULL;
					wykonywalne_ruchy->x = i;
					wykonywalne_ruchy->y = j;
				}
				else
				{
					Ruch *akt = wykonywalne_ruchy;
					while (akt->next != NULL)
						akt = akt->next;
					Ruch *nowy = new Ruch;
					akt->next = nowy;
					nowy->next = NULL;
					nowy->x = i;
					nowy->y = j;
				}
			}
		}
	}
}
void wypiszWykonywalneRuchy(Ruch *wykonywalne_ruchy)
{
	if (wykonywalne_ruchy == NULL)
		return;
	Ruch *akt = wykonywalne_ruchy;
	while (akt != NULL) {
 		cout << '(' << akt->x << ", " << akt->y << ") ";
		akt = akt->next;
	}
	cout << "\n";
}

void usunRuch(Ruch *&wykonywalne_ruchy, int x, int y) 
{
	if (wykonywalne_ruchy == NULL)
		return;
	Ruch *akt = wykonywalne_ruchy;
	if (akt->x == x && akt->y == y){
		if (akt->next == NULL) 
		{
			delete akt;
			wykonywalne_ruchy = NULL;
			return;
		}
		wykonywalne_ruchy = wykonywalne_ruchy->next;
		delete akt;
		return;
	}
	while (akt->next->next!=NULL) 
	{
		if (akt->next->x == x && akt->next->y == y) 
		{
			Ruch *tmp = akt->next;
			akt->next = akt->next->next;
			delete tmp;
			tmp = NULL;
			return;
		}
		akt = akt->next;
	}
	if (akt->next->next == NULL && akt->next->x == x && akt->next->y == y) 
	{
		Ruch *tmp = akt->next;
		akt->next = NULL;	
		delete tmp;
		tmp = NULL;
		return;
	}
}	
void utworzSyna(Ruch *&ruchy, Pozycja *&aktualna_pozycja, Pozycja *&syn, int rozmiar, char gracz) 
{
	if (ruchy == NULL)
		return;	
	syn = new Pozycja;
	syn->ojciec = aktualna_pozycja;
	syn->x = ruchy->x;
	syn->y = ruchy->y;
	syn->dzieci = NULL;
	//cout << "x, y: " << syn->x << ' ' << syn->y << ' ' << gracz << "\n";
	utworzPomocznicza(aktualna_pozycja->plansza, syn->plansza, rozmiar);
	syn->plansza[syn->x][syn->y] = gracz;
	if (aktualna_pozycja->dzieci == NULL)
	{
		aktualna_pozycja->dzieci = new Dzieci;
		aktualna_pozycja->dzieci->next = NULL;
		aktualna_pozycja->dzieci->dziecko = syn;
	}
	else
	{
		Dzieci* akt = aktualna_pozycja->dzieci;
		while (akt->next != NULL)
			akt = akt->next;
		Dzieci * nowy = new Dzieci;
		akt->next = nowy;
		nowy->next = NULL;
		nowy->dziecko = syn;
	}
	usunRuch(ruchy, ruchy->x, ruchy->y);
}
void dodajRuch(Ruch*& lista_ruchow, int x, int y)
{
	if (lista_ruchow == NULL)
	{
		lista_ruchow = new Ruch;
		lista_ruchow->next = NULL;
		lista_ruchow->x = x;
		lista_ruchow->y = y;
	}
	else
	{
		Ruch* akt = lista_ruchow;
		while (akt->next != NULL)
			akt = akt->next;
		Ruch * nowy = new Ruch;
		akt->next = nowy;
		nowy->next = NULL;
		nowy->x = x;
		nowy->y = y;
	}
}
void losoujRuch(Ruch* lista_ruchow, int licznik, int &x, int &y) 
{
	int wylosowany = rand() % licznik;
	int i = 0;
	Ruch* akt = lista_ruchow;
	while (i != wylosowany) 
	{
		i++;
		akt = akt->next;
	}
	x = akt->x;
	y = akt->y;
}
