#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	int num_str;
	cin >> num_str;
	cin.ignore();
	string *strs = new string[num_str];
	int min_lenth = INT_MAX;
	for (int i = 0; i < num_str; i++) {
		getline(cin, strs[i]);
		if (strs[i].length() < min_lenth)
			min_lenth = strs[i].length();
	}

	string suffix;
	for (int i = 1; i <= min_lenth; i++) {
		char c = strs[0][strs[0].size() - i];
		bool equal = true;
		for (int j = 1; j < num_str; j++) {
			if (strs[j][strs[j].size() - i] != c) {
				equal = false;
				break;
			}
		}
		if (equal)
			suffix += c;
		else
			break;
	}
	if (suffix.empty())
		cout << "nai";
	else {
		reverse(suffix.begin(), suffix.end());
		cout << suffix;
	}

	return 0;
}