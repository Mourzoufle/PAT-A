#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Item {												// the kind of mooncakes
	double amount;
	double price;
};

/* cmp fuction for sorting kinds of mooncakes - according to their price per ton */
bool cmp(const Item &a, const Item &b) { return a.price / a.amount > b.price / b.amount; };

int main() {
	int num_item, amount;
	scanf("%d %d", &num_item, &amount);
	Item *items = new Item[num_item];
	for (int i = 0; i < num_item; i++)
		scanf("%lf", &items[i].amount);
	for (int i = 0; i < num_item; i++)
		scanf("%lf", &items[i].price);
	sort(items, items + num_item, cmp);

	double profit = 0;
	for (int i = 0; (i < num_item) && (amount > 0); i++) {	// halt when the required amount is met
		profit += min(items[i].price * amount / items[i].amount, items[i].price);
		amount -= items[i].amount;
	}
	printf("%.2lf", profit);

	return 0;
}