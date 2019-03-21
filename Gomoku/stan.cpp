#include "stan.h"
using namespace std;
char sprawdzStan(char **tab, int rozmiar, int pod_rzad) 
{
	if (sprawdzPion(tab, rozmiar, pod_rzad) == 'W' || sprawdzPoziom(tab, rozmiar, pod_rzad) == 'W' || sprawdzUkosy(tab, rozmiar, pod_rzad) == 'W' || SprawdzRemis(tab, rozmiar) == 'W')
		return 'W';
	else if(SprawdzRemis(tab, rozmiar) == 'R')
		return 'R';
	else return 'N';
}
char sprawdzPoziom(char **tab, int rozmiar, int pod_rzad) 
{
	int i, j, l; // l jako licznik pol zajetych przez danego gracza pod rzad
	for (i = 0; i < rozmiar; i++) { // sprawdzanie w kazdym wierszu tablicy
		l = 0;
		for (j = 0; j < rozmiar; j++)
		{
			if (j == 0 && tab[i][j] != ' ') // sprawdzanie, czy dane pole jest pierwszym polem z brzegu i czy dane pole jest zmienione przez gracza
				l++;
			if (j > 0 && tab[i][j - l] == tab[i][j] && tab[i][j] != ' ') // sprawdzanie, czy poprzednie pole jest rowne aktualnemu polu
				l++;
			else if (j > 0 && tab[i][j - 1] != tab[i][j]) // sprawdzanie, czy poprzednie pole jest rozne od aktualnego pola
				l = 0; // zerowanie licznika, bo taka sytuacja zachodzi, kiedy pole jest niezmienione lub zajete przez innego gracza
			if (j > 0 && l == 0 && tab[i][j] != ' ') // sprawdzanie, czy aktualne pole jest w ogole zajete przez jakiegos gracza
				l++;
			if (l == pod_rzad) // sprawdzanie, czy gracz zajal liczbe pol pod rzad potrzebna do wygranej
			{
				if (j == rozmiar - 1) // warunek brzegowy, kiedy za aktualnym polem nie ma juz zadnego pola, ktore moglby zajac dany gracz przekraczajac liczbe 5 pol i w ten sposob niespelniajac warunku koniecznego do granej (dokladnie 5 pol pod rzad)
					return 'W'; // zwracanie napisu "wygrana", ktory jest wykorzystywany pozniej
				else if (tab[i][j + 1] != tab[i][j - 1]) // sprawdzanie, czy pole za akutalnym jest rowne polu po aktualnym, zeby wykluczyc sytuacje, w ktorej gracz osiagnal wiecej niz 5 w rzedzie
					return 'W';
			}
		}
	}
	return 'N';
}
char sprawdzPion(char **tab, int rozmiar, int pod_rzad) 
{
	int i, j, l;
	for (j = 0; j < rozmiar; j++) // sprawdzanie w kazdej kolumnie tablicy
	{ 
		l = 0;
		for (i = 0; i < rozmiar; i++)
		{
			if (i == 0 && tab[i][j] != ' ')
				l++;
			if (i > 0 && tab[i - 1][j] == tab[i][j] && tab[i][j] != ' ')
				l++;
			else if (i > 0 && tab[i - 1][j] != tab[i][j])
				l = 0;
			if (i > 0 && l == 0 && tab[i][j] != ' ')
				l++;
			if (l == pod_rzad)
			{
				if (i == rozmiar - 1)
					return 'W';
				else if (tab[i + 1][j] != tab[i - 1][j])
					return 'W';
			}
		}
	}
	return 'N';
}
char sprawdzUkosy(char **tab, int rozmiar, int pod_rzad) 
{
	int i, j, l;
	for (i = 0; i < rozmiar; i++) // sprawdzanie po skosach rownoleglych do skosu ([14][0], [0][14]), lewa strona, od dolu do gory
	{
		l = 0;
		for (j = 0; j <= i; j++)
		{
			if (j == 0 && tab[i - j][j] != ' ')
				l++;
			if (j > 0 && tab[i + 1 - j][j - 1] == tab[i - j][j] && tab[i - j][j] != ' ')
				l++;
			else if (j > 0 && tab[i + 1 - j][j - 1] != tab[i - j][j])
				l = 0;
			if (j > 0 && l == 0 && tab[i - j][j] != ' ')
				l++;
			if (l == pod_rzad)
			{
				if (j == i && i != 0)
					return 'W';
				else if (tab[i + 1 - j][j + 1] != tab[i + 1 - j][j - 1])
					return 'W';
			}
		}
	}

	for (i = 0; i < rozmiar; i++) // sprawdzanie po skosach rownoleglych do skosu ([14][0], [0][14]), prawa strona, od gory do dolu
	{
		l = 0;
		for (j = rozmiar - 1; j >= i; j--)
		{
			if (j == rozmiar - 1 && tab[rozmiar - 1 - j + i][j] != ' ')
				l++;
			if (j < rozmiar - 1 && tab[rozmiar - 1 - j + i][j] == tab[rozmiar - 1 - j - 1 + i][j + 1] && tab[rozmiar - 1 - j + i][j] != ' ')
				l++;
			else if (j < rozmiar - 1 && tab[rozmiar - 1 - j - 1 + i][j + 1] != tab[rozmiar - 1 - j + i][j])
				l = 0;
			if (j < rozmiar - 1 && l == 0 && tab[rozmiar - 1 - j + i][j] != ' ')
				l++;
			if (l == pod_rzad)
			{
				if (j == i)
					return 'W';
				else if (tab[rozmiar - 1 - j - 1 + i][j + 1] != tab[rozmiar - 1 - j + 1 + i][j - 1])
					return 'W';
			}
		}
	}
	for (i = 0; i < rozmiar; i++) // sprawdzanie po skosach rownoleglych do skosu ([0][0], [14][14]), lewa strona, od gory do dolu
	{
		l = 0;
		for (j = 0; j < rozmiar - i; j++)
		{
			if (j == 0 && tab[i + j][j] != ' ')
				l++;
			if (j > 0 && tab[i + j - 1][j - 1] == tab[i + j][j] && tab[i + j][j] != ' ')
				l++;
			else if (j > 0 && tab[i + j - 1][j - 1] != tab[i + j][j])
				l = 0;
			if (j > 0 && l == 0 && tab[i + j][j] != ' ')
				l++;
			if (l == pod_rzad)
			{
				if ((i+j+1)==rozmiar)
					return 'W';
				else if (tab[i + j + 1][j + 1] != tab[i + j - 1][j - 1])
					return 'W';
			}
		}
	}
	for (j = 0; j < rozmiar; j++) // sprawdzanie po skosach rownoleglych do skosu ([0][0], [14][14]), prawa strona, od gory do dolu
	{
		l = 0;
		for (i = 0; i < rozmiar - j; i++)
		{
			if (i == 0 && tab[i][j + i] != ' ')
				l++;
			if (i > 0 && tab[i - 1][j + i - 1] == tab[i][j + i] && tab[i][j + i] != ' ')
				l++;
			else if (i > 0 && tab[i - 1][j + i - 1] != tab[i][j + i])
				l = 0;
			if (i > 0 && l == 0 && tab[i][j + i] != ' ')
				l++;
			if (l == pod_rzad)
			{
				if (i == j)
					return 'W';
				else if (tab[i + 1][j + i + 1] != tab[i - 1][j + i - 1])
					return 'W';
			}
		}
	}
	return 'N';
}
char SprawdzRemis(char **tab, int rozmiar) 
{
	int i, j;
	bool puste = false;
	for (i = 0; i < rozmiar; i++) 
		for(j=0; j<rozmiar; j++)
			if (tab[i][j] == ' ')
				puste = true;
	if (puste == true)
		return 'N';
	if (puste == false)
		return 'R';
}