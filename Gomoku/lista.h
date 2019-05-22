#pragma once
#ifndef LISTA_H
#define LISTA_H

struct Tura 
{
	char **plansza;
	Tura *next;
};
struct Ruch 
{
	int x;
	int y;
	Ruch *next;
};
struct Dzieci {
	struct Pozycja* dziecko;
	Dzieci* next;
};
struct Pozycja
{
	struct Dzieci* dzieci;
	Pozycja* ojciec;
	char** plansza;
	int wartosc;
	int x;
	int y;
};
void utworzSyna(Ruch*& ruchy, Pozycja*& aktualna_pozycja, Pozycja*& syn, int rozmiar, char gracz);
//void usunDrzewo(Pozycja*& wezel) {};
void dodajDoListy(Tura *&aktualna_tura, char **tab);
void usunListe(Tura *&pierwsza_tura);
void usunListe(Ruch *&wykonywalne_ruchy);
void pobierzWykonywalneRuchy(Ruch *&wykonywalne_ruchy, char **tab, int rozmiar);
void wypiszWykonywalneRuchy(Ruch *wykonywalne_ruchy);
void usunRuch(Ruch *&wykonywalne_ruchy, int x, int y);
void dodajRuch(Ruch*& lista_ruchow, int x, int y);
void losoujRuch(Ruch* lista_ruchow, int licznik, int &x, int &y);
#endif // !LISTA_H
