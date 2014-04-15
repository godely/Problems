#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <iostream>
#include <queue>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

using namespace std;

char str[10];
char lol[100][5];
int g[100];
int main() {
    int T, cas=1;
    scanf("%d", &T);
    while (T--) {
        rp(i,52) {
            scanf("%s", str);
            lol[i][0] = str[0];
            lol[i][1] = str[1];
            lol[i][2] = '\0';
            g[i] = (str[0] >= '2' && str[0] <= '9') ? str[0]-'0' : 10;
        }
        int j = 26, y = 0;
        rp(i,3) {
            int c = g[j];
            y += c;
            j -= (11-c);
            //printf("%d %d %d\n", c, j, y);
        }
        fr(i,0,25) lol[i+j+1][0] = lol[i+27][0], lol[i+j+1][1] = lol[i+27][1];
        printf("Case %d: %s\n", cas++, lol[y-1]);
    }
}
