#include <cstdio>
#include <cmath>

/* check if the number is prime */
bool is_prime(int num) {
	if (num < 2)						// 0, 1 - false
		return false;
	if (num < 4)						// 2, 3 - true
		return true;
	if (num % 2 == 0)					// even numbers beside of 2 - false
		return false;
	int limit = sqrt(num);				// only need to check factors not greater than sqrt(num)
	for (int i = 3; i <= limit; i += 2)
		if (num % i == 0)
			return false;
	return true;
}

int main() {
	long num;
	scanf("%ld", &num);
	printf("%ld=", num);
	if (num == 1)						// 1 has no prime factor, just print itself
		printf("1");
	for (long i = 2; i <= num; i += 2) {
		if (!is_prime(i))				// not a prime number - skip it
			continue;
		int expon = 0;					// compute the max exponent of each prime number that can divide the given number
		while (num % i == 0) {
			num /= i;
			expon++;
		}
		if (expon > 0)					// the prime number is a factor
			printf("%d", i);
		if (expon > 1)
			printf("^%d", expon);
		if ((expon > 0) && (num > 1))	// the number has other factors
			printf("*");
		if (i == 2)						// the next number to be checked should be 3
			i--;
	}

	return 0;
}