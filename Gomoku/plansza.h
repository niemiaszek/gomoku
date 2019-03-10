#pragma once
#ifndef PLANSZA_H
#define PLANSZA_H

void utworzPlansze(char **&tab, int rozmiar);
void wyswietlPlansze(char **tab, int rozmiar);
void kasujPlansze(char **tab, int rozmiar);
char ruchGracza(char **&tab, int rozmiar, char gracz);
char poruszaniePoPlanszy(char **&tab, int rozmiar, int &aktx, int &akty, char gracz);
#endif // PLANSZA_H
