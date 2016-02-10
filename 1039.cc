#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int str_to_int(char *name) {
	int res = 0;
	for (int i = 0; i < 3; i++)
		res = res * 26 + name[i] - 'A';

	return res * 10 + name[3] - '0';
}

int main() {
	int num_student, num_course;
	char student[5];
	scanf("%d %d", &num_student, &num_course);
	vector<int> *regs = new vector<int>[26 * 26 * 26 * 10];
	for (int i = 0; i < num_course; i++) {
		int course, num_reg;
		scanf("%d %d", &course, &num_reg);
		for (int j = 0; j < num_reg; j++) {
			scanf("%s", student);
			regs[str_to_int(student)].push_back(course);
		}
	}

	for (int i = 0; i < num_student; i++) {
		scanf("%s", student);
		printf("%s ", student);
		vector<int> *reg = &regs[str_to_int(student)];
		sort(reg->begin(), reg->end());
		printf("%d", reg->size());
		for (vector<int>::iterator iter = reg->begin(); iter != reg->end(); iter++)
			printf(" %d", *iter);
		printf("\n");
	}

	return 0;
}