#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define CL(a,b) memset(a,b,sizeof(a))
typedef unsigned long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef map<int,int> mii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define y1 Y1
#define MAXN 40100

int all(int a, int b, int c, int d) {
	int s = sum[c][d] - sum[c][b-1] - sum[a-1][d] + sum[a-1][b-1];
	if (s == (c-a+1)*(d-b+1)) return 1;
	else if (s == 0) return 0;
	else return -1;
}

int win(int i1, int j1, int i2, int j2) {
	int q = all(i1,j1,i2,j2);
	if (q == 0) return pd = 1;
	else if (q == 1) return pd = 0;
	else {
		
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &R, &C);
		CL(g,0);
		fr(i,1,R+1) fr(j,1,C+1) scanf("%d", &g[i][j]);
		fr(i,1,R+1) fr(j,1,C+1) sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
	}
}
