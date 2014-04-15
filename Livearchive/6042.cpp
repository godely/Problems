#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define LEFT 0
#define RIGHT 1

int N, H, W;
int sacred;

struct aux {
	int p, h;
	aux() {}
	aux(int p, int h) : p(p), h(h) {}
	
	bool operator<(const aux &lhs) const {
		return p < lhs.p;
	}
} ord[100];

int mark[55][555][2], turn = 0, dp[55][555][2];

int solveLeft(int ind, int pos) {
	if (mark[ind][pos][LEFT] == turn) return dp[ind][pos][LEFT];
	mark[ind][pos][LEFT] = turn;

	if (ord[ind].h <= H) return dp[ind][pos][LEFT] = 0;
	if (ind == 0) return dp[ind][pos][LEFT] = inf;
	
	if (ord[ind].h-ord[ind-1].h > H) return dp[ind][pos][LEFT] = inf;
	int ret = inf;
	if (ord[ind-1].h == sacred) {
		if (pos-ord[ind-1].p > W) return dp[ind][pos][LEFT] = inf;
		else return dp[ind][pos][LEFT] = solveLeft(ind-1, ord[ind-1].p);
	} else {
		for (int i = 0; i < pos; i++) {
			if (pos-i <= W) {
				ret = min(ret, (abs(i-ord[ind-1].p))*ord[ind-1].h + solveLeft(ind-1, i));
			}
		}
		return dp[ind][pos][LEFT] = ret;
	}
}

int solveRight(int ind, int pos) {
	if (mark[ind][pos][RIGHT] == turn) return dp[ind][pos][RIGHT];
	mark[ind][pos][RIGHT] = turn;

	if (ord[ind].h <= H) return dp[ind][pos][RIGHT] = 0;
	if (ind == N-1) return dp[ind][pos][RIGHT] = inf;
	
	if (ord[ind].h-ord[ind+1].h > H) return dp[ind][pos][RIGHT] = inf;
	int ret = inf;
	if (ord[ind+1].h == sacred) {
		if (ord[ind+1].p-pos > W) return dp[ind][pos][RIGHT] = inf;
		else return dp[ind][pos][RIGHT] = solveRight(ind+1, ord[ind+1].p);
	} else {
		for (int i = 500; i > pos; i--) {
			if (i-pos <= W) {
				ret = min(ret, (abs(i-ord[ind+1].p))*ord[ind+1].h + solveRight(ind+1, i));
			}
		}
		return dp[ind][pos][RIGHT] = ret;
	}
}

int main() {
	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		sacred = 0; turn++;
		scanf("%d%d%d", &N, &H, &W);
		rp(i,N) {
			scanf("%d%d", &ord[i].p, &ord[i].h);
			sacred = max(sacred,ord[i].h);
		}
		sort(ord,ord+N);
		int ret = inf;
		
		if (N == 1) {
			if (ord[0].h <= H) ret = 0;
			else ret = inf;
		}

		for (int i = 1; i < N; i++) {
			if (ord[i].h == sacred) {
				ret = min(ret, solveLeft(i, ord[i].p));
			}
		}
		
		for (int i = 0; i < N-1; i++) {
			if (ord[i].h == sacred) {
				ret = min(ret, solveRight(i, ord[i].p));
			}
		}
		
		if (ret < inf) printf("Case #%d: %d\n", cas++, ret);
		else printf("Case #%d: -1\n", cas++);
	}
}