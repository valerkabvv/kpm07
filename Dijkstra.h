#pragma once
#include"Graph.h"
#include"Edge.h"
#include"priority_queue.h"
#include<vector>

class DijkstraSP {
private:
	edge* edge_to;
	double* dist_to;
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
		edge_to = new edge[gr.get_v()];
		dist_to = new double[gr.get_v()];
		for (int i = 0; i < gr.get_v(); i++)
			dist_to[i] = MAX_DOUBLE;
		dist_to[s] = 0;
		pq.set_value(s, 0);
		while (!pq.isEmpty())
		{
			int v = pq.get_min();
			for (vector<edge>::iterator it = gr.adjency_to(v).begin(); it != gr.adjency_to(v).end(); it++)
				relax(*it);
		}
	}
};