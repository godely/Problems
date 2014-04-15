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
int k;
char str1[30], str2[30];
map<string, int> mapa;
bool foi[30][30], mark[30];
vector<int> adj[30];
vector<string> nome;

//scc
int low[30], num[30], counter;
int stack[3000], size;

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
			printf("%s", nome[v].c_str());
			if (a==v) break;
			else printf(", ");
		}
		printf("\n");
	}
}

int main() {
	int n, m, cas=1;
	bool ok = 0;
	while (scanf("%d%d", &n, &m) == 2 && (n||m)) {
		if (ok) printf("\n");
		else ok=1;
		k = 1;
		nome.clear();
		nome.push_back("");
		memset(foi,0,sizeof foi);
		memset(mark,0,sizeof mark);
		memset(num,-1,sizeof num);
		fr(i,1,n+1) adj[i].clear();
		mapa.clear();
		rp(i,m) {
			scanf("%s%s", str1, str2);
			if (mapa[str1]==0) mapa[str1]=k++, nome.push_back(str1);
			if (mapa[str2]==0) mapa[str2]=k++, nome.push_back(str2);
			if (!foi[mapa[str1]][mapa[str2]]) adj[mapa[str1]].push_back(mapa[str2]), foi[mapa[str1]][mapa[str2]]=1;
		}
		counter = 0;
		stclear();
		printf("Calling circles for data set %d:\n", cas++);
		fr(i,1,n+1) if(num[i]==-1) scc(i);
	}
	return 0;
}