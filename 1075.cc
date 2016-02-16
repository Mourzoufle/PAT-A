#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct User {
	int id;
	int *scores;
	int num_full;
	int total;

	void init(int id, int num_problem) {
		this->id = id;
		this->scores = new int[num_problem];
		for (int i = 0; i < num_problem; i++)
			this->scores[i] = -2;
		this->num_full = 0;
		this->total = 0;
	}
};

bool compare(User *a, User *b) {
	if (a->total != b->total)
		return a->total > b->total;
	if (a->num_full != b->num_full)
		return a->num_full > b->num_full;
	return a->id < b->id;
}

int main() {
	int num_user, num_problem, num_submit;
	scanf("%d %d %d", &num_user, &num_problem, &num_submit);
	int *scores = new int[num_problem];
	for (int i = 0; i < num_problem; i++)
		scanf("%d", scores + i);
	User *users = new User[num_user];
	for (int i = 0; i < num_user; i++)
		users[i].init(i, num_problem);
	for (int i = 0; i < num_submit; i++) {
		int idx_user, idx_problem, score;
		scanf("%d %d %d", &idx_user, &idx_problem, &score);
		if (score > users[--idx_user].scores[--idx_problem])
			users[idx_user].scores[idx_problem] = score;
	}

	vector<User *> ranks;
	for (int i = 0; i < num_user; i++) {
		bool show = false;
		for (int j = 0; j < num_problem; j++) {
			int score = users[i].scores[j];
			if (score > -1)
				show = true;
			if (score > 0)
				users[i].total += score;
			if (score == scores[j])
				users[i].num_full++;
		}
		if (show)
			ranks.push_back(users + i);
	}
	sort(ranks.begin(), ranks.end(), compare);

	int cur_rank = 1;
	for (int i = 0; i < ranks.size(); i++) {
		if (ranks[i]->total < ranks[cur_rank - 1]->total)
			cur_rank = i + 1;
		printf("%d %05d %d", cur_rank, ranks[i]->id + 1, ranks[i]->total);
		for (int j = 0; j < num_problem; j++) {
			int score = ranks[i]->scores[j];
			if (score == -2)
				printf(" -");
			else
				printf(" %d", score > 0 ? score : 0);
		}
		printf("\n");
	}

	return 0;
}