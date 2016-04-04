#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Record {
	char name[16];
	char id[16];
	int grade;
};

/* compare fuction for sorting records - according to grades */
bool cmp(Record *a, Record *b) { return a->grade > b->grade; }

int main() {
	int num_record;
	scanf("%d", &num_record);
	Record *records = new Record[num_record];
	for (int i = 0; i < num_record; i++)
		scanf("%s %s %d", records[i].name, records[i].id, &records[i].grade);
	int lower, upper;	// lower and upper bounds of the interval
	scanf("%d %d", &lower, &upper);

	vector<Record *> records_valid;
	for (int i = 0; i < num_record; i++)
		if ((records[i].grade >= lower) && (records[i].grade <= upper))
			records_valid.push_back(records + i);
	if (records_valid.empty())
		printf("NONE");
	else {
		sort(records_valid.begin(), records_valid.end(), cmp);
		for (int i = 0; i < records_valid.size(); i++)
			printf("%s %s\n", records_valid[i]->name, records_valid[i]->id);
	}

	return 0;
}