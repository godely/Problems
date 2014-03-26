#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)

typedef unsigned long long ull;

ull A[10];

int win(ull x, ull y, ull z) {
	int state = 0;
	bool foi = 0;
	if (y > 0) {
		y--;

		if (y > z + 1) {
			if (x&1) return 1;
		} else if (y >= z) return 3;
		else if (!(x&1)) return 1;

		y++;
		foi = 1;
	}
	if (z > 0) {
		z--;

		if (z > y + 1) {
			if (x&1) return 1;
		} else if (z >= y) return 3;
		else if (!(x&1)) return 1;

		z++;
		foi = 1;
	}
	if (foi) return 2;
	else return 3;
}

char lol[10000];
string strlol;
int main() {
	int T, N, cas = 1;
	ull L, B;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		cl(A,0);
		rp(i,N) {
			scanf("%llu%llu", &L, &B);
			if (B%3 < 2) {
				A[B%3] += (L-1)*(B-1);
			} else {
				A[2] += (L>>1ULL)*(B-1);
				A[1] += (L - (L>>1ULL) - 1)*(B-1);
			}
		}
		//printf("%llu %llu %llu\n", A[0], A[1], A[2]);
		int res = win(A[0],A[1],A[2]);
		printf("Case %d: ", cas++);
		if (res == 1) puts("M");
		else if (res == 2) puts("J");
		else puts("Draw");
	}
	return 0;
}