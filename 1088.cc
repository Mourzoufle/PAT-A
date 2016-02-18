#include <cstdio>
#include <string>

using namespace std;

long long GCD(long long a, long long b) {
	while (true) {
		a %= b;
		if (a == 0)
			return b;
		b %= a;
		if (b == 0)
			return a;
	}
}

void print(long long num, long long denom) {
	if (denom == 0) {
		printf("Inf");
		return;
	}
	if (num == 0) {
		printf("0");
		return;
	}
	if (denom < 0) {
		num = -num;
		denom = -denom;
	}

	bool is_neg = num < 0;
	if (is_neg) {
		printf("(-");
		num = -num;
	}
	if (num >= denom) {
		printf("%lld", num / denom);
		num %= denom;
		if (num > 0)
			printf(" ");
	}
	if (num > 0) {
		long long gcd = GCD(num, denom);
		printf("%lld", num / gcd);
		if (denom > gcd)
			printf("/%lld", denom / gcd);
	}
	if (is_neg)
		printf(")");
}

int main() {
	string ops[4] = { " + ", " - ", " * ", " / " };
	long long num_a, num_b, denom_a, denom_b;
	scanf("%lld/%lld %lld/%lld", &num_a, &denom_a, &num_b, &denom_b);
	long long gcd = GCD(denom_a, denom_b);
	for (int i = 0; i < 4; i++) {
		print(num_a, denom_a);
		printf("%s", ops[i].c_str());
		print(num_b, denom_b);
		printf(" = ");
		switch (i) {
		case 0:
			print(num_a * (denom_b / gcd) + num_b * (denom_a / gcd), denom_a * (denom_b / gcd));
			break;
		case 1:
			print(num_a * (denom_b / gcd) - num_b * (denom_a / gcd), denom_a * (denom_b / gcd));
			break;
		case 2:
			print(num_a * num_b, denom_a * denom_b);
			break;
		default:
			print(num_a * denom_b, denom_a * num_b);
		}
		printf("\n");
	}

	return 0;
}