#ifndef __UTILS_H_
#define __UTILS_H_
#include <stdlib.h> 
#include<iostream>

class Utils {
public:


template<typename T>
static void fillVector(T* arr,size_t size) {
	// srand(time(NULL));
	
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 201 - 100;
	}
}
template<typename T>
static void printVector(T* arr, size_t size) {
	// srand(time(NULL));

	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';
}
};

#endif // !__UTILS_H_

