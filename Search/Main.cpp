#include "Sort.h"
#include "Search.h"
#include <string>
#include<ctime>
#include <stdio.h>
#include <time.h>
using namespace std;

template<class t>
void out(t arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << "   ";
	}
	std::cout << std::endl;
}

template<class t>
void Rand(t arr[], int len)
{
	for (unsigned i = 0; i < len; i++)
	{
		arr[i] = (-1000 + rand() % 2000);
	}
}

void Tests(int Length)
{
	int* Test = new int[Length];


	cout << "Wait))" << endl;
	Rand(Test, Length);
	cout << "SequenceSearch - -1 for (" << Length << " elements)" << endl;
	unsigned int start = clock();
	cout << "Index: " << SeqSearch(Test, Length, -1) << endl;
	unsigned int end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << 'c';
	cout << endl << endl << endl << endl;

	cout << "Wait))" << endl;
	QuickSort(Test, 0, Length - 1);
	cout << "BinSearch - -1 for (" << Length << " elements)" << endl;
	start = clock();
	cout << "Index: " << BinSearch(Test, 0, Length - 1, -1) << endl;
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << 'c';
	cout << endl << endl << endl << endl;

	cout << "Wait))" << endl;
	cout << "AllocSearch - -1 for (" << Length << " elements)" << endl;
	start = clock();
	cout << "Index: " << AllocSearch(Test, Length, Test[0], Test[Length - 1], -1) << endl;
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << 'c';
	cout << endl << endl << endl << endl;
}



int main()
{
	int Length = 10;
	int A[] = { 12, 5, 2, 5, 23, 65, 2, 0, 2, 32 };
	string searchStr;
	int search = 0;

	cout << "SequenceSearch" << endl;
	out(A, Length);
	while (searchStr != "-1")
	{
		cout << "Search: ";
		cin >> searchStr;
		search = stoi(searchStr);
		cout << "Index: " << SeqSearch(A, Length, search) << endl;

		cout << "Stop: -1" << endl;
	}

	cout << "BinSearch" << endl;
	QuickSort(A, 0, Length - 1);
	out(A, Length);
	searchStr = "";
	while (searchStr != "-1")
	{
		cout << "Search - ";
		cin >> searchStr;
		search = stoi(searchStr);
		cout << "Index - " << BinSearch(A, 0, Length - 1, search) << endl;

		cout << "Stop: -1" << endl;
	}

	cout << "AllocSearch" << endl;
	out(A, Length);
	searchStr = "";
	while (searchStr != "-1")
	{
		cout << "Search - ";
		cin >> searchStr;
		search = stoi(searchStr);
		cout << "Index - " << AllocSearch(A, Length, A[0], A[Length - 1], search) << endl;

		cout << "Stop: -1" << endl;
	}

	cout << endl << endl << endl << endl;

	Tests(10000);

	system("pause");
	return 0;
}