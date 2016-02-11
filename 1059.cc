#include <cstdio>
#include <cmath>

bool is_prime(long num) {
	long length = sqrt(num) + 1;
	for (long i = 3; i <= length; i += 2)
		if (num % i == 0)
			return false;

	return true;
}

int main() {
	long num;
	scanf("%ld", &num);
	printf("%ld=", num);
	if (num == 1)
		printf("1");
	for (long i = 2; i <= num; i++) {
		if (!is_prime(i))
			continue;
		int count = 0;
		while (num % i == 0) {
			num /= i;
			count++;
		}
		if (count > 0)
			printf("%ld", i);
		if (count > 1)
			printf("^%d", count);
		if ((count > 0) && num > 1)
			printf("*");
	}

	return 0;
}