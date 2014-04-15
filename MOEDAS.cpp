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
typedef long long ll;
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
#define MAXN 111
#define MAXM 51000

int x[MAXN];
int dp[2][MAXM];

int main() {
	int n, m;
	while (scanf("%d", &m) == 1 && m > 0) {
		scanf("%d", &n);
		rp(i,n) scanf("%d", &x[i]);
		CL(dp,0x3f);
		dp[0][0] = 0;
		int a = 1;
		rp(i,n) {
			for (int j = 0; j <= m; j++) {
				dp[a][j] = dp[a^1][j];
				if (j >= x[i]) dp[a][j] = min(dp[a][j],dp[a][j-x[i]]+1);
				/*if (dp[a][j] == INF) printf("- ");
				else printf("%d ", dp[a][j]);//*/
			}
			a^=1;
			//puts("");
		}
		if (dp[a^1][m] == INF) printf("Impossivel\n");
		else printf("%d\n", dp[a^1][m]);
	}
}