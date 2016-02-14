#include <cstdio>
#include <algorithm>

using namespace std;

int ordered(int num, int is_inc) {
	int *digits = new int[4];
	for (int i = 0; i < 4; i++) {
		digits[i] = num % 10;
		num /= 10;
	}
	sort(digits, digits + 4);
	int res = 0;
	if (is_inc)
		for (int i = 0; i < 4; i++)
			res = res * 10 + digits[i];
	else
		for (int i = 3; i >= 0; i--)
			res = res * 10 + digits[i];

	return res;
}

int main() {
	int num;
	scanf("%d", &num);
	while (true) {
		int inc = ordered(num, true), dec = ordered(num, false);
		num = dec - inc;
		printf("%04d - %04d = %04d\n", dec, inc, num);
		if ((num == 0) || (num == 6174))
			break;
	}

	return 0;
}