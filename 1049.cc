#include <cstdio>

int main() {
	int num, num_one = 0;									// the number; number of 1s appeared in numbers from 1 to this number
	scanf("%d", &num);
	for (int i = 1; i <= num; i *= 10) {
		int upper = num / (i * 10), lower = num % (i * 10);	// the number higher than the current digit, and the remaining part
		/* the number of 1s appeared in each digit is determined by the number higher than the digit, the current digit, and the lower part
			the upper part contributes its value of i numbers whose current digit is 1
			if the current digit is 0 (the remaining part < i), then no more 1 in this digit
			else if the current digit is 1 (the remaining part < i * 2), then the lower part contributes its value + 1 more 1s
			else there are i more 1s
		*/
		num_one += upper * i + (lower >= i ? (lower >= i * 2 ? i : lower - i + 1) : 0);
	}
	printf("%d", num_one);

	return 0;
}