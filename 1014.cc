#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

void print(int time) {
	if (time < 0)
		cout << "Sorry" << endl;
	else
		printf("%02d:%02d\n", time / 60, time % 60);
}

int main() {
	int num_window, capacity, num_customer, num_query;
	cin >> num_window >> capacity >> num_customer >> num_query;
	int *finishes = new int[num_customer];
	queue<int> *windows = new queue<int>[num_window];
	for (int i = 0; i < num_window; i++)
		windows[i].push(480);

	for (int i = 0; i < num_customer; i++) {
		int idx = 0;
		for (int j = 1; j < num_window; j++)
			if (windows[idx].size() > windows[j].size())
				idx = j;
		if (windows[idx].size() == capacity) {
			idx = 0;
			for (int j = 1; j < num_window; j++) {
				if (windows[idx].front() > windows[j].front())
					idx = j;
			}
			windows[idx].pop();
		}
		cin >> finishes[i];
		if ((windows[idx].back() >= 1020) || (windows[idx].back() < 0))
			finishes[i] = -1;
		else
			finishes[i] += windows[idx].back();
		windows[idx].push(finishes[i]);
	}

	for (int i = 0; i < num_query; i++) {
		int idx;
		cin >> idx;
		print(finishes[--idx]);
	}

	return 0;
}