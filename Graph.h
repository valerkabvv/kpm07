#pragma once
#include<vector>
#include"Edge.h"

using namespace std;

class weighted_digraph {
protected:
	int v;
	vector<vector<edge>>  adjency_list;
public:
	weighted_digraph(int n) :v(n) {
		adjency_list = vector<vector<edge>>(n);
		for (int i = 0; i < n; i++)
			adjency_list[i] = vector<edge>();
	}

//    weighted_digraph(weighted_digraph &g):v(g.get_v())
//    {
//        adjency_list = vector<vector<edge>>(v);
//        for (int i = 0; i < v; i++)
//            adjency_list[i] = vector<edge>();
//    }

    weighted_digraph():v(0),adjency_list(0){}

	void add_edge(edge e) { adjency_list[e.from()].push_back(e); }

	vector<edge> adjency_to(int n) {
		return adjency_list[n];
	}
	int get_v() { return this->v; }

};
