#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define pb push_back

using namespace std;

vector<int> vet[1000001];
int mark[1000001], passo=0;

int main() {
	int n, m, a, b;
	while (scanf("%d%d", &n, &m) == 2) {
		passo++;
		rp(i,n) {
			scanf("%d", &a);
			if (mark[a]!=passo) {
				mark[a]=passo;
				vet[a].clear();
			}
			vet[a].pb(i+1);
		}
		rp(i,m) {
			scanf("%d%d", &b, &a);
			if (mark[a] != passo || b > vet[a].size()) printf("0\n");
			else printf("%d\n", vet[a][b-1]);
		}
	}
	return 0;
}