#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int num_day;
	cin >> num_day;
	int *days = new int[num_day];
	for (int i = 0; i < num_day; i++)
		cin >> days[i];

	sort(days, days + num_day);
	int e_num = 0;
	for (int i = 0; i + e_num < num_day; i++)
		e_num = max(e_num, min(days[i] - 1, num_day - i));
	cout << e_num;

	return 0;
}