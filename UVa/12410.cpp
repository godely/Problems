#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define F first
#define S second

using namespace std;

long long A, maxone, ideal, K;
pair<long long, long long> dp[33][4][8][33][33][3];
int calc[33][4][8][33][33][3], passo=0;

pair<long long, long long> solve(int ind, int b3, int b7, int k, int ones, bool beira) {
    if (k > K || ones > maxone) return make_pair(0,0);
    if (ind < 0) {
        if (b3==0 && b7!=0) return make_pair(0,1);
        else return make_pair(0,0);
    }
    if (calc[ind][b3][b7][k][ones][beira]==passo) return dp[ind][b3][b7][k][ones][beira];
    calc[ind][b3][b7][k][ones][beira]=passo;

    //printf("Ind:%d B3:%d B7:%d K:%d Ones:%d Beira:%d\n", ind, b3, b7, k, ones, beira);

    int newK = (ideal&(1LL<<ind)) ? 1 : 0;
    pair<long long, long long> res;
    pair<long long, long long> ret;
    if (!beira || A&(1LL<<ind)) {
        ret = solve(ind-1, (b3+(1LL<<ind))%3, (b7+(1LL<<ind))%7, k+(newK^1), ones+1, beira);
        res.F += (1LL<<ind)*ret.S + ret.F;
        res.S += ret.S;
        ret = solve(ind-1, b3, b7, k+newK, ones, 0);
        res.F += ret.F;
        res.S += ret.S;
    } else {
        ret = solve(ind-1, b3, b7, k+newK, ones, beira);
        res.F += ret.F;
        res.S += ret.S;
        //printf(" > > %d %d\n", ret.F, ret.S);
    }
    //printf(" > %lld %d\n", res.F, res.S);
    return dp[ind][b3][b7][k][ones][beira]=res;
}

int main() {
    int T, cas=1;
    long long a, b;
    pair<long long, int> resB, resA;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld%lld%lld", &a, &b, &maxone, &ideal, &K);
        A=b;
        printf("Case %d: ", cas++);
        passo++;
        resB = solve(32, 0, 0, 0, 0, 1);
        if (b == 0)
            printf("%lld\n", resB.F);
        else {
            A=a-1;
            passo++;
            resA = solve(32, 0, 0, 0, 0, 1);
            printf("%lld\n", resB.F-resA.F);
        }
    }
}
