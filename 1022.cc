#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
	int id;
	string contents[5];
};

bool compare(const Book &a, const Book &b) { return a.id < b.id; };

int main() {
	int num_book, num_query;
	scanf("%d", &num_book);
	Book *books = new Book[num_book];
	for (int i = 0; i < num_book; i++) {
		scanf("%d", &books[i].id);
		getchar();
		char contents[5][1024];
		for (int j = 0; j < 5; j++) {
			gets(contents[j]);
			books[i].contents[j] = contents[j];
		}
	}
	sort(books, books + num_book, compare);

	scanf("%d", &num_query);
	for (int i = 0; i < num_query; i++) {
		int type;
		char content[128];
		scanf("%d: ", &type);
		gets(content);
		printf("%d: %s\n", type, content);
		bool find = false;
		for (int j = 0; j < num_book; j++) {
			if (type == 3) {
				if (books[j].contents[2].find(content) != string::npos) {
					printf("%07d\n", books[j].id);
					find = true;
				}
			}
			else if (books[j].contents[type - 1] == content) {
				printf("%07d\n", books[j].id);
				find = true;
			}
		}
		if (!find)
			printf("Not Found\n");
	}

	return 0;
}