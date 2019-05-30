/**
 * \file interfejs.h
 * \brief Plik nag��wkowy modu�u interfejs
 *
 * Modu� interfejs zawiera metody s�u��ce do komunikacji programu z u�ytkownikiem i na odwr�t
 */

#pragma once
#ifndef INTERFEJS_H
#define INTERFEJS_H

 /**
  * \brief Procedura uruchamiaj�ca menu startowe.
  * Wita u�ytkownika, a nast�pnie prowadzi do funkcji void menuGlowne();
  */
void menuStart();

/**
 * \brief Procedura uruchamiaj�ca menu glowne.
 * Umo�liwia wybranie, z jakiej g��wnej funkcjonalno�ci programu chcemy skorzysta�
 */
void menuGlowne();

/**
 * \brief Procedura uruchamiaj�ca menu przed gr�.
 * Pobiera od u�ytkownika kilka parametr�w potrzebnych do zdefiniowania przed rozpocz�ciem rozgrywki, a nast�pne uruchamia jeden z tryb�w rozgrywki
 * \see rozgrywka.h
 */
void menuPrzedGra();

/**
 * \brief Procedura pobieraj�ca znak typu int od u�ytkownika.
 * S�u�y do sprawdzania czy u�ytkownik poda� prawid�ow� liczb�
 * \param zakres_dolny Minimalny mo�liwy int, kt�ry mo�e poda� u�ytkownik
 * \param zakres_gorny Maksymalny mo�liwy int do podania
 * \return Liczba pobrana od u�ytkownika
 */
int pobierzZnak(int zakres_dolny, int zakres_gorny);

/**
 * \brief Procedura czyszcz�ca konsol�
 * Czy�ci konsol� korzystaj�c z biblioteki Windows.h
 */
void czyscEkran();

/**
 * \brief Procedura s�u�aca do zatrzymania si� a� do pobrania znaku z klawiatury.
 * Wy�wietla instrukcj�, �e potrzebne jest naci�ni�cie klawisza, aby program przeszed� do nast�pnej operacji
 */
void kliknijAbyPrzejscDalej();

/**
 * \brief Procedura ko�cz�ca program
 * Ko�czy dzia�anie programu, umo�liwiaj�c ponowne uruchumienie void menuGlowne();
 */
void zakonczProgram();

/**
 * \brief Procedura s�u��ca do przemieszczania znacznika gracza po tablicy.
 * Umo�liwia graczowi zobaczenie, gdzie aktualnie znajduje si� jego kursor na planszy i sygnalizuje, czy mo�e wykona� ruch. Daje mo�liwo�� sterowania programem. 
 * \param tab Plansza, po kt�rej gracz ma si� porusza�
 * \param rozmiar Wielko�� planszy
 * \param aktx aktualna pozycja kursora w x-indeksie
 * \param akty aktualna pozycja kursora w y-indeksie
 * \param gracz znak, jakim oznacza si� pionek gracza
 * \return Polecenie do sterowania programem
 */
char poruszaniePoPlanszy(char **&tab, int rozmiar, int &aktx, int &akty, char gracz);

/**
 * \brief Procedura s�u��ca do wy�wietlenia planszy.
 * Umo�liwia graczowi zobaczenie planszy, na kt�rej toczy si� rozgrywka
 * \param tab Plansza, po kt�rej gracz ma si� porusza�
 * \param rozmiar Wielko�� planszy
 */
void wyswietlPlansze(char **tab, int rozmiar);

/**
 * \brief Procedura wy�wietla u�ytkownikowi b��d otarcia pliku
 * U�wiadamia u�ytkownika, �e plik zosta� b��dnie otwarty
 */
void komunikatBladOtwarciaPliku();

/**
 * \brief Procedura s�u��ca do powiadomienia gracza o rezultacie rozgrywki
 * Wy�wietla informacj�, czy kt�ry� z graczy wygra� i czeka, a� gracz przejdzie dalej
 */
void komunikatRezultat(char rezultat);

/**
 * \brief Procedura s�u��ca do powiadomienia gracza o liczbie wywo�a� funkcji 
 * Wy�wietla informacj�, ile razy wykonano funkcj�
 * \see int minimax(Pozycja*& aktualna_pozycja, int glebokosc, int& alfa, int& beta, bool gracz_tury, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int &ilosc, int &ilosc_finalnych);
 * \param ilosc Informacja o liczbie wykona� funkcji
 * \param ilosc_finalnych Informacja o liczbie ocenianych ko�cowych stan�w (liczba wszystkich mo�liwych gier)
 */
void wyswietlIlosciWywolan(int ilosc, int ilosc_finalnych);

#endif // INTERFEJS_H
