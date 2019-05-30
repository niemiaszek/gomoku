/**
 * \file interfejs.h
 * \brief Plik nag³ówkowy modu³u interfejs
 *
 * Modu³ interfejs zawiera metody s³u¿¹ce do komunikacji programu z u¿ytkownikiem i na odwrót
 */

#pragma once
#ifndef INTERFEJS_H
#define INTERFEJS_H

 /**
  * \brief Procedura uruchamiaj¹ca menu startowe.
  * Wita u¿ytkownika, a nastêpnie prowadzi do funkcji void menuGlowne();
  */
void menuStart();

/**
 * \brief Procedura uruchamiaj¹ca menu glowne.
 * Umo¿liwia wybranie, z jakiej g³ównej funkcjonalnoœci programu chcemy skorzystaæ
 */
void menuGlowne();

/**
 * \brief Procedura uruchamiaj¹ca menu przed gr¹.
 * Pobiera od u¿ytkownika kilka parametrów potrzebnych do zdefiniowania przed rozpoczêciem rozgrywki, a nastêpne uruchamia jeden z trybów rozgrywki
 * \see rozgrywka.h
 */
void menuPrzedGra();

/**
 * \brief Procedura pobieraj¹ca znak typu int od u¿ytkownika.
 * S³u¿y do sprawdzania czy u¿ytkownik poda³ prawid³ow¹ liczbê
 * \param zakres_dolny Minimalny mo¿liwy int, który mo¿e podaæ u¿ytkownik
 * \param zakres_gorny Maksymalny mo¿liwy int do podania
 * \return Liczba pobrana od u¿ytkownika
 */
int pobierzZnak(int zakres_dolny, int zakres_gorny);

/**
 * \brief Procedura czyszcz¹ca konsolê
 * Czyœci konsolê korzystaj¹c z biblioteki Windows.h
 */
void czyscEkran();

/**
 * \brief Procedura s³u¿aca do zatrzymania siê a¿ do pobrania znaku z klawiatury.
 * Wyœwietla instrukcjê, ¿e potrzebne jest naciœniêcie klawisza, aby program przeszed³ do nastêpnej operacji
 */
void kliknijAbyPrzejscDalej();

/**
 * \brief Procedura koñcz¹ca program
 * Koñczy dzia³anie programu, umo¿liwiaj¹c ponowne uruchumienie void menuGlowne();
 */
void zakonczProgram();

/**
 * \brief Procedura s³u¿¹ca do przemieszczania znacznika gracza po tablicy.
 * Umo¿liwia graczowi zobaczenie, gdzie aktualnie znajduje siê jego kursor na planszy i sygnalizuje, czy mo¿e wykonaæ ruch. Daje mo¿liwoœæ sterowania programem. 
 * \param tab Plansza, po której gracz ma siê poruszaæ
 * \param rozmiar Wielkoœæ planszy
 * \param aktx aktualna pozycja kursora w x-indeksie
 * \param akty aktualna pozycja kursora w y-indeksie
 * \param gracz znak, jakim oznacza siê pionek gracza
 * \return Polecenie do sterowania programem
 */
char poruszaniePoPlanszy(char **&tab, int rozmiar, int &aktx, int &akty, char gracz);

/**
 * \brief Procedura s³u¿¹ca do wyœwietlenia planszy.
 * Umo¿liwia graczowi zobaczenie planszy, na której toczy siê rozgrywka
 * \param tab Plansza, po której gracz ma siê poruszaæ
 * \param rozmiar Wielkoœæ planszy
 */
void wyswietlPlansze(char **tab, int rozmiar);

/**
 * \brief Procedura wyœwietla u¿ytkownikowi b³¹d otarcia pliku
 * Uœwiadamia u¿ytkownika, ¿e plik zosta³ b³êdnie otwarty
 */
void komunikatBladOtwarciaPliku();

/**
 * \brief Procedura s³u¿¹ca do powiadomienia gracza o rezultacie rozgrywki
 * Wyœwietla informacjê, czy któryœ z graczy wygra³ i czeka, a¿ gracz przejdzie dalej
 */
void komunikatRezultat(char rezultat);

/**
 * \brief Procedura s³u¿¹ca do powiadomienia gracza o liczbie wywo³añ funkcji 
 * Wyœwietla informacjê, ile razy wykonano funkcjê
 * \see int minimax(Pozycja*& aktualna_pozycja, int glebokosc, int& alfa, int& beta, bool gracz_tury, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int &ilosc, int &ilosc_finalnych);
 * \param ilosc Informacja o liczbie wykonañ funkcji
 * \param ilosc_finalnych Informacja o liczbie ocenianych koñcowych stanów (liczba wszystkich mo¿liwych gier)
 */
void wyswietlIlosciWywolan(int ilosc, int ilosc_finalnych);

#endif // INTERFEJS_H
