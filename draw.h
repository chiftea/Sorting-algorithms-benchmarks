#pragma once
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

int draw_main(){
	int i = 0;
	int sel = 1;
	int c = 0;

	while (i == 0) {
		switch (sel)
		{
		case 1:
			system("cls");
			cout << ">> 1. RadixSort" << "\n";
			cout << "   2. MergeSort" << "\n";
			cout << "   3. ShellSort" << "\n";
			cout << "   4. Heapsort " << "\n";
			cout << "   5. Quicksort" << "\n";
			cout << "   6. EXIT     " << "\n";
			//system("pause");
			break;

		case 2:
			system("cls");
			cout << "   1. RadixSort" << "\n";
			cout << ">> 2. MergeSort" << "\n";
			cout << "   3. ShellSort" << "\n";
			cout << "   4. Heapsort " << "\n";
			cout << "   5. Quicksort" << "\n";
			cout << "   6. EXIT     " << "\n";
			//system("pause");
			break;

		case 3:
			system("cls");
			cout << "   1. RadixSort" << "\n";
			cout << "   2. MergeSort" << "\n";
			cout << ">> 3. ShellSort" << "\n";
			cout << "   4. Heapsort " << "\n";
			cout << "   5. Quicksort" << "\n";
			cout << "   6. EXIT     " << "\n";
			//system("pause");
			break;
		case 4:
			system("cls");
			cout << "   1. RadixSort" << "\n";
			cout << "   2. MergeSort" << "\n";
			cout << "   3. ShellSort" << "\n";
			cout << ">> 4. Heapsort " << "\n";
			cout << "   5. Quicksort" << "\n";
			cout << "   6. EXIT     " << "\n";
			break;
		case 5:
			system("cls");
			cout << "   1. RadixSort" << "\n";
			cout << "   2. MergeSort" << "\n";
			cout << "   3. ShellSort" << "\n";
			cout << "   4. Heapsort " << "\n";
			cout << ">> 5. Quicksort" << "\n";
			cout << "   6. EXIT     " << "\n";
			break;
		case 6:
			system("cls");
			cout << "   1. RadixSort" << "\n";
			cout << "   2. MergeSort" << "\n";
			cout << "   3. ShellSort" << "\n";
			cout << "   4. Heapsort " << "\n";
			cout << "   5. Quicksort" << "\n";
			cout << ">> 6. EXIT     " << "\n";
		}

		//Sleep(100);


		int c = _getch();

		switch (c) {
		case KEY_UP:
			sel--;
			if (sel <= 0) {
				sel = 6;
			}
			break;

		case KEY_DOWN:
			sel++;
			if (sel > 6) {
				sel = 1;
			}
			break;
		case ENTER:
			i = 1;
			break;
		}
	}
	return sel;
}

int draw_manual() {
	int i = 0;
	int sel = 1;
	int c = 0;

	while (i == 0) {
		switch (sel)
		{
		case 1:
			system("cls");
			cout << ">> KEYBOARD_INPUT" << "\n"
			     << "   FILE_INPUT    " << "\n"
			     << "   EXIT          " << "\n";
			//system("pause");
			break;

		case 2:
			system("cls");
			cout << "   KEYBOARD_INPUT" << "\n"
			     << ">> FILE_INPUT    " << "\n"
			     << "   EXIT          " << "\n";
			//system("pause");
			break;

		case 3:
			system("cls");
			cout << "   KEYBOARD_INPUT" << "\n"
			     << "   FILE_INPUT    " << "\n"
			     << ">> EXIT          " << "\n";
			//system("pause");
			break;
		}

		//Sleep(100);


		int c = _getch();

		switch (c) {
		case KEY_UP:
			sel--;
			if (sel <= 0) {
				sel = 3;
			}
			break;

		case KEY_DOWN:
			sel++;
			if (sel > 3) {
				sel = 1;
			}
			break;
		case ENTER:
			i = 1;
			break;
		}
	}
	return sel;
}
int draw_print() {
	int i = 0;
	int sel = 1;
	int c = 0;

	while (i == 0) {
		switch (sel)
		{
		case 0:
			system("cls");
			cout << " PRINT UNSORTED AND SORTED ARRAYS" << "\n"
				 << " IN OUTPUT.TXT FILE ?            " << "\n\n"
				 << "     >> DON'T PRINT (FASTER)     " << "\n"
				 << "        PRINT       (SLOWER)     " << "\n";
			//system("pause");
			break;

		case 1:
			system("cls");
			cout << " PRINT UNSORTED AND SORTED ARRAYS" << "\n"
				 << " IN OUTPUT.TXT FILE ?            " << "\n\n"
				 << "        DON'T PRINT (FASTER)     " << "\n"
				 << "     >> PRINT       (SLOWER)     " << "\n";
			//system("pause");
			break;
		}

		//Sleep(100);


		int c = _getch();

		switch (c) {
		case KEY_UP:
			sel--;
			if (sel < 0) {
				sel = 1;
			}
			break;

		case KEY_DOWN:
			sel++;
			if (sel > 1) {
				sel = 0;
			}
			break;
		case ENTER:
			i = 1;
			break;
		}
	}
	return sel;
}