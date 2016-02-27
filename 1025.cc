#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Record {
	long long id;
	int location;
	int score;
};

bool compare(Record *a, Record *b) {
	if (a->score != b->score)
		return a->score > b->score;
	return a->id < b->id;
}

int main() {
	vector<Record*> records;
	int num_location;
	scanf("%d", &num_location);
	for (int i = 0; i < num_location; i++) {
		int num_record;
		scanf("%d", &num_record);
		for (int j = 0; j < num_record; j++) {
			Record *record = new Record;
			scanf("%lld %d", &record->id, &record->score);
			record->location = i;
			records.push_back(record);
		}
	}
	sort(records.begin(), records.end(), compare);

	int *ranks = new int[num_location];
	int *scores = new int[num_location];
	int *nums_record = new int[num_location];
	for (int i = 0; i < num_location; i++) {
		ranks[i] = 1;
		scores[i] = 0;
		nums_record[i] = 0;
	}
	int rank = 1, score = records[0]->score;
	printf("%d\n", records.size());
	for (int i = 0; i < records.size(); i++) {
		nums_record[records[i]->location]++;
		if (scores[records[i]->location] > records[i]->score)
			ranks[records[i]->location] = nums_record[records[i]->location];
		scores[records[i]->location] = records[i]->score;
		if (score > records[i]->score)
			rank = i + 1;
		score = records[i]->score;
		printf("%013lld %d %d %d\n", records[i]->id, rank, records[i]->location + 1, ranks[records[i]->location]);
	}

	return 0;
}