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
#define iter(a) typeof((a).begin())
#define Tr(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rF(a,b,c) for( int a = c-1; a>=b ; --a )
#define Rp(a,b) Fr(a,0,b)
#define fr Fr
#define rp Rp
#define cl(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,pair<int,int> > pdi;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define MAXN 1000
#define MAXM 120000
#define MOD 200003

int R[100], C[100], M[100];
int g[1000][1000];
int sq[1000][1000];
int dp[511][511][7];
int mark[511][511][7], passo;
int n;

int sum(int ci, int cj, int fi, int fj) {
	int r = sq[fi][fj];
	if (ci > 0) r -= sq[ci-1][fj];
	if (cj > 0) r -= sq[fi][cj-1];
	if (ci > 0 && cj > 0) r += sq[ci-1][cj-1];
	return r;
}

int go(int i, int j, int k) {
	int &pd = dp[i][j][k];
	if (mark[i][j][k] == passo) return pd;
	mark[i][j][k] = passo;
	int S = sum(i,j,i+R[k-1]-1,j+C[k-1]-1);
	if (k == n+1) return pd = S * M[k-1];
	int Rl = R[k-1] - R[k] + 1;
	int Cl = C[k-1] - C[k] + 1;
	int ret = 0;
	rp(ni,Rl) rp(nj,Cl) {
		int ci = i + ni;
		int cj = j + nj;
		int fi = ci + R[k] - 1;
		int fj = cj + C[k] - 1;
		ret = max(ret, (S - sum(ci,cj,fi,fj))*M[k-1] + go(ci,cj,k+1));
	}
	return pd = ret;
}

int main() {
	cl(mark,0); passo = 0;
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &R[0], &C[0], &n);
		fr(i,1,n+1) scanf("%d", &R[i]);
		fr(i,1,n+1) scanf("%d", &C[i]);
		rp(i,n+1) scanf("%d", &M[i]);
		rp(i,R[0]) rp(j,C[0]) {
			scanf("%d", &g[i][j]);
			sq[i][j] = g[i][j];
			if (i > 0) sq[i][j] += sq[i-1][j];
			if (j > 0) sq[i][j] += sq[i][j-1];
			if (i > 0 && j > 0) sq[i][j] -= sq[i-1][j-1];
		}
		passo++;
		printf("%d\n", go(0,0,1));
	}
}