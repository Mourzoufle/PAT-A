#include <cstdio>

int main() {
	long long galleon_a, sickle_a, knut_a;
	long long galleon_b, sickle_b, knut_b;
	scanf("%lld.%lld.%lld", &galleon_a, &sickle_a, &knut_a);
	scanf("%lld.%lld.%lld", &galleon_b, &sickle_b, &knut_b);
	printf("%lld.%lld.%lld", galleon_a + galleon_b + (sickle_a + sickle_b + (knut_a + knut_b > 28 ? 1 : 0) > 16 ? 1 : 0), (sickle_a + sickle_b + (knut_a + knut_b > 28 ? 1 : 0)) % 17, (knut_a + knut_b) % 29);

	return 0;
}