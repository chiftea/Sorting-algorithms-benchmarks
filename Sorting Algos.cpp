#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <vector>


#include "../radix.h"
#include "../merge.h"

#include "../get_max.h"
#include "../print.h"
#include "../populate_array.h"
#include "../read.h"
#include "Shell.h"
#include "heap.h"
#include "quicksort.h"
#include "draw.h"



using namespace std;
#define MAXSIZE 100000000
#define MAXVALUE 100000000
#define MAX_INT 2147483647




/*  for algorithm:
		for test:
			populate array w/ random numbers following test conditions /-/-/-/
				backup array (without backup-ing the time comparisons between sorting algorithms are irrelevant) /-/-/-/-/
				sort using own algorithm {measure time}
					rollback array or use copy
				sort using default c++ sort {measure time}

*/

//int draw()
//{
//	int i = 0;
//	int sel = 1;
//	int c = 0;
//
//	while (i == 0) {
//		switch (sel)
//		{
//		case 1:
//			system("cls");
//			cout << ">> 1. RadixSort" << "\n";
//			cout << "   2. MergeSort" << "\n";
//			cout << "   3. ShellSort" << "\n";
//			cout << "   4. Heapsort " << "\n";
//			cout << "   5. Quicksort" << "\n";
//			cout << "   6. EXIT     " << "\n";
//			//system("pause");
//			break;
//
//		case 2:
//			system("cls");
//			cout << "   1. RadixSort" << "\n";
//			cout << ">> 2. MergeSort" << "\n";
//			cout << "   3. ShellSort" << "\n";
//			cout << "   4. Heapsort " << "\n";
//			cout << "   5. Quicksort" << "\n";
//			cout << "   6. EXIT     " << "\n";
//			//system("pause");
//			break;
//
//		case 3:
//			system("cls");
//			cout << "   1. RadixSort" << "\n";
//			cout << "   2. MergeSort" << "\n";
//			cout << ">> 3. ShellSort" << "\n";
//			cout << "   4. Heapsort " << "\n";
//			cout << "   5. Quicksort" << "\n";
//			cout << "   6. EXIT     " << "\n";
//			//system("pause");
//			break;
//		case 4:
//			system("cls");
//			cout << "   1. RadixSort" << "\n";
//			cout << "   2. MergeSort" << "\n";
//			cout << "   3. ShellSort" << "\n";
//			cout << ">> 4. Heapsort " << "\n";
//			cout << "   5. Quicksort" << "\n";
//			cout << "   6. EXIT     " << "\n";
//			break;
//		case 5:
//			system("cls");
//			cout << "   1. RadixSort" << "\n";
//			cout << "   2. MergeSort" << "\n";
//			cout << "   3. ShellSort" << "\n";
//			cout << "   4. Heapsort " << "\n";
//			cout << ">> 5. Quicksort" << "\n";
//			cout << "   6. EXIT     " << "\n";
//			break;
//		case 6:
//			system("cls");
//			cout << "   1. RadixSort" << "\n";
//			cout << "   2. MergeSort" << "\n";
//			cout << "   3. ShellSort" << "\n";
//			cout << "   4. Heapsort " << "\n";
//			cout << "   5. Quicksort" << "\n";
//			cout << ">> 6. EXIT     " << "\n";
//		}
//
//		//Sleep(100);
//
//
//		int c = _getch();
//
//		switch (c) {
//		case KEY_UP:
//			sel--;
//			if (sel <= 0) {
//				sel = 6;
//			}
//			break;
//
//		case KEY_DOWN:
//			sel++;
//			if (sel > 6) {
//				sel = 1;
//			}
//			break;
//		case ENTER:
//			i = 1;
//			break;
//		}
//	}
//	return sel;
//}

void print_res(int res, string sort)
{
	std::cout << "Time of " << sort << " sort = " << res << " microseconds"
		<< " or " << (float)res / 1000000 << " seconds" << std::endl;
}

