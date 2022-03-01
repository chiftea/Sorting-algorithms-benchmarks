#pragma once
#include <vector>
#include "radix.h"
//BUBA 
using std::vector;

int getMax(vector<int>& vect, int n)
{
	int Max = vect[0];
	for (int i = 1; i < n; ++i)
		if (vect[i] > Max)
			Max = vect[i];
	return Max;
}