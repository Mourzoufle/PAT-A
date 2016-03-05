#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int num_window, capacity, num_customer, num_query;
	scanf("%d %d %d %d", &num_window, &capacity, &num_customer, &num_query);
	int *finishes = new int[num_customer];												// finish time of each customer
	queue<int> *windows = new queue<int>[num_window];
	for (int i = 0; i < num_window; i++)												// open at 8:00 - assume each window has a customer till that time
		windows[i].push(480);
	for (int i = 0; i < num_customer; i++) {
		int cur_window = 0;																// find the window has shortest queue
		for (int j = 1; j < num_window; j++)
			if (windows[j].size() < windows[cur_window].size())
				cur_window = j;
		if (windows[cur_window].size() == capacity) {									// all windows are full
			cur_window = 0;
			for (int j = 1; j < num_window; j++) {
				if (windows[j].front() < windows[cur_window].front())					// then find the window that the head of the queue leaves earliest
					cur_window = j;
			}
			windows[cur_window].pop();													// in this case the queue should be updated
		}
		scanf("%d", &finishes[i]);														// finish time = serve time + processing time
		if ((windows[cur_window].back() >= 1020) || (windows[cur_window].back() < 0))	// the previous one finishes after 17:00 or cannot get served
			finishes[i] = -1;															// then this customer cannot be served
		else
			finishes[i] += windows[cur_window].back();
		windows[cur_window].push(finishes[i]);
	}
	for (int i = 0; i < num_query; i++) {
		int customer;
		scanf("%d", &customer);
		if (finishes[--customer] < 0)
			printf("Sorry\n");
		else
			printf("%02d:%02d\n", finishes[customer] / 60, finishes[customer] % 60);
	}

	return 0;
}