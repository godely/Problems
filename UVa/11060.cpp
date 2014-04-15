#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define pb push_back
#define getA() mapa[str1]
#define getB() mapa[str2]

using namespace std;

map<string,int> mapa;
vector<string> nome;
int n, m, k, aux;
char str1[1111], str2[1111];
int grau[1111];
vector<int> adj[1111];

int main() {
	int cas=1;
	while (scanf("%d", &n)==1) {
		mapa.clear();
		nome.clear(); nome.pb("");
		k=1;
		rp(i,n) {
			scanf("%s", str1);
			grau[k]=0;
			adj[k].clear();
			getA()=k++;
			nome.pb(str1);
		}
		scanf("%d",&m);
		rp(i,m) {
			scanf("%s%s", str1, str2);
			adj[getA()].pb(getB());
			grau[getB()]++;
		}
		priority_queue<int,vector<int>, greater<int> > fila;
		fr(i,1,n+1) {
			if (!grau[i]) fila.push(i);
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", cas++);
		while (!fila.empty()) {
			aux = fila.top();
			printf(" %s", nome[aux].c_str());
			fila.pop();
			rp(i,adj[aux].size()) {
				grau[adj[aux][i]]--;
				if (!grau[adj[aux][i]]) fila.push(adj[aux][i]);
			}
		}
		printf(".\n\n");
	}
	return 0;
}