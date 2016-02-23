#include <iostream>
#include <cmath>

using namespace std;

int reverse(int num, int radix) {
	int res = 0;
	while (num > 0) {
		res = res * radix + num % radix;
		num /= radix;
	}

	return res;
}

bool is_prime(int num) {
	if (num < 2)
		return false;
	if (num == 2)
		return true;
	if (num % 2 == 0)
		return false;
	int limit = sqrt(num);
	for (int i = 3; i <= limit; i += 2)
		if (num % i == 0)
			return false;
	return true;
}

int main() {
	while (true) {
		int num, radix;
		cin >> num;
		if (num < 0)
			break;
		cin >> radix;
		if (is_prime(num) && is_prime(reverse(num, radix)))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}