#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a, b, sizeof(a))
#define inf 1000000000000000LL
#define LL long long

LL MIN_, _A, _B, C, D;
bool ok;
void bt(int ind, LL A, LL B) {
	//printf("%d\n", ind);
	if (ind >= 32) {
		//printf("%lld %lld\n", A, B);
		if (abs(A-B) < MIN_ && ((A&B)==C) && ((A|B)==D)) {
			MIN_ = abs(A-B);
			_A = min(A,B);
			_B = max(A,B);
			ok = 1;
		}
		return;
	}

	if (C&(1<<ind)) {
		bt(ind+1, A|(1<<ind), B|(1<<ind));
	} else {
		if (D&(1<<ind)) {
			bt(ind+1, A|(1<<ind), B);
			bt(ind+1, A, B|(1<<ind));
		} else {
			bt(ind+1, A, B);
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld", &C, &D);
		MIN_ = inf;
		ok = 0;
		bt(0,0,0);
		if (ok) printf("%lld %lld\n", _A, _B);
		else printf("-1\n");
	}
	return 0;
}
