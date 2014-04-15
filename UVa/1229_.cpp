#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define pb push_back
using namespace std;
#define MAXN 211
struct graf{
	int low,ind;
	vector<int> adj;
}mat[MAXN];
int topo,tmp,cor,pilha[MAXN],color[MAXN],grau[MAXN],qnt[MAXN];
bool napilha[MAXN],tem[MAXN];
char str[10*MAXN];
void scc(int no){
	mat[no].ind=mat[no].low=tmp++;
	pilha[topo++]=no;
	napilha[no]=1;
	rp(i,mat[no].adj.size()){
		int next=mat[no].adj[i];
		if(mat[next].ind==-1){
			scc(next);
			mat[no].low=min(mat[no].low,mat[next].low);
		}else if(napilha[next]) mat[no].low=min(mat[no].low,mat[next].ind);
	}
	if(mat[no].low==mat[no].ind){
		int next;
		do{
			next=pilha[--topo];
			napilha[next]=0;
			color[next]=cor;
		}while(no!=next);
		cor++;
	}
}
map<string,int> mapa;
vector<int> ans,lista[MAXN];
vector<string> bla;
bool cmp(int a,int b){
	return bla[a]<bla[b];
}
int main(){
	int n,cont,ini,fim;
	char *pt;
	while(gets(str)>0){
		sscanf(str,"%d",&n);
		if(!n) break;
		cont=1;
		mapa.clear();
		ans.clear();
		bla.clear();
		bla.pb("");
		rp(i,MAXN){
			lista[i].clear();
			color[i]=-1;
			napilha[i]=0;
			mat[i].adj.clear();
			mat[i].low=-1;
			mat[i].ind=-1;
			grau[i]=0;
			qnt[i]=0;
			tem[i]=0;
		}
		rp(i,n){
			gets(str);
			pt = strtok(str," ");
			if(mapa[pt]==0){
				mapa[pt]=cont++;
				bla.pb(pt);
			}
			ini=mapa[pt];
			pt = strtok(NULL," ");
			while(pt) {
				if(mapa[pt]==0){
					mapa[pt]=cont++;
					bla.pb(pt);
				}
				fim=mapa[pt];
				mat[ini].adj.pb(fim);
				pt = strtok(NULL," ");
			}
		}
		cor=tmp=1;
		topo=0;
		fr(i,1,cont) if(mat[i].ind==-1) scc(i);
		fr(i,1,cont){
			qnt[color[i]]++;
			rp(j,mat[i].adj.size()){
				int next=mat[i].adj[j];
				if(color[i]==color[next]) continue;
				grau[color[i]]++;
				lista[color[i]].pb(color[next]);
			}
		}
		for(int i=cor-1;i>-1;i--) if(!grau[i]||qnt[i]>1||tem[i]){
			fr(j,1,cont) if(color[j]==i) ans.pb(j);
			rp(j,lista[i].size()) tem[lista[i][j]]=1;
		}
		sort(ans.begin(),ans.end(),cmp);
		if(!ans.size()) continue;
		printf("%d\n",ans.size());
		printf("%s",bla[ans[0]].c_str());
		fr(i,1,ans.size()) printf(" %s",bla[ans[i]].c_str());
		printf("\n");
	}
	return 0;
}
