#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Item {
	double amount;
	double price;
};

bool compare(const Item &a, const Item &b) { return a.price / a.amount > b.price / b.amount; };

int main() {
	int num_item;
	double amount;
	cin >> num_item >> amount;
	Item *items = new Item[num_item];
	for (int i = 0; i < num_item; i++)
		cin >> items[i].amount;
	for (int i = 0; i < num_item; i++)
		cin >> items[i].price;
	sort(items, items + num_item, compare);

	double profit = 0;
	for (int i = 0; i < num_item; i++) {
		if (amount <= 0)
			break;
		profit += amount < items[i].amount ? items[i].price * amount / items[i].amount : items[i].price;
		amount -= items[i].amount;
	}
	printf("%.2f", profit);

	return 0;
}