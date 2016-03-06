#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

double prices[24];												// price in each hour

struct Time {
	int day;
	int hour; 
	int minute;

	void next_hour() {											// get the top of the next hour after the current time
		if (++hour == 24) {										// a new day begins
			day++;
			hour = 0;
		}
		minute = 0;
	}

	bool operator < (const Time &time) const {					// operator overloading
		if (day != time.day)
			return day < time.day;
		if (hour != time.hour)
			return hour < time.hour;
		return minute < time.minute;
	}
};

struct Record {
	char name[32];
	Time time;
	bool is_on;
};

/* compare fuction for sorting records - records with same name sorted together */
bool cmp(const Record &a, const Record &b) {
	if (strcmp(a.name, b.name) != 0)
		return strcmp(a.name, b.name) < 0;
	return a.time < b.time;
}

/* get length and price of a phone call between the head and the tail time */
void compute(Time head, Time &tail, int &length, double &price) {
	length = 0, price = 0;
	Time next = head;
	for (next.next_hour(); !(tail < next); next.next_hour()) {	// compute at each top of the hour till the next hour is out of range
		length += 60 - head.minute;
		price += prices[head.hour] * (60 - head.minute);
		head = next;
	}
	length += tail.minute - head.minute;						// if the call not ends at the top of an hour
	price += prices[head.hour] * (tail.minute - head.minute);
}

int main() {
	for (int i = 0; i < 24; i++) {
		scanf("%lf", &prices[i]);
		prices[i] /= 100;										// from cents to dollars
	}
	int num_record, month;
	scanf("%d", &num_record);
	Record *records = new Record[num_record];
	for (int i = 0; i < num_record; i++) {
		char status[16];
		scanf("%s %d:%d:%d:%d %s", &records[i].name, &month, &records[i].time.day, &records[i].time.hour, &records[i].time.minute, status);
		records[i].is_on = status[1] == 'n';					// "on-line"
	}
	sort(records, records + num_record, cmp);

	char cur_name[16];											// name of current user
	bool print = false;											// if the current user has corrent record(s) and should be printed
	int idx_on;													// the index of the latest record whose status is on-line
	double total_price;
	for (int i = 0; i < num_record; i++) {
		if (strcmp(cur_name, records[i].name) != 0) {			// begin to deal with records of a new user
			if (print)											// the former user has corrent record(s) - then print the total price
				printf("Total amount: $%.2f\n", total_price);
			strcpy(cur_name, records[i].name);
			print = false;
			idx_on = -1;
			total_price = 0;
		}
		if (records[i].is_on)									// got an on-line record
			idx_on = i;
		else if (idx_on >= 0) {									// got an off-line record and can be paired with an on-line one
			if (!print) {										// information of the current has not been printed yet
				printf("%s %02d\n", cur_name, month);
				print = true;									// this user should be printed
			}
			int cur_length;
			double cur_price;
			compute(records[idx_on].time, records[i].time, cur_length, cur_price);
			total_price += cur_price;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", records[idx_on].time.day, records[idx_on].time.hour, records[idx_on].time.minute, records[i].time.day, records[i].time.hour, records[i].time.minute, cur_length, cur_price);
			idx_on = -1;
		}	
	}
	if (print)													// DO NOT FORGET - the last user has not been checked yet
		printf("Total amount: $%.2f\n", total_price);

	return 0;
}