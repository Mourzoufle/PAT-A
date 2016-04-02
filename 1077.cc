#include <cstdio>
#include <cstring>

int main() {
	int num_str;
	scanf("%d\n", &num_str);
	char **strs = new char *[num_str];
	for (int i = 0; i < num_str; i++) {
		strs[i] = new char[512];
		gets(strs[i]);
	}

	int *indices = new int[num_str];	// the index of each string at which the character is under processing
	for (int i = 0; i < num_str; i++)
		indices[i] = strlen(strs[i]);
	while (true) {
		bool is_same = true;			// flag indicating if the current position of each string is still part of the common suffix
		for (int i = 0; i < num_str; i++) {
			indices[i]--;
			if ((indices[i] < 0) || (strs[i][indices[i]] != strs[0][indices[0]])) {
				is_same = false;
				break;
			}
		}
		if (!is_same)
			break;
	}
	if (strs[0][++indices[0]] == '\0')	// no common suffix
		printf("nai");
	else
		printf("%s", strs[0] + indices[0]);

	return 0;
}