#include <cstdio>
#include <algorithm>

using namespace std;

struct Customer {
	int arriving_time;
	int serving_time;
};

bool compare(const Customer &a, const Customer&b) { return a.arriving_time < b.arriving_time; };

int main() {
	int num_customer, num_window;
	scanf("%d %d", &num_customer, &num_window);
	Customer *customers = new Customer[num_customer];
	for (int i = 0; i < num_customer; i++) {
		int hour, minute, second;
		scanf("%d:%d:%d %d", &hour, &minute, &second, &customers[i].serving_time);
		customers[i].arriving_time = hour * 3600 + minute * 60 + second;
		if (customers[i].serving_time > 60)
			customers[i].serving_time = 60;
	}
	sort(customers, customers + num_customer, compare);

	int *windows = new int[num_window];
	for (int i = 0; i < num_window; i++)
		windows[i] = 28800;
	int sum = 0, num_valid = 0;
	for (int i = 0; i < num_customer; i++) {
		if (customers[i].arriving_time > 61200)
			break;
		int idx = 0;
		for (int j = 1; j < num_window; j++)
			if (windows[idx] > windows[j])
				idx = j;
		if (windows[idx] > customers[i].arriving_time)
			sum += windows[idx] - customers[i].arriving_time;
		else
			windows[idx] = customers[i].arriving_time;
		windows[idx] += customers[i].serving_time * 60;
		num_valid++;
	}
	printf("%.1f", sum / 60.0 / num_valid);

	return 0;
}