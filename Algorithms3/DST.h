#pragma once
#pragma once
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

//the goal of this class is to find all connected components of a given graph
class DST {
	vector<vector<int> > adj;
	vector<int> dis, fin;
public:
	DST(int size) :adj(size), dis(size, -1), fin(size, -1) {

	}

	long cont = 0;
	void search(int node) {
		if (dis[node] >= 0)return;
		dis[node] = cont++;
		for (int child : adj[node]) {
			if (dis[child] < 0)search(child);
		}
		fin[node] = cont++;

	}


	vector<vector<int> >  transpose(vector<vector<int> >& from) {
		vector<vector<int> > ret(from.size());
		for (int i = 0; i < from.size(); i++) {
			for (int dest : from[i]) {
				ret[dest].push_back(i);
			}
		}
		return ret;
	}

	void topol() {
		cont = 0;
		for (int i = 0; i < adj.size(); i++)search(i);

		vector<int> ord; for (int i = 0; i < adj.size(); i++)ord.push_back(i);

		sort(ord.begin(), ord.end(), [&](const int& el1, const int& el2) {
			return fin[el1] > fin[el2];
		});

		adj = transpose(adj);

		fin.clear(); fin.resize(adj.size(), -1);
		dis.clear(); dis.resize(adj.size(), -1);
		cont = 0;
		for (int i = 0; i < adj.size(); i++) {
			int val = ord[i];
			if (dis[val] < 0)cout << "new component " << val << endl;
			search(val);
		}

	}


	void test() {
		for (int i = 1; i < 3; i++) {
			adj[i].push_back(i - 1);
			adj[i - 1].push_back(i);
		}
		adj[3].push_back(3 - 1);

		for (int i = 4; i < adj.size(); i++) {
			adj[i].push_back(i - 1);
			adj[i - 1].push_back(i);
		}

		topol();
	}


};