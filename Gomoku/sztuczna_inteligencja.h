#pragma once
#include "lista.h"

#ifndef SZTUCZNA_INTELIGENCJA_H
#define SZTUCZNA_INTELIGENCJA_H
void latwy(char **&tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, Ruch *&wykonywalne_ruchy);
void sredni(char **&tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, Ruch *&wykonywalne_ruchy);
void trudny(char**& tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int glebokosc);	
int minimax(Pozycja*& aktualna_pozycja, int glebokosc, int& alfa, int& beta, bool gracz_tury, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int &ilosc, int &ilosc_finalnych);
#endif // SZTUCZNA_INTELIGENCJA_H
