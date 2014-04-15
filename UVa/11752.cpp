#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

bool isPrime[111];

int main() {
	unsigned long long limit = (unsigned long long)18446744073709551615.0;
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i <= 100; i++) {
		if (isPrime[i]) {
			for (long long j = (long long)i*i; j <= 100; j+=i) {
				isPrime[j] = false;
			}
		}
	}

	bool canTakeThis[66000];
	memset(canTakeThis, 1, sizeof canTakeThis);
	for (int i = 2; i <= 256; i++) {
		if (canTakeThis[i]) {
			//printf("%d\n", i);
			for (int j = i*i; j <= 65536; j*=i) {
				canTakeThis[j] = false;
			}
		}
	}


	unsigned long long q[100000];
	int size = 0;
	unsigned long long c;
	int j;
	q[size++] = 1;
	for (int i = 2; i < 65536; i++) {
		if (canTakeThis[i]) {
			//printf("%d\n", i);
			j = 4;
			c = (unsigned long long)i*i*i*i;
			while(c <= limit) {
				if (!isPrime[j]) {
					q[size++] = c;
				}
				if (c > limit/i) break;
				j++;
				c*=i;
			}
			//
			//size = unique(q, q+size) - q;
		}
	}
	sort(q, q+size);
	for (int i = 0; i < size; i++) {
		printf("%llu\n", q[i]);
	}
}
