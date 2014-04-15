#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define LL long long
#define mod 1000000007

using namespace std;

int C[1111][1111];
int main() {
    for (int i = 0; i <= 1000; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
        }
    }
    int T, N, K, D, count;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &N, &K, &D);
        count = N-2*(D-1)-1;
    }
    return 0;
}
