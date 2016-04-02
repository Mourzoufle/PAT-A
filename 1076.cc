#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

/* BFS - compute number of forwards the given user can get */
int get_num_forward(vector<int> *followers_users, int num_user, int user, int level) {
	bool *forward = new bool[num_user];							// flags indicating whether each user has forwarded the post
	for (int i = 0; i < num_user; i++)
		forward[i] = false;
	forward[user] = true;
	int num_forward = 0;
	queue<int> queue;											// BFS
	queue.push(user);
	for (int i = 0; i < level; i++) {
		int cur_size = queue.size();
		for (int j = 0; j < cur_size; j++) {
			int user = queue.front();
			for (int k = 0; k < followers_users[user].size(); k++) {
				int follower = followers_users[user][k];
				if (!forward[follower]) {						// this follower has not forwarded the post yet
					queue.push(follower);
					num_forward++;
					forward[follower] = true;
				}
			}
			queue.pop();
		}
	}
	delete[] forward;

	return num_forward;
}

int main() {
	int num_user, level;										// number of users; number of levels of indirect followers that are counted
	scanf("%d %d", &num_user, &level);
	vector<int> *followers_users = new vector<int>[num_user];	// followers of each user
	for (int i = 0; i < num_user; i++) {
		int num_follow;											// number of users this user follows
		scanf("%d", &num_follow);
		for (int j = 0; j < num_follow; j++) {
			int user;
			scanf("%d", &user);
			followers_users[--user].push_back(i);
		}
	}

	int *nums_forward = new int[num_user];						// number of forwards each user can get
	for (int i = 0; i < num_user; i++)
		nums_forward[i] = -1;									// all the numbers of forwards are not computed yet
	int num_query;
	scanf("%d", &num_query);
	for (int i = 0; i < num_query; i++) {
		int user;
		scanf("%d", &user);
		if (nums_forward[--user] < 0)
			nums_forward[user] = get_num_forward(followers_users, num_user, user, level);
		printf("%d\n", nums_forward[user]);
	}

	return 0;
}