#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string chop(string value, int num_digit) {
	bool is_zero = true;
	int inc = 1, expon = 0;
	string res = "0.";
	for (int i = 0; i < value.length(); i++) {
		if (value[i] == '0') {
			if (!is_zero) {
				res += value[i];
				expon += inc;
			}
			else if (inc < 0)
				expon--;
		}
		else if (value[i] == '.') {
			if (expon > 0)
				inc = 0;
			else {
				expon = 1;
				inc = -1;
			}
		}
		else {
			is_zero = false;
			expon += inc;
			res += value[i];
		}
	}
	for (int i = num_digit + 2 - res.length(); i > 0; i--)
		res += '0';
	if (is_zero)
		expon = 0;
	stringstream stream;
	stream << expon;
	return res.substr(0, num_digit + 2) + "*10^" + stream.str();
}

int main() {
	int num_digit;
	string a, b;
	cin >> num_digit >> a >> b;
	a = chop(a, num_digit);
	b = chop(b, num_digit);
	if (a == b)
		cout << "YES " << a;
	else
		cout << "NO " << a << " " << b;

	return 0;
}