/**
 * \file plansza.h
 * \brief Plik nag³ówkowy modu³u plansza
 *
 * Modu³ plansza zawiera metody wykorzystywane do operowania plansz¹ (tablic¹ dwuwymiarow¹ typu char **)
 */

#pragma once
#ifndef PLANSZA_H
#define PLANSZA_H

 /**
  * \brief Procedura tworz¹ca planszê
  * Tworzy tablicê dwuwymiarow¹ dynamiczn¹ o zadanym rozmiarze
  * \param tab Tworzona plansza
  * \param rozmiar Rozmiar planszy
  */
void utworzPlansze(char **&tab, int rozmiar);

/**
  * \brief Procedura kasuj¹ca planszê
  * Zwalnia pamiêæ zarezerwowan¹ wczeœniej pod planszê
  * \param tab Tworzona plansza
  * \param rozmiar Rozmiar planszy
  */
void kasujPlansze(char **tab, int rozmiar);

/**
  * \brief Procedura tworz¹ca planszê pomcocnicz¹
  * Tworzy kopiê zadanej tablicy dwuwymiarowej dynamicznej o zadanym rozmiarze
  * \param tab Plansza, któr¹ kopiujemy
  * \param pomocnicza plansza, któr¹ tworzymy
  * \param rozmiar Rozmiar planszy
  */
void utworzPomocznicza(char **tab, char **&pomocnicza, int rozmiar);

#endif // PLANSZA_H
