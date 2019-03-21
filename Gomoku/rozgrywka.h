#pragma once
#ifndef ROZGRYWKA_H
#define ROZGRYWKA_H
void graczvsgracz(int rozmiar, int pod_rzad);
void graczvskomputer(int rozmiar, int pod_rzad, int trudnosc);
void komputervskomputer(int rozmiar, int pod_rzad, int trudnosc);
void zakonczRozgrywke(char **tab, int rozmiar);
char ruchGracza(char **&tab, int rozmiar, char gracz, int &aktx, int &akty);
#endif // !ROZGRYWKA_H
