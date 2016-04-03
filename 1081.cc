#include <cstdio>

/* get the greatest common divisor of a and b */
long get_gcd(long a, long b) {
	while (true) {
		if (a % b == 0)
			return b;
		a %= b;
		if (b % a == 0)
			return a;
		b %= a;
	}
}

int main() {
	int num_num;																				// number of rational numbers
	scanf("%d", &num_num);
	long *numerators = new long[num_num];
	long *denominators = new long[num_num];
	long long common_denominator = 1;															// the common denominator - lowest common multiple of all the denominators
	for (int i = 0; i < num_num; i++) {
		scanf("%ld/%ld", &numerators[i], &denominators[i]);
		common_denominator *= denominators[i] / get_gcd(common_denominator, denominators[i]);	// lcm(a, b) = a * b / gcd(a, b)
	}

	long long sum_numerator = 0;																// sum of all the numerators (with the common denominator)
	for (int i = 0; i < num_num; i++)
		sum_numerator += numerators[i] * (common_denominator / denominators[i]);
	if (sum_numerator == 0)																		// just print 0
		printf("0");
	else {
		if (sum_numerator < 0) {
			printf("-");
			sum_numerator = -sum_numerator;
		}
		long long gcd = get_gcd(sum_numerator, common_denominator);
		sum_numerator /= gcd;
		common_denominator /= gcd;
		if (sum_numerator >= common_denominator) {												// has integer part
			printf("%lld", sum_numerator / common_denominator);
			sum_numerator %= common_denominator;
			if (sum_numerator != 0)																// has fractional part
				printf(" ");
		}
		if (sum_numerator != 0)
			printf("%lld/%lld", sum_numerator, common_denominator);
	}

	return 0;
}