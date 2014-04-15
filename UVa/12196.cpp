#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 11111
#define LL long long
#define pb push_back
#define inf 0x3f3f3f3f

vector<int> stud[MAXN];
int N, K;

int test(int k) {
	int ret = 0, pos;
	rp(i,N) {
		pos = lower_bound(stud[i].begin(), stud[i].end(), k) - stud[i].begin();
		ret += abs(2*pos-(int)stud[i].size());
	}
	return ret;
}

int main() {
	int a, meio, ans;
	while (scanf("%d", &N) == 1 && N > 0) {
		rp(i,N) stud[i].clear();
		rp(i,N) {
			scanf("%d", &K);
			rp(j,K) scanf("%d", &a), stud[i].pb(a);
			sort(stud[i].begin(), stud[i].end());
		}
		ans = inf;
		for (int i = 0; i <= 1000; i++) {
			meio = test(i);
			if (meio < ans) ans = meio;
		}
		printf("%d%c", ans, 10);
	}
	return 0;
}