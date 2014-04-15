#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair
typedef long long ll;

int n, m;
int l, a[(1<<21)+10], b[(1<<21)+10], c[(1<<21)+10];
int q;
ll S[30], T[30], pot2[30];

pair<ll,ll> countInv(int l, int r, int m) {
	ll numInv1 = 0, numInv2 = 0;
	int k = l;
	int i = l, j = m+1;
	while (i <= m && j <= r) {
		if (b[j] < b[i]) {
			c[k] = b[j];
			numInv1 += m-i+1;
			j++;
			k++;
		} else if (b[i] < b[j]) {
			c[k] = b[i];
			numInv2 += r-j+1;
			i++;
			k++;
		} else {
			int d = b[i], oi = i, oj = j;
			while (i <= m && b[i] == d) c[k++] = b[i++];
			while (j <= r && b[j] == d) c[k++] = b[j++];
			numInv1 += ll(m-i+1)*ll(j-oj);
			numInv2 += ll(r-j+1)*ll(i-oi);
		}
	}
	while (i <= m) c[k++] = b[i++];
	while (j <= r) c[k++] = b[j++];
	for (k = l; k <= r; k++) b[k] = c[k];
    return MP(numInv1,numInv2);
}

int countBits(int R) {
	int c = !R;
	while (R) R>>=1, c++;
	return c;
}

void build(int R, int l, int r) {
	if (l == r) {
		b[l] = a[l];
	} else {
		int m = (l+r)>>1;
		build(R<<1,l,m);
		build((R<<1)+1,m+1,r);

		pair<ll,ll> ci = countInv(l,r,m);
		S[n-countBits(R)+1] += ci.F;
		T[n-countBits(R)+1] += ci.S;
	}
}

int main() {
	cl(S,0); cl(T,0);
	scanf("%d", &n);
	l = (1<<n);
	rp(i,l) scanf("%d", &a[i+1]);
	build(1,1,l);
	scanf("%d", &m);
	rp(i,m) {
		scanf("%d", &q);
		for (int i = q; i > 0; i--) swap(S[i],T[i]);
		ll ans = 0;
		fr(i,1,n+1) ans += S[i];
		cout << ans << endl;
	}//*/
}