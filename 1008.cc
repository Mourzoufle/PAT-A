#include <cstdio>

int main() {
	int cur = 0, sum = 0, num_request;		// current floor; total time; number of requests to this elevator
	scanf("%d", &num_request);
	for (int i = 0; i < num_request; i++) {
		int next;
		scanf("%d", &next);
		if (next > cur)						// up
			sum += 6 * (next - cur);
		else								// down
			sum += 4 * (cur - next);
		cur = next;
	}
	printf("%d", sum + 5 * num_request);	// wait for 5 seconds for each request

	return 0;
}