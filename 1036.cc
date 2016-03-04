#include <cstdio>
#include <cstring>

struct Student {
	char name[16];
	char id[16];
	int grade;

	Student(int grade): grade(grade) {}

	void set(char *name, char *id, int grade) {
		strcpy(this->name, name);
		strcpy(this->id, id);
		this->grade = grade;
	}
};

int main() {
	int num_student;
	scanf("%d", &num_student);
	Student max_girl(-1), min_boy(101);
	for (int i = 0; i < num_student; i++) {
		char name[16], id[16];
		char gender;
		int grade;
		scanf("%s %c %s %d", name, &gender, id, &grade);
		if ((gender == 'F') && (max_girl.grade < grade))
			max_girl.set(name, id, grade);
		if ((gender == 'M') && (min_boy.grade > grade))
			min_boy.set(name, id, grade);
	}

	if (max_girl.grade < 0)
		printf("Absent\n");
	else
		printf("%s %s\n", max_girl.name, max_girl.id);
	if (min_boy.grade > 100)
		printf("Absent\n");
	else
		printf("%s %s\n", min_boy.name, min_boy.id);
	if ((max_girl.grade < 0) || (min_boy.grade > 100))
		printf("NA");
	else
		printf("%d", max_girl.grade - min_boy.grade);

	return 0;
}