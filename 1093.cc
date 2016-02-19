#include <iostream>

using namespace std;

int main() {
	string str;
	cin >> str;
	long long **counts = new long long*[str.size()];
	for (int i = 0; i < str.size(); i++) {
		counts[i] = new long long[3];
		for (int j = 0; j < 3; j++)
			counts[i][j] = 0;
	}
	counts[0][0] = str[0] == 'P' ? 1 : 0;
	counts[0][1] = 0;
	counts[0][2] = 0;
	for (int i = 1; i < str.size(); i++) {
		counts[i][0] = counts[i - 1][0] + (str[i] == 'P' ? 1 : 0);
		counts[i][1] = counts[i - 1][1] + (str[i] == 'A' ? counts[i - 1][0] : 0);
		counts[i][2] = counts[i - 1][2] + (str[i] == 'T' ? counts[i - 1][1] : 0);
	}
	cout << counts[str.size() - 1][2] % 1000000007;

	return 0;
}