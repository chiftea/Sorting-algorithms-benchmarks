#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <vector>

#include "radix.h"
#include "merge.h"

#include "get_max.h"
#include "print.h"
#include "populate_array.h"
#include "read.h"
#include "Shell.h"
#include "heap.h"
#include "quicksort.h"



using namespace std;
#define MAXSIZE 100000000
#define MAXVALUE 100000000
#define MAX_INT 2147483647
//void countsort(vector<int>& vect, int n, int exp, int base);
//void my_radix(vector<int>& vect, int base);

//void populate_array(vector<int>& vect, int arr_size = 1000, int max_val = 100000)
//{
//	//mersene twister (random device seed)  + uniform int distribution
//	std::random_device rd;
//	std::mt19937 mt(rd());
//	std::uniform_int_distribution<int> gen(0, max_val);
//
//	/*for (int i = 0; i < 16; ++i)
//		std::cout << dist(mt) << "\n";*/
//
//	for (int i = 0; i < arr_size; ++i)
//		vect[i] = gen(mt);
//}

//int getMax(vector<int>& vect, int n)
//{
//	int mx = vect[0];
//	for (int i = 1; i < n; ++i)
//		if (vect[i] > mx)
//			mx = vect[i];
//	return mx;
//}



//void print(vector<int>& vect)
//{
//	for (int i = 0; i < vect.size(); i++)
//		cout << i << " ";
//	cout << endl << endl;
//}


/*  for algorithm:
		for test:
			populate array w/ random numbers following test conditions /-/-/-/
				backup array (without backup-ing the time comparisons between sorting algorithms are irrelevant) /-/-/-/-/
				sort using own algorithm {measure time}
					rollback array or use copy
				sort using default c++ sort {measure time}

*/



void print_res(int res, string sort)
{
	std::cout << "Time of " << sort << " sort = " << res << " microseconds"
		<< " or " << (float)res / 1000000 << " seconds" << std::endl;
}

int main()
{
	//ifstream f("input_tests.txt");

	int tests;
	int res1, res2;
	int N;
	int Max;
	int base;
	long long longN, longMax;
	vector<int>::iterator first_el, last_el;
	string filename("output.txt");
	clean_output(filename);

	//f >> tests;
	cout << "Number of tests: ";
	cin >> tests;


	for (int i = 1; i <= tests; ++i) {

		//reads n0 of elements + max element
		readSize(longN, longMax);

		//casting values long long - > int
		N = (int)longN;
		Max = (int)longMax;
		vector<int> vect(N);

		//generates array of N elements with a max value Max
		populate_array(vect, N, Max);
		vector<int> vect2 = vect; //backup for second sort


		print_unsorted(vect, N, Max, filename);

		// ###############################            sort x sort            ###############################

		//read_base(base, Max);
		vector<int> tmp(vect.size() + 1, 0);
		int dr = (int)vect.size() - 1;
		auto begin1 = std::chrono::high_resolution_clock::now();
		//my_radix(vect, base);
		//MergeSort(vect, tmp, N, 0, dr);
		//ShellSort(vect, N);
		//heapSortIterative(vect, N);
		//heapSortRecursive(vect, N);
		quickSort(vect, 0, N - 1);
		auto end1 = std::chrono::high_resolution_clock::now();
		//###############################                  end sort                   ###############################

		print_sorted(vect, N, Max, filename);

		auto res1 = chrono::duration_cast<chrono::microseconds>(end1 - begin1);
		//res1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1).count();

		vector<string> algo(6);
		algo[0] = "my_radix";
		algo[1] = "merge_sort";
		algo[2] = "shell_sort";
		algo[3] = "heapSort";
		algo[4] = "ceva";
		algo[5] = "std::sort";
		print_res(int(res1.count()), algo[0]);

		//print_unsorted(vect2, N, Max, filename);

		//###############################            sort using (std::sort)            ###############################
		//trying to make the stopwatch more exact by preparing iterators
		first_el = vect2.begin();
		last_el = vect2.end();

		auto begin2 = std::chrono::high_resolution_clock::now();
		std::sort(first_el, last_el);
		auto end2 = std::chrono::high_resolution_clock::now();

		////###############################                  end sort                   ###############################
		//print(vect2);
		//print_sorted(vect2, N, Max, filename);

		auto res2 = chrono::duration_cast<chrono::microseconds>(end2 - begin2);
		print_res(int(res2.count()), algo[5]);
		cout << "##### UNSORTED AND SORTED ARRAYS FOR BOTH ALGORITHMS"
			<< " ARE PRINTED IN THE OUTPUT.TXT FILE #####\n\n\n";
	}
	return 0;
}