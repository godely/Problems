#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define LSOne(x) (x&(-x))
#define MAXN 100100
#define ll long long

ll EXPO[MAXN], EXPO2[MAXN], B, P, L, ATUAL[MAXN];
int N;

ll _x, _y, _d;
void extendedEuclid(ll a, ll b) {
	if (b==0) { _x = 1; _y = 0; _d = a; return; }
	extendedEuclid(b, a%b);
	ll x1 = _y;
	ll y1 = _x - (a/b)*_y;
	_x = x1;
	_y = y1;
}

ll t[MAXN];
ll get(int i) {
	ll sum = 0;
	for(; i; i -= LSOne(i)) sum = (sum+t[i]+P)%P;
	return sum;
}

void add(int i, ll x) {
	for (; i <= L; i += LSOne(i)) t[i] = (t[i]+x+P)%P;
}

char str[50];
ll a, b;
int main() {
	EXPO[0] = EXPO2[0] = 1;
	while (scanf("%lld%lld%lld%d", &B, &P, &L, &N) == 4 && B > 0) {
		extendedEuclid(B,P);
		if (_x < 0) _x += P;

		t[0] = ATUAL[0] = 0;
		fr(i,1,L+1) {
			EXPO[i] = (EXPO[i-1]*B)%P;
			EXPO2[i] = (EXPO2[i-1]*_x)%P;
			t[i] = 0;
			ATUAL[i] = 0;
		}
		rp(i,N) {
			scanf("%s%lld%lld", str, &a, &b);
			if (str[0] == 'E') {
				add(a, b*EXPO[L-a]-ATUAL[a]);
				ATUAL[a] = b*EXPO[L-a];
			} else {
				ll res = (get(b) - get(a-1) + P)%P;
				res = (res*EXPO2[L-b])%P;
				printf("%lld\n", res);
			}
		}
		printf("-\n");
	}
	return 0;
}