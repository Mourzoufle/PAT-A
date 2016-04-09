#include <cstdio>
#include <cmath>

int main() {
	int num;
	scanf("%d", &num);

	int head, max_length = 0;	// head of the consecutive factors; max length of the consecutive factors
	int max_factor = sqrt(num);	// only need to check to this (possible) factor
	for (int i = 2; i <= max_factor; i++) {
		int cur_num = num, cur_length = 0;
		for (int j = i; cur_num % j == 0; j++) {
			cur_num /= j;
			cur_length++;
		}
		if (cur_length > max_length) {
			max_length = cur_length;
			head = i;
		}
	}
	if (max_length == 0)
		printf("1\n%d", num);
	else {
		printf("%d\n%d", max_length, head);
		for (int i = 1; i < max_length; i++)
			printf("*%d", head + i);
	}

	return 0;
}