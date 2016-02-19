#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Record {
	string id;
	int time;
	bool is_in;
};

int str_to_time(string str) {
	for (int i = 0; i < str.size(); i++)
		str[i] -= '0';

	return str[0] * 36000 + str[1] * 3600 + str[3] * 600 + str[4] * 60 + str[6] * 10 + str[7];
}

bool compare(const Record &a, const Record &b) { return a.time < b.time; } 

int main() {
	int num_record, num_query;
	cin >> num_record >> num_query;
	Record *records = new Record[num_record];
	map<string, int> indices;
	vector<string> ids;
	for (int i = 0; i < num_record; i++) {
		string id, time, status;
		cin >> id >> time >> status;
		if (indices.find(id) == indices.end()) {
			indices[id] = indices.size() - 1;
			ids.push_back(id);
		}
		records[i].id = id;
		records[i].time = str_to_time(time);
		records[i].is_in = status == "in";
	}
	sort(records, records + num_record, compare);

	int *ins = new int[indices.size()];
	int *sums = new int[indices.size()];
	for (int i = 0; i < indices.size(); i++) {
		ins[i] = -1;
		sums[i] = 0;
	}
	vector<Record *> vector;
	for (int i = 0; i < num_record; i++) {
		int idx = indices[records[i].id];
		if (records[i].is_in)
			ins[idx] = i;
		else if (ins[idx] >= 0) {
			vector.push_back(records + ins[idx]);
			vector.push_back(records + i);
			sums[idx] += records[i].time - records[ins[idx]].time;
			ins[idx] = -1;
		}
	}
	sort(vector.begin(), vector.end());

	int *nums = new int[86400];
	int num = 0, time = 0;
	for (int i = 0; i < vector.size(); i++) {
		while (time < vector[i]->time)
			nums[time++] = num;
		num += vector[i]->is_in ? 1 : -1;
		nums[time] = num;
	}
	for (int i = vector.back()->time + 1; i < 86400; i++)
		nums[i] = num;

	for (int i = 0; i < num_query; i++) {
		string id;
		cin >> id;
		cout << nums[str_to_time(id)] << endl;
	}
	string maxs;
	int max = -1;
	for (int i = 0; i < indices.size(); i++) {
		if (sums[i] > max) {
			max = sums[i];
			maxs = ids[i] + " ";
		}
		else if (sums[i] == max)
			maxs += ids[i] + " ";
	}
	cout << maxs;
	printf("%02d:%02d:%02d", max / 3600, (max % 3600) / 60, max % 60);

	return 0;
}