#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;

struct st {
	int a, b, ind;
	st() {}
	st(int a, int b) : a(a), b(b) {}
	
	bool operator <(const st &lhs) const {
		if (b != lhs.b) return b > lhs.b;
		return a > lhs.a;
	}
} el[1111];

int sz = 0;
int dp[1111], back[1111];

bool cmp(int a, int b) { return el[a].a < el[b].a; }

void lis() {
	int x = 0;
	fr(i,0,sz) {
		int y = lower_bound(dp,dp+x,i,cmp) - dp;
		if (y == x) x++;
		dp[y] = i;
		if (!y) back[i] = -1;
		else back[i] = dp[y-1];
	}
	printf("%d\n", x);
	if (x) {
		stack<int> st;
		for (int i = dp[x-1]; ~i; i = back[i]) st.push(el[i].ind);
		while (!st.empty()) printf("%d\n", st.top()), st.pop();
	}
}

int main() {
	while (scanf("%d%d", &el[sz].a, &el[sz].b) == 2) {
		el[sz].ind = sz+1;
		sz++;
	}
	sort(el, el+sz);
	lis();
}