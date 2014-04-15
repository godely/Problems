#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define fr(a,b,c) for(int a=b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

map<long long, int> dp;
int solve(long long n) {
    if (n==1) return 1;
    if (dp[n] != 0) return dp[n];
    //printf("%llu\n", n);
    return dp[n] = (n&1)?1+solve(3*n+1):1+solve(n/2);
}

int main() {
    int n, m, a, b;
    int maxi, temp, res;
	dp[1] = 4;
    while (scanf("%d%d", &n, &m)==2 && n > 0){
        maxi=0;
        a=min(n,m), b=max(n,m);
        fr(i,a,b+1) {
			solve(i);
			temp = dp[i];
			if (temp > maxi) {
				maxi = temp;
				res = i;
			}
		}
        printf("Between %d and %d, %d generates the longest sequence of %d values.\n",a,b,res,maxi-1);
    }
	return 0;
}