int main()
{	
	ifstream f("input_tests.txt");
	//ifstream f("input_tests2.txt");
	int faster = 0;
	int res1, res2, resultRadix;
	int tests, N, Max, base = 0;
	int res1_micros = 0, res2_micros, res_microseconds = 0, print;
	int dr;
	int a = 0, caz, caz_input;
	float res1_seconds = 0., res2_seconds = 0., res_seconds = 0;
	long long longN, longMax, res_overall = 0;
	vector<int>::iterator first_el, last_el;
	vector<string> algo = { "my_radix" ,"merge_sort","shell_sort", "heapSort" ,"quickSort", "introSort"};
	string filename("output.txt"), results_filename("time_res.txt");
	clean_output(filename);
	clean_output(results_filename);

	//f >> tests;

a:
	caz = draw_main();
	system("cls");
	if (caz == 6) return 0;
	caz_input = draw_manual();
	if (caz_input == 3) return 0;
	system("cls");
	if(caz_input == 2)
	cout << "READING FROM FILE input_tests.txt";
	cout << "Number of tests: ";
	if (caz_input == 2){
		f >> tests;
		cout << tests << " tests\n";
	}
	else
		cin >> tests;
	print = draw_print();
	for (int i = 1; i <= tests; ++i) {
		readSize(longN, longMax, f, caz_input);
		//casting values long long - > int
		N = (int)longN;
		Max = (int)longMax;
		vector<int> vect(N);

		populate_array(vect, N, Max);
		vector<int> vect2 = vect; //backup for second sort

		if(print)
		print_unsorted(vect, N, Max, filename);

		// ###############################            sort using x sort            ###############################

		dr = (int)vect.size() - 1;
		resultRadix = 0;
		vector<int> tmp(vect.size() + 1, 0);

		auto begin1 = std::chrono::high_resolution_clock::now();

		switch (caz) {
		case 1: {
			if(base == 0 or (base < Max && base >= 46340))
			read_base(base, Max);
			auto beginn = std::chrono::high_resolution_clock::now();
			my_radix(vect, base);
			auto endd = std::chrono::high_resolution_clock::now();
			resultRadix = int((chrono::duration_cast<chrono::microseconds>(endd - beginn)).count());
			a = 1; }
			  break;
		case 2: {
			MergeSort(vect, tmp, N, 0, dr);
			a = 2; }
			  break;
		case 3: {
			ShellSort(vect, N);
			a = 3; }
			break;
		case 4: {
			heapSortIterative(vect, N);
			//heapSortRecursive(vect, N);
			a = 4; }
			break;
		case 5: {
			if (N >= 100000){
				cout << "Error: N = " << N << " is too big"; return 0;
			}
			quickSort(vect, 0, N - 1);
			a = 5; }
			break;
		}
		//###############################                  end x sort                   ###############################
		auto end1 = std::chrono::high_resolution_clock::now();
		auto res1 = chrono::duration_cast<chrono::microseconds>(end1 - begin1);
		if (print)
		print_sorted(vect, N, Max, filename);

		//special time calculation for radix_sort
		if (a == 1){
			print_res(resultRadix, algo[a - 1]);
			res1_micros = resultRadix;
			res1_seconds = (float)res1_micros / 1000000;
		}
		else {
			print_res(int(res1.count()), algo[a - 1]);
			res1_micros = (int)res1.count();
			res1_seconds = (float)res1_micros / 1000000;
		}
		//print_unsorted(vect2, N, Max, filename);

		//###############################            sort using (std::sort)            ###############################
		//trying to make the stopwatch more exact by preparing iterators
		first_el = vect2.begin();
		last_el = vect2.end();

		auto begin2 = std::chrono::high_resolution_clock::now();
		std::sort(first_el, last_el);
		auto end2 = std::chrono::high_resolution_clock::now();

		////###############################                  end std::sort                   ###############################
		//print(vect2);
	    //	if (print)
		//print_sorted(vect2, N, Max, filename);

		auto res2 = chrono::duration_cast<chrono::microseconds>(end2 - begin2);
		print_res(int(res2.count()), algo[5]);
		res2_micros = (int)res2.count();
		if (res2_micros > res1_micros) faster = 1;
		else if (res1_micros > res2_micros) faster = 2;
		else faster = 3;
		res2_seconds = (float)res2_micros / 1000000;
		res_microseconds = abs(res1_micros - res2_micros);
		res_overall += long long(res1_micros - res2_micros);
		res_seconds = abs(res1_seconds - res2_seconds);
		//cout << " \n ###########     res_seconds = " << res_seconds << endl;
		print_results(res_microseconds, res_seconds, N, Max, results_filename,
			algo[a - 1], algo[5], faster, tests, i, res_overall);
		
		cout << "##### UNSORTED AND SORTED ARRAYS FOR BOTH ALGORITHMS"
			<< " ARE PRINTED IN THE OUTPUT.TXT FILE #####\n"
			<<"##### TIME RESULTS ARE PRINTED IN THE time_res.txt FILE #####\n\n\n";
	}

	return 0;
}