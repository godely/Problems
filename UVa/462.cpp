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

int F[4][7];
int G[130];
int H[130];

int main() {
    G['S'] = 0;
    G['H'] = 1;
    G['D'] = 2;
    G['C'] = 3;

    H['2'] = H['3'] = H['4'] = H['5'] = H['6'] = H['7'] = H['8'] = H['9'] = H['T'] = 5;
    H['A'] = 1;
    H['J'] = 2;
    H['Q'] = 3;
    H['K'] = 4;

    int size;
    while (scanf("%s", str) == 1) {
        memset(F,0,sizeof F);
        F[G[str[1]]][0]++;
        F[G[str[1]]][H[str[0]]]++;
        for(int i = 1; i <= 12; i++) {
            scanf("%s", str);
            F[G[str[1]]][0]++;
            F[G[str[1]]][H[str[0]]]++;
            //printf(" (%s %d %d) ", str, G[str[1]], H[str[0]]);
        }
        int c, points = 0, points2 = 0, allStop = 0, soma = 0;
        for (int i = 0; i < 4; i++) {
            if (F[i][0] > soma) soma = F[i][0];
            c = 0;
            c += (4*F[i][1] + 3*F[i][4] + 2*F[i][3] + F[i][2]);
            if (F[i][0] == 1) c-=F[i][4];
            if (F[i][0] <= 2) c-=F[i][3];
            if (F[i][0] <= 3) c-=F[i][2];
            points2 += c;
            if (F[i][0] == 2) c++;
            else if (F[i][0] == 1) c+=2;
            else if (F[i][0] == 0) c+=2;
            points += c;
            if (F[i][1] > 0 || (F[i][4] > 0 && F[i][0] > 1) || (F[i][3] > 0 && F[i][0] > 2)) allStop |= (1<<i);
        }
        if (points < 14) printf("PASS\n");
        else if (points2 >= 16 && allStop == 15) printf("BID NO-TRUMP\n");
        else {
            if (soma == F[0][0]) printf("BID S\n");
            else if (soma == F[1][0]) printf("BID H\n");
            else if (soma == F[2][0]) printf("BID D\n");
            else printf("BID C\n");
        }
    }
    return 0;
}
