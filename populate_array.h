#pragma once
#include <iostream>
#include <vector>
//using namespace std;
void populate_array(std::vector<int>& vect, int arr_size = 1000, int max_val = 100000)
{
	//mersene twister (random device seed)  + uniform int distribution
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> gen(0, max_val);

	/*for (int i = 0; i < 16; ++i)
		std::cout << dist(mt) << "\n";*/

	for (int i = 0; i < arr_size; ++i)
		vect[i] = gen(mt);
}