#include <cstdio>
#include <algorithm>

using namespace std;

struct Station {
	double distance;																											// distance from place of departure
	double price;																												// price of gas
};

/* compare fuction for stations - from the nearest to the farthest */
bool cmp(const Station &a, const Station &b) { return a.distance < b.distance; }

int main() {
	double capacity, dst, avg_distance;																							// tank capacity; the destination; average distance per unit gas can run
	int num_station;
	scanf("%lf %lf %lf %d", &capacity, &dst, &avg_distance, &num_station);
	Station *stations = new Station[num_station];
	for (int i = 0; i < num_station; i++)
		scanf("%lf %lf", &stations[i].price, &stations[i].distance);
	sort(stations, stations + num_station, cmp);

	if (stations[0].distance > 0) {																								// the car cannot get filled even at the place of departure!
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	int idx_cur = 0;																											// current station the car is located
	double cur_capacity = 0, price = 0;																							// current available capacity of the tank
	while (true) {
		int idx_next = -1;																										// the next station that the car will get filled
		for (int i = idx_cur + 1; i < num_station; i++) {
			if ((stations[i].distance >= dst) || (stations[i].distance - stations[idx_cur].distance > capacity * avg_distance))	// end searching when the distance of the station is further than the destination or cannot be reached even with a full tank
				break;
			if ((idx_next < 0) || (stations[i].price < stations[idx_next].price)) {												// find a station whose price of gas is lower - it will be the next station the car get filled
				idx_next = i;
				if (stations[idx_next].price < stations[idx_cur].price)															// the price is even lower than the current station - just get there!
					break;
			}
		}
		if (idx_next < 0) {																										// no station to go for
			if (dst - stations[idx_cur].distance > capacity * avg_distance)														// if the car cannot get to the destination - print the maximum distance
				printf("The maximum travel distance = %.2f", stations[idx_cur].distance + capacity * avg_distance);
			else																												// or print the total price
				printf("%.2f", price + ((dst - stations[idx_cur].distance) / avg_distance - cur_capacity) * stations[idx_cur].price);
			break;
		}
		else {
			if (stations[idx_cur].price > stations[idx_next].price) {															// the next station has cheaper gas - fill the tank at the current station with gas just enough to get to the next one
				price += ((stations[idx_next].distance - stations[idx_cur].distance) / avg_distance - cur_capacity) * stations[idx_cur].price;
				cur_capacity = 0;
			}
			else if ((dst - stations[idx_cur].distance) <= capacity * avg_distance) {											// or no cheaper gas the car can currently expect, but the current station can make it get to the destination - fill just enough gas
				printf("%.2f", price + ((dst - stations[idx_cur].distance) / avg_distance - cur_capacity) * stations[idx_cur].price);
				break;
			}
			else {																												// or make the tank full at the current station, and search at the next one
				price += (capacity - cur_capacity) * stations[idx_cur].price;
				cur_capacity = capacity - (stations[idx_next].distance - stations[idx_cur].distance) / avg_distance;
			}
			idx_cur = idx_next;
		}
	}

	return 0;
}