#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define prox(i) (i+1)%N
#define ant(i) (i+N-1)%N

using namespace std;

bool C[1111111];
int P[111111], p = 0;

void sieve() {
	for (int i = 2; i < 40000; i++) {
		if (!C[i]) {
			P[p++] = i;
			for (int j = i*i; j < 40000; j+=i) C[j] = 1;
		}
	}
}

int passo=0;
int prev[5000], next[5000];
int main() {
	sieve();
    int N, m, i, j, c;
    for (N = 1; N <= 3501; N++) {
		for (i = 0; i < N; i++) next[i] = prox(i), prev[i] = ant(i);
		i = 0, j = 0, m = 0;
		while (m < N) {
			//printf("%d\n", P[i]);
			for (c = 1; c < P[i]; c++, j=next[j]);
			i++;
			//printf("> %d %d %d\n", j, P[i], m);
			next[prev[j]] = next[j];
			prev[next[j]] = prev[j];
			j = next[j];
			m++;
		}
		printf("%d, ", j+1);
    }
    return 0;
}
