#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <iostream>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define stclear() size=0
#define stpush(a) stack[size++] = a
#define stpop() size--
#define sttop() stack[size-1]
#define add(a,b) to[z]=b, ant[z]=adj[a], adj[a]=z++

using namespace std;

//geral
bool mark[100001];
int to[100001], ant[100001], adj[100001], z;
bool in[100001];

//scc
int low[100001], num[100001], counter, paint;
int stack[100001], color[100001], size, qnt;

void scc(int a) {
	mark[a]=1;
	num[a]=low[a]=counter++;
	stpush(a);
	for (int i = adj[a]; i != -1; i = ant[i]) {
		if (num[to[i]]==-1) scc(to[i]);
		if (mark[to[i]]) low[a] = min(low[a],low[to[i]]);
		else if (!in[color[to[i]]]) in[color[to[i]]]=1, qnt--;
	}
	if (low[a]==num[a]) {
		while(1) {
			int v = sttop();
			stpop();
			mark[v]=0;
			color[v]=paint;
			if (a==v) break;
		}
		qnt++;
		paint++;
	}
}

int main() {
	int T, n, m, a, b;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		fr(i,1,n+1) mark[i]=color[i]=in[i]=0, num[i]=adj[i]=-1;
		z=0;
		rp(i,m) {
			scanf("%d%d", &a, &b);
			add(a,b);
		}
		counter = qnt = 0;
		paint=1;
		stclear();
		for (int i = n; i>=1; i--) if (num[i]==-1) scc(i);
		printf("%d\n", qnt);
	}
	return 0;
}