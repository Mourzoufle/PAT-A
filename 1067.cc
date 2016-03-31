#include <cstdio>

int main() {
	int num_num;						// number of the numbers
	scanf("%d", &num_num);
	int *indices = new int[num_num];	// index of each number - store numbers in this way to avoid repeatedly searching for them in the array
	for (int i = 0; i < num_num; i++) {
		int num;
		scanf("%d", &num);
		indices[num] = i;
	}

	int num_swap = 0, head = 1;			// number of swap operations; head of the number, numbers from which are unordered
	while (true) {
		int cur_num = indices[0];		// swap 0 and the number that should be in the current place of 0
		if (cur_num == 0) {				// 0 is in the right place - swap it with the first unordered number
			for (int i = head; i < num_num; i++) {
				if (indices[i] != i) {
					cur_num = i;
					head = i + 1;
					break;
				}
			}
			if (cur_num == 0)			// unordered number not found - the array is already sorted
				break;
			indices[0] = indices[cur_num];
			indices[cur_num] = 0;
		}
		else {
			indices[0] = indices[cur_num];
			indices[cur_num] = cur_num;
		}
		num_swap++;
	}
	printf("%d", num_swap);

	return 0;
}