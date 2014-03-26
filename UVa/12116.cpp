#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof(a))
#define cpy(a,b) memcpy(a,b,sizeof b)
typedef long long ll;
typedef long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef map<int,int> mii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define y1 Y1
#define MAXN 47100

bool prime[MAXN+10];
int prm[MAXN+10], fat[MAXN+10], sz;

ll dp[MAXN+10];
map<int,ll> m;

void preprocess() {
	cl(prime,1);
	prime[0] = prime[1] = 0;
	for (int i = 4; i < MAXN; i+=2) fat[i] = 2, prime[i] = 0;
	fat[2] = 2;
	sz = 0;
	prm[sz++] = 2;
	for (int i = 3; i < MAXN; i+=2) {
		if (prime[i]) {
			prm[sz++] = i;
			fat[i] = i;
			for(ll j = (ll)i*i; j < MAXN; j+=i) fat[j] = i, prime[j] = 0;
		}
	}
	int s;
	ll res;
	fr(i,2,MAXN) {
		s = sqrt(i);
		res = 1;
		if (s*s == i) res += dp[s];
		else s++;
		fr(j,2,s) if (i%j==0) {
			res+=dp[j]+dp[i/j];
		}
		dp[i] = res;
	}
}

int arr[MAXN+10], k;
ll rec(int x) {
	if (x < MAXN) return dp[x];
	else if (m.count(x) > 0) return m[x];
	int s = sqrt(x);
	ll res = 1;
	int stor = -1;
	rp(i,k) {
		if (arr[i] > s) break;
		if (x%arr[i]==0) {
			res+=dp[arr[i]];
			if (arr[i] != x/arr[i]) res+=rec(x/arr[i]);
		}
	}
	return m[x] = res;
}

int T;
ll n;
int main() {
	int cas = 1;
	preprocess();
	scanf("%d", &T);
	m.clear();
	while (T--) {
		scanf("%lld", &n); n++;
		if (n < MAXN) printf("Case %d: %lld\n", cas++, dp[n]);
		else {
			int s = sqrt(n);
			ll res = 1;
			int stor = -1;
			if (s*s == n) res += dp[s], stor = s;
			else s++;
			k = 0;
			fr(i,2,s) if (n%i==0) res+=dp[i], arr[k++] = i, arr[k++] = n/i;
			if (~stor) arr[k++] = stor;
			sort(arr,arr+k);
			fr(i,2,s) if (n%i==0) res+=rec(n/i);
			//rp(i,k) printf("%d ", arr[i]);
			//puts("");
			printf("Case %d: %lld\n", cas++, res);
		}
	}
}