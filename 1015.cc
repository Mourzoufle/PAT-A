#include <cstdio>
#include <cmath>

/* reverse the number according to the given radix */
int reverse(int num, int radix) {
	int res = 0;
	while (num > 0) {
		res = res * radix + num % radix;
		num /= radix;
	}

	return res;
}

/* check if the number is a prime */
bool is_prime(int num) {
	if (num < 2)			// 0, 1 - false
		return false;
	if (num < 4)			// 2, 3 - true
		return true;
	if (num % 2 == 0)		// even numbers beside of 2 - false
		return false;
	int limit = sqrt(num);	// only need to check factors not greater than sqrt(num)
	for (int i = 3; i <= limit; i += 2)
		if (num % i == 0)
			return false;
	return true;
}

int main() {
	while (true) {
		int num, radix;
		scanf("%d", &num);
		if (num < 0)
			break;
		scanf("%d", &radix);
		if (is_prime(num) && is_prime(reverse(num, radix)))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}