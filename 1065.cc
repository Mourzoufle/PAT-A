#include <cstdio>

int main() {
	int num_case;
	scanf("%d", &num_case);
	for (int i = 1; i <= num_case; i++) {
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		long long sum = a + b;
		bool grt;
		if ((a > 0) && (b > 0) && (sum <= 0))		// overflow
			grt = true;
		else if ((a < 0) && (b < 0) && (sum >= 0))	// underflow
			grt = false;
		else
			grt = sum > c;
		if (grt)
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
	}

	return 0;
}