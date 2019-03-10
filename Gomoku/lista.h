#pragma once
#ifndef LISTA_H
#define LISTA_H
struct Tura 
{
	char **plansza;
	Tura *next;
};
void dodajDoListy(Tura *&aktualna_tura, char **tab);
void usunListe(Tura *&pierwsza_tura);
#endif // !LISTA_H
