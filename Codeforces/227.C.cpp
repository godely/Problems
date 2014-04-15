#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

long long N, M;

long long expo(long long n, long long exp) {
    if (exp==0) return 1;
    if (exp==1) return n;
    long long res = expo(n, exp/2);
    res=(res*res)%M;
    if (exp&1) res=(res*n)%M;
    return res;
}

int main() {
    scanf("%I64d%I64d", &N, &M);

    long long S = (expo(3LL,N) - 1 + M)%M;

    printf("%I64d\n", S);
}
