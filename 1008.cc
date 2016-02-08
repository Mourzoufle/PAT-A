#include <iostream>

using namespace std;

int main() {
	int cur = 0, time = 0;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int next;
		cin >> next;
		if (next > cur)
			time += 6 * (next - cur);
		else
			time += 4 * (cur - next);
		cur = next;
	}
	cout << time + 5 * num;

	return 0;
}