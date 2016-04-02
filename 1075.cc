#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct User {
	int id;
	int *scores;																	// score of each problem
	int num_full;																	// number of problems that is full scored
	int total_score;																// total score

	void set(int id, int num_problem) {
		this->id = id;
		this->scores = new int[num_problem];
		for (int i = 0; i < num_problem; i++)
			this->scores[i] = -2;													// -2: no solution has submitted for this problem
		this->num_full = 0;
		this->total_score = 0;
	}
};

/* compare fuction for sorting users - first according to their total scores, then number of problems that are full scored if there is a tie, then the IDs */
bool cmp(User *a, User *b) {
	if (a->total_score != b->total_score)
		return a->total_score > b->total_score;
	if (a->num_full != b->num_full)
		return a->num_full > b->num_full;
	return a->id < b->id;
}

int main() {
	int num_user, num_problem, num_submit;
	scanf("%d %d %d", &num_user, &num_problem, &num_submit);
	int *scores_full = new int[num_problem];										// full score of each problem
	for (int i = 0; i < num_problem; i++)
		scanf("%d", &scores_full[i]);
	User *users = new User[num_user];
	for (int i = 0; i < num_user; i++)
		users[i].set(i, num_problem);
	for (int i = 0; i < num_submit; i++) {
		int user, problem, score;
		scanf("%d %d %d", &user, &problem, &score);
		if (score > users[--user].scores[--problem]) {
			users[user].total_score += max(score, 0) - max(users[user].scores[problem], 0);
			users[user].scores[problem] = score;
			if (score == scores_full[problem])										// got full score on this problem
				users[user].num_full++;
		}
	}

	vector<User *> users_valid;														// users that have got score for any problem
	for (int i = 0; i < num_user; i++) {
		for (int j = 0; j < num_problem; j++) {
			if (users[i].scores[j] >= 0) {
				users_valid.push_back(users + i);
				break;
			}
		}
	}
	sort(users_valid.begin(), users_valid.end(), cmp);
	int cur_rank = 1;																// current rank
	for (int i = 0; i < users_valid.size(); i++) {
		if (users_valid[i]->total_score < users_valid[cur_rank - 1]->total_score)	// current user has lower score
			cur_rank = i + 1;
		printf("%d %05d %d", cur_rank, users_valid[i]->id + 1, users_valid[i]->total_score);
		for (int j = 0; j < num_problem; j++) {
			int score = users_valid[i]->scores[j];
			if (score == -2)
				printf(" -");
			else
				printf(" %d", max(score, 0));
		}
		printf("\n");
	}

	return 0;
}