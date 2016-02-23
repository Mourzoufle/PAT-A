#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int prices[24];

struct Time {
	int month;
	int day;
	int hour; 
	int minute;

	void next_hour() {
		if (++this->hour == 24) {
			this->day++;
			this->hour = 0;
		}
		this->minute = 0;
	}
};

struct Record {
	string name;
	Time time;
	bool is_on;
};

bool before(const Time &a, const Time &b) {
	if (a.month != b.month)
		return a.month < b.month;
	if (a.day != b.day)
		return a.day < b.day;
	if (a.hour != b.hour)
		return a.hour < b.hour;
	return a.minute < b.minute;
}

bool compare(const Record &a, const Record &b) {
	if (a.name != b.name)
		return a.name < b.name;
	return before(a.time, b.time);
}

int get_price(Time &head, Time &tail, double &price) {
	int res = 0;
	price = 0;
	Time cur = head;
	Time next = cur;
	next.next_hour();
	while (!before(tail, next)) {
		res += 60 - cur.minute;
		price += 0.01 * prices[cur.hour] * (60 - cur.minute);
		cur = next;
		next.next_hour();
	}
	price += 0.01 * prices[cur.hour] * (tail.minute - cur.minute);
	return res + tail.minute - cur.minute;
}

int main() {
	for (int i = 0; i < 24; i++)
		scanf("%d", &prices[i]);
	int num_record;
	scanf("%d", &num_record);
	Record *records = new Record[num_record];
	for (int i = 0; i < num_record; i++) {
		char name[32], status[16];
		scanf("%s %d:%d:%d:%d %s", name, &records[i].time.month, &records[i].time.day, &records[i].time.hour, &records[i].time.minute, status);
		records[i].name = name;
		records[i].is_on = status[1] == 'n';
	}
	sort(records, records + num_record, compare);

	string cur_name;
	bool print;
	int on_idx;
	double sum;
	for (int i = 0; i < num_record; i++) {
		if (cur_name != records[i].name) {
			if (!cur_name.empty() && sum > 0)
				printf("Total amount: $%.2f\n", sum);
			cur_name = records[i].name;
			print = false;
			on_idx = -1;
			sum = 0;
		}
		if (records[i].is_on)
			on_idx = i;
		else if (on_idx >= 0) {
			if (!print) {
				printf("%s %02d\n", cur_name.c_str(), records[i].time.month);
				print = true;
			}
			double cur;
			int time = get_price(records[on_idx].time, records[i].time, cur);
			sum += cur;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", records[on_idx].time.day, records[on_idx].time.hour, records[on_idx].time.minute, records[i].time.day, records[i].time.hour, records[i].time.minute, time, cur);
			on_idx = -1;
		}
	}
	if (sum > 0)
		printf("Total amount: $%.2f\n", sum);

	return 0;
}