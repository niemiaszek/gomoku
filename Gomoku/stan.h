#pragma once
#ifndef STAN_H
#define STAN_H
char sprawdzStan(char **tab, int rozmiar, int pod_rzad, int &suma);
char sprawdzPion(char **tab, int rozmiar, int pod_rzad, int &suma);
char sprawdzPoziom(char **tab, int rozmiar, int pod_rzad, int &suma);
char sprawdzUkosy(char **tab, int rozmiar, int pod_rzad, int &suma);
char SprawdzRemis(char **tab, int rozmiar);
#endif // !STAN_H
