#pragma once
#include <vector>
#include "radix.h"
using namespace std;

int getMax(vector<int>& vect, int n)
{
	int mx = vect[0];
	for (int i = 1; i < n; ++i)
		if (vect[i] > mx)
			mx = vect[i];
	return mx;
}