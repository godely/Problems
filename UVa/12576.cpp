//by stor
#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mod 7477777
#define ll long long

ll C[100100][6];
ll r, res;
int main() {
	C[0][0] = 1;
	fr(i,1,100010) {
		C[i][0] = 1;
		fr(j,1,5) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
		}
	}
	int cas = 1;
	int T, N; scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("Case %d: ", cas++);
		if (N < 5) printf("0\n");
		else {
			res = 0;
			fr(i,3,N-1) {
				r = N-i-1;
				r = (r*r)%mod;
				res = (res+(r*C[i][3])%mod)%mod;
			}
			printf("%lld\n", (5*res)%mod);
		}
	}
	return 0;
}