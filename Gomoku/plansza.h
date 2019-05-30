/**
 * \file plansza.h
 * \brief Plik nag��wkowy modu�u plansza
 *
 * Modu� plansza zawiera metody wykorzystywane do operowania plansz� (tablic� dwuwymiarow� typu char **)
 */

#pragma once
#ifndef PLANSZA_H
#define PLANSZA_H

 /**
  * \brief Procedura tworz�ca plansz�
  * Tworzy tablic� dwuwymiarow� dynamiczn� o zadanym rozmiarze
  * \param tab Tworzona plansza
  * \param rozmiar Rozmiar planszy
  */
void utworzPlansze(char **&tab, int rozmiar);

/**
  * \brief Procedura kasuj�ca plansz�
  * Zwalnia pami�� zarezerwowan� wcze�niej pod plansz�
  * \param tab Tworzona plansza
  * \param rozmiar Rozmiar planszy
  */
void kasujPlansze(char **tab, int rozmiar);

/**
  * \brief Procedura tworz�ca plansz� pomcocnicz�
  * Tworzy kopi� zadanej tablicy dwuwymiarowej dynamicznej o zadanym rozmiarze
  * \param tab Plansza, kt�r� kopiujemy
  * \param pomocnicza plansza, kt�r� tworzymy
  * \param rozmiar Rozmiar planszy
  */
void utworzPomocznicza(char **tab, char **&pomocnicza, int rozmiar);

#endif // PLANSZA_H
