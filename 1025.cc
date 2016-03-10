#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Record {
	long long id;
	int location;
	int score;
};

/* compare fuction for sorting records - sorted by score, then id if the scores are equal */
bool cmp(Record *a, Record *b) {
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
	sort(records.begin(), records.end(), cmp);

	int *nums_record = new int[num_location];						// number of records in each location that are already processed
	int *cur_ranks = new int[num_location];							// current rank in each location
	int *cur_scores = new int[num_location];						// corresponding score of the current rank in each location
	for (int i = 0; i < num_location; i++) {
		cur_ranks[i] = 1;
		cur_scores[i] = 0;
		nums_record[i] = 0;
	}
	int cur_rank = 1, cur_score = records[0]->score;				// current global rank and score
	printf("%d\n", records.size());
	for (int i = 0; i < records.size(); i++) {
		nums_record[records[i]->location]++;
		if (cur_scores[records[i]->location] > records[i]->score)	// lower than the current score of this location, update current rank
			cur_ranks[records[i]->location] = nums_record[records[i]->location];
		cur_scores[records[i]->location] = records[i]->score;
		if (cur_score > records[i]->score)							// lower than current global score, update current global rank
			cur_rank = i + 1;
		cur_score = records[i]->score;
		printf("%013lld %d %d %d\n", records[i]->id, cur_rank, records[i]->location + 1, cur_ranks[records[i]->location]);
	}

	return 0;
}