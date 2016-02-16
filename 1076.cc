#include <iostream>
#include <list>
#include <queue>

using namespace std;

int BFS(int *reposts, list<int> *users, int num_user, int depth, int user) {
	bool *post = new bool[num_user];
	for (int i = 0; i < num_user; i++)
		post[i] = false;
	post[user] = true;
	queue<int> followers;
	followers.push(user);
	for (int i = 0; i < depth; i++) {
		int num_follower = followers.size();
		for (int j = 0; j < num_follower; j++) {
			int follower = followers.front();
			followers.pop();
			for (list<int>::iterator iter = users[follower].begin(); iter != users[follower].end(); iter++) {
				if (!post[*iter]) {
					followers.push(*iter);
					post[*iter] = true;
				}
			}
		}
	}
	for (int i = 0; i < num_user; i++)
		if (post[i])
			reposts[user]++;
	delete[] post;

	return reposts[user];
}

int main() {
	int num_user, depth;
	cin >> num_user >> depth;
	list<int> *users = new list<int>[num_user];
	for (int i = 0; i < num_user; i++) {
		int num_follow;
		cin >> num_follow;
		for (int j = 0; j < num_follow; j++) {
			int user;
			cin >> user;
			users[--user].push_back(i);
		}
	}
	int *reposts = new int[num_user];
	for (int i = 0; i < num_user; i++)
		reposts[i] = -1;
	int num_query;
	cin >> num_query;
	for (int r = 0; r < num_query; r++) {
		int user;
		cin >> user;
		cout << (reposts[user - 1] < 0 ? BFS(reposts, users, num_user, depth, user - 1) : reposts[user - 1]) << endl;
	}

	return 0;
}