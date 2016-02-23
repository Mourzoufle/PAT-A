#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string nums[][13] = {
	"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
	"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"
};

int main() {
	int num;
	cin >> num;
	cin.ignore();
	for (int i = 0; i < num; i++) {
		string str;
		getline(cin, str);
		if ((str[0] >= '0') && (str[0] <= '9')) {
			stringstream ss;
			int value;
			ss << str;
			ss >> value;
			if (value > 12) {
				cout << nums[1][value / 13];
				if (value % 13 > 0)
					cout << " " << nums[0][value % 13];
				cout << endl;
			}
			else
				cout << nums[0][value % 13] << endl;
		}
		else {
			int value = 0;
			int idx = str.find(" ");
			if (idx != string::npos) {
				for (int j = 0; j < 13; j++) {
					if (nums[1][j] == str.substr(0, idx)) {
						value = j * 13;
						break;
					}
				}
				str = str.substr(idx + 1);
			}
			for (int j = 0; j < 13; j++) {
				if (nums[0][j] == str) {
					value += j;
					break;
				}
				if (nums[1][j] == str) {
					value = j * 13;
					break;
				}
			}
			cout << value << endl;
		}
	}

	return 0;
}