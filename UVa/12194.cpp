#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 1111
#define LL long long
#define F first
#define S second

int X[MAXN], Y[MAXN], sp, res;
LL len[MAXN*MAXN];

LL dist(int i, int j) {
	return (LL)(X[i]-X[j])*(X[i]-X[j]) + (LL)(Y[i]-Y[j])*(Y[i]-Y[j]);
}

int main() {
	int N, cnt;
	while (scanf("%d", &N) == 1 && N > 0) {
		res = 0;
		rp(i,N) {
			scanf("%d%d", &X[i], &Y[i]);
		}
		rp(i,N) {
			sp = 0;
			rp(j,N) {
				if (i == j) continue;
				len[sp++] = dist(i,j);
			}
			sort(len, len+sp);
			len[sp] = -1;
			cnt = 1;
			for (int j = 1; j <= sp; j++) {
				if (len[j] != len[j-1]) {
					if (cnt > 1) res += (cnt*(cnt-1))/2;
					cnt = 0;
				}
				cnt++;
			}
		}
		printf("%d%c", res, 10);
	}
	return 0;
}