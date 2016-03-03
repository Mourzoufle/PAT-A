#include <cstdio>

const int MAX_TERM = 1001;

int main() {
	double *terms = new double[MAX_TERM];
	for (int i = 0; i < MAX_TERM; i++)
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
	for (int i = MAX_TERM - 1; i >= 0; i--)
		if (terms[i] != 0)
			printf(" %d %.1lf", i, terms[i]);

	return 0;
}