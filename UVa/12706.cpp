#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

#define BASE 100007
#define MOD 1000000007LL
#define MAXN 100100

ll x[MAXN], y[MAXN];
ll l[MAXN];
ll alf[MAXN], alf2[MAXN];
int k;

ll expmod(ll a, ll b) {
    ll r = 1;
    for (; b; a=(a*a)%MOD, b>>=1) if (b&1) r=(r*a)%MOD;
    return r;
}

int main() {
	int T, n, m;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		k = 0;
		rp(i,n) scanf("%lld", &x[i]), l[k++] = x[i];
		rp(i,m) scanf("%lld", &y[i]), l[k++] = y[i];
		sort(l,l+k);
		k = unique(l,l+k) - l;
		rp(i,n) x[i] = lower_bound(l,l+k,x[i]) - l + 1;
		rp(i,m) y[i] = lower_bound(l,l+k,y[i]) - l + 1;
		
		if (n < m) printf("0\n");
		else {
		    sort(y,y+m);
		    cl(alf,0); cl(alf2,0);
		    rp(i,m) alf[y[i]]++, alf2[x[i]]++;
		    ll hash = 0, hash2 = 0;
		    fr(i,1,k+1) {
		        hash = (hash*BASE)%MOD;
		        hash = (hash+expmod(i,alf[i]))%MOD;
		        
		        hash2 = (hash2*BASE)%MOD;
		        hash2 = (hash2+expmod(i,alf2[i]))%MOD;
		    }
		    ll res = 0;
		    //printf("1 %lld\n", hash2);
		    if (hash == hash2) res++;
		    for (int i = m; i < n; i++) {
		        hash2 = (hash2 + (expmod(BASE,k-x[i-m])*((expmod(x[i-m],alf2[x[i-m]]-1) - expmod(x[i-m],alf2[x[i-m]]) + MOD)%MOD) + MOD)%MOD + MOD)%MOD;
		        //printf("%lld*(%lld-%lld)\n", expmod(BASE,k-x[i-m]), expmod(x[i-m],alf2[x[i-m]]-1), expmod(x[i-m],alf2[x[i-m]]));
		        alf2[x[i-m]]--;
		        hash2 = (hash2 + (expmod(BASE,k-x[i])*((expmod(x[i],alf2[x[i]]+1) - expmod(x[i],alf2[x[i]]) + MOD)%MOD) + MOD)%MOD + MOD)%MOD;
		        //printf("%lld*(%lld-%lld)\n", expmod(BASE,k-x[i]), expmod(x[i],alf2[x[i]]+1), expmod(x[i],alf2[x[i]]));
		        alf2[x[i]]++;
		        //printf("%d %lld\n", i-m+2, hash2);
		        if (hash2 == hash) res+=(ll(i-m+2)*ll(i-m+2));
		    }
		    printf("%lld\n", res);
		}
	}
	return 0;
}