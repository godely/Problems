#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define BASE 29

unsigned long long H[20], hash;

char A[1511][20], B[1511][20];
int sizeA[1511], sizeB[1511];
unsigned long long hashA[1511], hashB[1511];

set<unsigned long long> S;
char str[100];
int main() {
	int cas = 1, M, N;
	H[0] = 1;
	fr(i,1,11) H[i] = H[i-1]*BASE;
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &M, &N);
		getchar();
		rp(j,M) {
			gets(A[j]);
			sizeA[j] = strlen(A[j]);
			hash = 0;
			for (int k = 0; k < sizeA[j]; k++) {
				hash = (hash*BASE) + A[j][k] - 'a' + 1;
			}
			hashA[j] = hash;
		}
		rp(j,N) {
			gets(B[j]);
			sizeB[j] = strlen(B[j]);
			hash = 0;
			for (int k = 0; k < sizeB[j]; k++) {
				hash = (hash*BASE) + B[j][k] - 'a' + 1;
			}
			hashB[j] = hash;
		}
		S.clear();
		rp(i,M) {
			rp(j,N) {
				S.insert(hashA[i]*H[sizeB[j]] + hashB[j]);
			}
		}
		printf("Case %d: %d\n", cas++, S.size());
	}
}