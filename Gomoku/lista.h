/**
 * \file lista.h
 * \brief Plik nag��wkowy modu�u lista
 *
 * Modu� lista zawiera definicje struktur u�ywanych jako elementy list oraz metod wykorzystywanych na listach
 */

#pragma once
#ifndef LISTA_H
#define LISTA_H

/* niewykorzystana funkcjonalno�� programu
struct Tura 
{
	char **plansza;
	Tura *next;
};*/
/**
 * \brief Element listy ruch�w na planszy
 * U�ywane do pobierania wykonowalnych ruch�w w funkcji 
 * void pobierzWykonywalneRuchy(Ruch *&wykonywalne_ruchy, char **tab, int rozmiar) 
 * lub listy tworzenia listy ruch�w o takiej samej warto�ci
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
 * \brief Element listy dzieci mo�liwych pozycji Pozycja
 * U�ywane w trudnym poziomie trudno�ci 
 * void trudny(char**& tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int glebokosc)
 */
struct Dzieci {
	/// Element typu Pozycja
	struct Pozycja* dziecko;
	/// Nast�pny element listy
	Dzieci* next;
};
/**
 * \brief W�ze� drzewa
 * U�ywane w trudnym poziomie trudno�ci
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
	/// Warto�� danej pozycji obliczan w int minimax(Pozycja * &aktualna_pozycja, int glebokosc, int& alfa, int& beta, bool gracz_tury, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int &ilosc, int &ilosc_finalnych)
	int wartosc;
	/// x-owy idneks
	int x;
	/// y-owy indeks
	int y;
};

/**
 * \brief Tworzy dziecko pozycji
 * Tworzy dziecko typu Pozycja Danej pozycji korzystaj�c z listy dost�pnych ruch�w Ruchy
 * \param ruchy mo�iwe ruchy
 * \param aktualna_pozycja pozycja wyj�ciowa
 * \param syn dziecko pozycji
 * \param rozmiar wielko�� planszy
 * \param gracz znak syna
 */
void utworzSyna(Ruch*& ruchy, Pozycja*& aktualna_pozycja, Pozycja*& syn, int rozmiar, char gracz);

//void usunDrzewo(Pozycja*& wezel) {};
//void dodajDoListy(Tura *&aktualna_tura, char **tab);
//void usunListe(Tura *&pierwsza_tura);

/**
 * \brief Kasuje list�
 * U�ywane przy usuwaniu list typu Ruch
 * \param wykonywalne_ruchy lista ruch�w do usuni�cia
 */
void usunListe(Ruch *&wykonywalne_ruchy);

/**
 * \brief Pobiera mo�liwe ruchy
 * Sprawdza, jakie ruchy mo�na wykona� na danej planszy
 * \param wykonywalne_ruchy lista ruch�w
 * \param tab plansza
 * \param rozmiar rozmiar planszy
 */
void pobierzWykonywalneRuchy(Ruch *&wykonywalne_ruchy, char **tab, int rozmiar);

/**
 * \brief wypisuje wykonwalne ruchy (debugging)
 * U�ywana procedura do debuggowania, gdzie dodawa�em metod� usuwania ruch�w i kasowania listy
 * \param wykonywalne_ruchy lista do wypisania
 */
void wypiszWykonywalneRuchy(Ruch * wykonywalne_ruchy);

/**
 * \brief Usuwa ruch z listy
 * Kasuje ruch o zadanych wsp�rz�dnych z listy
 * \param wykonywalne_ruchy lista, z kt�rej usuwamy
 * \param x x-owy indeks
 * \param y y-owy indeks
 */
void usunRuch(Ruch *& wykonywalne_ruchy, int x, int y);

/**
 * \brief Dodaje ruch do listy
 * Dodaje ruch o zadanych wsp�rz�dnych do listy
 * \param lista_ruchow lista, do kt�rej dodajemy
 * \param x x-owy indeks
 * \param y y-owy indeks
 */
void dodajRuch(Ruch*& lista_ruchow, int x, int y);

/**
 * \brief Losuje ruch z listy
 * Wybiera wsp�rz�dne pseudolosowego elementu listy ruch�w
 * \param lista_ruchow lista, z kt�rej losujemy
 * \param licznik ca�kowita ilo�� ruch�w
 * \param x x-owy indeks
 * \param y y-owy indeks
 */
void losoujRuch(Ruch* lista_ruchow, int licznik, int &x, int &y);

#endif // !LISTA_H
