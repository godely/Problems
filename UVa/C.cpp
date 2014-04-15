#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define cl(a,b) memset((a),(b),sizeof(a))
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define CL(a,b) memset(a,b,sizeof a)
#define db(x) cerr <<#x"=="<<x<<endl;
#define _ << "," <<
#define pb push_back
#define mp make_pair
#define MAXN 10010
#define oo 0x3f3f3f3f
typedef unsigned long long ull;

char g[511][511];
int n, m, dp[2][511][511];

int main() {
	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		rp(i,n) scanf("%s", g[i]);
		if (g[0][0] == '#') printf("Case #%d: 0\n", cas++);
		else {
			CL(dp,-1);
			dp[0][0][0] = 1;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (g[i][j] == '.') {
						if (i-1 >= 0 && dp[0][i-1][j] >= 0) dp[0][i][j] = max(dp[0][i][j],1+dp[0][i-1][j]);
						if (j-1 >= 0 && dp[0][i][j-1] >= 0) dp[0][i][j] = max(dp[0][i][j],1+dp[0][i][j-1]);
					}
				}
			}
			for (int i = n-1; i >= 0; i--) {
				for (int j = m-1; j >= 0; j--) {
					if (g[i][j] == '.') {
						dp[1][i][j] = 1;
						if (i+1 < n) dp[1][i][j] = max(dp[1][i][j],1+dp[1][i+1][j]);
						if (j+1 < m) dp[1][i][j] = max(dp[1][i][j],1+dp[1][i][j+1]);
					} else {
						dp[1][i][j] = 0;
					}
				}
			}
			/*rp(k,2) {
				rp(i,n) {
					rp(j,m) printf("%d ", dp[k][i][j]);
					puts("");
				}
				puts("---");
			}*/
			int res = dp[1][0][0];
			//printf("%d\n", res);
			rp(i,n) {
				rp(j,m) {
					if (j > 0 && dp[0][i][j-1] != -1 && g[i][j] == '.') {
						for (int k = i; k >= 0 && g[k][j] != '#'; k--) {
							res = max(res,dp[0][i][j-1] + (i-k+1) + ((j<m-1) ? dp[1][k][j+1] : 0));
						}
					}
					if (i > 0 && dp[0][i-1][j] != -1 && g[i][j] == '.') {
						for (int k = j; k >= 0 && g[i][k] != '#'; k--) {
							res = max(res,dp[0][i-1][j] + (j-k+1) + ((i<n-1) ? dp[1][i+1][k] : 0));
						}
					}
				}
			}
			printf("Case #%d: %d\n", cas++, res);
		}
	}
}