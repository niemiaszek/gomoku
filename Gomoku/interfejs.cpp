#include <iostream>
#include "interfejs.h"
#include <Windows.h>
#include <conio.h>
using namespace std;
void menuStart() 
{
	cout << "WITAJ W GRZE " << endl;
	cout << "GOMOKU" << endl;
	cout << "Gra powstaje jako projekt na zaliczenie Zasad Programowania Strukturalnego 2 i jest dostepny na GitHub pod adresem:" << endl;
	cout << "www.github.com/niemiasze/gomoku" << endl << endl;
	cout << "Kliknij dowolny przycisk, aby przejsc dalej..." << endl;
	kliknijAbyPrzejscDalej();
}
void menu1() {}
void kliknijAbyPrzejscDalej() 
{
	_getch();
}