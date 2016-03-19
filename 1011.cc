#include <cstdio>

const char RESULTS[3] = {'W', 'T', 'L'};

int main() {
	double profit = 1;				// initial multiplier
	double odds[3];
	for (int i = 0; i < 3; i++) {
		int idx = 0;				// selected result
		for (int j = 0; j < 3; j++) {
			scanf("%lf", &odds[j]);
			if (odds[j] > odds[idx])
				idx = j;
		}
		profit *= odds[idx];
		printf("%c ", RESULTS[idx]);
	}
	printf("%.2lf", (profit * 0.65 - 1) * 2);

	return 0;
}