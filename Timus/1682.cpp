//by stor
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAXN 300000
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define ll long long
#define pb push_back

using namespace std;

int rep[MAXN+1111], mark[MAXN+1111], passo = 0;
int findset(int i) { return (i == rep[i]) ? i : rep[i] = findset(rep[i]); }
void link(int i, int j) { rep[findset(i)] = findset(j); }
bool isSameSet(int i, int j) { return (findset(i) == findset(j)); }
void init(int n) { rp(i,n+1) rep[i] = i; }

vector<ll> fila1[MAXN], fila2[MAXN];
int size;

int main() {
	ll K;
	scanf("%lld", &K);
	init(K+1000);
	for (ll i = 1;; i++) {
		passo++;
		size = fila1[(i*i)%K].size();
		//printf("%lld (%d)\n", i, size);
		rp(j,size) {
			//printf("%lld\n", fila1[(i*i)%K][j]);
			mark[fila1[(i*i)%K][j]] = passo;
			if (isSameSet(i,fila1[(i*i)%K][j])) {
				printf("%lld\n", i);
				goto lol;
			}
			link(i,fila1[(i*i)%K][j]);
		}
		size = fila2[i%K].size();
		//printf("%lld (%d)\n", i, size);	
		rp(j,size) {
			if (mark[fila2[i%K][j]]==passo) continue;
			//printf("%lld\n", fila2[i%K][j]);
			if (isSameSet(i,fila2[i%K][j])) {
				//printf("Same set %lld with %lld\n", i, fila2[i%K][j]);
				printf("%lld\n", i);
				goto lol;
			}
			link(i,fila2[i%K][j]);
		}
		//printf("Deixando %lld na fila1[%lld] e na fila2[%lld]\n", i, (K - i%K)%K, (K - (i*i)%K)%K);
		fila1[(K - i%K)%K].pb(i);
		fila2[(K - (i*i)%K)%K].pb(i);
	}
	printf("-1\n");
	lol:;
	return 0;
}
