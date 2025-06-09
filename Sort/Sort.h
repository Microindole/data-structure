#pragma once

#include<iostream>
using namespace std;
int Partition(int array[], int left, int right);
void QuickSort(int array[], int left, int right);
void QuickSort(int array[], int left, int right) {
	if (left < right) {
		int q = Partition(array, left, right);//�һ�׼
		QuickSort(array, left, q - 1);
		QuickSort(array, q + 1, right);//�ֶ���֮���Ի�׼��ֳ�������
	}
}
int Partition(int array[], int left, int right) {
	int l = left, r = right + 1;
	int x = array[left];
	while (true) {
		while (array[++l] < x && l < right);
		while (array[--r] > x);
		if (l >= r)
			break;
		swap(array[l], array[r]);
	}
	array[left] = array[r];
	array[r] = x;
	return r;
}
