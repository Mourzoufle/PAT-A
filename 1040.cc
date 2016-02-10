#include <iostream>

using namespace std;

int main() {
	string str;
	getline(cin, str);
	int max = 1;
	for (int i = 0; i < str.length(); i++) {
		int cur = 1;
		while ((i >= cur) && (i + cur < str.length()) && (str[i - cur] == str[i + cur]))
			cur++;
		cur = (cur << 1) - 1;
		if (max < cur)
			max = cur;
		cur = 1;
		while ((i >= cur - 1) && (i + cur < str.length()) && (str[i + 1 - cur] == str[i + cur]))
			cur++;
		cur = (cur - 1) << 1;
		if (max < cur)
			max = cur;
	}
	cout << max;

	return 0;
}