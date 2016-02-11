#include <iostream>

using namespace std;

bool is_prime(long num) {
	for (long i = 3; i * i <= num; i += 2)
		if (num % i == 0)
			return false;

	return true;
}

int main() {
	long num;
	cin >> num;
	cout << num << "=";
	if (num == 1)
		cout << "1";
	for (long i = 2; i <= num; i += 2) {
		if (!is_prime(i))
			continue;
		int count = 0;
		while (num % i == 0) {
			num /= i;
			count++;
		}
		if (count > 0)
			cout << i;
		if (count > 1)
			cout << "^" << count;
		if ((count > 0) && num > 1)
			cout << "*";
		if (i == 2)
			i--;
	}

	return 0;
}