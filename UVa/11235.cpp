#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

int N, Q;
int vet[100100], tab[100100], val[1<<20];
map<int, int> mapa;

int q(int ini, int fim, int R, int i, int j) {
	if (ini > j || fim < i) return 0;
	if (ini <= i && j <= fim) return val[R];
	int M = (i+j)/2;
	return max(q(ini, fim, 2*R, i, M), q(ini, fim, 2*R+1, M+1, j));
}

void createSeg(int R, int i, int j) {
	if (i == j) val[R] = tab[i];
	else {
		int M = (i+j)/2;
		createSeg(2*R, i, M);
		createSeg(2*R+1, M+1, j);
		val[R] = max(val[2*R],val[2*R+1]);
	}
}
int main() {
	int ini, fim, last, temp, k, iniFreq, fimFreq, temp1, temp2, maxT;
	while (scanf("%d%d", &N, &Q) && N) {
		last = 0, temp = 0, k = 1;
		mapa.clear();
		for (int i = 0; i < N; i++) {
			scanf("%d", &vet[i]);
			if (!i) last = vet[i];
			if (vet[i] != last) mapa[last] = k, tab[k++] = temp, temp = 0;
			temp++;
			last = vet[i];
		}
		mapa[last] = k;
		tab[k] = temp;
		createSeg(1, 1, k);
		while (Q--) {
			maxT = 0;
			scanf("%d%d", &ini, &fim);
			ini--, fim--;
			if (vet[ini] == vet[fim]) {
				printf("%d\n", fim-ini+1);
				continue;
			}
			temp1 = upper_bound(vet, vet+N, vet[ini])-vet;
			temp2 = lower_bound(vet, vet+N, vet[fim])-vet-1;
			maxT = max(temp1-ini, fim-temp2);
			if (temp1 > temp2) printf("%d\n", maxT);
			else {
				ini = mapa[vet[temp1]];
				fim = mapa[vet[temp2]];
				printf("%d\n", max(maxT, q(ini, fim, 1, 1, k)));
			}
		}
	}
}