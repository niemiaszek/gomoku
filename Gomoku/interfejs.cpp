#include <iostream>
#include "interfejs.h"
#include <Windows.h>
#include <conio.h>
#include "pliki.h"
#include <string>
#include "plansza.h" 
#include "rozgrywka.h"
#include <iomanip>
using namespace std;
const int MAX = 55;
HANDLE Kolor;

void menuStart() 
{
	Kolor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Kolor, 3);
	cout << "WITAJ W GRZE ";
	SetConsoleTextAttribute(Kolor, 6);
	cout << "GOMOKU" << "\n" << "\n";
	SetConsoleTextAttribute(Kolor, 3);
	cout << "Gra powstala jako projekt na zaliczenie Zasad Programowania Strukturalnego 2 i jest dostepna na GitHub pod adresem:" << "\n";
	SetConsoleTextAttribute(Kolor, 6);
	cout << "www.github.com/niemiaszek/gomoku" << "\n" << "\n";
	kliknijAbyPrzejscDalej();
	menuGlowne();
}
void menuGlowne() 
{
	czyscEkran();
	SetConsoleTextAttribute(Kolor, 4);
	cout << "GLOWNE MENU" << "\n" << "\n";
	SetConsoleTextAttribute(Kolor, 3);
	cout << "Wybierz opcje wpisujac indeks opcji z klawiatury i zatwierdzajac przez enter:" << "\n";
	SetConsoleTextAttribute(Kolor, 2);
	cout << "1. Historia Gomoku" << "\n";
	cout << "2. Zasady Gomoku wykorzystywane w tej grze" << "\n";
	cout << "3. Rozpoczecie gry" << "\n";
	cout << "4. Zakoncz gre" << "\n";
	switch (pobierzZnak(1, 4))
	{
	case 1:
		SetConsoleTextAttribute(Kolor, 6);
		wyswietlTekstZPliku("historia.txt");
		break;
	case 2:
		SetConsoleTextAttribute(Kolor, 6);
		wyswietlTekstZPliku("zasady.txt");
		break;
	case 3:
		menuPrzedGra();
		break;
	case 4: 
		zakonczProgram();
		break;
	}

}
void menuPrzedGra()
{
	czyscEkran();
	SetConsoleTextAttribute(Kolor, 4);
	cout << "MENU PRZED GRA" << "\n" << "\n";
	SetConsoleTextAttribute(Kolor, 3);
	cout << "Wybierz tryb rozgrywki, tak jak w poprzednim menu:" << "\n";
	SetConsoleTextAttribute(Kolor, 2);
	cout << "1. Gracz vs Gracz" << "\n";
	cout << "2. Gracz vs Komputer" << "\n";
	cout << "3. Komputer vs Komputer" << "\n" << "\n";
	int tryb = pobierzZnak(1, 3);
	int trudnosc;
	if (tryb == 2 || tryb == 3) 
	{
		czyscEkran();
		SetConsoleTextAttribute(Kolor, 3);
		cout << "Wybierz poziom trudonosci komputera" << "\n";
		SetConsoleTextAttribute(Kolor, 2);
		cout << "1. Latwy" << "\n";
		cout << "2. Sredni" << "\n";
		cout << "3. Trudny" << "\n";
		trudnosc = pobierzZnak(1, 3);
	}
	czyscEkran();
	SetConsoleTextAttribute(Kolor, 3);
	cout << "Ustalmy, ile pol z rzedu wygrywa" << "\n";
	SetConsoleTextAttribute(Kolor, 7);
	cout << "Prosze, podaj liczbe pol z rzedu, potrzebna do wygranej..." << "\n";
	int pod_rzad = pobierzZnak(1, MAX);
	czyscEkran();
	SetConsoleTextAttribute(Kolor, 3);
	cout << "Przed rozpoczeciem gry nalezy ustalic rozmiar planszy" << "\n";
	SetConsoleTextAttribute(Kolor, 7);
	cout << "Prosze, podaj rozmiar kwadratowej planszy..." << "\n";
	int rozmiar = pobierzZnak(pod_rzad, MAX);
	czyscEkran();
	SetConsoleTextAttribute(Kolor, 6);
	cout << "Wybrano tryb nr " << tryb << "\n" << "Ilosc pol z rzedu: " << pod_rzad << "\n" << "Rozmiar planszy: " << rozmiar << "\n";
	SetConsoleTextAttribute(Kolor, 7);
	cout << "Jezeli chcesz zmienic swoj wybor kliknij 1. Kazdy inny przycisk spowoduje przejscie do rozgrywki..." << "\n";
	if (_getch() == '1')
		menuPrzedGra();
	switch (tryb) 
	{
	case 1:
		graczvsgracz(rozmiar, pod_rzad);
		break;
	case 2:
		graczvskomputer(rozmiar, pod_rzad, trudnosc);
		break;
	case 3:
		komputervskomputer(rozmiar, pod_rzad, trudnosc);
		break;
	}
}
void menuZapisu(Tura *pierwsza_tura) 
{
	czyscEkran();
	cout << "Czy chcesz zapisaæ rozgrywke do pliku? Jezeli tak, to wcisnij 1." << "\n";
	char znak = _getch();
	if (znak != '1')
		zakonczProgram();
	cout << "Podaj nazwe pliku, do ktorego chcesz zapisac gre (pamietaj o rozszerzeniu .txt)" << "\n";
	string nazwa_pliku; 
	getline(cin, nazwa_pliku);
	//zapiszGreDoPliku(nazwa_pliku, pierwsza_tura);
	usunListe(pierwsza_tura);
	zakonczProgram();
}

