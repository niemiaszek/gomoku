/**
 * \file sztuczna_inteligencja.h
 * \brief Plik nag³ówkowy modu³u sztuczna_inteligencja
 *
 * Modu³ sztuczna_inteligencja definiuje ró¿ne poziomy trudnoœci komputera
 */

#pragma once
#include "lista.h"

#ifndef SZTUCZNA_INTELIGENCJA_H
#define SZTUCZNA_INTELIGENCJA_H

 /**
   * \brief Procedura u¿ywana do symulowania ³atwego poziomu trudnoœci przeciwnika
   * £atwy poziom trudnoœci opiera siê jedynie na ocenianiu aktualnej sytuacji, tzn. blokowaniu koñcz¹cego ruchu przeciwnika lub stawianiu w³asnego koñcz¹cego ruchu
   * Je¿eli nie ma takich ruchów, to losowana jest pozycja do zajêcia, st¹d stopieñ trudnoœci jest bardzo niski.
   * \param tab Plansza, na której toczy siê rozgrywka
   * \param rozmiar Rozmiar planszy
   * \param pod_rzad Liczba elementów z rzêdu wymagana do wygaranej
   * \param gracz Znacznik gracza
   * \param przeciwnik Znacznik przeciwnika
   * \param wykonywalne_ruchy lista mo¿liwych ruchów komputera
   */
void latwy(char **&tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, Ruch *&wykonywalne_ruchy);

/**
  * \brief Procedura u¿ywana do symulowania œredniego poziomu trudnoœci przeciwnika
  * Œredni poziom trudnoœci jest naturalnie bardziej z³o¿ony niz ³atwy. Mo¿na z nim prowadziæ ca³kiem naturaln¹ rozgrywkê. Umiarkowana z³o¿onoœæ obliczeniowa (szybko wybierane ruchy).
  * Nie jest mo¿e bardzo wymagaj¹cy, da siê go ³atwo pokonaæ, kiedy zna siê jego algorytm dzia³ania.
  * Funkcja sprawdza ró¿nice pomiêdzy aktualnym stanem planszy a wszystkimi mo¿liwymi przysz³ymi stanami, oceniaj¹c przysz³y stan przez sumê wartoœci u¿ytecznoœci tego stanu dla gracza i przeciwnika.
  * Stawiany jest ruch w to miejsce, które posiada maksymaln¹ ocenê stanu. Wspó³czynnik u¿ytecznoœci dla gracza jest równy dwa, ¿eby komputer preferowa³ swoje dobre ruchy nad ruchami blokuj¹cymi przeciwnika.
  * \param tab Plansza, na której toczy siê rozgrywka
  * \param rozmiar Rozmiar planszy
  * \param pod_rzad Liczba elementów z rzêdu wymagana do wygaranej
  * \param gracz Znacznik gracza
  * \param przeciwnik Znacznik przeciwnika
  * \param wykonywalne_ruchy Lista mo¿liwych ruchów komputera
  */
void sredni(char **&tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, Ruch *&wykonywalne_ruchy);

/**
  * \brief Procedura u¿ywana do symulowania trudnego poziomu trudnoœci przeciwnika
  * Trudny poziom komputera. W grze na planszy 3x3 jest niepokonany. Korzysta z funkcji minimax, ¿eby wybraæ najlepszy ruch. Ewentualnie losuje z elementów o takiej samej u¿ytecznoœci, aby urozmaiciæ rozgrywkê.
  * Niestey ograniczy³em siê z korzystania z niego tylko dla planszy 3x3, gdzie da siê ca³kowicie zbudowaæ drzewo poszukiwañ (dla 3x3 jest to ponad milion rekurencyjnych wykonañ minimax i oko³o 255tysiêcy mo¿liwych rozegrañ).
  * W dokumentacji funkcji minimax rozwiniêta jest ta kwestia. Z za³¹czon¹ dyrektyw¹ preprocesora _DEBUG wyœwietla wartoœci mo¿liwych ruchów w aktualnej turze.
  * \param tab Plansza, na której toczy siê rozgrywka
  * \param rozmiar Rozmiar planszy
  * \param pod_rzad Liczba elementów z rzêdu wymagana do wygaranej
  * \param gracz Znacznik gracza
  * \param przeciwnik Znacznik przeciwnika
  * \param glebokosc Zak³adana na pocz¹tku maksymalna g³êbokoœæ poszukiwañ, z której musia³em zrezygnowaæ przyjmuj¹æ j¹ na maksymaln¹ g³êbokoœæ dla drzewa 3x3
  */
void trudny(char**& tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int glebokosc);

