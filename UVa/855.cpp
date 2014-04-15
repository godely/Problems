#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define LL long long

using namespace std;

int Y[51111], X[51111];
int main() {
    int T, S, A, F;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &S, &A, &F);
        rp(i,F) scanf("%d%d", &Y[i], &X[i]);
        sort(Y,Y+F);
        sort(X,X+F);
        printf("(Street: %d, Avenue: %d)\n", Y[(F-1)/2], X[(F-1)/2]);
    }
    return 0;
}
