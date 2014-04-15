#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
#define cl(a,b) memset((a),(b),sizeof(a))
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define db(x) cerr <<#x"=="<<x<<endl;
#define _ << "," <<
#define pb push_back
#define mp make_pair
#define MAXN 10010

vector<int> mat[MAXN];
int qnt[MAXN],grau[MAXN];

int main(){
	int u,q,v,c,n;
	while(scanf("%d",&n)>0&&n){
		rp(i,n+1) mat[i].clear(),grau[i]=0;
		rp(i,n){
			scanf("%d%d%d",&u,&q,&c);
			qnt[u]=q;
			rp(i,c){
				scanf("%d",&v);
				mat[v].pb(u);
				grau[u]++;
			}
		}
		queue<int> fila;
		fr(i,1,n+1) if(!grau[i]) fila.push(i);
		int ans=0;
		while(!fila.empty()){
			int next=fila.front();
			fila.pop();
			int dif=qnt[next]-1;
			ans+=abs(dif);
			rp(i,mat[next].size()){
				qnt[mat[next][i]]+=dif;
				grau[mat[next][i]]--;
				if(!grau[mat[next][i]]) fila.push(mat[next][i]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
