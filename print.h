#pragma once
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& vect)
{
	for (int i = 0; i < vect.size(); i++)
		cout << i << " ";
	cout << endl << endl;
}