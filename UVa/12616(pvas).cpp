#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;




#define fr(i,a,b) for(int i=a;i<b;++i)
#define rep(i,b) fr(i,0,b)
#define N 30000
#define M 300000
#define mp make_pair
#define X first
#define Y second

int to[M], nxt[M], val[M];
int adj[N], r[N], tot[N], pai[N], low[N], ord[N], markv[N];
int cod[M], marke[M];
int tam[N];
pii ar[N];
bool mk[N];
stack<int> pilha;
vector<int> ls[N];
int n, m;
ll prods[M];
int cnt;
void add(int a, int b){
	to[cnt] = b, nxt[cnt] = adj[a], val[cnt] = 0, cod[cnt] = -1;
	marke[cnt] = 0;
	adj[a] = cnt;
	cnt++;
}

int nbc;
void gera(int w){
	while(pilha.top()!=w){
		cod[pilha.top()] = nbc;
		pilha.pop();
	}
	cod[pilha.top()] = nbc;
	pilha.pop();
}

int getr(int a){ 
	if(r[a]!=a) r[a] = getr(r[a]);
	return r[a];
}
void unir(int a, int b){
	if(getr(a)!=getr(b)){
		tam[r[b]] += tam[r[a]];
		r[r[a]] = r[b];
	}		
}

int tempo;
void dfs(int no, int dad){
	pai[no] = dad, ord[no] = low[no] = tempo++;
	markv[no] = 1;
	tot[no] = 1;
	int esc=-1;
	for(int i=adj[no];i>=0;i=nxt[i]){
		int w = to[i];
		if(w==pai[no])
			esc = i;
		if(!marke[i])
			marke[i] = marke[i^1] = 1, pilha.push(i);
		if(!markv[w]){			
			dfs(w,no);
			val[i] = tot[w];
			tot[no] += val[i];
			low[no] = min(low[no], low[w]); 
			if(low[w] >= ord[no]){
				nbc++;
				gera(i);
			}
		}else if(w != dad){
			low[no] = min(low[no], ord[w]);			
		}
	}
	if(esc!=-1) val[esc] = tam[getr(no)] - tot[no];
}

int main(){
	int cas;
	scanf("%d",&cas);
	rep(u,cas){
		scanf("%d %d",&n,&m);
		fr(i,1,n+1) adj[i] = -1, r[i] = i, pai[i]=-1, markv[i]=0, tam[i]=1;
		cnt = 0;
		rep(i,m){
			int a, b;
			scanf("%d %d",&a,&b);
			add(a,b);
			add(b,a);
			unir(a,b);
		}
		tempo=0;
		nbc=0;
		fr(i,1,n+1) if(!markv[i]) dfs(i,-1);
		
		for(int i=0;i<cnt;i+=2){
			//if(marke[i] == marke[i+1]) throw 0;
			cod[i] = cod[i+1] = max(cod[i],cod[i+1]);
		}
		ll rsp = 0LL;
		fr(no,1,n+1){
			int qtd = 0;
			ll prod = 1LL, sum=0, sum2=0;
			for(int i=adj[no];i>=0;i=nxt[i]){
				ar[qtd++] = mp(cod[i],val[i]);
				//printf(" [%d %d] %d %d\n",no,to[i],cod[i],val[i]);
			}
			ll tmp=0;
			sort(ar,ar+qtd);
			rep(i,qtd){					
				if(i && ar[i].X != ar[i-1].X){
					tmp += sum*sum2;
					//printf(" (%d) %lld %lld\n",no,sum,sum2);
					sum2 += sum;
					sum = ar[i].Y;
				}else
					sum += ar[i].Y;
			}
			tmp += sum2*sum;
			//printf(" %lld--%d\n",tmp,no);
			rsp += tmp;
		}
		printf("Case %d: %lld\n",u+1,2LL*rsp);		
	}
	return 0;
}