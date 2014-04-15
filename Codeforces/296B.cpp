#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007LL

char a[111111], b[111111];

int n;
long long dp[111111][5];
//c&1 = Si > Wi
//c&2 = Sj < Wj

long long solve(int i, int c) {
    if (~dp[i][c]) return dp[i][c];
    if (i >= n) return dp[i][c] = (c == 3);
    
    long long ret = 0;
    if (a[i] == '?' &&  b[i] == '?') {
        if (c == 3) ret = (100*solve(i+1, c))%mod;
        else {
            if (c&1) ret = (55*solve(i+1, c) + 45*solve(i+1,c|2))%mod;
            else if (c&2) ret = (55*solve(i+1, c) + 45*solve(i+1,c|1))%mod;
            else ret = (10*solve(i+1,c) + 45*solve(i+1,c|1) + 45*solve(i+1,c|2))%mod;
        }
    } else if (a[i] == '?') {
        if (c == 3) ret = (10*solve(i+1, c))%mod;
        else {
            if (c&1) ret = ((b[i]-'0')*solve(i+1, c|2) + (10-(b[i]-'0'))*solve(i+1, c))%mod;
            else if (c&2) ret = ((9-(b[i]-'0'))*solve(i+1, c|1) + (b[i]-'0'+1)*solve(i+1, c))%mod;
            else ret = (solve(i+1,c) + (b[i]-'0')*solve(i+1,c|2) + (9-(b[i]-'0'))*solve(i+1,c|1))%mod;
        }
    } else if (b[i] == '?') {
        if (c == 3) ret = (10*solve(i+1, c))%mod;
        else {
            if (c&1) ret = ((9-(a[i]-'0'))*solve(i+1, c|2) + (a[i]-'0'+1)*solve(i+1, c))%mod;
            else if (c&2) ret = ((a[i]-'0')*solve(i+1, c|1) + (10-(a[i]-'0'))*solve(i+1, c))%mod;
            else ret = (solve(i+1,c) + (9-(a[i]-'0'))*solve(i+1,c|2) + (a[i]-'0')*solve(i+1,c|1))%mod;
        }
    } else {
        if (a[i] < b[i]) ret = solve(i+1, c|2)%mod;
        else if (a[i] > b[i]) ret = solve(i+1, c|1)%mod;
        else ret = solve(i+1, c)%mod;
    }
    return dp[i][c] = ret;
}

int main() {
    scanf("%d", &n);
    scanf("%s%s", a, b);
    memset(dp,-1,sizeof dp);
    printf("%I64d\n", solve(0,0));
}