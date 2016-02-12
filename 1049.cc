#include <iostream>

using namespace std;

int main() {
	int num, count = 0;
	cin >> num;
	for (int expon = 1; expon <= num; expon *= 10) {
		int upper = num / (expon * 10), lower = num % (expon * 10);
		count += upper * expon + (lower >= expon ? (lower >= (expon << 1) ? expon : lower - expon + 1) : 0);
	}
	cout << count;

	return 0;
}