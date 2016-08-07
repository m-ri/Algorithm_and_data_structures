#pragma once

#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

class RadixSort {


	int getDigitLev(int num, int lev) {
		int base = pow(10, lev);
		return (num / base) % (10);
	}
	vector<int> sortLev(const vector<int> & inp, const int lev) {
		vector<int> bucket[10];
		for (int num : inp) {
			bucket[getDigitLev(num, lev)].push_back(num);
		}

		vector<int> ret;
		for (vector<int> &vec : bucket)
			for (int val : vec) {
				ret.push_back(val);
			}

		return ret;
	}

public:
	void test() {
		vector<int> vect;
		for (int i = 0; i < 10; i++) {
			vect.push_back((23 + i * 9) % 11);
		}
		vect.push_back(500);
		vect.push_back(502);
		vect.push_back(501);

		for (int i = 0; i < 3; i++) {
			vect = sortLev(vect, i);
		}

		for (int val : vect) {
			cout << val << " ";
		}


	}
};
