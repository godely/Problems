//by stor
#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define pb push_back
#define stclear() size=0
#define stpush(a) stack[size++] = a
#define stpop() size--
#define sttop() stack[size-1]

#define N(x,i) (6*(i) + ((2*(x))+1))
#define Y(x,i) (6*(i) + (2*(x)))
#define NEG(x) ((x)^1)

int jog[11111][2];
vector<int> adj[61111];

//scc
int mark[61111], low[61111], num[61111], counter;
int color[61111], paint;
stack<int> st;

void scc(int a) {
	mark[a]=1;
	num[a]=low[a]=counter++;
	st.push(a);
	for (int i = 0; i < adj[a].size(); i++) {
		int v = adj[a][i];
		if (num[v]==-1) scc(v);
		if (mark[v]) low[a] = min(low[a],low[v]);
	}
	if (low[a]==num[a]) {
		while(1) {
			int v = st.top(); st.pop();
			mark[v]=0;
			color[v]=paint;
			if (a==v) break;
		}
		paint++;
	}
}

void clau(int x, int y) {
	int negx = NEG(x), negy = NEG(y);
	adj[negx].pb(y);
	adj[negy].pb(x);
}

bool two_sat(int n) {
	bool ok = 1;
	while (!st.empty()) st.pop();
	memset(num, -1, sizeof num);
	counter = paint = 0;
	for (int i = 0; i < 6*n; i++) if (num[i]==-1) scc(i);
	for (int i = 0; i < 6*n; i+=2) ok &= (color[i] != color[i+1]);
	return ok;
}

int main() {
	//A ou B: clau(Y(A), Y(B))
	//A ou NAO(B): clau(Y(A), N(B))
	//NAO(A) ou B: clau(N(A), Y(B))
	//NAO(A) ou NAO(B): clau(N(A), N(B))
	cin.sync_with_stdio(false);
	int T, n, K, a, b, c, cas = 1;
	bool ok;
	cin >> T;
	while (T--) {
		ok = 1;
		cin >> n >> K;
		rp(i,n) {
			rp(j,6) adj[6*i+j].clear();
			cin >> a;
			a--;
			clau(N((a+2)%3, i), N((a+2)%3, i));
			clau(N(a,i), N((a+1)%3, i));
			clau(Y(a,i), Y((a+1)%3, i));
			jog[i][0] = a;
			jog[i][1] = (a+1)%3;
		}
		rp(i,K) {
			cin >> a >> b >> c;
			a--; b--;
			if (a==b) {
				if (c==1) ok = 0;
				continue;
			}
			if (c==0) {
				clau(N(jog[a][0],a), N((jog[a][0]+1)%3,b));
				clau(N(jog[a][0],a), N((jog[a][0]+2)%3,b));
				clau(N(jog[a][1],a), N((jog[a][1]+1)%3,b));
				clau(N(jog[a][1],a), N((jog[a][1]+2)%3,b));
			} else {
				clau(N(jog[a][0],a), N(jog[a][0],b));
				clau(N(jog[a][1],a), N(jog[a][1],b));
			}
		}
		if (ok) ok = two_sat(n);
		if (ok) cout << "Case #" << cas++ << ": yes" << endl;
		else cout << "Case #" << cas++ << ": no" << endl;
	}
	return 0;
}