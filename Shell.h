#pragma once
#include <vector>
using std::vector;

void ShellSort(vector<int>& vect, int n)
{
	int i, j, temp;
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < n; i++)
		{
			temp = vect[i];
			for (j = i; j >= gap && vect[j - gap] > temp; j -= gap)
				vect[j] = vect[j - gap];
			vect[j] = temp;
		}
	}
}