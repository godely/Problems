#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
using namespace std;

int N, M, F, L;

int p[20][2], mark[20];

bool bt(int ind, int last) {
	//printf("> %d %d\n", ind, last);
	if (ind == N) {
		rp(i,M) if (!mark[i] && ((p[i][0] == last && p[i][1] == L) || (p[i][0] == L && p[i][1] == last))) return 1;
		return 0;
	}
	bool ok = 0;
	rp(i,M) {
		if (!mark[i]) {
			if (p[i][0] == last) {
				mark[i] = 1;
				ok |= bt(ind+1, p[i][1]);
				mark[i] = 0;
			} else if (p[i][1] == last) {
				mark[i] = 1;
				ok |= bt(ind+1, p[i][0]);
				mark[i] = 0;
			}
		}
		if (ok) return 1;
	}
	return 0;
}

int main() {	
	while (scanf("%d", &N) == 1 && N > 0) {
		scanf("%d", &M);
		scanf("%*d%d %d%*d", &F, &L);
		rp(i,M) scanf("%d%d", &p[i][0], &p[i][1]), mark[i] = 0;
		if (bt(1,F)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}