#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
using namespace std;

int v[2010];
int main() {
	int T, N, M, cas = 1, m, l, t;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		M = N;
		rp(i,N) scanf("%d", &v[i]);
		printf("Case %d:", cas++);
		if(N < 11) printf(" go home!\n");
		else {
			l = 0;
			for (int k = 11; k > 0; k--) {
				m = -1000000001;
				for (int i = l; i <= l+M-k; i++) {
					if (v[i] > m) {
						m = v[i];
						t = i+1;
					}
				}
				printf(" %d", m);
				l = t;
				M = N-l;
			}
			printf("\n");
		}
	}
}