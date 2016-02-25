#include <iostream>
#include <vector>

using namespace std;

void num_to_vec(int num, int base, vector<int> &vector) {
	while (num > 0) {
		vector.push_back(num % base);
		num /= base;
	}
	if (vector.empty())
		vector.push_back(0);
}

int main() {
	int num, base;
	cin >> num >> base;
	vector<int> vector;
	num_to_vec(num, base, vector);
	bool reverse = true;
	for (int i = 0; i < (vector.size() >> 1); i++) {
		if (vector[i] != vector[vector.size() - 1 - i]) {
			reverse = false;
			break;
		}
	}
	if (reverse)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << vector.back();
	for (int i = vector.size() - 2; i >= 0; i--)
		cout << " " << vector[i];

	return 0;
}