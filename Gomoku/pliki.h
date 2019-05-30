/**
 * \file pliki.h
 * \brief Plik nag��wkowy modu�u plansza
 *
 * Modu� pliki ten s�u�y do przeprowadzania operacji na plikach
 */

#pragma once
#include "lista.h"
#ifndef PLIKI_H
#define PLIKI_H
using namespace std;

/**
 * \brief Procedura wy�wietlaj�ca tekst z zadanego pliku
 * Wy�wietla tekst z pliku o zaadnej nazwie
 * \param nazwa_pliku nazwa pliku, z kt�rego chcemy wy�wietli� tekst
 */
void wyswietlTekstZPliku(string nazwa_pliku);

//void wysweitlGreZPliku(string nazwa_pliku);
//void zapiszGreDoPliku(string nazwa_pliku, Tura *pierwsza_tura);

#endif // PLIKI_H
