#include "sztuczna_inteligencja.h"
#include <iostream>
#include "plansza.h"
#include "stan.h"
#include <cstdlib>
#include <ctime>
#include <climits>
#include "conio.h"
#include "lista.h"
#include <algorithm>
#include "interfejs.h"
using namespace std;
void latwy(char**& tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, Ruch*& wykonywalne_ruchy) //sprawdza sie dobrze jedynie przy planszy 3v3, wszedzie indziej jest losowy 
{
	int sumka;
	char** pomocnicza;
	int komputerx, komputery;
	utworzPomocznicza(tab, pomocnicza, rozmiar); // sprawdzanie od strony komputera
	bool is_computer = false;
	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++)
		{
			if (is_computer == true)
				break;
			if (pomocnicza[i][j] == ' ')
			{
				pomocnicza[i][j] = gracz;
				if (sprawdzStan(pomocnicza, rozmiar, pod_rzad, sumka) == 'W')
				{
					tab[i][j] = gracz;
					komputerx = i;
					komputery = j;
					is_computer = true;
				}
				if (is_computer == true)
					break;
				pomocnicza[i][j] = ' ';
			}
		}
	bool is_player = false;  // sprawdzanie od strony gracza
	if (is_computer == false)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++)
			{
				if (is_player == true)
					break;
				if (tab[i][j] == ' ')
				{
					pomocnicza[i][j] = przeciwnik;
					if (sprawdzStan(pomocnicza, rozmiar, pod_rzad, sumka) == 'W')
					{
						tab[i][j] = gracz;
						komputerx = i;
						komputery = j;
						is_player = true;
					}
					if (is_player == true)
						break;
					pomocnicza[i][j] = ' ';
				}
			}
		}
	}
	if (is_player == false && is_computer == false)
	{
		srand(time(NULL));
		while (true)
		{
			int xrnd = rand() % rozmiar;
			int yrnd = rand() % rozmiar;
			if (tab[xrnd][yrnd] != ' ')
				continue;
			tab[xrnd][yrnd] = gracz;
			komputerx = xrnd;
			komputery = yrnd;
			break;
		}
	}
	usunRuch(wykonywalne_ruchy, komputerx, komputery);
	kasujPlansze(pomocnicza, rozmiar);
}
void sredni(char**& tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, Ruch * &wykonywalne_ruchy) //sredni poziom przeciwnika. Latwy do oszukania i pokonania, kiedy zna sie algorytm jego dzialania
{
	int* najlepszy_x = new int, * najlepszy_y = new int, * najlepszy = new int; // Deklarowanie poczatkowych wskaznikow na wspolrzedne ruchu o najwiekszej sumie i o najwiekszym wyniku 
	*najlepszy = *najlepszy_x = *najlepszy_y = 0;
	Ruch* akt = wykonywalne_ruchy; // tworzenie wkaznika pomocniczego na aktualny ruch
	char** pomocnicza; // tworzenie tablicy pomocniczej, wykorzystywanej do podstawiania ruchow graczy
	utworzPomocznicza(tab, pomocnicza, rozmiar);
	while (akt != NULL) { // dopoki nie skoncza sie wykonywalne ruchy
		int suma_przed = 0, suma_gracz = 0, suma_przeciwnik = 0; // tworzenie sum tymczasowych istniejacych przy danym ruchu
		sprawdzStan(pomocnicza, rozmiar, pod_rzad, suma_przed); // sprawdzanie stanu gry przed jakimkolwiek ruchem
		pomocnicza[akt->x][akt->y] = gracz; // podstawienie pionka gracza do aktualnej pozycji 
		char jest_wygrana = sprawdzStan(pomocnicza, rozmiar, pod_rzad, suma_gracz); // skrocenie przesukiwania, natychmiastowe zakonczenie gry, jezeli dany ruch daje mozliwosc wygranej
		if (jest_wygrana == 'W')
		{
			*najlepszy_x = akt->x;
			*najlepszy_y = akt->y;
			break;
		}
		pomocnicza[akt->x][akt->y] = przeciwnik; // zamienienie pionka na pionek przeciwnika i sprawdzenie stanu gry przy takim ruchu
		sprawdzStan(pomocnicza, rozmiar, pod_rzad, suma_przeciwnik);
		//cout << "x=" << akt->x << " y=" << akt->y << " suma przed: " << suma_przed << "  suma gracz: " << suma_gracz << " suma przeciwnik: " << suma_przeciwnik << "\n";
		if (2 * (suma_gracz - suma_przed) + (suma_przeciwnik - suma_przed) > * najlepszy) // zamienienie najlepszego dotychzasowego ruchu na obecny ruch, jezeli suma ró¿nic po ruchów graczy jest wiêksza ni¿ aktualna najwiêksza
		{
			*najlepszy_x = akt->x;
			*najlepszy_y = akt->y;
			*najlepszy = 2 * (suma_gracz - suma_przed) + (suma_przeciwnik - suma_przed); //mnoznik dwa przy roznicy gracza bierze sie stad, ze wygrana gracza jest preferowana niz blokowanie ruchu wygrywajacego gracza
		}
		//cout << "najlepszy x: " << *najlepszy_x << " najlepszy y: " << *najlepszy_y << " najlepszy: " << *najlepszy << "\n";
		pomocnicza[akt->x][akt->y] = ' '; // przywrocenie polu o aktualnych wspolrzednych zerowego stanu
		akt = akt->next; // przejscie do nastepnego wykonywalnego ruchu
	}
	tab[*najlepszy_x][*najlepszy_y] = gracz; //podstawienie pod najlepszy ruch pionka gracza
	usunRuch(wykonywalne_ruchy, *najlepszy_x, *najlepszy_y);
	delete najlepszy_x, najlepszy_y, najlepszy;
	kasujPlansze(pomocnicza, rozmiar);
}
void trudny(char**& tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int glebokosc)
{
	Pozycja* wezel = new Pozycja;
	wezel->dzieci = NULL;
	wezel->ojciec = NULL;
	char** plansza;
	utworzPomocznicza(tab, plansza, rozmiar);
	wezel->plansza = plansza;
	int alfa = INT_MIN;
	int beta = INT_MAX;;
	int ilosc = 0;
	int ilosc_finalnych = 0;
	wezel->wartosc = minimax(wezel, glebokosc, alfa, beta, true, rozmiar, pod_rzad, gracz, przeciwnik, ilosc, ilosc_finalnych);
	//cout << "wartosc: " << wezel->wartosc << "\n";
#ifdef _DEBUG
	cout << "TO ILOSC: " << ilosc << " A TO ILOSC FINALNYCH STANOW: " << ilosc_finalnych << endl;
#endif // _DEBUG
	Dzieci* akt = wezel->dzieci;
	Ruch *lista_do_losowania=NULL;
	int licznik = 0;
	while (akt != NULL)
	{
#ifdef _DEBUG
		wyswietlPlansze(akt->dziecko->plansza, rozmiar);
		cout << "Wartosc tego pierwszego ruchu: " << akt->dziecko->wartosc << "\n";
		kliknijAbyPrzejscDalej();
#endif // _DEBUG
		if (akt->dziecko->wartosc == wezel->wartosc)
		{
			dodajRuch(lista_do_losowania, akt->dziecko->x, akt->dziecko->y);
			licznik++;
		}
		akt = akt->next;
	}
	int wylosowany_x, wylosowany_y;
	losoujRuch(lista_do_losowania, licznik, wylosowany_x, wylosowany_y);
	usunListe(lista_do_losowania);
	tab[wylosowany_x][wylosowany_y] = gracz;
	while (wezel->dzieci != NULL)
	{
		Dzieci* tmp = wezel->dzieci;
		wezel->dzieci = wezel->dzieci->next;
		kasujPlansze(tmp->dziecko->plansza, rozmiar);
		delete tmp;
		tmp = NULL;
	}
	kasujPlansze(wezel->plansza, rozmiar);
	delete wezel;
	//usunDrzewo(wezel);
}
int minimax(Pozycja * &aktualna_pozycja, int glebokosc, int& alfa, int& beta, bool gracz_tury, int rozmiar, int pod_rzad, char gracz, char przeciwnik, int &ilosc, int &ilosc_finalnych)
{
	//cout << "glebokosc: " << glebokosc << "\n";
	ilosc++;
	int suma_poczatkowa;
	char stan = sprawdzStan(aktualna_pozycja->plansza, rozmiar, pod_rzad, suma_poczatkowa);
	if (glebokosc == 0 || stan != 'N')
	{
		ilosc_finalnych++;
		/*if (gracz_tury == true) {
			//cout << "przeciwnik: ";
			int przewaga_przeciwnika = ocenaStanu(aktualna_pozycja->plansza, rozmiar, pod_rzad, gracz);
			aktualna_pozycja->plansza[aktualna_pozycja->x][aktualna_pozycja->y] = ' ';
			int ocena_przed = ocenaStanu(aktualna_pozycja->plansza, rozmiar, pod_rzad, gracz) + ocenaStanu(aktualna_pozycja->plansza, rozmiar, pod_rzad, przeciwnik);
			aktualna_pozycja->plansza[aktualna_pozycja->x][aktualna_pozycja->y] = gracz;
			int przewaga_gracza = ocenaStanu(aktualna_pozycja->plansza, rozmiar, pod_rzad, gracz);
			aktualna_pozycja->plansza[aktualna_pozycja->x][aktualna_pozycja->y] = przeciwnik;
			int uzytecznosc_gracza = przewaga_gracza - ocena_przed;
			ocena = 5 / 3 * przewaga_przeciwnika - uzytecznosc_gracza;
		}
		else
		{
			//cout << "gracz: ";
			int ocena_gracza = ocenaStanu(aktualna_pozycja->plansza, rozmiar, pod_rzad, gracz);
			aktualna_pozycja->plansza[aktualna_pozycja->x][aktualna_pozycja->y] = ' ';
			int gracza_przed = ocenaStanu(aktualna_pozycja->plansza, rozmiar, pod_rzad, gracz);
			int przewaga_gracza = ocena_gracza - gracza_przed;
			int przeciwnika_przed = ocenaStanu(aktualna_pozycja->plansza, rozmiar, pod_rzad, gracz) + ocenaStanu(aktualna_pozycja->plansza, rozmiar, pod_rzad, przeciwnik);
			aktualna_pozycja->plansza[aktualna_pozycja->x][aktualna_pozycja->y] = przeciwnik;
			int przewaga_przeciwnika = ocenaStanu(aktualna_pozycja->plansza, rozmiar, pod_rzad, przeciwnik);
			aktualna_pozycja->plansza[aktualna_pozycja->x][aktualna_pozycja->y] = gracz;
			int uzytecznosc_przeciwnika = 5 / 3 * przewaga_przeciwnika - przeciwnika_przed;
			ocena = przewaga_gracza;
		}*/
		//wyswietlPlansze(aktualna_pozycja->plansza, rozmiar);
		int ocena = ocenaStanu(aktualna_pozycja->plansza, rozmiar, pod_rzad, gracz)/2;
		if (ocena > 0)
			ocena += glebokosc;
		else ocena -= glebokosc;
		//kasujPlansze(aktualna_pozycja->plansza, rozmiar);
		//delete aktualna_pozycja;*/
		if (stan == 'R')
				ocena= 0;
		//cout << ocena << "\n";


		return ocena;
	}
	char znak_syna = gracz;
	if (gracz_tury == true)
		znak_syna = przeciwnik;
	Ruch * ruchy = NULL;
	pobierzWykonywalneRuchy(ruchy, aktualna_pozycja->plansza, rozmiar);
	if (gracz_tury == true)
	{
		aktualna_pozycja->wartosc = INT_MIN;
		while (ruchy != NULL)
		{
			Pozycja* syn;
			utworzSyna(ruchy, aktualna_pozycja, syn, rozmiar, gracz);
			ilosc++;
			syn->wartosc = minimax(syn, glebokosc - 1, alfa, beta, false, rozmiar, pod_rzad, gracz, przeciwnik, ilosc, ilosc_finalnych);
			//cout << "Wartosc syna dla true: " << syn->wartosc << "\n";
			//wyswietlPlansze(syn->plansza, rozmiar);
			aktualna_pozycja->wartosc = max(aktualna_pozycja->wartosc, syn->wartosc);
			alfa = max(alfa, syn->wartosc);
			//cout << "beta: " << beta << " alfa: " << alfa << "\n";
			//cout << "Syn x, y: " << syn->x << ' ' << syn->y << "\n";
			//wypiszWykonywalneRuchy(ruchy);
			//if (beta <= alfa)
				//break;
		}
		//wyswietlPlansze(aktualna_pozycja->plansza, rozmiar);
		//cout << "Wartoœæ tej planszy dla true: " << aktualna_pozycja->wartosc << "\n";
	}
	else
	{
		aktualna_pozycja->wartosc = INT_MAX;;
		while (ruchy != NULL)
		{
			Pozycja* syn;
			utworzSyna(ruchy, aktualna_pozycja, syn, rozmiar, przeciwnik);
			ilosc++;
			syn->wartosc = minimax(syn, glebokosc - 1, alfa, beta, true, rozmiar, pod_rzad, gracz, przeciwnik, ilosc, ilosc_finalnych	);
			//cout << "Wartosc syna dla false: " << syn->wartosc << "\n";
			//wyswietlPlansze(syn->plansza, rozmiar);
			aktualna_pozycja->wartosc = min(aktualna_pozycja->wartosc, syn->wartosc);
			beta = min(beta, syn->wartosc);
			//if (beta <= alfa)
				//break;
		}
		//wyswietlPlansze(aktualna_pozycja->plansza, rozmiar);
		//cout << "Wartoœæ tej planszy dla false: " << aktualna_pozycja->wartosc << "\n";
	}
	if (aktualna_pozycja->ojciec != NULL)
		while (aktualna_pozycja->dzieci != NULL)
		{
			Dzieci* tmp = aktualna_pozycja->dzieci;
			aktualna_pozycja->dzieci = aktualna_pozycja->dzieci->next;
			if (tmp->dziecko->plansza != NULL)
				kasujPlansze(tmp->dziecko->plansza, rozmiar);
			delete tmp->dziecko;
			delete tmp;
			tmp = NULL;
		}

	return aktualna_pozycja->wartosc;
}
