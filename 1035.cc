#include <cstdio>
#include <vector>

using namespace std;

struct Account {
	char id[16];
	char password[16];
};

/* check if the given password needs to be modified, and do it */
bool modify(char *password) {
	bool modify = false;			// flag indicating if the password is modified
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
	int num_account, num_modify = 0;
	scanf("%d", &num_account);
	Account *accounts = new Account[num_account];
	vector<int> indices_modified;	// the indices of modified accounts
	for (int i = 0; i < num_account; i++) {
		scanf("%s %s", &accounts[i].id, &accounts[i].password);
		if (modify(accounts[i].password))
			indices_modified.push_back(i);
	}
	if (indices_modified.empty()) {	// no account is modified
		if (num_account > 1)
			printf("There are %d accounts and no account is modified", num_account);
		else 
			printf("There is 1 account and no account is modified");
	}
	else {
		printf("%d\n", indices_modified.size());
		for (int i = 0; i < indices_modified.size(); i++)
			printf("%s %s\n", accounts[indices_modified[i]].id, accounts[indices_modified[i]].password);
	}

	return 0;
}