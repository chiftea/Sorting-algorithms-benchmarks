#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
#define MAXSIZE 100000000
#define MAXVALUE 100000000
#define MAX_INT 2147483647


void readSize(long long& longN, long long& longMax)
{
	bool N_err, Max_err;
	do {
		N_err = 0;
		Max_err = 0;
		cout << "N, Max = ";
		cin >> longN;
		cin >> longMax;
		if (longN > MAXSIZE or longN < 1) {
			N_err = 1;
			cout << "\n### Numarul de elemente (" << longN << ") este prea mare / nul ###\n";
		}
		if (longMax > MAXVALUE or longMax < 1) {
			Max_err = 1;
			cout << "\n### Valoarea maxima (" << longMax << ") este prea mare / nula ###\n";
		}
	} while (N_err == 1 or Max_err == 1);
}