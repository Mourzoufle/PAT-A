#include <cstdio>

int main() {
	int num_num;	// number of numbers
	scanf("%d", &num_num);
	double sum = 0;
	for (int i = 0; i < num_num; i++) {
		double num;
		scanf("%lf", &num);
		sum += num * (i + 1) * (num_num - i);
	}
	printf("%.2lf", sum);

	return 0;
}