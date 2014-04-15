#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) == 2 && a > 0) {
        int m = abs(a-b);
        int sq = sqrt(m);
        int c = 0;
        for (int i = 1; i <= sq; i++) {
            if (i*i == m) c++;
            else if (m%i==0) c+=2;
        }
        printf("%d\n", c);
    }
    return 0;
}
