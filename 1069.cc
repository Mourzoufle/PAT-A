#include <cstdio>
#include <algorithm>

using namespace std;

/* compute the value of the number with each digit sorted in increasing (inc = 1) or decreasing (inc = -1) order */
int get_ordered(int num, int inc) {
	int digits[4];
	for (int i = 0; i < 4; i++) {
		digits[i] = num % 10;
		num /= 10;
	}
	sort(digits, digits + 4);
	int value = 0;
	for (int i = (inc > 0 ? 0 : 3); (i < 4) && (i >= 0); i += inc)
		value = value * 10 + digits[i];

	return value;
}

int main() {
	int num;
	scanf("%d", &num);
	while (true) {
		int inc = get_ordered(num, 1), dec = get_ordered(num, -1);	// value of the number with each digit sorted in increasing and decreasing order
		num = dec - inc;
		printf("%04d - %04d = %04d\n", dec, inc, num);
		if ((num == 0) || (num == 6174))							// halt when 6174 comes or all the digits are the same
			break;
	}

	return 0;
}