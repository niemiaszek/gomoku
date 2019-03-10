#include <iostream>
#include "lista.h"
using namespace std;
void dodajDoListy(Tura *&aktualna_tura, char **tab) 
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
}