/**
 * \file rozgrywka.h
 * \brief Plik nag��wkowy modu�u rozgrywka
 *
 * Modu� rozgrywka s�u�y do symulacji partii w k�ko i krzy�yk i definiuje dzia�anie tryb�w gry
 */

#pragma once
#include "lista.h"
#ifndef ROZGRYWKA_H
#define ROZGRYWKA_H

 /**
  * \brief Procedura rozpoczynaj�ca gr� pomi�dzy dwoma graczami
  * Umo�liwia naprzemienne wykonywanie ruch�w, dop�ki trwa rozgrywka
  * \param pod_rzad liczba element�w z rz�du, kt�ra jest wymagana do wygranej
  * \param rozmiar Rozmiar planszy
  */
void graczvsgracz(int rozmiar, int pod_rzad);

/**
 * \brief Procedura rozpoczynaj�ca gr� pomi�dzy graczem i komputerem
 * Umo�liwia graczowi sterowanie, wykonuje ruchy komputera
 * \param pod_rzad liczba element�w z rz�du, kt�ra jest wymagana do wygranej
 * \param rozmiar Rozmiar planszy
 * \param trudnosc Stopie� trudno�ci komputera
 */
void graczvskomputer(int rozmiar, int pod_rzad, int trudnosc);

/**
 * \brief Procedura rozpoczynaj�ca symulacj� pomi�dzy komputerem
 * Wykonuje ruchy komputera od pocz�tku rozgrywki a� do ko�ca
 * \param pod_rzad liczba element�w z rz�du, kt�ra jest wymagana do wygranej
 * \param rozmiar Rozmiar planszy
 * \param trudnosc Stopie� trudno�ci komputera
 */
void komputervskomputer(int rozmiar, int pod_rzad, int trudnosc);

/**
 * \brief Procedura ko�cz�ca rozgrywk� pomi�dzy graczami
 * Usuwa plansz� i prowadzi do menu ko�cowego
 * \param tab Plansza, na kt�rej toczy si� rozgrywka
 * \param rozmiar Rozmiar planszy
 */
void zakonczRozgrywke(char **tab, int rozmiar);

/**
 * \brief Procedura ko�cz�ca rozgrywk� w rozgrywkach z komputerem
 * Usuwa plansz� i prowadzi do menu ko�cowego, dodatkowo czyszcz�� ewentualn� list� ruch�w do wykonania komputera
 * \param tab Plansza, na kt�rej toczy�a si� rozgrywka
 * \param rozmiar Rozmiar planszy
 * \param Ruchy Lista ruch�w do wykonania komputera
 */
void zakonczRozgrywke(char **tab, int rozmiar, Ruch *&Ruchy);

/**
 * \brief Procedura sterowania dla gracza
 * S�u�y do zatwierdzania ruchu, poruszania si� do planszy, zako�czania rozgrywki przez gracza
 * \param tab Plansza, na kt�rej toczy
 * \param rozmiar Rozmiar planszy
 * \param gracz Znacznik gracza
 * \param aktx Aktualna wsp�rz�dna x-owa kursora
 * \param akty Aktualna wsp�rz�dna y-owa kursora
 * \return Polecenie u�ytkowniak
 */
char ruchGracza(char **&tab, int rozmiar, char gracz, int &aktx, int &akty);
#endif // !ROZGRYWKA_H
