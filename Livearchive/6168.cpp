#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

const double EPS = 1e-7;

struct PT {
	int x, y;
	
	bool operator <(const PT &lhs) const {
		if (y != lhs.y) return y < lhs.y;
		return x < lhs.x;
	}
} P[5100];

int dist2(int a, int b) { return (P[a].x-P[b].x)*(P[a].x-P[b].x) + (P[a].y-P[b].y)*(P[a].y-P[b].y); }

double ray;
int N, L, vis[5100], passo = 0;

bool dfs(int k) {
	if (vis[k] == passo) return 0;
	vis[k] = passo;
	if (P[k].y+2*ray >= N) return 1;
	for (int i = 0; i < L && P[i].y <= P[k].y+2*ray; i++) if (i != k && vis[i] != passo && dist2(k,i) <= 4*ray*ray && dfs(i)) return 1;
	return 0;
}

int main() {
	while (scanf("%d%d", &N, &L) == 2 && (N+L)>0) {
		rp(i,L) {
			scanf("%d%d", &P[i].x, &P[i].y);
		}
		sort(P, P+L);
		double ini = 0, fim = N, meio;
		while (fabs(ini-fim) > EPS) {
			meio = (ini+fim)/2;
			ray = meio/2;
			passo++;
			bool ok = 1;
			for (int i = 0; ok && i < L && P[i].y <= 2*ray; i++) if (vis[i] != passo && dfs(i)) ok = 0;
			if (ok) ini = meio;
			else fim = meio;
		}
		printf("%.3lf\n", ini);
	}
	return 0;
}