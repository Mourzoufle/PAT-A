#include <cstdio>
#include <cmath>

/* check if the number is prime */
bool is_prime(int num) {
	if (num < 2)					// 0, 1 - false
		return false;
	if (num < 4)					// 2, 3 - true
		return true;
	if (num % 2 == 0)				// even numbers beside of 2 - false
		return false;
	int limit = sqrt(num);			// only need to check factors not greater than sqrt(num)
	for (int i = 3; i <= limit; i += 2)
		if (num % i == 0)
			return false;
	return true;
}

/* insert the key into the given table */
int insert(int *table, int size, int key) {
	int base_addr = key % size;		// the base address address of the key
	for (int i = 0; i < size; i++) {
		int cur_addr = (base_addr + i * i) % size;
		if (table[cur_addr] == 0) {	// the current address is available
			table[cur_addr] = key;
			return cur_addr;
		}
	}
	return -1;						// the key cannot get a position to be inserted
}

int main() {
	int size, num_key;
	scanf("%d %d", &size, &num_key);
	if (size < 3)					// find the next prime
		size = 2;
	else {
		size = size / 2 * 2 + 1;
		while (!is_prime(size))
			size += 2;
	}
	int *table = new int[size];
	for (int i = 0; i < size; i++)
		table[i] = 0;
	for (int i = 0; i < num_key; i++) {
		if (i > 0)
			printf(" ");
		int key;
		scanf("%d", &key);
		int addr = insert(table, size, key);
		if (addr < 0)
			printf("-");
		else
			printf("%d", addr);
	}

	return 0;
}