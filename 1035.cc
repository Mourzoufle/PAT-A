#include <cstdio>
#include <vector>

using namespace std;

struct Record {
	char id[16];
	char password[16];
};

bool modify(char *password) {
	bool modify = false;
	for (int i = 0; password[i] != '\0'; i++) {
		if (password[i] == '1') {
			password[i] = '@';
			modify = true;
		}
		else if (password[i] == '0') {
			password[i] = '%';
			modify = true;
		}
		else if (password[i] == 'l') {
			password[i] = 'L';
			modify = true;
		}
		else if (password[i] == 'O') {
			password[i] = 'o';
			modify = true;
		}
	}

	return modify;
}

int main() {
	int num_record, num_modify = 0;
	scanf("%d", &num_record);
	Record *records = new Record[num_record];
	vector<int> modified_indices;
	for (int i = 0; i < num_record; i++) {
		scanf("%s %s", &records[i].id, &records[i].password);
		if (modify(records[i].password))
			modified_indices.push_back(i);
	}
	if (modified_indices.empty()) {
		if (num_record > 1)
			printf("There are %d accounts and no account is modified", num_record);
		else 
			printf("There is 1 account and no account is modified");
	}
	else {
		printf("%d\n", modified_indices.size());
		for (int i = 0; i < modified_indices.size(); i++)
			printf("%s %s\n", records[modified_indices[i]].id, records[modified_indices[i]].password);
	}

	return 0;
}