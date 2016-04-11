#include <cstdio>
#include <cmath>

/* compare function to check if array a is less than b - according to the sums of the elemenets in them */
bool cmp(int *a, int *b, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += a[i] - b[i];

	return sum < 0;
}

int main() {
	int sum, num_num, expon;																						// target sum; number of numbers; the exponent
	scanf("%d %d %d", &sum, &num_num, &expon);

	int max_num = pow(sum + 1 - num_num, 1.0 / expon);																// max number that is possible for factorization
	int *expons = new int[max_num + 1];
	for (int i = 0; i <= max_num; i++)
		expons[i] = pow(i, expon) + 0.5;

	int *best_sln = new int[num_num];																				// the best solution
	int *cur_sln = new int[num_num];																				// current solution
	for (int i = 0; i < num_num; i++) {
		best_sln[i] = 0;
		cur_sln[i] = max_num;
	}
	int idx = 0, cur_sum = 0;																						// index of current number under checking; current sum
	while (idx >= 0) {
		while ((cur_sum + expons[cur_sln[idx]] > sum) || ((cur_sum + expons[cur_sln[idx]] == sum) && (idx < num_num - 1)))
			cur_sln[idx]--;
		if ((cur_sln[idx] == 0) || (idx == num_num - 1)) {
			if ((idx == num_num - 1) && (cur_sum + expons[cur_sln[idx]] == sum) && cmp(best_sln, cur_sln, num_num))	// better solution found
				for (int i = 0; i < num_num; i++)
					best_sln[i] = cur_sln[i];
			if (--idx >= 0)
				cur_sum -= expons[cur_sln[idx]--];
		}
		else {
			cur_sln[idx + 1] = cur_sln[idx];
			cur_sum += expons[cur_sln[idx++]];
		}
	}
	if (best_sln[0] == 0)																							// no solution found
		printf("Impossible");
	else {
		printf("%d = %d^%d", sum, best_sln[0], expon);
		for (int i = 1; i < num_num; i++)
			printf(" + %d^%d", best_sln[i], expon);
	}

	return 0;
}