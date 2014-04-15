#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;

struct st {
	int a, b, ind;
	st() {}
	
	bool operator <(const st &lhs) const {
		if (b != lhs.b) return b < lhs.b;
		return a > lhs.a;
	}
} el[1111];

int dp[1111], back[1111];
int main() {
	int sz = 0;
	while (scanf("%d%d", &el[sz].a, &el[sz].b) == 2) {
		el[sz].ind = sz+1;
		sz++;
	}
	sort(el, el+sz);
	int best = 0, who = -1;
	memset(back,-1,sizeof back);
	fr(i,0,sz) {
		dp[i] = 1;
		fr(j,0,i) {
			if (el[j].b < el[i].b && el[j].a > el[i].a && dp[j]+1 > dp[i]) {
				dp[i] = dp[j]+1;
				back[i] = j;
			}
		}
		if (dp[i] > best) {
			best = dp[i];
			who = i;
		}
	}
	printf("%d\n", best);
	for (int i = who; ~i; i = back[i]) printf("%d\n", el[i].ind);
}