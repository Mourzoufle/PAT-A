#include <iostream>
#include <climits>

using namespace std;

long long get_value(string num, long long radix) {
	long long res = 0;
	for (int i = 0; i < num.length(); i++) {
		res *= radix;
		if ((num[i] >= '0') && (num[i] <= '9'))
			res += num[i] - '0';
		else if ((num[i] >= 'a') && (num[i] <= 'z'))
			res += num[i] - 'a' + 10;
	}

	return res;
}

void get_radix(string num, long long value) {
	long long start = 0, end = value + 1, min = LLONG_MAX;
	for (int i = 0; i < num.length(); i++)
		if (start < num[i])
			start = num[i];
	if ((start >= '0') && (start <= '9'))
		start -= '0' - 1;
	else if ((start >= 'a') && (start <= 'z'))
		start -= 'a' - 11;

	while (start <= end) {
		long long cur_radix = (start + end) >> 1;
		long long cur_value = get_value(num, cur_radix);
		if ((cur_value < value) && (cur_value > 0))
			start = cur_radix + 1;
		else {
			end = cur_radix - 1;
			if ((cur_value == value) && (min > cur_radix))
				min = cur_radix;
		}
	}
	if (min < LLONG_MAX)
		cout << min;
	else
		cout << "Impossible";
}

int main() {
	string a, b;
	long long radix;
	int flag;
	cin >> a >> b >> flag >> radix;
	if (flag == 1)
		get_radix(b, get_value(a, radix));
	else if (flag == 2)
		get_radix(a, get_value(b, radix));

	return 0;
}