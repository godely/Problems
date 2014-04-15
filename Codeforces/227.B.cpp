#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

long long pos[111111];

int main() {
    long long n;
    int a, m;
    scanf("%I64d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        pos[a]=i;
    }

    scanf("%d", &m);
    long long v=0, b=0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        v+=pos[a]+1;
        b+=(n-pos[a]);
    }
    printf("%I64d %I64d\n", v, b);

    return 0;
}
