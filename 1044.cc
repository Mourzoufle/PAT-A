#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int num_item, price, pay = INT_MAX;
	scanf("%d %d", &num_item, &price);
	int *items = new int[num_item];
	for (int i = 0; i < num_item; i++)
		scanf("%d", items + i);
	vector<int *> indices;
	int head = 0, tail = 0, cur_pay = items[tail];
	while (true) {
		if (cur_pay < price)
			tail++;
		else {
			if (cur_pay <= pay) {
				if (cur_pay < pay) {
					pay = cur_pay;
					indices.clear();
				}
				int *idx = new int[2];
				idx[0] = head;
				idx[1] = tail;
				indices.push_back(idx);
			}
			cur_pay -= items[head];
			head++;
			if (head > tail)
				tail++;
			else
				cur_pay -= items[tail];
		}
		if (tail == num_item)
			break;
		cur_pay += items[tail];
	}
	for (vector<int *>::iterator iter = indices.begin(); iter != indices.end(); iter++)
		printf("%d-%d\n", ++(*iter)[0], ++(*iter)[1]);

	return 0;
}