#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

pii mdc(int a, int b) {
    if (b==0) return pii(1,0);
    pii u = mdc(b,a%b);
    return pii(u.second, u.first - (a/b)*u.second);
}

int main() {
    int a, b;
    pii c;
    while (scanf("%d%d", &a, &b)==2) {
        c = mdc(a,b);
        printf("%d %d %d\n", c.first, c.second, c.first*a+c.second*b);
    }
    return 0;
}
