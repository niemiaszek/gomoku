#pragma once
#ifndef ROZGRYWKA_H
#define ROZGRYWKA_H
void graczvsgracz(int rozmiar, int pod_rzad);
void graczvskomputer();
void komputervskomputer();
void zakonczRozgrywke(char **tab, int rozmiar);
char ruchGracza(char **&tab, int rozmiar, char gracz);
#endif // !ROZGRYWKA_H
