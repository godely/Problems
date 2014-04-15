#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 10100

int B, N, a, b, c, saldo[MAXN];
bool ok;

int main() {
	while (scanf("%d%d", &B, &N) == 2 && B > 0) {
		fr(i,1,B+1) scanf("%d", &saldo[i]);
		rp(i,N) {
			scanf("%d%d%d", &a, &b, &c);
			saldo[a]-=c;
			saldo[b]+=c;
		}
		ok = 1;
		fr(i,1,B+1) if (saldo[i] < 0) {
			ok = 0;
			break;
		}
		if (ok) printf("S\n");
		else printf("N\n");
	}
	return 0;
}