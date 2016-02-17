#include <iostream>

using namespace std;

int next_prime(int num) {
	if (num < 2)
		return 2;
	num = ((num >> 1) << 1) + 1;
	while (true) {
		bool is_prime = true;
		for (int i = 3; i * i <= num; i += 2) {
			if (num % i == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime)
			return num;
		else
			num += 2;
	}
}

int insert(int *table, int size, int key) {
	int base = key % size;
	for (int i = 0; i < size; i++) {
		int pos = (base + i * i) % size;
		if (table[pos] == 0) {
			table[pos] = key;
			return pos;
		}
	}

	return -1;
}

int main() {
	int size, num;
	cin >> size >> num;
	size = next_prime(size);
	int *table = new int[size];
	for (int i = 0; i < size; i++)
		table[i] = 0;
	int *nums = new int[num];
	int *poses = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> nums[i];
		poses[i] = insert(table, size, nums[i]);
	}

	for (int i = 0; i < num; i++) {
		if (i > 0)
			cout << " ";
		if (poses[i] < 0)
			cout << "-";
		else
			cout << poses[i];
	}

	return 0;
}