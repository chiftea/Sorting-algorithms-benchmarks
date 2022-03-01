#pragma once
#include <iostream>
#include <vector>
#include "get_max.h"

#define MAXSIZE 100000000
#define MAXVALUE 100000000
#define MAX_INT 2147483647
using std::cin; using std::cout;
using std::vector; using std::endl;
//using namespace std;

void read_base(int& base, int Max)
{
	bool base_err;
	do {
		base_err = 0;
		cout << "base??? : ";
		cin >> base;
		if (base <= 1 or base >= MAX_INT or (base < Max && base >= 46340))
		{
			base_err = 1;
			cout << endl << "ERROR: Base cannot be <= 1,\nbase^2 cannot be bigger than max_int if base is lower than max\n";
		}

	} while (base_err);
}
void countsort(vector<int>& vect, int n, int exp, int base)
{
	vector<int> output(n), count(base, 0);
	int i;

	for (i = 0; i < n; i++)
		count[vect[i] / exp % base]++;

	for (i = 1; i < base; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[(vect[i] / exp) % base] - 1] = vect[i];
		count[(vect[i] / exp) % base] --;
	}

	for (i = 0; i < n; i++)
		vect[i] = output[i];
}
void my_radix(vector<int>& vect, int base) {
	int n = (int) vect.size();
	int m = getMax(vect, n);

	for (int exp = 1; m / exp > 0; exp *= base)
		countsort(vect, n, exp, base);
}

