#include <cstdio>
#include <string>

using namespace std;

int main() {
	char data[128];
	scanf("%s", data);
	string str = data;
	int height = (str.size() + 2) / 3;
	int width = str.size() - (height << 1) + 2;
	for (int i = 1; i < height; i++) {
		printf("%c", str[i - 1]);
		for (int j = 2; j < width; j++)
			printf(" ");
		printf("%c\n", str[str.size() - i]);
	}
	for (int i = height - 1; i < str.size() + 1 - height; i++)
		printf("%c", str[i]);

	return 0;
}