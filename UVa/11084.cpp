#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define sf(a) scanf("%d", &a)
#define sf2(a,b) scanf("%d%d", &a, &b)
#define sf3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define sf4(a,b,c,d) scanf("%d%d%d%d", &a, &b, &c, &d)
typedef pair<int,int> pii;
typedef long long ll;
#define MP make_pair
#define F first
#define S second
#define oo 0x3f3f3f3f

int T, d;
char str[20];
int a[20], s, cnt[20];
int FULL;

ll dp[1<<11][10010];
int mark[1<<11][10010], passo;

ll go(int mask, int sum) {
	ll &pd = dp[mask][sum];
	if (mark[mask][sum] == passo) return pd;
	mark[mask][sum] = passo;
	if (mask == FULL) return pd = (sum == 0);
	
	ll res = 0;
	rp(i,s) {
		if (((mask>>i)&1)==0) {
			res += go(mask|(1<<i),((sum*10)+a[i])%d);
		}
	}
	return pd = res;
}

int fat[20];
int main() {
	fat[0] = 1;
	fr(i,1,10) fat[i] = fat[i-1]*i;
	cl(mark,0); passo = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%s%d", str, &d);
		s = strlen(str);
		cl(cnt,0);
		rp(i,s) a[i] = str[i]-'0', cnt[a[i]]++;
		sort(a,a+s);
		FULL = (1<<s)-1;

		passo++;
		ll r = go(0,0);
		
		rp(i,10) {
			r /= fat[cnt[i]];
		}
		
		printf("%lld\n", r);
	}
}