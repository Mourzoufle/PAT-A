#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
	int id;
	string contents[5];					// 0: title; 1: author; 2: keywords; 3: publisher; 4: year
};

/* compare fuction for sorting books - according to the id of each book */
bool cmp(const Book &a, const Book &b) { return a.id < b.id; };

int main() {
	int num_book, num_query;
	scanf("%d", &num_book);
	Book *books = new Book[num_book];
	for (int i = 0; i < num_book; i++) {
		scanf("%d\n", &books[i].id);	// jump over '\n'						
		char contents[1024];
		for (int j = 0; j < 5; j++) {
			gets(contents);				// may contain spaces
			books[i].contents[j] = contents;
		}
	}
	sort(books, books + num_book, cmp);

	scanf("%d", &num_query);
	for (int i = 0; i < num_query; i++) {
		int type;
		char content[128];
		scanf("%d: ", &type);
		gets(content);					// may contain spaces
		printf("%d: %s\n", type, content);
		bool find = false;
		for (int j = 0; j < num_book; j++) {
			if (((type == 3) && (books[j].contents[2].find(content) != string::npos)) || (books[j].contents[type - 1] == content)) {
				printf("%07d\n", books[j].id);
				find = true;
			}
		}
		if (!find)						// no book found for this query
			printf("Not Found\n");
	}

	return 0;
}