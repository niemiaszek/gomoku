#pragma once
#ifndef INTERFEJS_H
#define INTERFEJS_H

void menuStart();
void menuGlowne();
void menuPrzedGra();
int pobierzZnak(int zakres_dolny, int zakres_gorny);
void czyscEkran();
void kliknijAbyPrzejscDalej();
void zakonczProgram();
char poruszaniePoPlanszy(char **&tab, int rozmiar, int &aktx, int &akty, char gracz);
void wyswietlPlansze(char **tab, int rozmiar);
void komunikatBladOtwarciaPliku();
void komunikatRezultat(char rezultat);
#endif // INTERFEJS_H
