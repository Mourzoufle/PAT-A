#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int num_element;										// number of elements in the sequence
	scanf("%d", &num_element);
	int *elements = new int[num_element];					// the elements sequence
	for (int i = 0; i < 2; i++)								// NOTE: the initial sequence is useless
		for (int j = 0; j < num_element; j++)
			scanf("%d", &elements[j]);

	if (elements[1] < elements[0]) {						// must be heap sort
		printf("Heap Sort\n");
		int size_heap = num_element;						// index of the last element in the heap
		while (elements[--size_heap] >= elements[0]);
		swap(elements[0], elements[size_heap]);				// the first element of the heap is now in the elements part
		int idx = 0;
		while (idx < size_heap) {
			int left = idx * 2 + 1, right = idx * 2 + 2;	// indices of left and right children in the heap
			if ((right < size_heap) && (elements[right] > elements[left]) && (elements[right] > elements[idx])) {
				swap(elements[idx], elements[right]);
				idx = right;
			}
			else if ((left < size_heap) && (elements[left] >elements[idx])) {
				swap(elements[idx], elements[left]);
				idx = left;
			}
			else
				break;
		}
	}
	else {
		printf("Insertion Sort\n");
		int idx = 1;										// index of the first unsorted element
		while (elements[idx] >= elements[idx - 1])
			idx++;
		sort(elements, elements + idx + 1);					// sort the first idx + 1 elements
	}
	printf("%d", elements[0]);
	for (int i = 1; i < num_element; i++)
		printf(" %d", elements[i]);

	return 0;
}