#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

bool isPrime[100010];
int primo[10000], k;

void gerarPrimos() {
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i < 317; i++) {
		if (isPrime[i]) {
			for (int j = i*i; j <= 100000; j+=i) {
				isPrime[j] = false;
			}
		}
	}
	k = 0;
	for (int i = 2; i <= 100000; i++) {
		if (isPrime[i]) primo[k++] = i;
	}
}

int main() {
	gerarPrimos();
	double x;
	int t, max, tempA, tempB, sqrTemp, a, b, m;
	while (scanf("%d%d%d", &m, &a, &b) == 3 && m) {
		x = (double)a/b;
		max = 0;
		sqrTemp = (int)sqrt(m);
		for (int i = 0; primo[i] <= sqrTemp; i++) {
			for (int j = i; primo[j] <= m && j < k; j++) {
				t = primo[i]*primo[j];
				if (t <= m && ((double)primo[i]/primo[j]) >= x && t > max) {
					max = t;
					tempA = primo[i];
					tempB = primo[j];
				}
			}
		}
		printf("%d %d\n", tempA, tempB);
	}
}