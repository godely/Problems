#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define MAXN 1000010
#define inf 0x3f3f3f3f

using namespace std;

int x[1111], y[1111];

int dist2(int i, int j) {
	return (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
}

struct edge {
	int i, j, type;
	double cost;
	
	edge(){}
	edge(int i, int j, double cost, int type) : i(i), j(j), cost(cost), type(type) {}
	
	bool operator<(const edge &lhs) const {
		return cost < lhs.cost;
	}
} lista[1000101];
int k;

int rep[1111];
int findset(int i) {
	if (i==rep[i]) return i;
	return rep[i] = findset(rep[i]);
}
bool link(int i, int j) {
	if ((i=findset(i))==(j=findset(j))) return 0;
	rep[i]=j;
	return 1;
}

int main() {
	int T, N, r;
	scanf("%d", &T);
	fr(cas,1,T+1) {
		scanf("%d%d", &N, &r);
		rp(i,N) scanf("%d%d", &x[i], &y[i]), rep[i]=i;
		k = 0;
		rp(i,N) fr(j,i+1,N) {
			if (dist2(i,j) <= r*r) lista[k++] = edge(i,j,sqrt(dist2(i,j)),1);
			else lista[k++] = edge(i,j,sqrt(dist2(i,j)),2);
		}
		int states = 1;
		double c1 = 0, c2 = 0;
		sort(lista,lista+k);
		rp(i,k) {
			//printf("> %d %d %lf %d %d %d\n", lista[i].i, lista[i].j, lista[i].cost, lista[i].type, findset(lista[i].i), findset(lista[i].j));
			if (link(lista[i].i,lista[i].j)) {
				if(lista[i].type==1) c1+=lista[i].cost;
				else c2+=lista[i].cost, states++;
			}
		}
		printf("Case #%d: %d %d %d\n", cas, states, (int)(c1+0.5), (int)(c2+0.5));
	}
	return 0;
}