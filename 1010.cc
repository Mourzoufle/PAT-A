#include <cstdio>
#include <climits>

/* get the value of the number representation under given radix */
long long get_value(char *num, long long radix) {
	long long value = 0;
	for (int i = 0; num[i] != '\0'; i++) {
		value *= radix;
		if (num[i] >= 'a')								// a-z, note that 'a' > '9' in ASCII
			value += num[i] - 'a' + 10;
		else											// 0-9
			value += num[i] - '0';
	}

	return value;
}

/* Binary Search - get the min radix of the number representation to make it equal to the given value (if possible) */
void get_radix(char *num, long long value) {
	long long head = 0, tail = value + 1, radix = 0;	// the max candidate radix is value + 1 (if only want to find the min radix)
	for (int i = 0; num[i] != '\0'; i++)
		if (num[i] > head)								// find the max number, note that 'a' > '9' in ASCII
			head = num[i];
	if (head >= 'a')									// the first possible candidate is max + 1
		head -= 'a' - 11;
	else
		head -= '0' - 1;

	while (head <= tail) {								// binary search
		long long cur_radix = (head + tail) / 2;
		long long cur_value = get_value(num, cur_radix);
		if ((cur_value < value) && (cur_value > 0))		// current value must be positive - be aware of OVERFLOW!!!
			head = cur_radix + 1;
		else {											// if found a candidate radix - continue to search a smaller one
			tail = cur_radix - 1;
			if (cur_value == value)
				radix = cur_radix;
		}
	}
	if (radix > 0)										// found at least one radix
		printf("%lld", radix);
	else
		printf("Impossible");
}

int main() {
	char a[16], b[16];
	int flag;
	long long radix;
	scanf("%s %s %d %lld", a, b, &flag, &radix);
	if (flag == 1)										// the given radix is for a
		get_radix(b, get_value(a, radix));
	else												// the given radix is for b
		get_radix(a, get_value(b, radix));

	return 0;
}