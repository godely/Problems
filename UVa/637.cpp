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
    int n, m, k, a, b;
    while (scanf("%d%d", &n, &m) == 2 && (n > 0 || m > 0)) {
        a = n, b = m;
        if (n > m) swap(n,m);
        if (n == 1) k = m;
        else if (n == 2) k = ((m+3)/4)*4 - ((m%4) == 1 ? 2 : 0);
        else k = max(((m+1)/2)*n - ((m&1)?n/2 : 0), ((n+1)/2)*m - ((n&1)?m/2 : 0));
        printf("%d knights may be placed on a %d row %d column board.\n", k, a, b);
    }
    return 0;
}
