#include <cstdio>

int main() {
	int galleon_a, sickle_a, knut_a, galleon_b, sickle_b, knut_b;
	scanf("%d.%d.%d %d.%d.%d", &galleon_a, &sickle_a, &knut_a, &galleon_b, &sickle_b, &knut_b);

	int galleon = galleon_a + galleon_b, sickle = sickle_a + sickle_b, knut = knut_a + knut_b;	// the sum in each kind of currencies
	if (knut > 28) {																			// has carry
		sickle++;
		knut %= 29;
	}
	if (sickle > 16) {																			// has carry
		galleon++;
		sickle %= 17;
	}
	printf("%d.%d.%d", galleon, sickle, knut);
	
	return 0;
}