#pragma once
#include<vector>
#include<iostream>


class BinarySearch {

	std::vector<int>::iterator search(std::vector<int> &vect, std::vector<int>::iterator start, std::vector<int>::iterator end, int value) {
		if (start >= end)return vect.end();
		int dist = std::distance(start, end);
		std::vector<int>::iterator piv = start + dist / 2;
		if (*piv == value)return piv;
		else if (*piv > value)return search(vect, start, piv, value);
		else return search(vect, piv + 1, end, value);
	}



public:
	void test() {
		std::vector<int> vect(100);
		for (int i = 0; i < 100; i++)vect[i] = i * 3 + 3;

		auto print = [&](std::vector<int>::iterator it) {
			if (it != vect.end())std::cout << *it << std::endl;
			else std::cout << "not found" << std::endl;
		};

		print(search(vect, vect.begin(), vect.end(), 20));
		print(search(vect, vect.begin(), vect.end(), 30));
		print(search(vect, vect.begin(), vect.end(), -20));
		print(search(vect, vect.begin(), vect.end(), 2000));

	}


};