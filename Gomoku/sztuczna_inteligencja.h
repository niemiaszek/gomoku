/**
 * \file sztuczna_inteligencja.h
 * \brief Plik nag��wkowy modu�u sztuczna_inteligencja
 *
 * Modu� sztuczna_inteligencja definiuje r�ne poziomy trudno�ci komputera
 */

#pragma once
#include "lista.h"

#ifndef SZTUCZNA_INTELIGENCJA_H
#define SZTUCZNA_INTELIGENCJA_H

 /**
   * \brief Procedura u�ywana do symulowania �atwego poziomu trudno�ci przeciwnika
   * �atwy poziom trudno�ci opiera si� jedynie na ocenianiu aktualnej sytuacji, tzn. blokowaniu ko�cz�cego ruchu przeciwnika lub stawianiu w�asnego ko�cz�cego ruchu
   * Je�eli nie ma takich ruch�w, to losowana jest pozycja do zaj�cia, st�d stopie� trudno�ci jest bardzo niski.
   * \param tab Plansza, na kt�rej toczy si� rozgrywka
   * \param rozmiar Rozmiar planszy
   * \param pod_rzad Liczba element�w z rz�du wymagana do wygaranej
   * \param gracz Znacznik gracza
   * \param przeciwnik Znacznik przeciwnika
   * \param wykonywalne_ruchy lista mo�liwych ruch�w komputera
   */
void latwy(char **&tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, Ruch *&wykonywalne_ruchy);

/**
  * \brief Procedura u�ywana do symulowania �redniego poziomu trudno�ci przeciwnika
  * �redni poziom trudno�ci jest naturalnie bardziej z�o�ony niz �atwy. Mo�na z nim prowadzi� ca�kiem naturaln� rozgrywk�. Umiarkowana z�o�ono�� obliczeniowa (szybko wybierane ruchy).
  * Nie jest mo�e bardzo wymagaj�cy, da si� go �atwo pokona�, kiedy zna si� jego algorytm dzia�ania.
  * Funkcja sprawdza r�nice pomi�dzy aktualnym stanem planszy a wszystkimi mo�liwymi przysz�ymi stanami, oceniaj�c przysz�y stan przez sum� warto�ci u�yteczno�ci tego stanu dla gracza i przeciwnika.
  * Stawiany jest ruch w to miejsce, kt�re posiada maksymaln� ocen� stanu. Wsp�czynnik u�yteczno�ci dla gracza jest r�wny dwa, �eby komputer preferowa� swoje dobre ruchy nad ruchami blokuj�cymi przeciwnika.
  * \param tab Plansza, na kt�rej toczy si� rozgrywka
  * \param rozmiar Rozmiar planszy
  * \param pod_rzad Liczba element�w z rz�du wymagana do wygaranej
  * \param gracz Znacznik gracza
  * \param przeciwnik Znacznik przeciwnika
  * \param wykonywalne_ruchy Lista mo�liwych ruch�w komputera
  */
void sredni(char **&tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, Ruch *&wykonywalne_ruchy);

/**
  * \brief Procedura u�ywana do symulowania trudnego poziomu trudno�ci przeciwnika
  * Trudny poziom komputera. W grze na planszy 3x3 jest niepokonany. Korzysta z funkcji minimax, �eby wybra� najlepszy ruch. Ewentualnie losuje z element�w o takiej samej u�yteczno�ci, aby urozmaici� rozgrywk�.
  * Niestey ograniczy�em si� z korzystania z niego tylko dla planszy 3x3, gdzie da si� ca�kowicie zbudowa� drzewo poszukiwa� (dla 3x3 jest to ponad milion rekurencyjnych wykona� minimax i oko�o 255tysi�cy mo�liwych rozegra�).
  * W dokumentacji funkcji minimax rozwini�ta jest ta kwestia. Z za��czon� dyrektyw� preprocesora _DEBUG wy�wietla warto�ci mo�liwych ruch�w w aktualnej turze.
  * \param tab Plansza, na kt�rej toczy si� rozgrywka
  * \param rozmiar Rozmiar planszy
  * \param pod_rzad Liczba element�w z rz�du wymagana do wygaranej
  * \param gracz Znacznik gracza
  * \param przeciwnik Znacznik przeciwnika
  * \param glebokosc Zak�adana na pocz�tku maksymalna g��boko�� poszukiwa�, z kt�rej musia�em zrezygnowa� przyjmuj�� j� na maksymaln� g��boko�� dla drzewa 3x3
  */
void trudny(char**& tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int glebokosc);

