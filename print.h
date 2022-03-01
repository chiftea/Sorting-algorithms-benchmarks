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
	g << "UNSORTED ARRAY OF " << N << " ELEMENTS AND A MAX VALUE OF " << Max << "\n\n\n\n\n";
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