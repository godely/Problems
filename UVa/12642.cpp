#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <iostream>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 2011
typedef long long ll;
using namespace std;

int n, p[MAXN], x[MAXN];
int mark[MAXN], passo;

struct Matrix {
	int l[MAXN];
	
	Matrix() {}
	
	Matrix operator*(const Matrix &q) {
		Matrix ret;
		rp(i,n) ret.l[i] = q.l[l[i]];
		return ret;
	}
} aux, res;

void expo(ll n) {
	for (; n; n >>= 1LL, aux=aux*aux) if (n&1) res=res*aux;
}

ll gcd(ll a, ll b) { return (!b) ? a : gcd(b,a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

ll r;
int main() {
	passo = 0;
	memset(mark,0,sizeof mark);
	while (scanf("%d%lld", &n, &r) == 2) {
		rp(i,n) scanf("%d", &p[i]), p[i]--, x[i] = i;
		
		passo++;
		ll m = 1, cyc;
		rp(i,n) {
			if (mark[i] != passo) {
				int k = i;
				cyc = 0;
				do {
					mark[k] = passo;
					cyc++;
					k = p[k];
				} while (k != i);
			}
			m = lcm(m,cyc);
		}
		r%=m;
		
		rp(i,n) res.l[i] = i, aux.l[p[i]] = i;
		expo(r);
		
		rp(i,n) p[res.l[i]] = i;
		printf("%d", p[0]+1);
		fr(i,1,n) printf(" %d", p[i]+1);
		puts("");
	}
	return 0;
}