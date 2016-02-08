#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	bool isNeg = sum < 0;
	if (isNeg)
		sum = -sum;
	string disp;
	for (int i = 0; sum > 0; i++) {
		if ((i > 0) && (i % 3 == 0))
			disp += ',';
		disp += '0' + sum % 10;
		sum /= 10;
	}
	if (disp.length() == 0)
		disp = "0";
	else if (isNeg)
		disp += '-';
	reverse(disp.begin(), disp.end());
	cout << disp;

	return 0;
}