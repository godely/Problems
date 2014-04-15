#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

char str[5];
int main() {
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%s%d%d", str, &n, &m);
        if (n > m) swap(n,m);
        if (str[0] == 'r') printf("%d\n", n);
        else if (str[0] == 'k') printf("%d\n", max(((m+1)/2)*n - ((m&1)?n/2 : 0), ((n+1)/2)*m - ((n&1)?m/2 : 0)));
        else if (str[0] == 'K') printf("%d\n", ((n+1)/2)*((m+1)/2));
        else {
            if (n <= 2) {
                if (m <= 2) printf("1\n");
                else printf("2\n");
            } else if (n == 3) {
                if (m == 3) printf("2\n");
                else printf("3\n");
            } else printf("%d\n", n);
        }
    }
    return 0;
}
