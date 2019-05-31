/**
 * \file stan.h
 * \brief Plik nag��wkowy modu�u stan
 *
 * Modu� stan s�u�y do sprawdzania stanu planszy, tzn. czy  zosta�y spe�nione warunki wygranej, oceny heurystycznej danej planszy
 */

#pragma once
#ifndef STAN_H
#define STAN_H

 /**
  * \brief Procedura u�ywana do oceny planszy
  * U�ywana do ocenienia, kt�ry gracz ma przewag� przy zadanej planszy
  * Wykorzystywana w funkcji int minimax(Pozycja*& aktualna_pozycja, int glebokosc, int& alfa, int& beta, bool gracz_tury, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int &ilosc, int &ilosc_finalnych);.
  * Podobna do int ocenaStanu(char** tab, int rozmiar, int pod_rzad, char gracz);, lecz ocenia warto�� tablicy pod k�tem kt�rego� z graczy.
  * Im wi�kzsa liczba co do warto�ci bezwzgl�dnej tym wi�ksza przewaga kt�rego� z graczy. Zero oznacza
  * \param tab Plansza, na kt�rej toczy si� rozgrywka
  * \param rozmiar Rozmiar planszy
  * \param pod_rzad Liczba element�w z rz�du wymagana do wygaranej
  * \param gracz Znacznik gracza
  * \return Warto�� danej planszy
  */
int ocenaStanu(char** tab, int rozmiar, int pod_rzad, char gracz);

/**
 * \brief Procedura u�ywana do sprawdzenia stanu planszy
 * Pocz�tkowo u�ywana do sprawdzenia, czy kt�ry� gracz spe�ni� warunek wygranej (zwracane 'W') lub czy jest remis ('R') b�d� stan nieko�cowy ('N').
 * Nast�pnie do��czona funkcja oceny planszy pod k�tem jej zape�nienia.
 * Wi�cej element�w kt�rego� z graczy z rz�du - wy�sza warto�� liczbowa planszy. Nie rozr�niamy ujemnych punkt�w, ka�dy postawiony pionek podwy�sza warto�� planszy, lecz w r�nym stopniu.
 * Z tej oceny korzysta void sredni(char**& tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, Ruch * &wykonywalne_ruchy).
 * \param tab Plansza poddawana sprawdzeniu
 * \param rozmiar Rozmiar planszy
 * \param pod_rzad Liczba element�w z rz�du wymagana do wygaranej
 * \param suma Warto�� tablicy podawana przez referencj�, gdy� pocz�tkowo funkcja ta mia�a zwraca� jedynie znak rozr�niaj�cy r�ne stany planszy, a chcia�em unikn�� dublowania funkcji.
 * \return Identyfikator stanu
 */
char sprawdzStan(char **tab, int rozmiar, int pod_rzad, int &suma);

/**
 * \brief Procedura u�ywana do sprawdzenia stanu pion�w
 * SK�ada si� na funkcj� char sprawdzStan(char **tab, int rozmiar, int pod_rzad, int &suma);.
 * Przechodzi po wszystkich mo�liwych pionach, sprawdzaj�c, czy gracz spe�ni� warunki ko�cowe
 * \param tab Plansza poddawana sprawdzeniu
 * \param rozmiar Rozmiar planszy
 * \param pod_rzad Liczba element�w z rz�du wymagana do wygaranej
 * \param suma Warto�� tablicy podawana przez referencj�, gdy� pocz�tkowo funkcja ta mia�a zwraca� jedynie znak rozr�niaj�cy r�ne stany planszy, a chcia�em unikn�� dublowania funkcji.
 * \return Identyfikator stanu
 */
char sprawdzPion(char **tab, int rozmiar, int pod_rzad, int &suma);

/**
 * \brief Procedura u�ywana do sprawdzenia stanu poziom�w
 * SK�ada si� na funkcj� char sprawdzStan(char **tab, int rozmiar, int pod_rzad, int &suma);.
 * Przechodzi po wszystkich mo�liwych poziomach, sprawdzaj�c, czy gracz spe�ni� warunki ko�cowe
 * \param tab Plansza poddawana sprawdzeniu
 * \param rozmiar Rozmiar planszy
 * \param pod_rzad Liczba element�w z rz�du wymagana do wygaranej
 * \param suma Warto�� tablicy podawana przez referencj�, gdy� pocz�tkowo funkcja ta mia�a zwraca� jedynie znak rozr�niaj�cy r�ne stany planszy, a chcia�em unikn�� dublowania funkcji.
 * \return Identyfikator stanu
 */
char sprawdzPoziom(char **tab, int rozmiar, int pod_rzad, int &suma);

/**
 * \brief Procedura u�ywana do sprawdzenia stanu ukos�w
 * SK�ada si� na funkcj� char sprawdzStan(char **tab, int rozmiar, int pod_rzad, int &suma);.
 * Przechodzi po wszystkich mo�liwych ukosach, sprawdzaj�c, czy gracz spe�ni� warunki ko�cowe
 * \param tab Plansza poddawana sprawdzeniu
 * \param rozmiar Rozmiar planszy
 * \param pod_rzad Liczba element�w z rz�du wymagana do wygaranej
 * \param suma Warto�� tablicy podawana przez referencj�, gdy� pocz�tkowo funkcja ta mia�a zwraca� jedynie znak rozr�niaj�cy r�ne stany planszy, a chcia�em unikn�� dublowania funkcji.
 * \return Identyfikator stanu
 */
char sprawdzUkosy(char **tab, int rozmiar, int pod_rzad, int &suma);

/**
 * \brief Procedura u�ywana do sprawdzenia czy jest remis
 * Sprawdza, czy jest jeszcze jakie� wolne miejsce na planszy. Je�eli nie ma, to zwraca 'R'. 
 * Potem w funkcjach jest sprawdzana na ko�cu, gdy �aden inny warunek nie zosta� spe�niony
 * \param tab Plansza poddawana sprawdzeniu
 * \param rozmiar Rozmiar planszy
 * \return Identyfikator stanu
 */
char SprawdzRemis(char **tab, int rozmiar);
#endif // !STAN_H
