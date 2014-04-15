#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

unsigned long long pd[511][511];
unsigned long long solve(int rest, int last) {
    if (rest == 0) return 1;
    if (last >= rest) return 0;
    if (~pd[rest][last]) return pd[rest][last];

    unsigned long long res = 0;
    for (int i = last+1; i <= rest; i++) {
        res += solve(rest-i, i);
    }
    return pd[rest][last] = res;
}

int main() {
    int N;
    memset(pd,-1,sizeof pd);
    scanf("%d", &N);
    printf("%llu\n", solve(N,0)-1);
}
