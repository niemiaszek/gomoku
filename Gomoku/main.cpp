/**
* \mainpage
* \par Kó³ko krzy¿yk
* Program do rozgrywania parti gry kó³ko i krzy¿yk (i pochodnych) miêdzy graczami lub z komputerem
* \author Patryk Niemiec
* \date 2019.05.31
* \version 1.0
* \par Kontakt:
* \a niemiecpatryk@outlook.com
*/

/**
 * \file main.cpp
 * \brief Plik z funkcj¹ main(), dodatkowo seeduje rand
 */

#include "interfejs.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
	srand(time(NULL));
	menuStart();
}