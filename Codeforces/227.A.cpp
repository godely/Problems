#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

long long cross(long long xi, long long yi, long long xj, long long yj) { return xi*yj - xj*yi; }

int main() {
    long long xa, ya, xb, yb, xc, yc;
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &xa, &ya, &xb, &yb, &xc, &yc);

    long long K = cross(xb-xa, yb-ya, xc-xb, yc-yb);
    //printf("%d %d %d %d\n", K);
    //int T = dot(xb-xa, yb-ya, xc-xb, yc-yb);
    if (K == 0) printf("TOWARDS\n");
    else if (K < 0) printf("RIGHT\n");
    else printf("LEFT\n");

    return 0;
}
