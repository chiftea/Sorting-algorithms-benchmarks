#pragma once

#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;


int partition(vector<int>& vect, int low, int high)
{

    int pivot = vect[low + rand() % (high - low)];
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++)
    {
        if (vect[j] < pivot)
        {
            i++; 
            swap(vect[i], vect[j]);
        }
    }
    swap(vect[i + 1], vect[high]);
    return (i + 1);
}

void quickSort(vector<int>& vect, int low, int high)
{
    if (low < high)
    {
        int pi = partition(vect, low, high);
        quickSort(vect, low, pi - 1);
        quickSort(vect, pi + 1, high);
    }
}
