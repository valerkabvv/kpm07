#pragma once
#define MAX_DOUBLE 1.79769e+308

class priority_queue {
private:
	int size;
	double* cont;
public:
	priority_queue(int n):size(n) {
		cont = new double[n];
		for (int i = 0; i < n; i++)
			cont[i] = MAX_DOUBLE;
	}

	void set_value(int indx, double value) {
		cont[indx] = value;
	}

	int get_min() {
		double min = MAX_DOUBLE;
		int min_indx = -1;
		for (int i = 0; i < size; i++) {
			if (cont[i] < min) {
				min = cont[i];
				min_indx = i;
			}
		}
		return min_indx;
	}

	int get_del_min() {
		int min_indx = this->get_min();
		if (min_indx != -1) {
			cont[min_indx] = MAX_DOUBLE;
		}
		return min_indx;
	}

	bool isEmpty() {
		if (this->get_min() == -1) { return true; }
		return false;
	}
};