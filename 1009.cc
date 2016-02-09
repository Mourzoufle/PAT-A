#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int num_a;
	cin >> num_a;
	int *expon_a = new int[num_a];
	double *coeff_a = new double[num_a];
	for (int i = 0; i < num_a; i++)
		cin >> expon_a[i] >> coeff_a[i];
	int num_b;
	cin >> num_b;
	int *expon_b = new int[num_b];
	double *coeff_b = new double[num_b];
	for (int i = 0; i < num_b; i++)
		cin >> expon_b[i] >> coeff_b[i];

	double *res = new double[2048];
	int num_nonzero = 0;
	for (int i = 0; i < 2048; i++)
		res[i] = 0;
	for (int i = 0; i < num_a; i++) {
		for (int j = 0; j < num_b; j++) {
			int expon = expon_a[i] + expon_b[j];
			double coeff = coeff_a[i] * coeff_b[j];
			if (res[expon] == 0)
				num_nonzero++;
			res[expon] += coeff;
			if (res[expon] == 0)
				num_nonzero--;
		}
	}
	cout << num_nonzero;
	for (int i = 2047; i >= 0; i--)
		if (res[i] != 0)
			printf(" %d %.1f", i, res[i]);

	return 0;
}