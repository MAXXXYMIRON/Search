#pragma once
#include<iostream>
template <class T>
int SeqSearch(T a[], int len, T key)
{
	for (int i = 0; i < len; i++)
	{
		if (a[i] == key) return i;
	}
	return -1;
}

template <class T>
int BinSearch(T a[], int low, int high, T key)
{
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == key) return mid;

		if (key < a[mid]) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}


int AllocSearch(int a[], int len, int min, int max, int key)
{
	if (key < min && key > max) return -1;

	int *invers = new int[(max - min) + 1];

	for (int i = 0; i < (max - min) + 1; i++)
	{
		invers[i] = -1;
	}

	for (int i = 0; i < len; i++)
	{
		invers[a[i] - min] = i;
	}

	return invers[key - min];
}