#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

/* chop the given representation of number with the given number of significant digits */
string chop(string num, int num_digit) {
	bool is_zero = true;										// the flag indication if the number is zero - change to false when a nonzero digit detected
	int expon = 0, inc = 1;										// the exponent in the resulting representation; the increase of it
	string chopped = "0.";										// the resulting representation
	for (int i = 0; i < num.length(); i++) {
		if (num[i] == '0') {
			if (!is_zero) {										// a nonzero digit has been detected before, this digit should be in the representation
				chopped += num[i];
				expon += inc;
			}
			else if (inc < 0)									// the number is less than 1, the digit should be counted in calculating the exponent
				expon--;
		}
		else if (num[i] == '.') {								// met the decimal part of the number
			if (expon > 0)										// if the number is no less than 1, the exponent will not change
				inc = 0;
			else {												// or the exponent will decrease
				expon = 1;
				inc = -1;
			}
		}
		else {													// a found nonzero digit
			is_zero = false;
			expon += inc;
			if (inc < 0)										// if the number is less than 1, then the exponent will not change after finding the first nonzero digit
				inc = 0;
			chopped += num[i];
		}
	}
	for (int i = num_digit + 2 - chopped.length(); i > 0; i--)	// add zero to the tail of the number if the significant digits are not enough
		chopped += '0';
	if (is_zero)
		expon = 0;
	stringstream stream;
	stream << expon;

	return chopped.substr(0, num_digit + 2) + "*10^" + stream.str();
}

int main() {
	int num_digit;
	char a[128], b[128];
	scanf("%d %s %s", &num_digit, a, b);
	string chop_a = chop(a, num_digit), chop_b = chop(b, num_digit);
	if (chop_a == chop_b)
		printf("YES %s", chop_a.c_str());
	else
		printf("NO %s %s", chop_a.c_str(), chop_b.c_str());

	return 0;
}