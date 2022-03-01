#pragma once

#include <vector>
using std::vector; using std::swap;

void buildMaxHeap(vector<int>& vect, int n)
{
	for (int i = 1; i < n; i++) {
		if (vect[i] > vect[(i - 1) / 2]) {
			int j = i;
			while (vect[j] > vect[(j - 1) / 2]) {
				swap(vect[j], vect[(j - 1) / 2]);
				j = (j - 1) / 2;
			}
		}
	}
}
void heapify(vector<int>& vect, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && vect[l] > vect[largest])
		largest = l;

	if (r < n && vect[r] > vect[largest])
		largest = r;

	if (largest != i) {
		swap(vect[i], vect[largest]);

		heapify(vect, n, largest);
	}
}

void heapSortRecursive(vector<int>& vect, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(vect, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(vect[0], vect[i]);
		heapify(vect, i, 0);
	}
}
void heapSortIterative(vector<int>& vect, int n)
{
	buildMaxHeap(vect, n);

	for (int i = n - 1; i > 0; i--)
	{
		swap(vect[0], vect[i]);
		int j = 0, index;

		do {
			index = (2 * j + 1);

			if (index < (i - 1) &&
				vect[index] < vect[index + 1])
				index++;

			if (index < i && vect[j] < vect[index])
				swap(vect[j], vect[index]);

			j = index;

		} while (index < i);
	}
}