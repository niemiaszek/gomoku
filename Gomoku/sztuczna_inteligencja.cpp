#include "sztuczna_inteligencja.h"
#include <iostream>
#include "plansza.h"
#include "stan.h"
#include <cstdlib>
#include <ctime>
#include "conio.h"
using namespace std;
void latwy(char **&tab, int rozmiar, int pod_rzad, char gracz, char przeciwnik) 
{
	char **pomocnicza;
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
				if (sprawdzStan(pomocnicza, rozmiar, pod_rzad) == 'W') 
				{
					tab[i][j] = gracz;
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
					if (sprawdzStan(pomocnicza, rozmiar, pod_rzad) == 'W')
					{
						tab[i][j] = gracz;
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
			break;
		}
	}
	kasujPlansze(pomocnicza, rozmiar);
}