#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

char str[20][1000];
double p[20][20];
double dp[20][20][20];
int mark[20][20][20];

double solve(int who, int beg, int end) {
	if (mark[who][beg][end]) return dp[who][beg][end];
	mark[who][beg][end] = 1;
	if (beg == end) return dp[who][beg][end] = 1.0;
	int half = (beg+end)/2;
	double ret = 0.0;
	if (who > half) {
		for (int i = beg; i <= half; i++) {
			ret += solve(i, beg, half)*p[who][i];
		}
		ret *= solve(who, half+1, end);
	} else {
		for (int i = half+1; i <= end; i++) {
			ret += solve(i, half+1, end)*p[who][i];
		}
		ret *= solve(who, beg, half);
	}
	return dp[who][beg][end] = ret;
}

int main() {
	rp(i,16) scanf("%s", str[i]);
	rp(i,16) rp(j,16) scanf("%lf", &p[i][j]), p[i][j]/=100.0;

	rp(i,16) {
		printf("%-10s p=%.2lf%%\n", str[i], 100*solve(i,0,15));
	}
}