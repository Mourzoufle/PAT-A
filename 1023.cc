#include <cstdio>
#include <string>

using namespace std;

/* get representation of the doubled value of the given number */
string get_double(string num) {
	string res;
	for (int i = 0; i < num.size(); i++)
		num[i] -= '0';
	if (num[0] > 4)													// current digit >=5 - carry is 1
		res += '1';
	for (int i = 1; i < num.size(); i++)
		res += (num[i - 1] * 2 + (num[i] > 4 ? 1 : 0)) % 10 + '0';	// doubled current digit + carry from the lower digit
	res += (num.back() * 2) % 10 + '0';

	return res;
}

/* get the histogram over different digits for the given representation of number */
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
	bool equal = true;												// if the doubled number is another permulation of the original one, then the histograms of them should be the same
	for (int i = 0; i < 10; i++) {
		if (hist_a[i] != hist_b[i]) {								// not a different permulation
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