#include <cstdio>

int main() {
	bool del[256];
	char str[1 << 14], dels[1 << 14];
	gets(str);
	gets(dels);
	for (int i = 0; dels[i] != '\0'; i++)
		del[dels[i]] = true;
	for (int i = 0; str[i] != '\0'; i++)
		if (!del[str[i]])
			putchar(str[i]);

	return 0;
}