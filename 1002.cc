#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	double *res = new double[1024];
	for (int i = 0; i < 1024; i++)
		res[i] = 0;

	int num_nonzero = 0;
	for (int i = 0; i < 2; i++) {
		int num_item;
		cin >> num_item;
		for (int j = 0; j < num_item; j++) {
			int expon;
			double coeff;
			cin >> expon >> coeff;
			if (res[expon] == 0)
				num_nonzero++;
			res[expon] += coeff;
			if (res[expon] == 0)
				num_nonzero--;
		}
	}

	cout << num_nonzero;
	for (int i = 1023; i >= 0; i--)
		if (res[i] != 0)
			printf(" %d %.1lf", i, res[i]);

	return 0;
}