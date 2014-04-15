#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <iostream>
#include <queue>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

using namespace std;

int main() {
    int T, N, a;
    scanf("%d", &T);
    fr(_, 1, T+1) {
        int maxi = 0;
        scanf("%d", &N);
        rp(i,N) scanf("%d", &a), maxi = max(maxi,a);
        printf("Case %d: %d\n", _, maxi);
    }
}
