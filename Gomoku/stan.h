/**
 * \file stan.h
 * \brief Plik nag³ówkowy modu³u stan
 *
 * Modu³ stan s³u¿y do sprawdzania stanu planszy, tzn. czy  zosta³y spe³nione warunki wygranej, oceny heurystycznej danej planszy
 */

#pragma once
#ifndef STAN_H
#define STAN_H

 /**
  * \brief Procedura u¿ywana do oceny planszy
  * U¿ywana do ocenienia, który gracz ma przewagê przy zadanej planszy
  * Wykorzystywana w funkcji int minimax(Pozycja*& aktualna_pozycja, int glebokosc, int& alfa, int& beta, bool gracz_tury, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int &ilosc, int &ilosc_finalnych);.
  * Podobna do int ocenaStanu(char** tab, int rozmiar, int pod_rzad, char gracz);, lecz ocenia wartoœæ tablicy pod k¹tem któregoœ z graczy.
  * Im wiêkzsa liczba co do wartoœci bezwzglêdnej tym wiêksza przewaga któregoœ z graczy. Zero oznacza
  * \param tab Plansza, na której toczy siê rozgrywka
  * \param rozmiar Rozmiar planszy
  * \param pod_rzad Liczba elementów z rzêdu wymagana do wygaranej
  * \param gracz Znacznik gracza
  * \return Wartoœæ danej planszy
  */
int ocenaStanu(char** tab, int rozmiar, int pod_rzad, char gracz);

/**
 * \brief Procedura u¿ywana do sprawdzenia stanu planszy
 * Pocz¹tkowo u¿ywana do sprawdzenia, czy któryœ gracz spe³ni³ warunek wygranej (zwracane 'W') lub czy jest remis ('R') b¹dŸ stan niekoñcowy ('N').
 * Nastêpnie do³¹czona funkcja oceny planszy pod k¹tem jej zape³nienia.
 * Wiêcej elementów któregoœ z graczy z rzêdu - wy¿sza wartoœæ liczbowa planszy. Nie rozró¿niamy ujemnych punktów, ka¿dy postawiony pionek podwy¿sza wartoœæ planszy, lecz w ró¿nym stopniu.
 * Z tej oceny korzysta void sredni(char**& tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, Ruch * &wykonywalne_ruchy).
 * \param tab Plansza poddawana sprawdzeniu
 * \param rozmiar Rozmiar planszy
 * \param pod_rzad Liczba elementów z rzêdu wymagana do wygaranej
 * \param suma Wartoœæ tablicy podawana przez referencjê, gdy¿ pocz¹tkowo funkcja ta mia³a zwracaæ jedynie znak rozró¿niaj¹cy ró¿ne stany planszy, a chcia³em unikn¹æ dublowania funkcji.
 * \return Identyfikator stanu
 */
char sprawdzStan(char **tab, int rozmiar, int pod_rzad, int &suma);

/**
 * \brief Procedura u¿ywana do sprawdzenia stanu pionów
 * SK³ada siê na funkcjê char sprawdzStan(char **tab, int rozmiar, int pod_rzad, int &suma);.
 * Przechodzi po wszystkich mo¿liwych pionach, sprawdzaj¹c, czy gracz spe³ni³ warunki koñcowe
 * \param tab Plansza poddawana sprawdzeniu
 * \param rozmiar Rozmiar planszy
 * \param pod_rzad Liczba elementów z rzêdu wymagana do wygaranej
 * \param suma Wartoœæ tablicy podawana przez referencjê, gdy¿ pocz¹tkowo funkcja ta mia³a zwracaæ jedynie znak rozró¿niaj¹cy ró¿ne stany planszy, a chcia³em unikn¹æ dublowania funkcji.
 * \return Identyfikator stanu
 */
char sprawdzPion(char **tab, int rozmiar, int pod_rzad, int &suma);

/**
 * \brief Procedura u¿ywana do sprawdzenia stanu poziomów
 * SK³ada siê na funkcjê char sprawdzStan(char **tab, int rozmiar, int pod_rzad, int &suma);.
 * Przechodzi po wszystkich mo¿liwych poziomach, sprawdzaj¹c, czy gracz spe³ni³ warunki koñcowe
 * \param tab Plansza poddawana sprawdzeniu
 * \param rozmiar Rozmiar planszy
 * \param pod_rzad Liczba elementów z rzêdu wymagana do wygaranej
 * \param suma Wartoœæ tablicy podawana przez referencjê, gdy¿ pocz¹tkowo funkcja ta mia³a zwracaæ jedynie znak rozró¿niaj¹cy ró¿ne stany planszy, a chcia³em unikn¹æ dublowania funkcji.
 * \return Identyfikator stanu
 */
char sprawdzPoziom(char **tab, int rozmiar, int pod_rzad, int &suma);

/**
 * \brief Procedura u¿ywana do sprawdzenia stanu ukosów
 * SK³ada siê na funkcjê char sprawdzStan(char **tab, int rozmiar, int pod_rzad, int &suma);.
 * Przechodzi po wszystkich mo¿liwych ukosach, sprawdzaj¹c, czy gracz spe³ni³ warunki koñcowe
 * \param tab Plansza poddawana sprawdzeniu
 * \param rozmiar Rozmiar planszy
 * \param pod_rzad Liczba elementów z rzêdu wymagana do wygaranej
 * \param suma Wartoœæ tablicy podawana przez referencjê, gdy¿ pocz¹tkowo funkcja ta mia³a zwracaæ jedynie znak rozró¿niaj¹cy ró¿ne stany planszy, a chcia³em unikn¹æ dublowania funkcji.
 * \return Identyfikator stanu
 */
char sprawdzUkosy(char **tab, int rozmiar, int pod_rzad, int &suma);

/**
 * \brief Procedura u¿ywana do sprawdzenia czy jest remis
 * Sprawdza, czy jest jeszcze jakieœ wolne miejsce na planszy. Je¿eli nie ma, to zwraca 'R'. 
 * Potem w funkcjach jest sprawdzana na koñcu, gdy ¿aden inny warunek nie zosta³ spe³niony
 * \param tab Plansza poddawana sprawdzeniu
 * \param rozmiar Rozmiar planszy
 * \return Identyfikator stanu
 */
char SprawdzRemis(char **tab, int rozmiar);
#endif // !STAN_H
