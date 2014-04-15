#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long

using namespace std;

bool C[11111];
LL P[555];
int k = 0;

int main() {
	for (int i = 2; k <= 520; i++) {
		if (!C[i]) {
			P[k++] = i;
			for (int j = i*i; j <= 11111; j+=i) C[j] = 1;
		}
	}
	int N, a, b, maximo, s;
	map<LL, int> mapa;
	LL hash;
	while (scanf("%d", &N) == 1 && N > 0) {
		mapa.clear();
		maximo = 0, s = 0;
		rp(i,N) {
			hash = 1;
			rp(j,5) scanf("%d", &a), hash*=P[a-100];
			mapa[hash]++;
			b = mapa[hash];
			if (b > maximo) maximo = s = b;
			else if (mapa[hash] == maximo) s += b;
		}
		printf("%d\n", s);
	}
}