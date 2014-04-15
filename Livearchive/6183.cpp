#include <bits/stdc++.h>

#define Fr(a,b,c) for(int a=b; a<c; a++)
typedef long long ll;

#define N 120

int n,m;
char ent[N];
int pontos[N], x[N], y[N], z[N];
int ind, r[N*N*N],c[N*N*N],s[N*N*N];

bool test(int i, int j, int k){
	Fr(l,0,n) if(pontos[l] != (i*x[l]+j*y[l]+k*z[l])) return 0;
	return 1;
}

int main(){
	while(scanf("%d%d",&n,&m)==2 && (n||m)){
		x[0]=y[0]=z[0]=0;
		ind=0;
		Fr(i,0,n) {
			x[i+1]=x[i];
			y[i+1]=y[i];
			z[i+1]=z[i];
	//		printf("> %d %d %d\n",x[i],y[i],z[i]);
			scanf("%s",ent);
			int tam = strlen(ent);
			bool ok=1;
			pontos[i]=0;
			Fr(j,0,tam){
				if(ent[j]=='.' && ok) pontos[i]++;
				else {
					ok=0;
					if(ent[j]=='(') x[i+1]++;
					else if(ent[j]==')') x[i+1]--;
					else if(ent[j]=='{') y[i+1]++;
					else if(ent[j]=='}') y[i+1]--;
					else if(ent[j]=='[') z[i+1]++;
					else if(ent[j]==']') z[i+1]--;
				}
			}
		}
		
		Fr(i,1,21) Fr(j,1,21) Fr(k,1,21)
			if(test(i,j,k)) r[ind]=i, c[ind]=j, s[ind]=k, ind++;
		
		printf("%d\n", ind);
		
		Fr(i,0,m){
			x[i+1]=x[i];
			y[i+1]=y[i];
			z[i+1]=z[i];
			scanf("%s",ent);
			int tam = strlen(ent);
			
			int resp=-1, found=0;
			Fr(bla,0,ind){
				int tmp = r[bla]*x[i]+c[bla]*y[i]+s[bla]*z[i];
				if(tmp!=resp) found++, resp=tmp;
			}
			
			if(found>1) resp=-1;
			printf("%d",resp);
			
			if(i==(m-1)) puts("");
			else printf(" ");
			
			Fr(j,0,tam){
				if(ent[j]=='(') x[i+1]++;
				else if(ent[j]==')') x[i+1]--;
				else if(ent[j]=='{') y[i+1]++;
				else if(ent[j]=='}') y[i+1]--;
				else if(ent[j]=='[') z[i+1]++;
				else if(ent[j]==']') z[i+1]--;
			}
		}
	
	}
	return 0;
}