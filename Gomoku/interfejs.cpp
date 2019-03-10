#include <iostream>
#include "interfejs.h"
#include <Windows.h>
#include <conio.h>
#include "pliki.h"
#include <string>
#include "rozgrywka.h"
using namespace std;
const int MAX = 45;
HANDLE Kolor;

void menuStart() 
{
	Kolor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Kolor, 3);
	cout << "WITAJ W GRZE ";
	SetConsoleTextAttribute(Kolor, 6);
	cout << "GOMOKU" << endl << endl;
	SetConsoleTextAttribute(Kolor, 3);
	cout << "Gra powstala jako projekt na zaliczenie Zasad Programowania Strukturalnego 2 i jest dostepny na GitHub pod adresem:" << endl;
	SetConsoleTextAttribute(Kolor, 6);
	cout << "www.github.com/niemiaszek/gomoku" << endl << endl;
	kliknijAbyPrzejscDalej();
	menuGlowne();
}
void menuGlowne() 
{
	czyscEkran();
	SetConsoleTextAttribute(Kolor, 4);
	cout << "GLOWNE MENU" << endl << endl;
	SetConsoleTextAttribute(Kolor, 3);
	cout << "Wybierz opcje wpisujac indeks opcji z klawiatury i zatwierdzajac przez enter:" << endl;
	SetConsoleTextAttribute(Kolor, 2);
	cout << "1. Historia Gomoku" << endl;
	cout << "2. Zasady Gomoku wykorzystywane w tej grze" << endl;
	cout << "3. Rozpoczecie gry" << endl;
	cout << "4. Zakoncz gre" << endl;
	switch (pobierzZnak(1, 4))
	{
	case 1: 
		wyswietlTekstZPliku("historia.txt");
		break;
	case 2:
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
	cout << "MENU PRZED GRA" << endl << endl;
	SetConsoleTextAttribute(Kolor, 3);
	cout << "Wybierz tryb rozgrywki, tak jak w poprzednim menu:" << endl;
	SetConsoleTextAttribute(Kolor, 2);
	cout << "1. Gracz vs Gracz" << endl;
	cout << "2. Gracz vs Komputer" << endl;
	cout << "3. Komputer vs Komputer" << endl << endl;
	int tryb = pobierzZnak(1, 3);
	czyscEkran();
	SetConsoleTextAttribute(Kolor, 3);
	cout << "Ustalmy, ile pol pod rzad wygrywa" << endl;
	SetConsoleTextAttribute(Kolor, 7);
	cout << "Prosze, podaj liczbe pol pod rzad, potrzebna do wygranej..." << endl;
	int pod_rzad = pobierzZnak(1, MAX);
	czyscEkran();
	SetConsoleTextAttribute(Kolor, 3);
	cout << "Przed rozpoczeciem gry nalezy ustalic rozmiar planszy" << endl;
	SetConsoleTextAttribute(Kolor, 7);
	cout << "Prosze, podaj rozmiar kwadratowej planszy..." << endl;
	int rozmiar = pobierzZnak(pod_rzad, MAX);
	czyscEkran();
	SetConsoleTextAttribute(Kolor, 6);
	cout << "Wybrano tryb nr " << tryb << endl << "Ilosc pol pod rzad: " << pod_rzad << endl << "Rozmiar tablicy: " << rozmiar << endl;
	SetConsoleTextAttribute(Kolor, 7);
	cout << "Jezeli chcesz zmienic swoj wybor, wcisnij 1. Kazda inna spowoduje przejscie do rozgrywki..." << endl;
	if (_getch() == '1')
		menuPrzedGra();
	menuGraczGracz(rozmiar, pod_rzad);
}
void menuGraczGracz(int rozmiar, int pod_rzad) 
{
	graczvsgracz(rozmiar, pod_rzad);
}
void menuZapisu(Tura *pierwsza_tura) 
{
	czyscEkran();
	cout << "Czy chcesz zapisac rozgrywke do pliku? Jezeli tak, to wcisnij 1." << endl;
	char znak = _getch();
	if (znak != '1')
		zakonczProgram();
	cout << "Prosze, podaj nazwe pliku, do ktorego chcesz zapisac gre (pamietaj o rozszerzeniu .txt)" << endl;
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
		cout << "Podano bledny znak! Prosze, sproboj ponownie podaz znak z przedzialu: ( " << zakres_dolny << ", " << zakres_gorny << " )\n";
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
	cout << "Wcisnij dowolny przycisk, aby przejsc dalej..." << endl;
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
	cout << "MENU KONCOWE" << endl << endl;
	SetConsoleTextAttribute(Kolor, 3);
	cout << "Dziekuje za uzywanie mojego programu." << endl;
	cout << "Jezeli chcialbys znowu zagrac w Gomoku, wcisnij 1" << endl;
	cout << "Kazdy inny przycisk spowoduje zamkniecie programu" << endl;
	SetConsoleTextAttribute(Kolor, 7);
	cout << "Wcisnij przycisk..." << endl;
	if (_getch() == '1')
		menuGlowne();
}