int pobierzZnak(int zakres_dolny, int zakres_gorny) 
{
	int znak;
	cin >> znak;
	while (cin.fail() || znak < zakres_dolny || znak > zakres_gorny) 
	{
		SetConsoleTextAttribute(Kolor, 4);
		cout << "Podano bledny! Prosze, sproboj ponownie podaz znak z przedzialu: ( " << zakres_dolny << ", " << zakres_gorny << " )\n";
		cin.clear();
		cin.ignore(1000, '\n');
		cin.sync();
		cin >> znak;
	}
	return znak;
}
void kliknijAbyPrzejscDalej() 
{
	SetConsoleTextAttribute(Kolor, 7);
	cout << "Wcisnij dowolny przycisk, aby przejsc dalej..." << "\n";
	_getch();
}
void czyscEkran() 
{
	system("cls");
}
void zakonczProgram() 
{
	czyscEkran();
	SetConsoleTextAttribute(Kolor, 4);
	cout << "MENU KONCOWE" << "\n" << "\n";
	SetConsoleTextAttribute(Kolor, 3);
	cout << "Dziekuje za uzywanie mojego programu" << "\n";
	cout << "Jezeli chcialbys znowu zagrac w Gomoku, wcisnij 1" << "\n";
	cout << "Kazdy inny przycisk spowoduje zamkniecie programu" << "\n";
	SetConsoleTextAttribute(Kolor, 7);
	cout << "Wcisnij przycisk..." << "\n";
	if (_getch() == '1')
		menuGlowne();
	return;
}
char poruszaniePoPlanszy(char **&tab, int rozmiar, int &aktx, int &akty, char gracz)
{
	czyscEkran();
	char **pomocnicza;
	utworzPomocznicza(tab, pomocnicza, rozmiar);
	if (tab[aktx][akty] == ' ')
		pomocnicza[aktx][akty] = gracz;
	if (tab[aktx][akty] == 'x' || tab[aktx][akty] == 'o')
		pomocnicza[aktx][akty] = '#';
	wyswietlPlansze(pomocnicza, rozmiar);
	SetConsoleTextAttribute(Kolor, 2);
	cout << "\n" << "Sterowanie" << setw(3) << ' ' << "Esc - Zakoncz rozgrywke"  << setw(3) << ' ' << "Strzalki - Poruszanie kursora"  << setw(3) << ' ' << "Enter - Zatwierdz ruch" << "\n";
	kasujPlansze(pomocnicza, rozmiar);
	int polecenie = _getch();	
	if (polecenie == 27)
		return 'E';
	if (polecenie == 0 || polecenie == 224)
	{
		switch (_getch())
		{
		case 72: //strza³ka w gore
			if (aktx > 0)
				aktx--;
			break;
		case 80: //strza³ka w dol
			if (aktx < rozmiar - 1)
				aktx++;
			break;
		case 77: //strza³ka w prawo
			if (akty < rozmiar - 1)
				akty++;
			break;
		case 75: //strza³ka w lewo
			if (akty > 0)
				akty--;
			break;
		}
	}
	else if (polecenie == 13)
	{
		if (tab[aktx][akty] == ' ') 
		{
			tab[aktx][akty] = gracz;
			return 'Z';
		}
	}
	poruszaniePoPlanszy(tab, rozmiar, aktx, akty, gracz);
}
void wyswietlPlansze(char **tab, int rozmiar)
{
	SetConsoleTextAttribute(Kolor, 6);
	for (int i = 0; i < rozmiar + 2; i++)
		cout << setw(2) << '#';
	cout << "\n";
	for (int i = 0; i < rozmiar; i++)
	{
		cout << setw(2) << '#';
		for (int j = 0; j < rozmiar; j++)
		{
			if (tab[i][j] == '#')
				SetConsoleTextAttribute(Kolor, 4);
			if (tab[i][j] == 'o')
				SetConsoleTextAttribute(Kolor, 7);
			if (tab[i][j] == 'x')
				SetConsoleTextAttribute(Kolor, 8);
			cout << setw(2) << tab[i][j];
			if (tab[i][j+1] == '#' && j != rozmiar - 1)
				SetConsoleTextAttribute(Kolor, 4);
			if (tab[i][j+1] == 'o' && j != rozmiar - 1)
				SetConsoleTextAttribute(Kolor, 7);
			if (tab[i][j+1] == 'x' && j != rozmiar - 1)
				SetConsoleTextAttribute(Kolor, 8);
		}
		SetConsoleTextAttribute(Kolor, 6);
		cout << setw(2) << '#' << "\n";
	}
	for (int i = 0; i < rozmiar + 2; i++)
		cout << setw(2) << '#';
	cout << "\n";
}
void komunikatBladOtwarciaPliku() 
{
	SetConsoleTextAttribute(Kolor, 4);
	cout << "Blad otwarcia pliku!" << "\n";
	kliknijAbyPrzejscDalej();
}
void komunikatRezultat(char rezultat) 
{
	SetConsoleTextAttribute(Kolor, 6);
	if (rezultat != 'R')
		cout << "Wygrywa gracz " << rezultat << '!' << "\n";
	if (rezultat == 'R')
		cout << "Remis!" << "\n";
	SetConsoleTextAttribute(Kolor, 2);
	cout << "Aby zakonczyc rozgrywke wcisnij Escape" << "\n";
	int polecenie = _getch();	
	while (polecenie != 27)
	{
		polecenie = _getch();
	}
}