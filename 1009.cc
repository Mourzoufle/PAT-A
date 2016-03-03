#include <cstdio>

const int MAX_TERM = 2001;

int main() {
	int nums_term[2];									// numbers of terms in two polynomials
	int *expons[2];										// exponents in two polynomials
	double *coeffs[2];									// coefficients in two polynomials
	for (int i = 0; i < 2; i++) {
		scanf("%d", &nums_term[i]);
		expons[i] = new int[nums_term[i]];
		coeffs[i] = new double[nums_term[i]];
		for (int j = 0; j < nums_term[i]; j++)
			scanf("%d %lf", &expons[i][j], &coeffs[i][j]);
	}

	double *terms = new double[MAX_TERM];				// the result
	int num_nonzero = 0;								// number of nonzero terms
	for (int i = 0; i < MAX_TERM; i++)
		terms[i] = 0;
	for (int i = 0; i < nums_term[0]; i++) {
		for (int j = 0; j < nums_term[1]; j++) {
			int expon = expons[0][i] + expons[1][j];	// multiplication - addition in exponents
			double coeff = coeffs[0][i] * coeffs[1][j];	// new coefficient
			if (terms[expon] == 0)						// a nonzero term occurred
				num_nonzero++;
			terms[expon] += coeff;
			if (terms[expon] == 0)						// a nonzero terms becomes zero
				num_nonzero--;
		}
	}
	printf("%d", num_nonzero);
	for (int i = MAX_TERM - 1; i >= 0; i--)
		if (terms[i] != 0)
			printf(" %d %.1lf", i, terms[i]);

	return 0;
}