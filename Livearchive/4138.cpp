#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define F first
#define S second
#define maxn 511
#define mp make_pair

typedef pair<int, pair<int,int> > pipii;

int rep[maxn];
void init(int n) { rp(i,n) rep[i] = i; }
int findset(int i) { if (i == rep[i]) return i; else return rep[i] = findset(rep[i]); }
bool sameset(int i, int j) { return findset(i) == findset(j); }
void unionset(int i, int j) { rep[findset(i)] = findset(j); }

priority_queue<pipii, vector<pipii>, greater<pipii> > heap;
int d[maxn][5];
int main() {
	int T, N; scanf("%d", &T);
	while (T--) {
		while (!heap.empty()) heap.pop();
		scanf("%d", &N);
		init(N);
		rp(i,N) {
			rp(k,4) scanf("%1d", &d[i][k]);
			rp(j,i) {
				int dist = 0;
				rp(k,4) {
					int a = min(d[i][k], d[j][k]);
					int b = max(d[i][k], d[j][k]);
					dist += min(10 + a - b, b - a);
				}
				heap.push(mp(dist,mp(i,j)));
			}
		}
		int cost = 100000000;
		rp(i,N) {
			int dist = 0;
			rp(k,4) {
				dist += min(10 - d[i][k], d[i][k]);
			}
			cost = min(cost, dist);
		}
		while (!heap.empty()) {
			pipii aux = heap.top(); heap.pop();
			if (!sameset(aux.S.F,aux.S.S)) unionset(aux.S.F, aux.S.S), cost+=aux.F;
		}
		printf("%d\n", cost);
	}
	return 0;
}