#include <cstdio>

int main() {
	int num_num;
	scanf("%d", &num_num);
	int *indices = new int[num_num];
	for (int i = 0; i < num_num; i++) {
		int num;
		scanf("%d", &num);
		indices[num] = i;
	}

	int num_swap = 0, head = 1;
	while (true) {
		int cur_num = indices[0];
		if (cur_num == 0) {
			for (int i = head; i < num_num; i++) {
				if (indices[i] != i) {
					cur_num = i;
					head = i + 1;
					break;
				}
			}
			if (cur_num == 0)
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