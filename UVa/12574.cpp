#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define ll long long
#define mod 1000000007
using namespace std;

int main() {
	int T, N;
	ll v, res, S;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		res = -1;
		S = 1;
		rp(i,N) {
			scanf("%lld", &v);
			res=(res-v+mod)%mod;
			S = (S*(v+1))%mod;
		}
		printf("%lld\n", (res+S)%mod);
	}
	return 0;
}