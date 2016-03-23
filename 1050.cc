#include <cstdio>

int main() {
	bool erase[256];					// flags of all the ASCII characters to be erased
	for (int i = 0; i < 256; i++)
		erase[i] = false;
	char str[16384], str_erase[16384];	// the original string; the string in which all the characters should be erased
	gets(str);
	gets(str_erase);
	for (int i = 0; str_erase[i] != '\0'; i++)
		erase[str_erase[i]] = true;
	for (int i = 0; str[i] != '\0'; i++)
		if (!erase[str[i]])
			putchar(str[i]);

	return 0;
}