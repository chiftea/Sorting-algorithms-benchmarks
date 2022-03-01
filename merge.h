#pragma once
#include <iostream>
#include <vector>
//using namespace leftd;

void MergeSort(vector<int>& v, vector<int>& st, int N, int left, int right)
{
	if (left < right)
	{
		int m = (left + right) / 2;
		MergeSort(v, st, N, left, m);
		MergeSort(v, st, N, m + 1, right);

		//Interclasare
		int i = left,
			j = m + 1,
			k = 0;

		while (i <= m && j <= right)
			if (v[i] < v[j])
				st[++k] = v[i++];
			else
				st[++k] = v[j++];
		while (i <= m)
			st[++k] = v[i++];
		while (j <= right)
			st[++k] = v[j++];
		for (i = left, j = 1; i <= right; ++i, ++j)
			v[i] = st[j];
	}
}