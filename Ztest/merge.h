#pragma once




template<typename T>
T* merge(T* arr1, T* arr2,T*arr_merge, int size1, int size2) {
	int index1 = 0, index2 = 0, index3 = 0;
	while (index1 < size1 && index2 < size2) {
		if (arr1[index1] <= arr2[index2]) {
			arr_merge[index3] = arr1[index1];
			index1++; index3++;
		}
		else {
			arr_merge[index3] = arr2[index2];
			index2++; index3++;
		}
	}while (index1 < size1) {
		arr_merge[index3] = arr1[index1];
		index3++; index1++;
	}while (index2 < size2) {
		arr_merge[index3] = arr2[index2];
		index3++; index2++;
	}
	return arr_merge;
}

int get_merge_size(int size1, int size2) {
	return size1 + size2;
}

template<typename T>
void print_arr(T* arr, int size) {
	int index = 0;
	for (; index < size; index++) 
		std::cout << arr[index] << "\t";
	std::cout << std::endl;
}