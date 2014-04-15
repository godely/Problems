#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define fr(a,b,c) for(int a=b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

int f0, f1, g0, g1, aux;
int main() {
    int n, m, a;
    while (scanf("%d%d", &n, &m)==2 && n>0) {
        rp(i,n) {
            rp(j,m) {
                scanf("%d", &a);
                if (j == 0) aux = a;
                else if (j == 1) aux = max(a,f1);
                else aux = max(a+f0, f1);
                f0 = f1, f1 = aux;
            }
            a = f1;
            if (i == 0) aux = a;
            else if (i == 1) aux = max(a,g1);
            else aux = max(a+g0, g1);
            g0 = g1, g1 = aux;
        }
        printf("%d\n", g1);
    }
}
