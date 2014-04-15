//by stor
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define ll long long
#define pb push_back

using namespace std;

char T[11111], P[1000];
int size, N, K;
int back[1000];

void pre_kmp() {
	int i = 0, j = -1;
	back[0] = -1;
	while (i < size) {
		while (j >= 0 && P[i] != P[j]) j = back[j];
		i++, j++;
		back[i] = j;
	}
}

void kmp() {
	int i = 0, j = 0;
	while (i < N) {
		while (j >= 0 && T[i] != P[j]) j = back[j];
		i++, j++;
	}
	while (j < size) T[i++] = P[j++];
	N = i; T[N] = '\0';
}

int main() {
	int Testes;
	scanf("%d", &Testes);
	while (Testes--) {
		scanf("%d%d", &N, &K);
		scanf("%s", T);
		size = N;
		fr(i,1,K) {
			scanf("%s", P);
			pre_kmp(); kmp();
		}
		printf("%d\n", N);
	}
	return 0;
}