//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

#define MAXN 120110 // 6*10^4
#define MAXM 180110 // 9*10^4

#define Y(a) (2*a)
#define N(a) (2*a+1)
#define NEG(a) (a^1)

int t, n, m, bob[MAXN];
int adj[MAXN], nos;
int to[MAXM], ant[MAXM], qtd;


void add(int x, int y) {
	int negx = NEG(x);
	to[qtd] = y, ant[qtd] = adj[negx]; adj[negx] = qtd++;
}

//scc
int comp[MAXN], num[MAXN], pilha[MAXN], pp, low[MAXN], ncomp, tempo;

int dfs(int x) {
	if(num[x] != -1) return num[x];
	num[x] = low[x] = tempo++;
	pilha[pp++] = x;
	
	for(int i = adj[x]; ~i; i = ant[i]) {
		int u = to[i];
		if(comp[u] == -1) low[x] = min(low[x], dfs(u));
	}
	
	if(num[x] == low[x]) {
		comp[x] = ncomp;
		while(pilha[--pp] != x) {
			int v = pilha[pp];
			comp[v] = ncomp;
		}
		
		ncomp++;
	}
	
	return low[x];
}

bool two_sat() {
	bool ok = true;
	Fr(i,0,nos) {
		ok &= comp[i] != comp[i + 1];
		++i;
	}
	
	return ok;
}

int main(){
	cin >> t;
	int _=1;
	while(t--){
		cin >> n >> m;
		Fr(i,0,n) cin >> bob[i];

		nos = 6 * n;
		Fr(i,0,nos) adj[i] = -1;
		qtd = 0;
		
		int pz = 0;
		Fr(i,0,n) {
			--bob[i];
			int aa = -1, bb = -1;
			if(bob[i] == 0) aa = 1, bb = 2;
			else if(bob[i] == 1) aa = 2, bb = 0;
			else if(bob[i] == 2) aa = 0, bb = 1;
			else assert(false);
			
			//bb is false // Nao pode jogar 'bb'
			add(N(bb) + pz, N(bb) + pz); // ~bb | ~bb
			
			//bob[i] | aa // Deve jogar alguma coisa!
			add(Y(bob[i]) + pz, Y(aa) + pz);
			add(Y(aa) + pz, Y(bob[i]) + pz);

			//bob[i] -> ~aa == ~bob[i] | ~aa
			// aa -> ~bob[i] == ~aa | ~bob[i]
			add(N(bob[i]) + pz, N(aa) + pz);
			add(N(aa) + pz, N(bob[i]) + pz);
			pz += 6;
		}
		
		
		Fr(i,0,m) {
			int a, b, c, u, v;
			cin >> a >> b >> c;
			--a, --b;
			a *= 6, b *= 6;
			if(c == 0) { // same
				Fr(z,0,3) { //Must be equal
					u = a + N(z), v = b + Y(z);
					add(u, v), add(v, u);
					u = a + Y(z), v = b + N(z);
					add(u, v), add(v, u);
				}
			} else if(c == 1) {
				Fr(z,0,3) { //Must be diff
					u = a + N(z), v = b + N(z);
					add(u, v), add(v, u);
					
					/*
					u = a + Y(z), v = b + Y(z);
					add(u, v), add(v, u);
					//*/
				}
				
			} else assert(false);
		}
		
		tempo = ncomp = pp = 0;
		Fr(i,0,nos) num[i] = low[i] = comp[i] = -1;
		Fr(i,0,nos) if(num[i] == -1) dfs(i);
		
		if(two_sat()) cout << "Case #" << _++ << ": yes" << endl;
		else cout << "Case #" << _++ << ": no" << endl;
	}
	
	return 0;
}