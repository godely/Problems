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

int T, N, K, a[110000];
ll cnt[1000];

int main() {
	int cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &K);
		rp(i,N) scanf("%d", &a[i]);
		sort(a,a+N);
		
		cl(cnt,0);
		ll res = 0;
		rp(i,N-1) {
			int b = a[i];
			if (b < 0) {
				b = -b;
				b = (K - b%K)%K;
			} else {
				b = b%K;
			}
			cnt[b]++;
			if (a[i] == a[i+1]) {
				if ((a[i]+a[i+1])%K == 0) res++;
				int j = i+2;
				for (; j < N && a[j] == a[i]; j++);
				i = j-1;
			}
		}
		if (a[N-2] != a[N-1]) cnt[a[N-1]%K]++;
		
		ll res2 = 0;
		fr(i,0,K) {
			//printf("%d %d: %lld %lld\n", i, (K-i)%K, cnt[i], cnt[(K-i)%K]);
			if (i == (K-i)%K) res2 += ((cnt[i]*(cnt[(K-i)%K]-1)));
			else res2 += ((cnt[i]*cnt[(K-i)%K]));
		}
		printf("Case %d: %lld\n", cas++, res + (res2>>1));
	}
}