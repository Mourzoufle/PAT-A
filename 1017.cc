#include <cstdio>
#include <algorithm>

using namespace std;

struct Customer {
	int time_arrive;																					// arriving time
	int time_serve;																						// time needed for serving this customer - in seconds
};

/* compare fuction for sorting customers - according to their arriving time */
bool cmp(const Customer &a, const Customer &b) { return a.time_arrive < b.time_arrive; };

int main() {
	int num_customer, num_window;
	scanf("%d %d", &num_customer, &num_window);
	Customer *customers = new Customer[num_customer];
	for (int i = 0; i < num_customer; i++) {
		int hour, minute, second;
		scanf("%d:%d:%d %d", &hour, &minute, &second, &customers[i].time_serve);
		customers[i].time_arrive = hour * 3600 + minute * 60 + second;									// convert time to seconds
		customers[i].time_serve = customers[i].time_serve > 60 ? 3600 : customers[i].time_serve * 60;	// serving time may not exceed an hour
	}
	sort(customers, customers + num_customer, cmp);

	int *windows = new int[num_window];																	// available time of each window
	for (int i = 0; i < num_window; i++)
		windows[i] = 28800;																				// open at 8:00
	double time_wait = 0, num_valid = 0;																// total waiting time; number of customers that actually get served
	for (int i = 0; i < num_customer; i++) {
		if (customers[i].time_arrive > 61200)															// customers come after 17:00 will not get served
			break;
		int cur_window = 0;
		for (int j = 1; j < num_window; j++)
			if (windows[j] < windows[cur_window])														// the current customer will choose the first available window
				cur_window = j;
		if (windows[cur_window] > customers[i].time_arrive)												// the customer comes before the window is available - has to wait
			time_wait += windows[cur_window] - customers[i].time_arrive;
		else
			windows[cur_window] = customers[i].time_arrive;												// or reset the time this window starts to serve
		windows[cur_window] += customers[i].time_serve;													// the time this window is available again
		num_valid++;
	}
	printf("%.1lf", time_wait / 60 / num_valid);														// print the average waiting time IN MINUTES

	return 0;
}