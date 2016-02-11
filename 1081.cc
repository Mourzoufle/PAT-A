#include <cstdio>

long long gcd(long long a, long long b) {
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
	int num;
	scanf("%d", &num);
	long long *nums = new long long[num];
	long long *denoms = new long long [num];
	long long lcm = 1;
	for (int i = 0; i < num; i++) {
		scanf("%lld/%lld", nums + i, denoms + i);
		lcm *= denoms[i] / gcd(lcm, denoms[i]);
	}
	long long sum = 0;
	for (int i = 0; i < num; i++) {
		nums[i] *= lcm / denoms[i];
		sum += nums[i];
	}
	if (sum < 0) {
		printf("-");
		sum = -sum;
	}
	if (sum == 0)
		printf("0");
	else {
		long long factor = gcd(sum, lcm);
		sum /= factor;
		lcm /= factor;
		if (sum >= lcm) {
			printf("%lld", sum / lcm);
			sum %= lcm;
			if (sum != 0)
				printf(" ");
		}
		if (sum != 0)
			printf("%lld/%lld", sum, lcm);
	}

	return 0;
}