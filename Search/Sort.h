#pragma once
#include<iostream>
template <class T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
void SelectionSort(T a[], int len)
{
	int small;
	for (int i = 0; i < len - 1; i++)
	{
		small = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[j] < a[small]) small = j;
		}
		Swap(a[i], a[small]);
	}
}



template <class T>
void BubbleSort(T a[], int len)
{
	int i = len - 1,
		last;

	while (i > 0)
	{
		last = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j + 1] < a[j])
			{
				Swap(a[j + 1], a[j]);
				last = j;
			}
		}
		i = last;
	}
}



template <class T>
void InsertionSort(T a[], int len)
{
	int j;
	T temp;
	for (int i = 0; i < len; i++)
	{
		temp = a[i];
		j = i;
		while (j > 0 && temp < a[j - 1])
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
	}
}



template <class T>
void QuickSort(T a[], int low, int high)
{
	int Up, Down, midlle;
	T temp;

	if (high - low <= 0) return;
	else if (high - low == 1)
	{
		if (a[high] < a[low]) Swap(a[low], a[high]);
		return;
	}

	midlle = (low + high) / 2;
	temp = a[midlle];
	Swap(a[midlle], a[low]);
	Up = low + 1;
	Down = high;

	do
	{
		while (Up <= Down && a[Up] <= temp) Up++;
		while (temp < a[Down]) Down--;

		if (Up < Down) Swap(a[Up], a[Down]);

	} while (Up < Down);

	a[low] = a[Down];
	a[Down] = temp;

	if (low < Down - 1) QuickSort(a, low, Down - 1);
	if (Down + 1 < high) QuickSort(a, Down + 1, high);
}



template <class T>
void ShellSort(T a[], int len)
{
	int j,
		d = len / 2;

	while (d > 0)
	{
		for (int i = 0; i < len - d; i++)
		{
			j = i;
			while (j >= 0 && a[j] > a[j + d])
			{
				Swap(a[j], a[j + d]);
				j--;
			}
		}

		d /= 2;
	}
}