#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <iostream>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define stclear() size=0
#define stpush(a) stack[size++] = a
#define stpop() size--
#define sttop() stack[size-1]

using namespace std;

//geral
bool mark[20001];
vector<int> adj[20001];

//scc
int low[20001], num[20001], counter, qnt;
int stack[20001], size;

void scc(int a) {
	mark[a]=1;
	num[a]=low[a]=counter++;
	stpush(a);
	rp(i,adj[a].size()) {
		if (num[adj[a][i]]==-1) scc(adj[a][i]);
		if (mark[adj[a][i]]) low[a] = min(low[a],low[adj[a][i]]);
	}
	if (low[a]==num[a]) {
		while(1) {
			int v = sttop();
			stpop();
			mark[v]=0;
			if (a==v) break;
		}
		qnt++;
	}
}



int main() {
	int n, m, a, b, c;
	while (scanf("%d%d", &n, &m)==2 && (n||m)) {
		memset(mark,0,sizeof mark);
		memset(num,-1,sizeof num);
		fr(i,1,n+1) adj[i].clear();
		rp(i,m) {
			scanf("%d%d%d", &a, &b, &c);
			adj[a].push_back(b);
			if (c==2) adj[b].push_back(a);
		}
		counter = qnt = 0;
		stclear();
		fr(i,1,n+1) if (num[i]==-1) scc(i);
		printf("%d\n", qnt==1);
	}
	return 0;
}