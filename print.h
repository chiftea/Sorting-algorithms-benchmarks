#pragma once
#include <vector>
#include <fstream>
#include <string>
//using namespace std;
using std::string; using std::ofstream;
using std::vector;

void clean_output(string filename)
{
	ofstream g(filename);
	g << "";
}
void print_unsorted(vector<int>& vect, int N, int Max, string filename = "output.txt")
{
	ofstream g;
	g.open(filename, std::ios_base::app);
	g << "\n\n\n";
	g << "######  UNSORTED ARRAY OF " << N << " ELEMENTS AND A MAX VALUE OF " << Max << "\n\n\n\n\n";
	for (auto i : vect)
		g << i << " ";
	g << "\n\n\n";
	g.close();
}
void print_sorted(vector<int>& vect, int N, int Max, string filename = "output.txt")
{
	ofstream g;
	g.open(filename, std::ios_base::app);
	g << "\n\n\n";
	g << "######  SORTED ARRAY OF " << N << " ELEMENTS AND A MAX VALUE OF " << Max << "\n\n\n\n\n";
	for (auto i : vect)
		g << i << " ";
	g << "\n\n\n";
	g.close();
}
void print_results(int res_int, float res_float, int N, int Max,
	string filename, string mySort, string introSort, int faster, 
	int tests, int i, long long res_overall) {
	ofstream g;
	g.open(filename, std::ios_base::app);
	
	if (faster == 1) {
		g << "For N = "<< N << " and Max = "<< Max  << " " << mySort
			<<" is faster than " << introSort << " by " << res_float << " seconds or "
			<< res_int << " microseconds" << "\n";
	}
	else  if (faster == 2){
		g << "For N = " << N << " and Max = " << Max << " " << introSort
			<< " is faster than " << mySort << " by " << res_float << " seconds or "
			<< res_int << " microseconds" << "\n";
	}
	else {
		g << "For N = " << N << " and Max = " << Max << " " << mySort
			<< " is as fast as " << introSort << "\n";
	}
	if (tests == i) {
		// res1_overall < res2_overall  so introSort takes more time than mySort
		if (res_overall < 0)
			g <<"On these tests " << mySort << " is overall faster than " << introSort
			<< " by " << abs(res_overall) << " microseconds or " << (float) abs(res_overall) / 1000000 << " seconds";
		else
			g << "On these tests " << introSort << " is overall faster than " << mySort
			<< " by " << res_overall << " microseconds or " << (float)res_overall / 1000000 << " seconds";
	}
	g.close();
}