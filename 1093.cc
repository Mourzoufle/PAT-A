#include <cstdio>

int main() {
	char *str = new char[16384];
	scanf("%s", str);

	long long counts[3] = {0, 0, 0};	// number of "P", "PA", and "PAT" in the string
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == 'P')
			counts[0]++;
		else if (str[i] == 'A')
			counts[1] += counts[0];
		else
			counts[2] += counts[1];
	}
	printf("%lld", counts[2] % 1000000007);

	return 0;
}