#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Record {
	string plate;										// plate number
	int time;
	bool is_in;
};

/* compare fuction for sorting records - according to their time */
bool cmp(const Record &a, const Record &b) { return a.time < b.time; } 

int main() {
	int num_record, num_query;
	scanf("%d %d", &num_record, &num_query);
	Record *records = new Record[num_record];
	for (int i = 0; i < num_record; i++) {
		char plate[16], status[4];
		int hour, minute, second;
		scanf("%s %d:%d:%d %s", plate, &hour, &minute, &second, status);
		records[i].plate = plate;
		records[i].time = hour * 3600 + minute * 60 + second;
		records[i].is_in = status[0] == 'i';			// "in"
	}
	sort(records, records + num_record, cmp);

	map<string, int> str_to_idx;						// index of each plate number in the records
	vector<string> plates;
	vector<int> indices_in;								// index of the last record whose status is in of each plates
	vector<int> periods;								// period of parking time of each car
	vector<Record *> records_valid;						// the valid records
	for (int i = 0; i < num_record; i++) {
		string plate = records[i].plate;
		if (str_to_idx.find(plate) == str_to_idx.end()) {
			str_to_idx[plate] = str_to_idx.size() - 1;
			plates.push_back(plate);
			indices_in.push_back(records[i].is_in ? i : -1);
			periods.push_back(0);
		}
		int idx = str_to_idx[plate];
		if (records[i].is_in)							// got a record whose status is in
			indices_in[idx] = i;
		else if (indices_in[idx] >= 0) {				// or the record is valid if there is already a record whose status is in
			records_valid.push_back(records + indices_in[idx]);
			records_valid.push_back(records + i);
			periods[idx] += records[i].time - records[indices_in[idx]].time;
			indices_in[idx] = -1;
		}
	}
	sort(records_valid.begin(), records_valid.end());	// the original records are already sorted, only need to sort the valid ones according to their address

	int num_park = 0, head = 0;							// number of parked cars; the first record that is not counted in calculating the number of parked cars
	for (int i = 0; i < num_query; i++) {
		int hour, minute, second;
		scanf("%d:%d:%d", &hour, &minute, &second);
		int time = hour * 3600 + minute * 60 + second;
		while (head < records_valid.size()) {
			if (records_valid[head]->time > time)		// record out of the range of time
				break;
			else
				num_park += records_valid[head++]->is_in ? 1 : -1;
		}
		printf("%d\n", num_park);
	}

	vector<string> plates_max;							// cars that have parked for the longest time period
	int max_period = 0;
	for (int i = 0; i < periods.size(); i++) {
		if (periods[i] > max_period) {
			max_period = periods[i];
			plates_max.clear();
			plates_max.push_back(plates[i]);
		}
		else if (periods[i] == max_period)
			plates_max.push_back(plates[i]);
	}
	sort(plates_max.begin(), plates_max.end());
	for (int i = 0; i < plates_max.size(); i++)
		printf("%s ", plates_max[i].c_str());
	printf("%02d:%02d:%02d", max_period / 3600, (max_period % 3600) / 60, max_period % 60);

	return 0;
}