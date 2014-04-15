#include <bits/stdc++.h>
using namespace std;
#define Fr(a,b,c) for(int a = b; a < c; a++)
#define Rp(a,b) Fr(a,0,b)
#define F first
#define S second
#define pb push
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007ULL
#define maxn 5011

int n;
ull pd[maxn][maxn];
ull pot[maxn];

ull solve(int ind, int big) {
	if (~pd[ind][big]) return pd[ind][big];
	if (ind == n-1) return pd[ind][big] = n;
	if (big == n-1) return pd[ind][big] = pot[n-ind];

	ull ret = 0;
	if (big > ind) ret = (big+1)*solve(ind+1, big)%mod;
	for (int i = max(ind+1,big+1); i < n; i++) ret = (ret+solve(ind+1, i))%mod;
	return pd[ind][big] = ret;
}

int main() {
	memset(pd,-1,sizeof pd);
	scanf("%d", &n);
	pot[0] = 1;
	Fr(i,1,n+1) pot[i] = (pot[i-1]*n)%mod;
	printf("%llu\n", solve(0,0));
}











