#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

using namespace std;

int adj[400][400][2];
int mark[400], passo=0;
int size[400];
int rep[400];
vector<int> next[400];

int find_set(int a) {
    if (rep[a]==a) return a;
    return rep[a]=find_set(rep[a]);
}

bool link(int a, int b) {
    a=find_set(a), b=find_set(b);
    if (a==b) return 0;
    rep[a]=b;
    return 1;
}

struct edge {
	int a, b, volt;
	bool is;
	edge() {}
	edge(int a, int b, int volt, bool is=0):a(a), b(b), volt(volt), is(is) {}

	bool operator<(const edge &lhs) const {
		return volt < lhs.volt;
	}
} E[160000];

struct abc {
    int id, volt;
    abc() {}
    abc(int id, int volt):id(id),volt(volt){}

    bool operator<(const abc &lhs) const {
        return volt > lhs.volt;
    }
};

int dfs(int x, int pai) {
	mark[x]=passo;
	//printf("%d %d\n", x, pai);
	int M=-1, MVolt=inf, ret, i;
	rp(j,next[x].size()) {
		if (adj[x][i][1] != pai && E[adj[x][i][0]].is) {
			if (mark[adj[x][i][1]]==passo) {
				if (E[adj[x][i][0]].volt < MVolt) MVolt=E[adj[x][i][0]].volt, M=adj[x][i][0];
			} else {
				ret = dfs(adj[x][i][1],x);
				if (ret != -1) {
					if (E[ret].volt < MVolt) MVolt=E[ret].volt, M=ret;
					if (E[adj[x][i][0]].volt < MVolt) MVolt = E[adj[x][i][0]].volt, M=adj[x][i][0];
				}
			}
		}
	}
	//printf("To no %d, retornando aresta %d de peso %d\n", x, M, MVolt);
	return M;
}

int main() {
	int N, M, a, b, volt, ret, count, res;
	priority_queue<abc> heapMin;
	while (scanf("%d", &N)==1 && N>0) {
		scanf("%d", &M);
		rp(i,N+1) size[i]=0;
		rp(i,N+1) rep[i]=i;
		rp(i,M) {
			scanf("%d%d%d", &a, &b, &volt);
			E[i]=edge(a,b,volt);
		}
		sort(E,E+M);
		rp(i,M) {
            adj[E[i].a][size[E[i].a]][0]=i;
            adj[E[i].a][size[E[i].a]++][1]=E[i].b;
            adj[E[i].b][size[E[i].b]][0]=i;
            adj[E[i].b][size[E[i].b]++][1]=E[i].a;
		}
		//printf("\n");
		//rp(i,M) printf("%d %d %d\n", E[i].a, E[i].b, E[i].volt);
		//printf("\n");
		res=inf;
		count=0;

		while (!heapMin.empty()) heapMin.pop();
		rp(i,N) next.clear();
		rp(i,M) {
			E[i].is=1;
			heapMin.push(abc(i,E[i].volt));
			next[E[i].a].push_back(E[i].b);
			next[E[i].b].push_back(E[i].a);
			count++;
			//printf("%d: \n", i);
			passo++;
			if (!link(E[i].a,E[i].b)) {
                ret = dfs(E[i].a,-1);
                if (ret!=-1) {
                    if (ret==heapMin.top().id) heapMin.pop();
                    rp(j,next[E[ret].a].size()) if (next[E[ret].a][j]==E[ret].b) next[E[ret].a].erase(j);
                    rp(j,next[E[ret].b].size()) if (next[E[ret].b][j]==E[ret].a) next[E[ret].b].erase(j);
                    //printf("> Remova a aresta %d com peso %d\n", ret, E[ret].volt);
                    E[ret].is=0;
                    count--;
                }
			}
			//printf("< %d\n", count);
			if (count == N-1) res=min(res,E[i].volt-heapMin.top().volt);
		}
		printf("%d\n", res);
	}
	return 0;
}
