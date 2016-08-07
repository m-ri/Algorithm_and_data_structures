#ifndef __MERGE_SORT_H
#define __MERGE_SORT_H

#include<vector>
#include<functional>

#include"Utils.h"

template<typename T>
class MergeSort {
private:
	void merge(T* array, int start1, int mid, int end2, std::function<int(T, T)> comparator) {
		std::vector<T> temp(end2 - start1 );
		int iDest = 0;
		int i1 = start1, i2 = mid;//indicies above two sub-arrrays
		while (i1 < mid && i2 < end2) {
			if (comparator(array[i1] , array[i2])) { temp[iDest] = array[i1++]; }
			else { temp[iDest] = array[i2++]; }
			iDest++;
		}
		while (i1 < mid) { temp[iDest++] = array[i1++]; }
		while (i2 < end2) { temp[iDest++] = array[i2++]; }
		//copy back the temp array
		for (int i = 0; i < (end2-start1);i++){
			array[start1 + i] = temp[i];
		}
	}


public:
	//end is next to last valid item
	void sort(T* array, int start, int end, std::function<int(T,T)> comparator) {
		if (start+1 >= end)return;//one item or less to be ordered

		int mid = start + (end - start) / 2;
		sort(array,start, mid,comparator);
		sort(array,mid, end,comparator);
		merge(array, start,  mid, end,comparator);


	}
	void sort(T* array, int start, int end) {
		sort(array, start, end, [](const T & a, const T & b)->int {return a < b; });
	}
	void test() {//it's valid only for numbers
		T array[100];
		Utils::fillVector(array, 100);
		sort(array, 0, 100);
		Utils::printVector(array, 100);
		sort(array, 0,100, [](const T & a, const T & b)->int {return a > b; });
		Utils::printVector(array, 100);
	}
};









#endif