/**
  * \brief Procedura wykonywuj¹ca algorytm minimax w celu znalezienia najlepszego ruchu.
  * Minimax to rekurencyjny algorytm minimalizowania maksymalnych mo¿liwych strat wykorzystywany w grach. W grze kó³ko i krzy¿yk, gdzie gracze wykonuj¹ ruchy naprzemiennie, zak³adamy, ¿e: 
  * Gracz wykonywuj¹cy w³aœnie ruch szuka maksimum wszystkich mo¿liwych ruchów, tzn. ruchu daj¹cego mu najwiêksz¹ przewagê.
  * Przeciwnik, wykonywuj¹cy ruch po graczu, szuka ruchu, który daje graczowi minimaln¹ przewagê.
  * Oznacza to, zak³adaj¹c, ¿e gracze bêd¹ grali jak najlepiej, to znajdziemy taki ruch, który bêdzie dla nas najlepszy z wszystkich mo¿liwych, które maj¹ szansê zajœæ (tzn. do których dopuœci przeciwnik, np. nie blokuj¹c go), gdy przeciwnik te¿ bêdzie gra³ optymalnie dla siebie.
  * W ten sposób. Sprawdzaj¹c wszystkie mo¿liwe pozycje, jesteœmy w stanie wybraæ najlepszy ruch.
  * Problem z wykonaniem minimaxu dzia³aj¹cego dla wiêkszych planszy (np. 15x15 jak gomoku) to z³o¿onoœæ obliczeniowa. 
  * Ten algorytm ma z³o¿onoœæ czasow¹ O(b^m), pamiêciow¹ O(b*m), gdzie b to wspó³czynnik rozga³êzienia (iloœæ ruchów, na które mo¿na pójœæ w danej turze), a m to g³êbokoœæ przeszukiwania.
  * £atwo zauwa¿yæ, ¿e przy wyk³adniczo rosn¹cej z³o¿onoœci, przeszukiwanie 8 czy 16 ruchów w g³¹b jest ju¿ niesamowicie wymagaj¹ce dla komputera.
  * Dla gier typu kó³ko i krzy¿yk liczba wszystkich mo¿liwych rozgrywek wynosi oko³o (a^2)!, gdzie a to liczba wierszy czy kolumn planszy. Dla kó³ko i krzy¿yk jest to 255168 (http://www.se16.info/hgb/tictactoe.htm) Ÿród³o, czyli nieco mniej ni¿ 9!.
  * Dla Gomoku (15^2)! znalezienie najlepszego ruchu jest problemem zupe³nym przestrzeni P, ale niewykonalnym w sensownym czasie i przy sensownej pamiêci. St¹d te¿ stosuje siê funkcje heurystyczne do oceny ruchu i ucina siê drzewo poszukiwañ na jakimœ poziomie.
  * Poziom 8 odpowiada ju¿ ca³kiem dobremu graczowi dla szachów, a poziom 16 pokonuje mistrza œwiata w szachach. Najwa¿niejsza jest jednak funkcja heursystyczna.
  * Aby zrealizowaæ dzia³aj¹cy minimax bez budowania pe³nego drzewa, potrzebowa³bym dzia³aj¹cej funkcji heurystycznej, której niestety w trakcie wykonywania tego projektu nie by³em w stanie stworzyæ. Moja funkcja oceny stanów dzia³a prawid³owo dla stanów koñcz¹cych, ale niejednoznacznie przewiduje dla stanów poœrednich.
  * Bez dobrej i szybkiej funkcji oceny (Moje funkcje sprawdzania stanu s¹ doœæ z³o¿one i czasoch³onne dla komputera), niemo¿liwe jest przeprowadznaie poszukiwania dla wiêkszych planszy z powodzeniem.
  * Zastosowanie odciêæ alfa-beta, z których w koniec koñców zrezygnowa³em, poniewa¿ jedynie pozwala³aby mi skróciæ wykonywanie funkcji dla 3x3, a nie przeszukiwaæ g³êbiej, zmienjszsa z³o¿onoœæ do O(2*b^(m/2)), ale wci¹¿ s¹ to zbyt wysokie wyniki dla moich funkcji oceny.
  * Musia³bym skorzystaæ z funkcji oceny innych programistów, co by znaczy³o, ¿e projekt nie do koñca by³by samodzielny, a ci¹gnê³oby sie za tym przerobienie ca³ego programu.
  * \param aktualna_pozycja Pozycja, dla której szukamy najlepszego ruchu.
  * \param alfa Kryterium alfa do odciêæ drzewa poszukiwañ
  * \param beta Kryterium beta do odciêæ drzewa poszukiwañ
  * \param gracz_tury Informacja, czy przeszukiwanie ma byæ wykonywanego dla gracza maksymalizuj¹cego czy minimalizuj¹cego
  * \param rozmiar Rozmiar planszy
  * \param pod_rzad Liczba elementów z rzêdu wymagana do wygaranej
  * \param gracz Znacznik gracza
  * \param przeciwnik Znacznik przeciwnika
  * \param glebokosc Zak³adana na pocz¹tku maksymalna g³êbokoœæ poszukiwañ, z której musia³em zrezygnowaæ przyjmuj¹æ j¹ na maksymaln¹ g³êbokoœæ dla drzewa 3x3
  * \param ilosc Informacja o liczbie wykonañ funkcji
  * \param ilosc_finalnych Informacja o liczbie ocenianych koñcowych stanów (liczba wszystkich mo¿liwych gier)
  */
int minimax(Pozycja*& aktualna_pozycja, int glebokosc, int& alfa, int& beta, bool gracz_tury, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int &ilosc, int &ilosc_finalnych);

#endif // SZTUCZNA_INTELIGENCJA_H
 