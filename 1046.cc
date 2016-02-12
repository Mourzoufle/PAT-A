#include <iostream>

using namespace std;

int main() {
	int num_distance, num_query;
	cin >> num_distance;
	int *distances = new int[num_distance];
	int total_distance = 0;
	for (int i = 0; i < num_distance; i++) {
		cin >> distances[i];
		total_distance += distances[i];
		if (i > 0)
			distances[i] += distances[i - 1];
	}
	cin >> num_query;
	for (int i = 0; i < num_query; i++) {
		int head, tail;
		cin >> head >> tail;
		int distance = (tail > 1 ? distances[tail - 2] : 0) - (head > 1 ? distances[head - 2] : 0);
		if (distance < 0)
			distance = -distance;
		cout << (distance > (total_distance >> 1) ? total_distance - distance : distance) << endl;
	}

	return 0;
}