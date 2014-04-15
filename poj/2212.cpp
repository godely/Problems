//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define CL(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 1061109567
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define maxn 110000
#define dbg if(0)
#define rp(a,b) Fr(a,0,b)
#define mp make_pair

int x, y, z, p, r, s;
int g[111][111][111];
pair<int,pii> fila[111*111*111];
int ini, fim;
pair<int,pii> aux;

int di[] = {1,0,-1,0,0,0};
int dj[] = {0,1,0,-1,0,0};
int dk[] = {0,0,0,0,1,-1};

bool pode(int i, int j, int k) {
	return i >= 0 && i < x && j >= 0 && j < y && k >= 0 && k < z;
}

int flood(int _i, int _j) {
	ini = fim = 0;
	int i = _i, j = _j, k = 0;
	fila[fim++] = mp(i,mp(j,k));
	g[i][j][k] = 0;
	int ret = 0;
	while (ini < fim) {
		aux = fila[ini++];
		ret++;
		i = aux.F, j = aux.S.F, k = aux.S.S;
		for (int t = 0; t < 6; t++) {
			if (pode(i+di[t],j+dj[t],k+dk[t]) && g[i+di[t]][j+dj[t]][k+dk[t]]) {
				g[i+di[t]][j+dj[t]][k+dk[t]] = 0;
				fila[fim++] = mp(i+di[t],mp(j+dj[t],k+dk[t]));
			}
		}
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(g, 0, sizeof g);
		scanf("%d%d%d", &x, &y, &z);
		rp(i,z) {
			scanf("%d", &p);
			rp(j,p) {
				scanf("%d%d", &r, &s);
				g[r-1][s-1][i] = 1;
			}
		}
		int res = 0;
		rp(i,x)	rp(j,y) {
			if (g[i][j][0]) {
				res += flood(i,j);
			}
		}
		printf("Je nutne vycerpat %d litru vody.\n", res*1000);
	}
	return 0;
}