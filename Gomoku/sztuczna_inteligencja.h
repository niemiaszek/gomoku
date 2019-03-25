#pragma once
#include "lista.h"
#ifndef SZTUCZNA_INTELIGENCJA_H
#define SZTUCZNA_INTELIGENCJA_H
void latwy(char **&tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, Ruch *&wykonywalne_ruchy);
void sredni(char **&tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, Ruch *&wykonywalne_ruchy);
#endif // SZTUCZNA_INTELIGENCJA_H
