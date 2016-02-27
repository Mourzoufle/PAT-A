#include <cstdio>
#include <string>

using namespace std;

string get_double(string num) {
	string res;
	if (num[0] > '4')
		res += '1';
	for (int i = 0; i < num.size() - 1; i++)
		res += ((((num[i] - '0') << 1) + (num[i + 1] > '4' ? 1 : 0)) % 10) + '0';
	res += (((num[num.size() - 1] - '0') << 1) % 10) + '0';

	return res;
}

int* num_to_hist(string num) {
	int *hist = new int[10];
	for (int i = 0; i < 10; i++)
		hist[i] = 0;
	for (int i = 0; i < num.size(); i++)
		hist[num[i] - '0']++;

	return hist;
}

int main() {
	char num[32];
	scanf("%s", num);
	string double_num = get_double(num);
	int *hist_a = num_to_hist(num), *hist_b = num_to_hist(double_num);
	bool equal = true;
	for (int i = 0; i < 10; i++) {
		if (hist_a[i] != hist_b[i]) {
			equal = false;
			break;
		}
	}
	if (equal)
		printf("Yes\n");
	else
		printf("No\n");
	printf("%s", double_num.c_str());

	return 0;
}