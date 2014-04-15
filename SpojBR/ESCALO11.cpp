#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#define MAXN 10000

using namespace std;

int n, adj[MAXN][MAXN], nadj[MAXN], tops[MAXN], foi[MAXN], ip;
int foi2[MAXN], rep[MAXN];

int findset(int a) {
	if (rep[a]==a) return a;
	return rep[a]=findset(rep[a]);
}
void join(int a, int b) {
	a=findset(a),b=findset(b);
	rep[a]=b;
}

int DFS(int k) {
	int i, j;
	
	foi[k] = foi2[k] = 1;
	for(j=nadj[k]-1; j >= 0; j--) {
		i = adj[k][j];
		if (foi2[i]) return 0;
		if (!foi[i] && !DFS(i)) return 0;
	}
	tops[--ip]=k;
	foi2[k]=0;
	
	return 1;
}

int ord_top() {
	int i;

	memset(foi, 0, n*sizeof(int));
	memset(foi2, 0, n*sizeof(int));
	ip=n;

	for (i=0; i < n; i++) if (!foi[i] && !DFS(i)) return 0;

	return 1;
}

bool cmp(int a, int b) {
	a=findset(a),b=findset(b);
	if (a==b) return 0;
	return a < b;
}

int main() {
	int m, i, from, to;
	while (scanf("%d%d", &n, &m) == 2 && n != 0) {
		memset(nadj,0,sizeof nadj);
		for(i=0; i<n; i++) rep[i]=i;
		for(i=0; i<m; i++) {
			scanf("%d%d", &from, &to);
			adj[from][nadj[from]++]=to;
			join(from,to);
		}
		for(i=0; i<n; i++) sort(adj[i],adj[i]+nadj[i]);
		if (!ord_top()) printf("*\n");
		else {
			sort(tops,tops+n,cmp);
			for (i=0; i<n;i++) printf("%d\n", tops[i]);
		}
	}
	return 0;
}