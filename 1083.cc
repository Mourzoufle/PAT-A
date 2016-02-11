#include <iostream>
#include <algorithm>

using namespace std;

struct Record {
	string name;
	string id;
	int grade;
};

bool compare(const Record &a, const Record &b) { return a.grade > b.grade; }

int main() {
	int num_record;
	cin >> num_record;
	Record *records = new Record[num_record];
	for (int i = 0; i < num_record; i++)
		cin >> records[i].name >> records[i].id >> records[i].grade;
	sort(records, records + num_record, compare);
	int lower, upper;
	cin >> lower >> upper;
	if ((records[0].grade < lower) || (records[num_record - 1].grade > upper))
		cout << "NONE";
	else {
		for (int i = 0; i < num_record; i++) {
			if (records[i].grade < lower)
				break;
			else if (records[i].grade <= upper)
				cout << records[i].name << " " << records[i].id << endl;
		}
	}

	return 0;
}