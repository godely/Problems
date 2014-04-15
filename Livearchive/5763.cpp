//by stor
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
#define LL int
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define pb push_back
#define db(x) cerr << #x " == " << x << "\n"
#define _ << ", " <<
#define inf 0x3f3f3f3f

int ter1[20];

int VISITED_ALL;
int mark[52];
int adj[52][52], cost[52][52], size[52];
int _free[52][52], sizeFree[52];
int attract[52][3], attractID[52][10], sizeID[52];
int cost_[52][7000], calc[52][7000], passo=0;

struct graf{
	int no, ternario, last;
	LL custo;
	graf(int no=0, int ternario=0, LL custo=0) : no(no),ternario(ternario),custo(custo) {}
	bool operator<(const graf &lhs) const {
		if (custo != lhs.custo) return custo > lhs.custo;
		return ternario < lhs.ternario;
	}
} next;

priority_queue<graf> fila;
void bfs(int initPode){
	while (!fila.empty()) fila.pop();
	fila.push(graf(1, initPode, 0));
	int no, last, ternario, tempo, k, proxTernario;
	calc[1][initPode] = passo;
	cost_[1][initPode] = 0;
	while(!fila.empty()){
		next = fila.top();
		fila.pop();
		no = next.no; ternario = next.ternario;
		if(ternario==VISITED_ALL && no==1){
			cout << next.custo << endl;
			break;
		}
		last = 0;
		//if(calc[no][ternario]==passo) continue;
		//printf("%d %d %d %d\n", no, ternario, next.custo);
		calc[no][ternario]=passo;
		while (last < sizeID[no]) {
			k = (ternario/ter1[attractID[no][last]])%3;
			if (k < 2) { //nao visitou ainda
				tempo = (k > 0) ? attract[attractID[no][last]][1] : attract[attractID[no][last]][0];
				proxTernario = ternario + ter1[attractID[no][last]]*(2-k);
				if (calc[no][proxTernario] != passo || cost_[no][proxTernario] > next.custo + tempo) {
					calc[no][proxTernario] = passo;
					cost_[no][proxTernario] = next.custo + tempo;
					fila.push(graf(no, proxTernario, next.custo + tempo));
				}
			}
			last++;
		}
		for (int i = 0; i < size[no]; i++) {
			proxTernario = ternario;
			for (int j = 0; j < sizeFree[adj[no][i]]; j++) {
				k = (ternario/ter1[_free[adj[no][i]][j]])%3;
				if (k == 0) proxTernario+=ter1[_free[adj[no][i]][j]];
			}
			if (calc[adj[no][i]][proxTernario] != passo || cost_[adj[no][i]][proxTernario] > next.custo + cost[no][i]) {
				calc[adj[no][i]][proxTernario] = passo;
				cost_[adj[no][i]][proxTernario] = next.custo + cost[no][i];
				fila.push(graf(adj[no][i], proxTernario, cost[no][i]+next.custo));
			}
		}
	}
}

void reset() {
	passo++;
	memset(size,0,sizeof size);
	memset(sizeFree,0,sizeof sizeFree);
	memset(sizeID, 0, sizeof sizeID);
}

int main() {
	cin.sync_with_stdio(false);
	ter1[0] = 1;
	for (int i = 1; i < 10; i++) ter1[i] = ter1[i-1]*3;
	int T, cas = 1;
	int N, M, K, a, b, d, Pi, Ti, FTi, Ni;
	cin >> T;
	while (T--) {
		reset();
		cin >> N >> M >> K;
		VISITED_ALL = ter1[K]-1;
		rp(i,M) {
			cin >> a >> b >> d;
			adj[a][size[a]] = b;
			adj[b][size[b]] = a;
			cost[a][size[a]++] = cost[b][size[b]++] = d;
		}
		rp(i,K) {
			cin >> Pi >> Ti >> FTi >> Ni;
			attractID[Pi][sizeID[Pi]++] = i;
			attract[i][0] = Ti; attract[i][1] = FTi;
			memset(mark,0,sizeof mark);
			rp(j,Ni) {
				cin >> a;
				if (mark[a]==1) continue;
				mark[a]=1;
				_free[a][sizeFree[a]++] = i;
			}
		}
		int initPode = 0;
		for (int j = 0; j < sizeFree[1]; j++) initPode += ter1[_free[1][j]];
		cout << "Case #" << cas++ << ": ";
		bfs(initPode);
	}
	return 0;
}