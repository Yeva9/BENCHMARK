#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <map>
#include <string>
#include <iomanip>
#include "../include/BenchmarkTable.hpp"
#include "../include/Timer.hpp"
#include "../include/ExternFunctions.hpp"

typedef long long ll;

using namespace std;

void RunAllArtaxiadAlgorithms(int*, int, const int&);

void RunAllArshakidAlgorithms(int*, int, const int&);

void RunAllBagratidAlgorithms(int*, int, const int&);

void RunAllRubenidAlgorithms(int*, int, const int&);

int*  GenerateRandomArray(int);

void CheckInputs(int, char**, int&, int&);

void RunFunctions(int*, int, int);

int main(int argc, char** argv) {
	srand(time(0));
	int size;
	int test_count;
	
	try {
		CheckInputs(argc, argv, size, test_count);
		int* array = GenerateRandomArray(size);
		RunFunctions(array, size, test_count);
	}
	catch (const char* message) {
		cout << message << endl;
	}
	return 0;
}

void RunAllArtaxiadAlgorithms(int* array, int size, const int& test_count) {
    BenchmarkTable table(test_count);
	cout << "\nArtaxiad team algorithms: ";
	try {
		table.Run(BubbleSortByArtaxiad, size, array, "Bubble");
		table.Run(QuickSortByArtaxiad, size, array, "Quick");
		table.Run(MergeSortByArtaxiad, size, array, "Merge");
		table.Run(HeapSortByArtaxiad, size, array, "Heap");
		table.Run(InsertionSortByArtaxiad, size, array, "Insertion");
		table.Run(SelectionSortByArtaxiad, size, array, "Selection");
		table.Run(ShellSortByArtaxiad, size, array, "Shell");
	} catch(const string message) {
		cout << message << endl;
		return;
	}
    table.PrintTable();
}

void RunAllArshakidAlgorithms(int* array, int size, const int& test_count) {
    BenchmarkTable table(test_count);
	cout << "\nArshakid team algorithms: ";
	try {
		table.Run(BubbleSortByArshakid, size, array, "Bubble");
		table.Run(QuickSortByArshakid, size, array, "Quick");
		table.Run(MergeSortByArshakid, size, array, "Merge");
		table.Run(HeapSortByArshakid, size, array, "Heap");
		table.Run(InsertionSortByArshakid, size, array, "Insertion");
		table.Run(SelectionSortByArshakid, size, array, "Selection");
		table.Run(ShellSortByArshakid, size, array, "Shell");
	} catch(const string message) {
		cout << message << endl;
		return;
	}
    table.PrintTable();
}

void RunAllBagratidAlgorithms(int* array, int size, const int& test_count) {
    BenchmarkTable table(test_count);
	cout << "\nBagratid team algorithms: ";
	try {
		table.Run(BubbleSortByBagratid, size, array, "Bubble");
		table.Run(QuickSortByBagratid, size, array, "Quick");
		table.Run(MergeSortByBagratid, size, array, "Merge");
		table.Run(HeapSortByBagratid, size, array, "Heap");
		table.Run(InsertionSortByBagratid, size, array, "Insertion");
		table.Run(SelectionSortByBagratid, size, array, "Selection");
		table.Run(ShellSortByBagratid, size, array, "Shell");
	} catch(const string message) {
		cout << message << endl;
		return;
	}
    table.PrintTable();
}

void RunAllRubenidAlgorithms(int* array, int size, const int& test_count) {
    BenchmarkTable table(test_count);
	cout << "\nRubenid team algorithms: ";
	try {
		table.Run(BubbleSortByRubenid, size, array, "Bubble");
		table.Run(QuickSortByRubenid, size, array, "Quick");
		table.Run(MergeSortByRubenid, size, array, "Merge");
		table.Run(HeapSortByRubenid, size, array, "Heap");
		table.Run(InsertionSortByRubenid, size, array, "Insertion");
		table.Run(SelectionSortByRubenid, size, array, "Selection");
		table.Run(ShellSortByRubenid, size, array, "Shell");
	} catch(const string message) {
		cout << message << endl;
		return;
	}
    table.PrintTable();
}

int*  GenerateRandomArray(int size) {
    int* array = new int[size];
	for (int i = 0; i < size; ++i) {
		array[i] = rand() % 100000;
	}
    return array;
}

void CheckInputs(int argc, char** argv, int& size, int& test_count) {
	if (argc < 2 || atoi(argv[1]) <= 0) {
		throw "Error, no input size!";
	}
	if (atoi(argv[1]) > 10000) {
		std::cout << "Please wait....." << std::endl;
	}
	size = atoi(argv[1]);
	test_count = argc < 3 || atoi(argv[2]) <= 0 ? 3 : min(3, atoi(argv[2]));
}

void RunFunctions(int* array, int size, int test_count) {
	RunAllArtaxiadAlgorithms(array, size, test_count);
	RunAllArshakidAlgorithms(array, size, test_count);
    RunAllBagratidAlgorithms(array, size, test_count);
	RunAllRubenidAlgorithms(array, size, test_count);
}
