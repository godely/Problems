#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof(a))
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

bool dp[102][102][102];
int n;
int p[111][3];

bool isWinning() {
	rp(a,n+1) rp(b,n+1) rp(c,n+1) {
		dp[a][b][c] = 0;
		fr(i,1,8) {
			if (((i&1)*p[a][0] + ((i&2)*p[b][1])>>1 + ((i&4)*p[c][2])>>2)%3 == 0) {
				if (a-(i&1) >= 0 && b-((i&2)>>1) >= 0 && c-((i&4)>>2) >= 0 && !dp[a-(i&1)][b-((i&2)>>1)][c-((i&4)>>2)]) {
					dp[a][b][c] = 1;
					break;
				}
			}
		}
	}
	return dp[n][n][n];
}

int main() {
	p[0][0] = p[0][1] = p[0][2] = 0;
	while (scanf("%d", &n) == 1 && n > 0) {
		rp(i,n) rp(j,3) scanf("%d", &p[n-i][j]);
		printf("%d\n", !isWinning());
	}
	return 0;
}