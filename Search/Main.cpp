#include "Sort.h"
#include "Search.h"
#include <string>
#include<ctime>
#include <stdio.h>
#include <time.h>
#include <fstream>
using namespace std;

template<class t>
void Rand(t arr[], int len)
{
	for (unsigned i = 0; i < len; i++)
	{
		arr[i] = (-1000 + rand() % 2000);
	}
}

void Tests(int Length, string nameFile)
{
	int* Test = new int[Length];

	ofstream file;
	file.open(nameFile);

	file << "Wait))" << "\n";
	Rand(Test, Length);
	file << "SequenceSearch - -1 for (" << Length << " elements)" << "\n";
	unsigned int start = clock();
	file << "Index: " << SeqSearch(Test, Length, -1) << "\n";
	unsigned int end = clock();
	file << (double)(end - start) / CLOCKS_PER_SEC << 'c';
	file << "\n" << "\n" << "\n" << "\n";

	file << "Wait))" << "\n";
	QuickSort(Test, 0, Length - 1);
	file << "BinSearch - -1 for (" << Length << " elements)" << "\n";
	start = clock();
	file << "Index: " << BinSearch(Test, 0, Length - 1, -1) << "\n";
	end = clock();
	file << (double)(end - start) / CLOCKS_PER_SEC << 'c';
	file << "\n" << "\n" << "\n" << "\n";

	file << "Wait))" << "\n";
	file << "AllocSearch - -1 for (" << Length << " elements)" << "\n";
	start = clock();
	file << "Index: " << AllocSearch(Test, Length, Test[0], Test[Length - 1], -1) << "\n";
	end = clock();
	file << (double)(end - start) / CLOCKS_PER_SEC << 'c';
	file << "\n" << "\n" << "\n" << "\n";
}



int main()
{
	int len = 10;
	int A[] = { 12, 5, 2, 5, 23, 65, 2, 0, 2, 32 };
	string searchStr;
	int search = 0;

	ofstream file;
	file.open("Tests.txt");

	for (int i = 0; i < len; i++)
	{
		file << A[i] << "   ";
		cout << A[i] << "   ";
	}
	file << "\n";
	cout << "\n";

	file << "SequenceSearch" << "\n";
	cout << "SequenceSearch" << "\n";
	while (searchStr != "-1")
	{
		file << "Search: ";
		cout << "Search: ";
		cin >> searchStr;
		file << searchStr;
		search = stoi(searchStr);
		file << "Index: " << SeqSearch(A, len, search) << "\n";
		cout << "Index: " << SeqSearch(A, len, search) << "\n";

		cout << "Stop: -1" << "\n";
	}



	file << "BinSearch" << "\n";
	cout << "BinSearch" << "\n";
	QuickSort(A, 0, len - 1);
	for (int i = 0; i < len; i++)
	{
		file << A[i] << "   ";
		cout << A[i] << "   ";
	}
	file << "\n";
	cout << "\n";
	searchStr = "";
	while (searchStr != "-1")
	{
		file << "Search - ";
		cout << "Search - ";
		cin >> searchStr;
		file << searchStr;
		search = stoi(searchStr);
		file << "Index - " << BinSearch(A, 0, len - 1, search) << "\n";
		cout << "Index - " << BinSearch(A, 0, len - 1, search) << "\n";

		cout << "Stop: -1" << "\n";
	}



	file << "AllocSearch" << "\n";
	cout << "AllocSearch" << "\n";
	for (int i = 0; i < len; i++)
	{
		file << A[i] << "   ";
		cout << A[i] << "   ";
	}
	file << "\n";
	cout << "\n";
	searchStr = "";
	while (searchStr != "-1")
	{
		file << "Search - ";
		cout << "Search - ";
		cin >> searchStr;
		file << searchStr;
		search = stoi(searchStr);
		file << "Index - " << AllocSearch(A, len, A[0], A[len - 1], search) << "\n";
		cout << "Index - " << AllocSearch(A, len, A[0], A[len - 1], search) << "\n";

		cout << "Stop: -1" << "\n";
	}

	file << "\n" << "\n" << "\n" << "\n";



	//Тестирование 10000 элементов заданных рандомно 
	//со снятием временных показателей
	Tests(10000, "Test1000.txt");

	system("pause");
	return 0;
}