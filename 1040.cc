#include <cstdio>
#include <cstring>

const int MAX_CHAR = 1024;	// max length of the input string

int main() {
	char str[MAX_CHAR];
	gets(str);																														// the input may contain spaces
	int length = strlen(str), max_length_symm = 1;																					// the length of the input string; max length of symmetric sub-string
	for (int i = 0; i < length; i++) {
		int cur_length_symm = 1;																									// (initially) half of the length of symmetric sub-string centered by str[i]
		while ((i >= cur_length_symm) && (i + cur_length_symm < length) && (str[i - cur_length_symm] == str[i + cur_length_symm]))	// there are two more characters that are symmetric
			cur_length_symm++;
		cur_length_symm = cur_length_symm * 2 - 1;																					// calculate the length of the whole symmetric sub-string centered by str[i]
		if (max_length_symm < cur_length_symm)
			max_length_symm = cur_length_symm;
		cur_length_symm = 1;																										// then check the symmetric sub-string centered by str[i] and str[i + 1]
		while ((i >= cur_length_symm - 1) && (i + cur_length_symm < length) && (str[i + 1 - cur_length_symm] == str[i + cur_length_symm]))
			cur_length_symm++;
		cur_length_symm = cur_length_symm * 2 - 2;
		if (max_length_symm < cur_length_symm)
			max_length_symm = cur_length_symm;
	}
	printf("%d", max_length_symm);

	return 0;
}