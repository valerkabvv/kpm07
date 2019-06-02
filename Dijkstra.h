#pragma once
#include"Graph.h"
#include"Edge.h"
#include"priority_queue.h"
#include<vector>

class DijkstraSP {
private:
    vector<edge> edge_to;
    vector<double> dist_to;
	priority_queue pq;

	void relax(edge e) {
		int v = e.from(); int w = e.to();
		if (dist_to[w] > dist_to[v] + e.get_weight()) {
			dist_to[w] = dist_to[v] + e.get_weight();
			edge_to[w] = e;
			pq.set_value(w, dist_to[w]);
		}
	}
public:
	DijkstraSP(weighted_digraph gr, int s):pq(gr.get_v()) {
        edge_to = vector<edge>(gr.get_v());
        dist_to = vector<double>(gr.get_v());
		for (int i = 0; i < gr.get_v(); i++)
			dist_to[i] = MAX_DOUBLE;
		dist_to[s] = 0;
		pq.set_value(s, 0);
		while (!pq.isEmpty())
		{
			int v = pq.get_del_min();
			vector<edge> vec = gr.adjency_to(v);
			for (vector<edge>::iterator it = vec.begin(); it != vec.end(); it++)
				relax(*it);
		}
	}
	double get_dist(int n) { return dist_to[n]; }
};
