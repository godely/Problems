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

int ter1[20];

int VISITED_ALL;
int adj[52][52], cost[52][52], size[52];
int _free[52][52], sizeFree[52];
int attract[52][3], attractID[52][10], sizeID[52];
int calc[52][7000][10], passo=0;

struct graf{
	int no,ternario,last;
	LL custo;
	graf(int no=0,int ternario=0,int last=0,LL custo=0):no(no),ternario(ternario),last(last),custo(custo) {}
	bool operator<(const graf &lhs)const{
		return custo>lhs.custo;
	}
} next;

priority_queue<graf> fila;

void bfs(int initPode){
	while (!fila.empty()) fila.pop();
	fila.push(graf(1,initPode,0,0));
	int no,last,ternario,tempo,k;
	while(!fila.empty()){
		next=fila.top();
		if(fila.size()>500000){
			cout << next.custo << endl;
			break;
		}
		fila.pop();
		no=next.no;
		ternario=next.ternario;
		last=next.last;
		if(ternario==VISITED_ALL&&no==1){
			cout << next.custo << endl;
			break;
		}
		if(calc[no][ternario][last]==passo) continue;
		printf("%d %d %d %d\n", no, ternario, last, next.custo);
		calc[no][ternario][last]=passo;
		if (last < sizeID[no]) {
			k = (ternario/ter1[attractID[no][last]])%3;
			tempo = (k > 0) ? attract[attractID[no][last]][1] : attract[attractID[no][last]][0];
			if (k<2 && calc[no][ternario+ter1[attractID[no][last]]*(2-k)][last+1]!=passo) fila.push(graf(no, ternario+ter1[attractID[no][last]]*(2-k), last+1, next.custo+tempo));
			//if (calc[no][ternario][last+1]!=passo) fila.push(graf(no, ternario, last+1, next.custo));
		}
		int tempTernario;
		for (int i = 0; i < size[no]; i++) {
			tempTernario = ternario;
			for (int j = 0; j < sizeFree[adj[no][i]]; j++) {
				k = (ternario/ter1[_free[adj[no][i]][j]])%3;
				if (k == 0) tempTernario+=ter1[_free[adj[no][i]][j]];
			}
			if (calc[adj[no][i]][tempTernario][0] != passo) fila.push(graf(adj[no][i], tempTernario, 0, cost[no][i]+next.custo));
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
			rp(j,Ni) {
				cin >> a;
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