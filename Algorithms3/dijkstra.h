#pragma once
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
#include<functional>


using namespace std;

class Dijkstra {
	vector<vector<pair<int, double> > > edges;//int:otherNode;double:distance


	typedef typename pair<int, double > Item;

	typedef struct {
		bool operator()(const Item& a, const Item &b) { return a.second < b.second; }
	}compStruct;

	double getDist(int from, int to) {
		vector<double> dists(edges.size(), FLT_MAX);
		vector<int> previousNode(edges.size(), -1);
		//dists[from] = 0;

		/*auto comp = []( Item a,  Item b) { return a.first < b.first; };
		priority_queue < Item, vector<Item>, decltype( comp) >  q;*/
		priority_queue < Item, vector<Item>, compStruct >  q;

		q.push(make_pair(0.0, from));
		previousNode[from] = from;

		while (!q.empty()) {
			Item currItem = q.top();
			q.pop();
			int curr = currItem.first;
			if (curr == to)return currItem.second;
			if (currItem.second < dists[curr]) {
				dists[curr] = currItem.second;
				for (pair<int, double> next : edges[curr]) {
					double nextDist = currItem.second + next.second;
					if (nextDist < dists[next.first]) {
						previousNode[next.first] = curr;
						q.push(make_pair(nextDist, next.first));

					}
				}
			}
		}
	}
public:
	void test() {
		edges.resize(10);
		edges[0].push_back(make_pair(1, 15.0));

		edges[0].push_back(make_pair(2, 1.0));
		edges[0].push_back(make_pair(3, 15.0));
		edges[0].push_back(make_pair(4, 15.0));
		edges[0].push_back(make_pair(5, 15.0));
		edges[2].push_back(make_pair(1, 1.0));
		edges[1].push_back(make_pair(3, 1.0));
		edges[3].push_back(make_pair(4, 1.0));
		edges[4].push_back(make_pair(5, 1.0));
		edges[5].push_back(make_pair(6, 1.0));

		cout << getDist(0, 5) << endl;
	}



};