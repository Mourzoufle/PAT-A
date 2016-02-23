#include <iostream>
#include <vector>

using namespace std;

int main() {
	int num;
	cin >> num;
	int *nums = new int[num];
	for (int i = 0; i < num; i++)
		cin >> nums[i];
	vector<int> valids;
	int max = nums[0];
	valids.push_back(max);
	for (int i = 1; i < num; i++) {
		if (nums[i] < max)
			while (!valids.empty()) {
				if (nums[i] < valids.back())
					valids.pop_back();
				else
					break;
			}
		else {
			max = nums[i];
			valids.push_back(max);
		}
	}
	cout << valids.size() << endl;
	if (!valids.empty()) {
		cout << valids[0];
		for (int i = 1; i < valids.size(); i++)
			cout << " " << valids[i];
	}
	cout << endl;

	return 0;
}