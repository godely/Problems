#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
using namespace std; 
#define fr(a,b,c) for (int a = b; a < c; a++) 
#define rp(a,b) fr(a,0,b) 
#define CL(a,b) memset((a),(b),sizeof (a))
#define MP make_pair
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> pii;

using namespace std;

int n, m, p[20];
int dp[1000100];

int main() {
	while (scanf("%d", &n) == 1) {
		scanf("%d", &m);
		rp(i,m) scanf("%d", &p[i]);
		sort(p,p+m);
		m = unique(p,p+m) - p;
		
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			dp[i] = 0;
			rp(j,m) {
				if (p[j] > i) break;
				if (!dp[i-p[j]]) {
					dp[i] = 1;
					break;
				}
			}
		}
		if (dp[n]) printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
	return 0;
}