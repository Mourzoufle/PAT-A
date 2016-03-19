#include <cstdio>
#include <map>

using namespace std;

const char COURSES[4] = {'A', 'C', 'M', 'E'};								// course 0: average

/* given the index of student, get the rank in ONE course */
int get_rank(int *scores, int num_student, int idx_student) {
	int rank = 1;
	for (int i = 0; i < num_student; i++)
		if (scores[i] > scores[idx_student])								// the rank is the number of higher scores + 1
			rank++;

	return rank;
}

int main() {
	int num_student, num_query;
	scanf("%d %d", &num_student, &num_query);
	int *scores[4];
	for (int i = 0; i < 4; i++)
		scores[i] = new int[num_student];
	map<int, int> map;														// map of student ids and their entries in the matrix of scores - for query
	for (int i = 0; i < num_student; i++) {
		int id;
		scanf("%d %d %d %d", &id, &scores[1][i], &scores[2][i], &scores[3][i]);
		scores[0][i] = (scores[1][i] + scores[2][i] + scores[3][i]) / 3;
		map[id] = i;
	}

	for (int i = 0; i < num_query; i++) {
		int id;
		scanf("%d", &id);
		if (map.find(id) == map.end()) {									// id not found
			printf("N/A\n");
			continue;
		}
		int idx_student = map[id], min_rank = num_student + 1, idx_course;	// ensure the initial value of min rank is out of range
		for (int j = 0; j < 4; j++) {
			int cur_rank = get_rank(scores[j], num_student, idx_student);
			if (cur_rank < min_rank) {										// replace only when the latter course provides a higher rank
				min_rank = cur_rank;
				idx_course = j;
			}
		}
		printf("%d %c\n", min_rank, COURSES[idx_course]);
	}

	return 0;
}