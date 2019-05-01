#include"Graph.h"
#include"Dijkstra.h"
#include"Edge.h"


int main() {
	 weighted_digraph g(5);
	 g.add_edge(edge(0, 1, 1));
	 g.add_edge(edge(0, 3, 2));
	 g.add_edge(edge(0, 4, 1));
	 g.add_edge(edge(1, 3, 1));
	 g.add_edge(edge(2, 1, 1));
	 g.add_edge(edge(3, 1, 1));
	 g.add_edge(edge(4, 2, 1));
	 g.add_edge(edge(3, 2, 1));
	 g.add_edge(edge(3, 4, 1));

	  DijkstraSP d(g, 2);
}