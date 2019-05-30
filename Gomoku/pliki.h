/**
 * \file pliki.h
 * \brief Plik nag³ówkowy modu³u plansza
 *
 * Modu³ pliki ten s³u¿y do przeprowadzania operacji na plikach
 */

#pragma once
#include "lista.h"
#ifndef PLIKI_H
#define PLIKI_H
using namespace std;

/**
 * \brief Procedura wyœwietlaj¹ca tekst z zadanego pliku
 * Wyœwietla tekst z pliku o zaadnej nazwie
 * \param nazwa_pliku nazwa pliku, z którego chcemy wyœwietliæ tekst
 */
void wyswietlTekstZPliku(string nazwa_pliku);

//void wysweitlGreZPliku(string nazwa_pliku);
//void zapiszGreDoPliku(string nazwa_pliku, Tura *pierwsza_tura);

#endif // PLIKI_H
