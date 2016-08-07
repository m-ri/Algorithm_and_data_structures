#pragma once
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<cassert>

using namespace std;

class MinHeap {
	vector<int> vect;

	int indexParent(int indexChild) { return (indexChild < 1 ? 0 : ((indexChild - 1) / 2)); }

	void push(int item) {
		vect.push_back(item);
		heapifyUp(vect.size() - 1);
	}
	void heapifyUp(int ind) {
		int up = indexParent(ind);
		while (ind != up)
		{
			if (vect[up] > vect[ind])swap(vect[up], vect[ind]);
			else return;
			ind = up;
			up = indexParent(up);
		}
		return;
	}
	void heapifyDown(int start = 0) {

		int act = start;
		while ((2 * act + 1) < vect.size()) {
			int next = act;
			if (vect[next] > vect[2 * act + 1])next = 2 * act + 1;
			if ((2 * act + 2)<vect.size() && vect[next] > vect[2 * act + 2])next = 2 * act + 2;
			if (next != act) { swap(vect[act], vect[next]); }
			else return;
			act = next;
		}
	}
	int top() {
		return vect[0];
	}
	void popMin() {
		vect[0] = vect.back();
		vect.pop_back();
		heapifyDown();
	}
	void printAll() {
		for (int i : vect) {
			cout << i << " ";
		}
		cout << endl;
	}
	/*Useful for create a new heap,knowing all items. It's complexity is just O(n)
	*/
	void addAll(const vector<int> &items) {
		assert(vect.size() == 0);
		vect.assign(items.begin(), items.end());

		for (int i = vect.size() - 1; i >= 0; i--) {
			heapifyDown(i);
		}

	}

public:

	void test() {
		vector<int> v({ -1000,56,800,-1,400,45,89,-50 });
		//push(20); push(110); push(30); push(-100); push(-99); push(100); push(15); push(250); push(207);
		addAll(v);
		printAll();
		cout << top() << " "; popMin();
		cout << top() << " "; popMin();
		cout << top() << " "; popMin();
		cout << top() << " "; popMin();
		cout << top() << " "; popMin();
		cout << top() << " "; popMin();
		cout << top() << " "; popMin();


		/*signed int aa = -1;
		unsigned int bb = -1;
		aa = aa >> 1;
		bb = bb >> 1;

		cout << (unsigned int)aa << " " << bb << endl;*/
	}

};