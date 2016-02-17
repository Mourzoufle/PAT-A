#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int num, ratio;
	cin >> num >> ratio;
	int *nums = new int[num];
	for (int i = 0; i < num; i++)
		cin >> nums[i];
	sort(nums, nums + num);

	int length = 1;
	for (int i = 0; i < num; i++) {
		while (i + length < num) {
			if (nums[i] < 1.0 * nums[i + length] / ratio)
				break;
			length++;
		}
	}
	cout << length;

	return 0;
}