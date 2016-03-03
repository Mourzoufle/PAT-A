#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int sum = a + b;
	bool is_neg = sum < 0;
	if (is_neg)
		sum = -sum;
	string disp;						// the reversed result
	for (int i = 0; sum > 0; i++) {
		if ((i > 0) && (i % 3 == 0))	// add comma when 3 digits read
			disp += ',';
		disp += '0' + sum % 10;
		sum /= 10;
	}
	if (disp.empty())
		disp = "0";
	else {
		if (is_neg)
			disp += '-';
		reverse(disp.begin(), disp.end());
	}
	printf("%s", disp.c_str());

	return 0;
}