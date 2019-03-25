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
	int suma;
	//Tura *pierwsza_tura = NULL;
	//Tura *aktualna_tura = pierwsza_tura;
	char **tab;
	utworzPlansze(tab, rozmiar);
	while (true) {
		char x = ruchGracza(tab, rozmiar, 'x', aktx, akty);
		if (x == 'E')
			break;
		//dodajDoListy(aktualna_tura, tab);
		char stan;
		stan = sprawdzStan(tab, rozmiar, pod_rzad, suma);
		if (stan == 'W')
		{
			komunikatRezultat('x');
			break;
		}
		if (stan == 'R')
		{
			komunikatRezultat('R');
			break;
		}
		cout << suma << endl;
		kliknijAbyPrzejscDalej();
		char o = ruchGracza(tab, rozmiar, 'o', aktx, akty);
		if (o == 'E')
			break;
		//dodajDoListy(aktualna_tura, tab);
		stan = sprawdzStan(tab, rozmiar, pod_rzad, suma);
		if (stan == 'W')
		{
			komunikatRezultat('o');
			break;
		}
		if (stan == 'R')
		{
			komunikatRezultat('R');
			break;
		}
		cout << suma << endl;
		kliknijAbyPrzejscDalej();
	}
	zakonczRozgrywke(tab, rozmiar);
}
void graczvskomputer(int rozmiar, int pod_rzad, int trudnosc) 
{
	czyscEkran();
	int suma;
	int aktx = rozmiar / 2, akty = rozmiar / 2;
	//Tura *pierwsza_tura = NULL;
	//Tura *aktualna_tura = pierwsza_tura;
	char **tab;
	Ruch *Ruchy = NULL;
	utworzPlansze(tab, rozmiar);
	while (true) 
	{
		if (Ruchy == NULL) pobierzWykonywalneRuchy(Ruchy, tab, rozmiar);
		char x = ruchGracza(tab, rozmiar, 'x', aktx, akty);
		if (x == 'E')
			break;
		usunRuch(Ruchy, aktx, akty);
		//wypiszWykonywalneRuchy(Ruchy);
		//dodajDoListy(aktualna_tura, tab);
		char stan;
		stan = sprawdzStan(tab, rozmiar, pod_rzad, suma);
		if (stan == 'W')
		{
			komunikatRezultat('x');
			break;
		}
		if (stan == 'R')
		{
			komunikatRezultat('R');
			break;
		}
		switch (trudnosc) {
		case 1:
			latwy(tab, rozmiar, pod_rzad, 'o', 'x', Ruchy);
			break;
		case 2:
			sredni(tab, rozmiar, pod_rzad, 'o', 'x', Ruchy);
			break;
		}
		wyswietlPlansze(tab, rozmiar);
		//wypiszWykonywalneRuchy(Ruchy);
		kliknijAbyPrzejscDalej();
		//dodajDoListy(aktualna_tura, tab);
		stan = sprawdzStan(tab, rozmiar, pod_rzad, suma);
		if (stan == 'W')
		{
			komunikatRezultat('o');
			break;
		}
		if (stan == 'R')
		{
			komunikatRezultat('R');
			break;
		}
		kliknijAbyPrzejscDalej();
	}
	zakonczRozgrywke(tab, rozmiar, Ruchy);
}
void komputervskomputer(int rozmiar, int pod_rzad, int trudnosc) 
{
	czyscEkran();

	int aktx = rozmiar / 2, akty = rozmiar / 2;
	//Tura *pierwsza_tura = NULL;
	//Tura *aktualna_tura = pierwsza_tura;
	Ruch *Ruchy = NULL;
	char **tab;
	int suma;
	utworzPlansze(tab, rozmiar);
	wyswietlPlansze(tab, rozmiar);
	if (Ruchy == NULL) pobierzWykonywalneRuchy(Ruchy, tab, rozmiar);
	kliknijAbyPrzejscDalej();
	while (true) {
		czyscEkran();
		switch (trudnosc) {
		case 1:
			latwy(tab, rozmiar, pod_rzad, 'x', 'o', Ruchy);
			break;
		case 2:
			sredni(tab, rozmiar, pod_rzad, 'x', 'o', Ruchy);
			break;
		}
		wyswietlPlansze(tab, rozmiar);
		kliknijAbyPrzejscDalej();
		//dodajDoListy(aktualna_tura, tab);
		char stan;
		stan= sprawdzStan(tab, rozmiar, pod_rzad, suma);
		if (stan == 'W')
		{
			komunikatRezultat('x');
			break;
		}
		if (stan == 'R')
		{
			komunikatRezultat('R');
			break;
		}
		czyscEkran();
		switch (trudnosc) {
		case 1:
			latwy(tab, rozmiar, pod_rzad, 'o', 'x', Ruchy);
			break;
		case 2:
			sredni(tab, rozmiar, pod_rzad, 'o', 'x', Ruchy);
			break;
		}
		wyswietlPlansze(tab, rozmiar);
		kliknijAbyPrzejscDalej();
		//dodajDoListy(aktualna_tura, tab);
		stan = sprawdzStan(tab, rozmiar, pod_rzad, suma);
		if (stan == 'W')
		{
			komunikatRezultat('o');
			break;
		}
		if (stan == 'R')
		{
			komunikatRezultat('R');
			break;
		}
	}
	zakonczRozgrywke(tab, rozmiar, Ruchy);
}
void zakonczRozgrywke(char **tab, int rozmiar, Ruch *&wykonywalne_ruchy) 
{
	usunListe(wykonywalne_ruchy);
	kasujPlansze(tab, rozmiar);
	zakonczProgram();
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