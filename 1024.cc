#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string add(string a, string b) {
	for (int i = 0; i < a.size(); i++) {
		a[i] -= '0';
		b[i] -= '0';
	}
	string res;
	bool carry = false;
	for (int i = a.size() - 1; i >= 0; i--) {
		int num = a[i] + b[i] + (carry ? 1 : 0);
		carry = num > 9;
		res += (num % 10) + '0';
	}
	if (carry)
		res += '1';
	reverse(res.begin(), res.end());

	return res;
}

int main() {
	char str[16];
	int num_step;
	scanf("%s %d", str, &num_step);
	string num = str;
	for (int i = 0; i < num_step; i++) {
		string rev_num = num;
		reverse(rev_num.begin(), rev_num.end());
		if (num == rev_num) {
			printf("%s\n%d", num.c_str(), i);
			return 0;
		}
		num = add(num, rev_num);
	}
	printf("%s\n%d", num.c_str(), num_step);

	return 0;
}