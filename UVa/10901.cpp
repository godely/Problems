#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define LL long long
#define mod 1000000007
#define topLeft() (bank[1].empty()?100000:bank[1].front())
#define topRight() (bank[0].empty()?100000:bank[0].front())
#define leftEmpty() bank[1].empty()
#define rightEmpty() bank[0].empty()
#define isLeft() where==1
#define leftPop() if (!bank[1].empty()) bank[1].pop()
#define rightPop() if (!bank[0].empty()) bank[0].pop()

using namespace std;

char gb[50];
int L[11111], R[11111], V[11111], l, r;
int main() {
    int T, n, t, m, time, where;
    int a, c;
    queue<int> bank[2];
    scanf("%d", &T);
    while (T--) {
        while (!bank[0].empty()) bank[0].pop();
        while (!bank[1].empty()) bank[1].pop();
        scanf("%d%d%d", &n, &t, &m);
        l = 0, r = 0;
        rp(i,m) {
            scanf("%d%s", &time, gb);
            bank[gb[0]=='l'].push(time);
            if (gb[0]=='l') L[l++] = i;
            else R[r++] = i;
        }
        l = r = a = 0;
        where = 1;
        while(!leftEmpty() || !rightEmpty()) {
            if (isLeft()) {
                if (topRight() < topLeft() && a < topLeft()) {
                    if (a < topRight()) a = topRight() + t;
                    else a += t;
                    goto sss;
                }
                if (!leftEmpty()) a = max(topLeft(),a);
                c = 0;
                while (c < n && topLeft() <= a) {
                    V[L[l++]] = a+t;
                    leftPop();
                    c++;
                }
                a += t;
            } else {
                if (topLeft() < topRight() && a < topRight()) {
                    if (a < topLeft()) a = topLeft() + t;
                    else a += t;
                    goto sss;
                }
                if (!rightEmpty()) a = max(topRight(),a);
                c = 0;
                while (c < n && topRight() <= a) {
                    V[R[r++]] = a+t;
                    rightPop();
                    c++;
                }
                a += t;
            }
            sss:;
            where ^= 1;
        }
        rp(i,m) printf("%d\n", V[i]);
        if (T) printf("\n");
    }
    return 0;
}
