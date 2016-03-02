#include <cstdio>

using namespace std;

int main() {
	double *terms = new double[1024];
	for (int i = 0; i < 1024; i++)
		terms[i] = 0;

	int num_nonzero = 0;
	for (int i = 0; i < 2; i++) {
		int num_term;
		scanf("%d", &num_term);
		for (int j = 0; j < num_term; j++) {
			int expon;
			double coeff;
			scanf("%d %lf", &expon, &coeff);
			if (terms[expon] == 0)	// a nonzero term occurred
				num_nonzero++;
			terms[expon] += coeff;
			if (terms[expon] == 0)	// a nonzero terms becomes zero
				num_nonzero--;
		}
	}

	printf("%d", num_nonzero);
	for (int i = 1023; i >= 0; i--)
		if (terms[i] != 0)
			printf(" %d %.1lf", i, terms[i]);

	return 0;
}