/**
  * \brief Procedura wykonywuj�ca algorytm minimax w celu znalezienia najlepszego ruchu.
  * Minimax to rekurencyjny algorytm minimalizowania maksymalnych mo�liwych strat wykorzystywany w grach. W grze k�ko i krzy�yk, gdzie gracze wykonuj� ruchy naprzemiennie, zak�adamy, �e: 
  * Gracz wykonywuj�cy w�a�nie ruch szuka maksimum wszystkich mo�liwych ruch�w, tzn. ruchu daj�cego mu najwi�ksz� przewag�.
  * Przeciwnik, wykonywuj�cy ruch po graczu, szuka ruchu, kt�ry daje graczowi minimaln� przewag�.
  * Oznacza to, zak�adaj�c, �e gracze b�d� grali jak najlepiej, to znajdziemy taki ruch, kt�ry b�dzie dla nas najlepszy z wszystkich mo�liwych, kt�re maj� szans� zaj�� (tzn. do kt�rych dopu�ci przeciwnik, np. nie blokuj�c go), gdy przeciwnik te� b�dzie gra� optymalnie dla siebie.
  * W ten spos�b. Sprawdzaj�c wszystkie mo�liwe pozycje, jeste�my w stanie wybra� najlepszy ruch.
  * Problem z wykonaniem minimaxu dzia�aj�cego dla wi�kszych planszy (np. 15x15 jak gomoku) to z�o�ono�� obliczeniowa. 
  * Ten algorytm ma z�o�ono�� czasow� O(b^m), pami�ciow� O(b*m), gdzie b to wsp�czynnik rozga��zienia (ilo�� ruch�w, na kt�re mo�na p�j�� w danej turze), a m to g��boko�� przeszukiwania.
  * �atwo zauwa�y�, �e przy wyk�adniczo rosn�cej z�o�ono�ci, przeszukiwanie 8 czy 16 ruch�w w g��b jest ju� niesamowicie wymagaj�ce dla komputera.
  * Dla gier typu k�ko i krzy�yk liczba wszystkich mo�liwych rozgrywek wynosi oko�o (a^2)!, gdzie a to liczba wierszy czy kolumn planszy. Dla k�ko i krzy�yk jest to 255168 (http://www.se16.info/hgb/tictactoe.htm) �r�d�o, czyli nieco mniej ni� 9!.
  * Dla Gomoku (15^2)! znalezienie najlepszego ruchu jest problemem zupe�nym przestrzeni P, ale niewykonalnym w sensownym czasie i przy sensownej pami�ci. St�d te� stosuje si� funkcje heurystyczne do oceny ruchu i ucina si� drzewo poszukiwa� na jakim� poziomie.
  * Poziom 8 odpowiada ju� ca�kiem dobremu graczowi dla szach�w, a poziom 16 pokonuje mistrza �wiata w szachach. Najwa�niejsza jest jednak funkcja heursystyczna.
  * Aby zrealizowa� dzia�aj�cy minimax bez budowania pe�nego drzewa, potrzebowa�bym dzia�aj�cej funkcji heurystycznej, kt�rej niestety w trakcie wykonywania tego projektu nie by�em w stanie stworzy�. Moja funkcja oceny stan�w dzia�a prawid�owo dla stan�w ko�cz�cych, ale niejednoznacznie przewiduje dla stan�w po�rednich.
  * Bez dobrej i szybkiej funkcji oceny (Moje funkcje sprawdzania stanu s� do�� z�o�one i czasoch�onne dla komputera), niemo�liwe jest przeprowadznaie poszukiwania dla wi�kszych planszy z powodzeniem.
  * Zastosowanie odci�� alfa-beta, z kt�rych w koniec ko�c�w zrezygnowa�em, poniewa� jedynie pozwala�aby mi skr�ci� wykonywanie funkcji dla 3x3, a nie przeszukiwa� g��biej, zmienjszsa z�o�ono�� do O(2*b^(m/2)), ale wci�� s� to zbyt wysokie wyniki dla moich funkcji oceny.
  * Musia�bym skorzysta� z funkcji oceny innych programist�w, co by znaczy�o, �e projekt nie do ko�ca by�by samodzielny, a ci�gn�oby sie za tym przerobienie ca�ego programu.
  * \param aktualna_pozycja Pozycja, dla kt�rej szukamy najlepszego ruchu.
  * \param alfa Kryterium alfa do odci�� drzewa poszukiwa�
  * \param beta Kryterium beta do odci�� drzewa poszukiwa�
  * \param gracz_tury Informacja, czy przeszukiwanie ma by� wykonywanego dla gracza maksymalizuj�cego czy minimalizuj�cego
  * \param rozmiar Rozmiar planszy
  * \param pod_rzad Liczba element�w z rz�du wymagana do wygaranej
  * \param gracz Znacznik gracza
  * \param przeciwnik Znacznik przeciwnika
  * \param glebokosc Zak�adana na pocz�tku maksymalna g��boko�� poszukiwa�, z kt�rej musia�em zrezygnowa� przyjmuj�� j� na maksymaln� g��boko�� dla drzewa 3x3
  * \param ilosc Informacja o liczbie wykona� funkcji
  * \param ilosc_finalnych Informacja o liczbie ocenianych ko�cowych stan�w (liczba wszystkich mo�liwych gier)
  */
int minimax(Pozycja*& aktualna_pozycja, int glebokosc, int& alfa, int& beta, bool gracz_tury, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int &ilosc, int &ilosc_finalnych);

#endif // SZTUCZNA_INTELIGENCJA_H
 