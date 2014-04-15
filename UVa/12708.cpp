#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
using namespace std;
typedef unsigned long long ull;

int main() {
    ull N;
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%llu", &N);
        printf("%llu\n", N>>1);
    }
}