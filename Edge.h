#pragma once


class edge {
private:
	int v, w;
	double weight;
public:
    edge(int a= 0,int b=0,double c=0):v(a),w(b),weight(c){}

	int from() { return v; }

	int to() { return w; }

	int get_weight() { return this->weight; }

	int compare(edge other) {
		if (this->weight > other.weight) { return 1; }
		if (this->weight < other.weight) { return -1; }
		return 0;
	}
};
