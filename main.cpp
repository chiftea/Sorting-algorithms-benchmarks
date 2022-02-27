#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <vector>

#include "../radix.h"
#include "../getmax.h"
#include "../print.h"
#include "../pop_arr.h"
#include "../read.h"

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

void print_unsorted(vector<int> vect,int N,int Max)
{
	ofstream g("output.txt");
	g << "UNSORTED ARRAY OF " << N << " ELEMENTS AND A MAX VALUE OF " << Max <<"\n\n\n\n\n";
		for (auto i : vect)
			g << i << " ";
		g << "\n\n\n";
		g.close();
}
void print_sorted(vector<int> vect, int N, int Max)
{
	ofstream g("output.txt");
	g << "######  SORTED ARRAY OF " << N << " ELEMENTS AND A MAX VALUE OF " << Max << "\n\n\n\n\n";
	for (auto i : vect)
		g << i << " ";
	g << "\n\n\n";
	g.close();
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

	//f >> tests;

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

		print_unsorted(vect, N, Max);
		
		// ###############################            sort using radix sort            ###############################
		
		read_base(base, Max);
		auto begin1 = std::chrono::high_resolution_clock::now();
		my_radix(vect, base);
		auto end1 = std::chrono::high_resolution_clock::now();
		//print(vect);

		print_sorted(vect, N, Max);

		auto res1 = chrono::duration_cast<chrono::microseconds>(end1 - begin1);
		//res1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1).count();

		std::cout << "Time of my_radix sort = " << res1.count() << " microseconds"
			<< " or " << (float)res1.count() / 1000000 << " seconds" << std::endl;


		print_unsorted(vect2, N, Max);

		//###############################            sort using (std::sort)            ###############################
		//trying to make the stopwatch more exact by preparing iterators
		first_el = vect2.begin();
		last_el = vect2.end();

		auto begin2 = std::chrono::high_resolution_clock::now();
		std::sort(first_el, last_el);
		auto end2 = std::chrono::high_resolution_clock::now();


		//print(vect2);
		print_sorted(vect2, N, Max);

		auto res2 = chrono::duration_cast<chrono::microseconds>(end2 - begin2);
		std::cout << "Time of default c++ std::sort = " << res2.count() << " microseconds"
			<< " or " << (float)res2.count() / 1000000 << " seconds" << std::endl;
		cout << "##### UNSORTED AND SORTED ARRAYS FOR BOTH ALGORITHMS"
			<< " ARE PRINTED IN THE OUTPUT.TXT FILE #####\n\n\n";


	}

	return 0;
}
