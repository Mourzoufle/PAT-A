#include <cstdio>
#include <cstring>

int main() {
	char id_in[16], id_out[16], first[] = "24:00:00", last[] = "00:00:00";	// ensure the initial values of fisrt & last time can be replaced by any student
	int num_student;
	scanf("%d", &num_student);
	for (int i = 0; i < num_student; i++) {
		char id[16], in[16], out[16];
		scanf("%s %s %s", id, in, out);
		if (strcmp(in, first) < 0) {										// got a student coming earlier
			strcpy(id_in, id);
			strcpy(first, in);
		}
		if (strcmp(out, last) > 0) {										// got a student going later
			strcpy(id_out, id);
			strcpy(last, out);
		}
	}
	printf("%s %s", id_in, id_out);

	return 0;
}