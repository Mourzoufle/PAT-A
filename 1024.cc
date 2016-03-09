#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

/* get the sum of number representation a and b - the result may be out of the range of long long integer, use string instead */
string get_sum(string a, string b) {
	string sum;
	for (int i = 0; i < a.size(); i++) {
		a[i] -= '0';
		b[i] -= '0';
	}
	bool carry = false;
	for (int i = a.size() - 1; i >= 0; i--) {			// ASSUMED a and b have equal length
		int num = a[i] + b[i] + (carry ? 1 : 0);		// current digit in a and b + carry from the lower digit
		carry = num > 9;
		sum += (num % 10) + '0';
	}
	if (carry)
		sum += '1';
	reverse(sum.begin(), sum.end());					// the representation of the sum is reversed

	return sum;
}

int main() {
	char num[16];
	int max_step;
	scanf("%s %d", num, &max_step);
	string original_num = num;
	for (int i = 0; i < max_step; i++) {
		string reversed_num = original_num;
		reverse(reversed_num.begin(), reversed_num.end());
		if (original_num == reversed_num) {				// got a palindromic number
			printf("%s\n%d", original_num.c_str(), i);
			return 0;
		}
		original_num = get_sum(original_num, reversed_num);
	}
	printf("%s\n%d", original_num.c_str(), max_step);	// if not get a palindromic number at the max step, just print the result

	return 0;
}