#include <bits/stdc++.h>
using namespace std;
#define Fr(a,b,c) for(int a = b; a < c; a++)
#define Rp(a,b) Fr(a,0,b)
#define F first
#define S second
#define pb push
#define mp make_pair

typedef pair<int, pair<int,int> > pipii;

int n, m, a, b, c;
int rep[1000100];

void init() { Rp(i,n) rep[i] = i; }
int findset(int x) { return (x == rep[x]) ? x : rep[x] = findset(rep[x]); }
bool sameset(int x, int y) { return findset(x) == findset(y); }
void unionset(int x, int y) { rep[findset(x)] = findset(y); }

priority_queue<pipii, vector<pipii>, greater<pipii> > heap;
int main() {
	while (scanf("%d%d", &n, &m) == 2 && (n+m) > 0) {
		init();
		while (!heap.empty()) heap.pop();
		Rp(i,m) scanf("%d%d%d", &a, &b, &c), heap.pb(mp(c,mp(a,b)));
		int ans = 0, k = 0;
		while (!heap.empty()) {
			pipii aux = heap.top();
			heap.pop();
			if (sameset(aux.S.F,aux.S.S)) continue;
			k++;
			unionset(aux.S.F,aux.S.S);
			ans = aux.F;
			if (k == n-1) break;
		}
		if (k == n-1) printf("%d\n", ans);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}