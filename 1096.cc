#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	int start, length = 0;
	int max = sqrt(num);
	for (int i = 2; i <= max; i++) {
		int cur_num = num, cur_length = 0;
		for (int j = i; cur_num % j == 0; j++) {
			cur_num /= j;
			cur_length++;
		}
		if (length < cur_length) {
			start = i;
			length = cur_length;
		}
	}
	if (length == 0)
		printf("1\n%d", num);
	else {
		printf("%d\n%d", length, start);
		for (int i = 1; i < length; i++)
			printf("*%d", start + i);
	}

	return 0;
}