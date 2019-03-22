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
	int score;
	int x;
	int y;
};
void dodajDoListy(Tura *&aktualna_tura, char **tab);
void usunListe(Tura *&pierwsza_tura);
#endif // !LISTA_H
