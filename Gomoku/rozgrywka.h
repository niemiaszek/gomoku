/**
 * \file rozgrywka.h
 * \brief Plik nag³ówkowy modu³u rozgrywka
 *
 * Modu³ rozgrywka s³u¿y do symulacji partii w kó³ko i krzy¿yk i definiuje dzia³anie trybów gry
 */

#pragma once
#include "lista.h"
#ifndef ROZGRYWKA_H
#define ROZGRYWKA_H

 /**
  * \brief Procedura rozpoczynaj¹ca grê pomiêdzy dwoma graczami
  * Umo¿liwia naprzemienne wykonywanie ruchów, dopóki trwa rozgrywka
  * \param pod_rzad liczba elementów z rzêdu, która jest wymagana do wygranej
  * \param rozmiar Rozmiar planszy
  */
void graczvsgracz(int rozmiar, int pod_rzad);

/**
 * \brief Procedura rozpoczynaj¹ca grê pomiêdzy graczem i komputerem
 * Umo¿liwia graczowi sterowanie, wykonuje ruchy komputera
 * \param pod_rzad liczba elementów z rzêdu, która jest wymagana do wygranej
 * \param rozmiar Rozmiar planszy
 * \param trudnosc Stopieñ trudnoœci komputera
 */
void graczvskomputer(int rozmiar, int pod_rzad, int trudnosc);

/**
 * \brief Procedura rozpoczynaj¹ca symulacjê pomiêdzy komputerem
 * Wykonuje ruchy komputera od pocz¹tku rozgrywki a¿ do koñca
 * \param pod_rzad liczba elementów z rzêdu, która jest wymagana do wygranej
 * \param rozmiar Rozmiar planszy
 * \param trudnosc Stopieñ trudnoœci komputera
 */
void komputervskomputer(int rozmiar, int pod_rzad, int trudnosc);

/**
 * \brief Procedura koñcz¹ca rozgrywkê pomiêdzy graczami
 * Usuwa planszê i prowadzi do menu koñcowego
 * \param tab Plansza, na której toczy siê rozgrywka
 * \param rozmiar Rozmiar planszy
 */
void zakonczRozgrywke(char **tab, int rozmiar);

/**
 * \brief Procedura koñcz¹ca rozgrywkê w rozgrywkach z komputerem
 * Usuwa planszê i prowadzi do menu koñcowego, dodatkowo czyszcz¹æ ewentualn¹ listê ruchów do wykonania komputera
 * \param tab Plansza, na której toczy³a siê rozgrywka
 * \param rozmiar Rozmiar planszy
 * \param Ruchy Lista ruchów do wykonania komputera
 */
void zakonczRozgrywke(char **tab, int rozmiar, Ruch *&Ruchy);

/**
 * \brief Procedura sterowania dla gracza
 * S³u¿y do zatwierdzania ruchu, poruszania siê do planszy, zakoñczania rozgrywki przez gracza
 * \param tab Plansza, na której toczy
 * \param rozmiar Rozmiar planszy
 * \param gracz Znacznik gracza
 * \param aktx Aktualna wspó³rzêdna x-owa kursora
 * \param akty Aktualna wspó³rzêdna y-owa kursora
 * \return Polecenie u¿ytkowniak
 */
char ruchGracza(char **&tab, int rozmiar, char gracz, int &aktx, int &akty);
#endif // !ROZGRYWKA_H
