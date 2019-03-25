#pragma once
#ifndef LISTA_H
#define LISTA_H
struct Tura 
{
	char **plansza;
	Tura *next;
};
struct Gracz 
{
	char gracz;
	int x;
	int y;
};
struct Ruch 
{
	int x;
	int y;
	Ruch *next;
};
void dodajDoListy(Tura *&aktualna_tura, char **tab);
void usunListe(Tura *&pierwsza_tura);
void usunListe(Ruch *&wykonywalne_ruchy);
void pobierzWykonywalneRuchy(Ruch *&wykonywalne_ruchy, char **tab, int rozmiar);
void wypiszWykonywalneRuchy(Ruch *wykonywalne_ruchy);
void usunRuch(Ruch *&wykonywalne_ruchy, int x, int y);
#endif // !LISTA_H
