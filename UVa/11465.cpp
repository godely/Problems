#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define pb push_back
#define LL long long

struct sum {
	LL qnt, soma, maior, soma2;
	sum() {}
	sum(LL qnt, LL soma, LL maior, LL soma2 = 0):qnt(qnt), soma(soma), maior(maior), soma2(soma2) {}
	bool operator<(const sum &lhs) const {
		if (qnt != lhs.qnt) return qnt < lhs.qnt;
		return soma < lhs.soma;
	}
};
vector<sum> S1, S2;
int size1, size2;

LL v[50];
int main() {
	int T, n, k, left, right, res, cas = 1;
	scanf("%d", &T);
	while (T--) {
		S1.clear(); S2.clear();
		scanf("%d%d", &n, &k);
		rp(i,n) scanf("%lld", &v[i]);
		sort(v,v+n);
		S1.pb(sum(0,0,0)); S2.pb(sum(0,0,0));
		size1 = size2 = 1;
		fr(i,0,(n+1)/2) {
			rp(j,size1) S1.pb(sum(S1[j].qnt+1, S1[j].soma+v[i], v[i]));
			size1 = S1.size();
		}
		fr(i,(n+1)/2,n) {
			rp(j,size2) S2.pb(sum(S2[j].qnt+1, v[i]-S2[j].soma2, v[i], S2[j].soma2+v[i]));
			size2 = S2.size();
		}
		sort(S1.begin(), S1.end()); sort(S2.begin(), S2.end());
		/*rp(i,size1) printf("%d %d %d\n", S1[i].qnt, S1[i].soma, S1[i].maior);
		printf("\n");
		rp(i,size2) printf("%d %d %d\n", S2[i].qnt, S2[i].soma, S2[i].maior);
		printf("\n");*/
		res = 0;
		rp(i,size1) {
			if (S1[i].qnt == k) res+=(S1[i].soma > 2*S1[i].maior);
			else {
				if (lower_bound(S2.begin(), S2.end(), sum(k-S1[i].qnt, -100000000000LL, 0)) != S2.end()) {
					right = lower_bound(S2.begin(), S2.end(), sum(k-S1[i].qnt, S1[i].soma, 0)) - S2.begin();
					left = lower_bound(S2.begin(), S2.end(), sum(k-S1[i].qnt, -100000000000LL, 0)) - S2.begin();
					//printf("> %d %d %d\n", i, left, right);
					if (S2[left].qnt == k-S1[i].qnt) res+=(right-left);
				}
			}
		}
		printf("Case %d: %d\n", cas++, res);
	}
	return 0;
}