//stor
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

int vet[11];
int p[2][111111], k[2], a;
int res[11111][2], pr=0;
int main() {
	int T;
	scanf("%d", &T);
	rp(i,T) scanf("%d", &vet[T-1-i]);
	p[0][k[0]++] = vet[0]-1;
	p[0][k[0]++] = vet[0];
	p[0][k[0]++] = vet[0]+1;
	a = 0;
	for (int i = 1; i < T; i++) {
		k[a^1] = 0;
		for (int j = 0; j < k[a]; j++) {
			if (vet[i]-p[a][j] >= 0 || i == T-1)
				p[a^1][k[a^1]++] = vet[i]-p[a][j];
			p[a^1][k[a^1]++] = vet[i]+p[a][j];
		}
		a^=1;
	}
	sort(p[a], p[a]+k[a]);
	k[a] = unique(p[a],p[a]+k[a])-p[a];
	int init = p[a][0];
	for (int i = 0; i < k[a]; i++) {
		if (i == k[a]-1 || p[a][i+1] != p[a][i]+1) {
			res[pr][0]=init;
			res[pr++][1]=p[a][i];
			init = p[a][i+1];
		}
	}
	printf("%d\n", pr);
	rp(i,pr) printf("%d %d\n", res[i][0], res[i][1]);
	return 0;
}