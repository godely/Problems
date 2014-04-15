#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define fr(a,b,c) for(int a=b; a < c; a++)
#define rp(a,b) fr(a,0,b)

unsigned long long LOL=0;
using namespace std;

map<unsigned int, int> dp;
int solve(unsigned int n) {
    if(n > LOL) LOL = n;
    if (n==1) return 1;
    if (dp[n] != 0) return dp[n];
    //printf("%llu\n", n);
    return dp[n] = (n&1)?1+solve(3*n+1):1+solve(n/2);
}

int main() {
    int n, m, a, b;
    int maxi;
    while (scanf("%d%d", &n, &m)==2){
        maxi=0;
        a=min(n,m), b=max(n,m);
        fr(i,a,b+1) maxi=max(solve(i),maxi);
        printf("%d %d %d\n",n,m,maxi);
    }
}
