//stor
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

unsigned long long F[80];
bool B[] = {0,1,1,0,1,1};
int main() {
    F[0] = 0;
    for (int i = 1, k = 0; i < 66; i++, k=(k+1)%6) {
        F[i] = 2*F[i-1]+B[k];
    }
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%llu\n", F[n]);
    }
    return 0;
}
