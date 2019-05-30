/**
 * \file lista.h
 * \brief Plik nag³ówkowy modu³u lista
 *
 * Modu³ lista zawiera definicje struktur u¿ywanych jako elementy list oraz metod wykorzystywanych na listach
 */

#pragma once
#ifndef LISTA_H
#define LISTA_H

/* niewykorzystana funkcjonalnoœæ programu
struct Tura 
{
	char **plansza;
	Tura *next;
};*/
/**
 * \brief Element listy ruchów na planszy
 * U¿ywane do pobierania wykonowalnych ruchów w funkcji 
 * void pobierzWykonywalneRuchy(Ruch *&wykonywalne_ruchy, char **tab, int rozmiar) 
 * lub listy tworzenia listy ruchów o takiej samej wartoœci
 */
struct Ruch 
{
	/// x-owy indeks
	int x;
	/// y-owy indeks
	int y;
	/// kolejny element listy
	Ruch *next;
};
/**
 * \brief Element listy dzieci mo¿liwych pozycji Pozycja
 * U¿ywane w trudnym poziomie trudnoœci 
 * void trudny(char**& tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int glebokosc)
 */
struct Dzieci {
	/// Element typu Pozycja
	struct Pozycja* dziecko;
	/// Nastêpny element listy
	Dzieci* next;
};
/**
 * \brief Wêze³ drzewa
 * U¿ywane w trudnym poziomie trudnoœci
 * void trudny(char**& tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int glebokosc)
 */
struct Pozycja
{
	/// Lista dzieci tej pozycji
	struct Dzieci* dzieci;
	/// Ojciec pozycji
	Pozycja* ojciec;
	/// Plansza dla danej pozycji
	char** plansza;
	/// Wartoœæ danej pozycji obliczan w int minimax(Pozycja * &aktualna_pozycja, int glebokosc, int& alfa, int& beta, bool gracz_tury, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int &ilosc, int &ilosc_finalnych)
	int wartosc;
	/// x-owy idneks
	int x;
	/// y-owy indeks
	int y;
};

/**
 * \brief Tworzy dziecko pozycji
 * Tworzy dziecko typu Pozycja Danej pozycji korzystaj¹c z listy dostêpnych ruchów Ruchy
 * \param ruchy mo¿iwe ruchy
 * \param aktualna_pozycja pozycja wyjœciowa
 * \param syn dziecko pozycji
 * \param rozmiar wielkoœæ planszy
 * \param gracz znak syna
 */
void utworzSyna(Ruch*& ruchy, Pozycja*& aktualna_pozycja, Pozycja*& syn, int rozmiar, char gracz);

//void usunDrzewo(Pozycja*& wezel) {};
//void dodajDoListy(Tura *&aktualna_tura, char **tab);
//void usunListe(Tura *&pierwsza_tura);

/**
 * \brief Kasuje listê
 * U¿ywane przy usuwaniu list typu Ruch
 * \param wykonywalne_ruchy lista ruchów do usuniêcia
 */
void usunListe(Ruch *&wykonywalne_ruchy);

/**
 * \brief Pobiera mo¿liwe ruchy
 * Sprawdza, jakie ruchy mo¿na wykonaæ na danej planszy
 * \param wykonywalne_ruchy lista ruchów
 * \param tab plansza
 * \param rozmiar rozmiar planszy
 */
void pobierzWykonywalneRuchy(Ruch *&wykonywalne_ruchy, char **tab, int rozmiar);

/**
 * \brief wypisuje wykonwalne ruchy (debugging)
 * U¿ywana procedura do debuggowania, gdzie dodawa³em metodê usuwania ruchów i kasowania listy
 * \param wykonywalne_ruchy lista do wypisania
 */
void wypiszWykonywalneRuchy(Ruch * wykonywalne_ruchy);

/**
 * \brief Usuwa ruch z listy
 * Kasuje ruch o zadanych wspó³rzêdnych z listy
 * \param wykonywalne_ruchy lista, z której usuwamy
 * \param x x-owy indeks
 * \param y y-owy indeks
 */
void usunRuch(Ruch *& wykonywalne_ruchy, int x, int y);

/**
 * \brief Dodaje ruch do listy
 * Dodaje ruch o zadanych wspó³rzêdnych do listy
 * \param lista_ruchow lista, do której dodajemy
 * \param x x-owy indeks
 * \param y y-owy indeks
 */
void dodajRuch(Ruch*& lista_ruchow, int x, int y);

/**
 * \brief Losuje ruch z listy
 * Wybiera wspó³rzêdne pseudolosowego elementu listy ruchów
 * \param lista_ruchow lista, z której losujemy
 * \param licznik ca³kowita iloœæ ruchów
 * \param x x-owy indeks
 * \param y y-owy indeks
 */
void losoujRuch(Ruch* lista_ruchow, int licznik, int &x, int &y);

#endif // !LISTA_H
