#include "rozgrywka.h"
#include "plansza.h"
#include "interfejs.h"
#include <iostream>
#include "lista.h"
#include "stan.h"
#include "sztuczna_inteligencja.h"
using namespace std;

void graczvsgracz(int rozmiar, int pod_rzad)
{
	czyscEkran();
	int aktx = rozmiar / 2, akty = rozmiar / 2;
	Tura *pierwsza_tura = NULL;
	Tura *aktualna_tura = pierwsza_tura;
	char **tab;
	utworzPlansze(tab, rozmiar);
	while (true) {

		char x = ruchGracza(tab, rozmiar, 'x', aktx, akty);
		if (x == 'E')
			break;
		dodajDoListy(aktualna_tura, tab);
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'W')
		{
			komunikatRezultat('x');
			break;
		}
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'R')
		{
			komunikatRezultat('R');
			break;
		}
		char o = ruchGracza(tab, rozmiar, 'o', aktx, akty);
		if (o == 'E')
			break;
		dodajDoListy(aktualna_tura, tab);
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'W')
		{
			komunikatRezultat('o');
			break;
		}
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'R')
		{
			komunikatRezultat('R');
			break;
		}
	}
	zakonczRozgrywke(tab, rozmiar);
}
void graczvskomputer(int rozmiar, int pod_rzad, int trudnosc) 
{
	czyscEkran();
	int aktx = rozmiar / 2, akty = rozmiar / 2;
	Tura *pierwsza_tura = NULL;
	Tura *aktualna_tura = pierwsza_tura;
	char **tab;
	utworzPlansze(tab, rozmiar);
	while (true) 
	{
		char x = ruchGracza(tab, rozmiar, 'x', aktx, akty);
		if (x == 'E')
			break;
		dodajDoListy(aktualna_tura, tab);
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'W')
		{
			komunikatRezultat('x');
			break;
		}
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'R')
		{
			komunikatRezultat('R');
			break;
		}
		latwy(tab, rozmiar, pod_rzad, 'o', 'x');
		wyswietlPlansze(tab, rozmiar);
		kliknijAbyPrzejscDalej();
		dodajDoListy(aktualna_tura, tab);
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'W')
		{
			komunikatRezultat('o');
			break;
		}
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'R')
		{
			komunikatRezultat('R');
			break;
		}
	}
	zakonczRozgrywke(tab, rozmiar);
}
void komputervskomputer(int rozmiar, int pod_rzad, int trudnosc) 
{
	czyscEkran();
	int aktx = rozmiar / 2, akty = rozmiar / 2;
	Tura *pierwsza_tura = NULL;
	Tura *aktualna_tura = pierwsza_tura;
	char **tab;
	utworzPlansze(tab, rozmiar);
	wyswietlPlansze(tab, rozmiar);
	kliknijAbyPrzejscDalej();
	while (true) {
		czyscEkran();
		latwy(tab, rozmiar, pod_rzad, 'x', 'o');
		wyswietlPlansze(tab, rozmiar);
		kliknijAbyPrzejscDalej();
		dodajDoListy(aktualna_tura, tab);
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'W')
		{
			komunikatRezultat('x');
			break;
		}
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'R')
		{
			komunikatRezultat('R');
			break;
		}
		czyscEkran();
		latwy(tab, rozmiar, pod_rzad, 'o', 'x');
		wyswietlPlansze(tab, rozmiar);
		kliknijAbyPrzejscDalej();
		dodajDoListy(aktualna_tura, tab);
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'W')
		{
			komunikatRezultat('o');
			break;
		}
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'R')
		{
			komunikatRezultat('R');
			break;
		}
	}
	zakonczRozgrywke(tab, rozmiar);
}
void zakonczRozgrywke(char **tab, int rozmiar) 
{
	kasujPlansze(tab, rozmiar);
	zakonczProgram();
}
char ruchGracza(char **&tab, int rozmiar, char gracz, int &aktx, int &akty)
{
	char opcja = poruszaniePoPlanszy(tab, rozmiar, aktx, akty, gracz);
	return opcja;
}