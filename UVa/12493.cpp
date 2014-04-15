#include <bits/stdc++.h>
using namespace std;

bool C[50000];
int Pr[50000], sizePr = 0;

void sieve() {
	for (int i = 2; i <= 46340; i++) {
		if (!C[i]) {
			Pr[sizePr++] = i;
			for (int j = i*i; j <= 46340; j+=i) {
				C[j] = 1;
			}
		}
	}
}

int phi(int n) {
	int M = n;
	for (int i = 0; i < sizePr && Pr[i]*Pr[i] <= n; i++) {
		if (n%Pr[i] == 0) {
			M -= M/Pr[i];
			while (n%Pr[i] == 0) n /= Pr[i];
		}
	}
	if (n > 1) M -= M/n;
	return M;
}

int main() {
	int N;
	sieve();
	while (scanf("%d", &N) == 1) {
		printf("%d\n", phi(N)/2);
	}
	return 0;
}