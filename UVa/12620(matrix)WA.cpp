#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;

ll n, m;

struct matriz {
	ll mat[3][3];
	matriz() {
		memset(mat,0,sizeof mat);
	}
	
	matriz operator*(const matriz &lhs) const {
		matriz ret;
		rp(i,2) rp(j,3) {
			ret.mat[i][j] = 0;
			rp(k,3) ret.mat[i][j] += mat[i][k]*lhs.mat[k][j];
			ret.mat[i][j]%=100;
		}
		rp(j,3) {
			ret.mat[2][j] = 0;
			rp(k,3) ret.mat[2][j] += (mat[2][k]*lhs.mat[k][j])%100;
		}
		return ret;
	}
};

ll calc(ll k) {
	matriz res = matriz();
	rp(i,3) res.mat[i][i] = 1;
	matriz aux = matriz();
	aux.mat[0][0] = aux.mat[0][1] = aux.mat[1][0] = aux.mat[2][0] = aux.mat[2][1] = aux.mat[2][2] = 1;
	for (; k; k>>=1, aux = aux*aux) if (k&1) res = res*aux;
	rp(i,3) {
		rp(j,3) printf("%lld ", res.mat[i][j]);
		puts("");
	}
	return 2 + res.mat[2][0] + res.mat[2][1];
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%lld", &m);
		calc(m);
		/*ll resA = (m/300)*s[300]+s[m%300];
		ll resB = ((n-1)/300)*s[300]+s[(n-1)%300];
		printf("%lld\n", resA-resB);*/
	}
	return 0;
}