#include <cstdio>
#include <cstring>

int main() {
	char str[128];
	scanf("%s", str);
	int length = strlen(str);
	int height = (length + 2) / 3, width = length + 2 - (height * 2);	// 2 * height + width - 2 = length of string
	for (int i = 0; i < height - 1; i++) {
		printf("%c", str[i]);
		for (int j = 2; j < width; j++)
			printf(" ");
		printf("%c\n", str[length - i - 1]);
	}
	for (int i = height - 1; i < length + 1 - height; i++)
		printf("%c", str[i]);

	return 0;
}