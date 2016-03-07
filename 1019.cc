#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int num, radix;
	scanf("%d %d", &num, &radix);

	vector<int> digits;								// the digits - reversed order according to the radix
	while (num >= radix) {
		digits.push_back(num % radix);
		num /= radix;
	}
	digits.push_back(num);

	bool is_palindromic = true;
	for (int i = 0; i < (digits.size() / 2); i++) {	// check half of the digits
		if (digits[i] != digits[digits.size() - 1 - i]) {
			is_palindromic = false;
			break;
		}
	}
	if (is_palindromic)
		printf("Yes\n");
	else
		printf("No\n");
	printf("%d", digits.back());					// digits in reversed order - print from the tail to the head
	for (int i = digits.size() - 2; i >= 0; i--)
		printf(" %d", digits[i]);

	return 0;
}