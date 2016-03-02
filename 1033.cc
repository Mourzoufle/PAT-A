#include <cstdio>
#include <algorithm>

using namespace std;

struct Station {
	double distance;
	double price;
};

bool compare(const Station &a, const Station &b) { return a.distance < b.distance; }

int main() {
	double capacity, dst, avg_distance;
	int num_station;
	scanf("%lf %lf %lf %d", &capacity, &dst, &avg_distance, &num_station);
	Station *stations = new Station[num_station];
	for (int i = 0; i < num_station; i++)
		scanf("%lf %lf", &stations[i].price, &stations[i].distance);
	sort(stations, stations + num_station, compare);

	if (stations[0].distance > 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	int idx_cur = 0;
	double cur_capacity = 0, price = 0;
	while (true) {
		int idx_next = -1;
		for (int i = idx_cur + 1; i < num_station; i++) {
			if ((stations[i].distance >= dst) || (stations[i].distance - stations[idx_cur].distance > capacity * avg_distance))
				break;
			if ((idx_next < 0) || (stations[i].price < stations[idx_next].price)) {
				idx_next = i;
				if (stations[idx_next].price < stations[idx_cur].price)
					break;
			}
		}
		if (idx_next < 0) {
			if (dst - stations[idx_cur].distance > capacity * avg_distance)
				printf("The maximum travel distance = %.2f", stations[idx_cur].distance + capacity * avg_distance);
			else
				printf("%.2f", price + ((dst - stations[idx_cur].distance) / avg_distance - cur_capacity) * stations[idx_cur].price);
			break;
		}
		else {
			if (stations[idx_cur].price > stations[idx_next].price) {
				price += ((stations[idx_next].distance - stations[idx_cur].distance) / avg_distance - cur_capacity) * stations[idx_cur].price;
				cur_capacity = 0;
			}
			else if ((dst - stations[idx_cur].distance) <= capacity * avg_distance) {
				printf("%.2f", price + ((dst - stations[idx_cur].distance) / avg_distance - cur_capacity) * stations[idx_cur].price);
				break;
			}
			else {
				price += (capacity - cur_capacity) * stations[idx_cur].price;
				cur_capacity = capacity - (stations[idx_next].distance - stations[idx_cur].distance) / avg_distance;
			}
			idx_cur = idx_next;
		}
	}

	return 0;
}