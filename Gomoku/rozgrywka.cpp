#include "rozgrywka.h"
#include "plansza.h"
#include "interfejs.h"
#include <iostream>
#include "lista.h"
#include "stan.h"
using namespace std;

void graczvsgracz(int rozmiar, int pod_rzad) 
{
	czyscEkran();
	Tura *pierwsza_tura=NULL;
	Tura *aktualna_tura = pierwsza_tura;
	char **tab;
	utworzPlansze(tab, rozmiar); 
	while(true){
		
		char x=ruchGracza(tab, rozmiar, 'x');
		if (x == 'E')
			break;
		dodajDoListy(aktualna_tura, tab);
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'W')
		{
			cout << "Wygrywa gracz x!" << endl;
			kliknijAbyPrzejscDalej();
			break;
		}
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'R')
		{
			cout << "Remis!" << endl;
			kliknijAbyPrzejscDalej();
			break;
		}
		char o=ruchGracza(tab, rozmiar, 'o');
		if (o == 'E')
			break;
		dodajDoListy(aktualna_tura, tab);
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'W')
		{
			cout << "Wygrywa gracz o!" << endl;
			kliknijAbyPrzejscDalej();
			break;
		}
		if (sprawdzStan(tab, rozmiar, pod_rzad) == 'R')
		{
			cout << "Remis!" << endl;
			kliknijAbyPrzejscDalej();
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