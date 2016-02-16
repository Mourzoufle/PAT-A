#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string num;
	cin >> num;
	if (num[0] == '-')
		cout << num.substr(0, 1);
	int expon;
	stringstream ss;
	ss << num.substr(num.find('E') + 1);
	ss >> expon;
	num = num.substr(1, num.find('E') - 1);
	if (expon < 0) {
		cout << "0.";
		for (int i = -1; i > expon; i--)
			cout << "0";
		cout << num.substr(0, 1) << num.substr(2);
	}
	else {
		cout << num.substr(0, 1);
		num = num.substr(2);
		if (expon <= num.length()) {
			cout << num.substr(0, expon);
			if (expon < num.length())
				cout << "." << num.substr(expon);
		}
		else {
			cout << num;
			for (int i = num.length(); i < expon; i++)
				cout << "0";
		}
	}

	return 0;
}