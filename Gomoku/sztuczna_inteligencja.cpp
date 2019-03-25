#include "sztuczna_inteligencja.h"
#include <iostream>
#include "plansza.h"
#include "stan.h"
#include <cstdlib>
#include <ctime>
#include "conio.h"
#include "lista.h"
using namespace std;
void latwy(char **&tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, Ruch *&wykonywalne_ruchy) 
{
	int sumka;
	char **pomocnicza;
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
void sredni(char **&tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik, Ruch *&wykonywalne_ruchy)
{
	int *najlepszy_x = new int, *najlepszy_y = new int , *najlepszy = new int;
	*najlepszy = *najlepszy_x = *najlepszy_y =0;
	Ruch *akt = wykonywalne_ruchy;
	char **pomocnicza;
	utworzPomocznicza(tab, pomocnicza, rozmiar);
	while (akt != NULL) {
		int suma_przed=0, suma_gracz=0, suma_przeciwnik=0;
		sprawdzStan(pomocnicza, rozmiar, pod_rzad, suma_przed);
		pomocnicza[akt->x][akt->y] = gracz;
		char is_win=sprawdzStan(pomocnicza, rozmiar, pod_rzad, suma_gracz);
		if (is_win == 'W') 
		{
			*najlepszy_x = akt->x;
			*najlepszy_y = akt->y;
			break;
		}
		pomocnicza[akt->x][akt->y] = przeciwnik;
		sprawdzStan(pomocnicza, rozmiar, pod_rzad, suma_przeciwnik);
		//cout << "x=" << akt->x << " y=" << akt->y << " suma przed: " << suma_przed << "  suma gracz: " << suma_gracz << " suma przeciwnik: " << suma_przeciwnik << endl;
		if (2*(suma_gracz-suma_przed) + (suma_przeciwnik-suma_przed) > *najlepszy)
		{
			*najlepszy_x = akt->x;
			*najlepszy_y = akt->y;
			*najlepszy = 2*(suma_gracz - suma_przed) + (suma_przeciwnik - suma_przed);
		}
		//cout << "najlepszy x: " << *najlepszy_x << " najlepszy y: " << *najlepszy_y << " najlepszy: " << *najlepszy << endl;
		pomocnicza[akt->x][akt->y] = ' ';
		akt = akt->next;
	}
	tab[*najlepszy_x][*najlepszy_y] = gracz;
	usunRuch(wykonywalne_ruchy, *najlepszy_x, *najlepszy_y);
	delete najlepszy_x, najlepszy_y, najlepszy;
	kasujPlansze(pomocnicza, rozmiar);
}