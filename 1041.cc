#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;
	int *numbers = new int[num];
	int *counts = new int[10240];
	for (int i = 0; i < 10240; i++)
		counts[i] = 0;
	for (int i = 0; i < num; i++) {
		cin >> numbers[i];
		counts[numbers[i]]++;
	}
	for (int i = 0; i < num; i++) {
		if (counts[numbers[i]] == 1) {
			cout << numbers[i];
			return 0;
		}
	}
	cout << "None";

	return 0;
}