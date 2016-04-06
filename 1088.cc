#include <cstdio>
#include <string>

using namespace std;

/* get the greatest common divisor of a and b */
long long get_gcd(long long a, long long b) {
	while (true) {
		if (a % b == 0)
			return b;
		a %= b;
		if (b % a == 0)
			return a;
		b %= a;
	}
}

/* get the string representation of the given rational number */
string get_str(long long numerator, long long denominator) {
	if (denominator == 0)																					// an illegal number
		return "Inf";
	if (numerator == 0)
		return "0";
	string res;
	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}
	bool is_neg = numerator < 0;
	if (is_neg) {
		res += "(-";
		numerator = -numerator;
	}
	if (numerator >= denominator) {																			// has integer part
		char str[32];
		sprintf(str, "%ld", numerator / denominator);
		res += str;
		numerator %= denominator;
		if (numerator != 0)
			res += ' ';
	}
	if (numerator != 0) {																					// has fractional part
		char str[32];
		long long gcd = get_gcd(numerator, denominator);
		sprintf(str, "%ld", numerator / gcd);
		res += str;
		if (denominator != gcd) {
			sprintf(str, "/%ld", denominator / gcd);
			res += str;
		}
	}
	if (is_neg)
		res += ')';

	return res;
}

int main() {
	long long numerator_a, denominator_a, numerator_b, denominator_b;
	scanf("%ld/%ld %ld/%ld", &numerator_a, &denominator_a, &numerator_b, &denominator_b);

	string str_a = get_str(numerator_a, denominator_a), str_b = get_str(numerator_b, denominator_b);
	long long common_denominator = denominator_a / get_gcd(denominator_a, denominator_b) * denominator_b;	// lcm(a, b) = a * b / gcd(a, b)
	printf("%s + %s = %s\n", str_a.c_str(), str_b.c_str(), get_str(numerator_a * common_denominator / denominator_a + numerator_b * common_denominator / denominator_b, common_denominator).c_str());
	printf("%s - %s = %s\n", str_a.c_str(), str_b.c_str(), get_str(numerator_a * common_denominator / denominator_a - numerator_b * common_denominator / denominator_b, common_denominator).c_str());
	printf("%s * %s = %s\n", str_a.c_str(), str_b.c_str(), get_str(numerator_a * numerator_b, denominator_a * denominator_b).c_str());
	printf("%s / %s = %s\n", str_a.c_str(), str_b.c_str(), get_str(numerator_a * denominator_b, denominator_a * numerator_b).c_str());

	return 0;
}