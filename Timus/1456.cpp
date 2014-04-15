//by stor
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#define ll long long
#define MAXN 100000

using namespace std;

bool comp[MAXN+10];
ll primes[MAXN+10], _sieve_size;

void sieve() {
	_sieve_size = 0;
	comp[0]=comp[1]=1;
	for (ll i = 2; i <= MAXN; i++) if (!comp[i]) {
		primes[_sieve_size++] = i;
		for (ll j = i*i; j <= MAXN; j+=i) comp[j] = 1;
	}
}

ll phi(ll N) {
	ll PF_idx=0, PF = primes[PF_idx], ans = N;
	while (N != 1 && (PF*PF <= N)) {
		if (N%PF == 0) ans -= ans/PF;
		while (N%PF == 0) N /= PF;
		PF = primes[++PF_idx];
	}
	if (N != 1) ans -= ans / N;
	return ans;
}

ll fastExp(ll n, ll exp, ll mod) {
	ll ans = 1;
	for (; exp > 0; exp >>= 1, n=(n*n)%mod) if (exp&1) ans=(ans*n)%mod;
	return ans;
}

ll findDiscreteLog(ll n, ll m, ll mod) {
	ll res = 0x3f3f3f3f;
	for (ll i = 1; i*i <= m; i++) {
		if (m%i == 0) {
			if (fastExp(n, i, mod) == 1) return i;
			else if (fastExp(n, m/i, mod) == 1) res = min(res, m/i);
		}
	}
	return res;
}

ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a%b)); }

int main() {
	sieve();
	ll n, mod;
	scanf("%lld %lld", &n, &mod);
	if (gcd(n, mod) == 1) printf("%lld\n", findDiscreteLog(n, phi(mod), mod));
	else printf("0\n");
	return 0;
}