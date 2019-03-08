#include <iostream>
#include "interfejs.h"
#include <Windows.h>
#include <conio.h>
#include "pliki.h"
using namespace std;

void menuStart() 
{
	cout << "WITAJ W GRZE ";
	cout << "GOMOKU" << endl << endl;
	cout << "Gra powstala jako projekt na zaliczenie Zasad Programowania Strukturalnego 2 i jest dostepny na GitHub pod adresem:" << endl;
	cout << "www.github.com/niemiasze/gomoku" << endl << endl;
	cout << "Kliknij dowolny przycisk, aby przejsc dalej..." << endl;
	kliknijAbyPrzejscDalej();
	menuGlowne();
}
void menuGlowne() 
{
	czyscEkran();
	cout << "GLOWNE MENU" << endl << endl;
	cout << "Wybierz opcje wpisujac indeks opcji z klawiatury i zatwierdzajac przez enter:" << endl;
	cout << "1. Historia Gomoku" << endl;
	cout << "2. Zasady Gomoku wykorzystywane w tej grze" << endl;
	cout << "3. Rozpoczecie gry" << endl;
	cout << "4. Zakoncz gre" << endl;
	switch (pobierzZnak(1, 4))
	{
	case 1: 
		wyswietlZPliku("historia.txt");
		break;
	case 2:
		wyswietlZPliku("zasady.txt");
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
	cout << "MENU PRZED GRA" << endl << endl;
	cout << "Wybierz tryb rozgrywki, tak jak w poprzednim menu:" << endl;
	cout << "1. Gracz vs Gracz" << endl;
	cout << "2. Gracz vs Komputer" << endl;
	cout << "3. Komputer vs Komputer" << endl << endl;
	int tryb = pobierzZnak(1, 3);
	cout << "Przed rozpoczeciem gry nalezy ustalic rozmiar planszy" << endl;
	cout << "Prosze, podaj rozmiar kwadratowej planszy..." << endl;
	int rozmiar = pobierzZnak(2, 1000);
	cout << "Wybrano tryb nr " << tryb << " i rozmiar tablicy " << rozmiar << endl;
	cout << "Jezeli chcesz zmienic swoj wybor, wcisnij i zatwierdz 1. Kazda inna spowoduje przejscie do rozgrywki..." << endl;
	char znak;
	cin >> znak;
	if (znak == '1')
		menuPrzedGra();
}
int pobierzZnak(int zakres_dolny, int zakres_gorny) 
{
	int znak;
	cin >> znak;
	while (!cin || znak < zakres_dolny || znak > zakres_gorny) 
	{
		cout << "Podano bledny znak. Prosze, sproboj ponownie podaz znak z przedzialu: ( " << zakres_dolny << ", " << zakres_gorny << " )\n";
		cin.clear();
		cin.sync();
		cin >> znak;
	}
	return znak;
}
void kliknijAbyPrzejscDalej() 
{
	_getch();
}
void czyscEkran() 
{
	system("cls");
}
void zakonczProgram() 
{
	czyscEkran();
	cout << "MENU KONCOWE" << endl << endl;
	cout << "Dziekuje za uzywanie mojego programu." << endl;
	cout << "Jezeli chcialbys znowu zagrac w Gomoku, wcisnij 1. Kazdy inny przycisk spwoduje zakonczenie programu" << endl;
	cout << "Wcisnij przycisk..." << endl;
	int znak;
	cin >> znak;
	if (znak == 1)
		menuGlowne();
}