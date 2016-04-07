#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int num_element;						// number of elements in the sequence
	scanf("%d", &num_element);
	int *initial = new int[num_element];	// the initial sequence
	for (int i = 0; i < num_element; i++)
		scanf("%d", &initial[i]);
	int *sorted = new int[num_element];		// the partially sorted sequence
	for (int i = 0; i < num_element; i++)
		scanf("%d", &sorted[i]);

	int idx = 1;							// index of the first unsorted element
	while (sorted[idx] >= sorted[idx - 1])
		idx++;
	bool is_insertion = true;				// flag indicating if the method is insertion sort
	for (int i = idx; i < num_element; i++) {
		if (initial[i] != sorted[i]) {
			is_insertion = false;
			break;
		}
	}

	if (is_insertion) {
		printf("Insertion Sort\n");
		sort(sorted, sorted + idx + 1);		// sort the first idx + 1 elements
	}
	else {
		printf("Merge Sort\n");
		int cur_size = 2;					// current size of merge sort - the number of finished iteration >= 1
		while (cur_size < num_element / 2) {
			bool finish = true;				// flag indicating the next iteration is finished
			for (int i = cur_size; i < num_element; i += cur_size * 2) {
				if (sorted[i] < sorted[i - 1]) {
					finish = false;
					break;
				}
			}
			if (!finish)
				break;
			cur_size *= 2;
		}
		cur_size *= 2;
		for (int i = 0; i < num_element; i += cur_size)
			sort(sorted + i, sorted + min(i + cur_size, num_element));
	}
	printf("%d", sorted[0]);
	for (int i = 1; i < num_element; i++)
		printf(" %d", sorted[i]);

	return 0;
}