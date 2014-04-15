#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define inf 0x3f3f3f3f

using namespace std;

int N, M;
int R[31111];
int Q[31111];
int SCALE[31111];

char acha(int x, int y, int scale, int num) {
    if (num==-1) return '.';
    else {
        int altura = 2*scale;
        int largura = scale+1;
        if (num == 0) {
            if (x > 0 && x < largura && (y == 0 || y == altura)) return '_';
            else if ((x == 0 && y < altura) || (x == largura && y < altura)) return '|';
            else return '.';
        } else if (num == 1) {
            if (x == largura && y < altura) return '|';
            else return '.';
        } else if (num == 2) {
            if (x > 0 && x < largura && (y == 0 || y == altura || y == altura/2)) return '_';
            else if ((x == 0 && y < altura/2) || (x == largura && y >= altura/2 && y < altura)) return '|';
            else return '.';
        } else if (num == 3) {
            if (x > 0 && x < largura && (y == 0 || y == altura || y == altura/2)) return '_';
            else if (x == largura && y < altura) return '|';
            else return '.';
        } else if (num == 4) {
            if ((x == largura && y < altura) || (x == 0 && y >= altura/2 && y < altura)) return '|';
            else if (x > 0 && x < largura && y == altura/2) return '_';
            else return '.';
        } else if (num == 5) {
            if (x > 0 && x < largura && (y == 0 || y == altura || y == altura/2)) return '_';
            else if ((x == 0 && y >= altura/2 && y < altura) || (x == largura && y < altura/2)) return '|';
            else return '.';
        } else if (num == 6) {
            if (x > 0 && x < largura && (y == 0 || y == altura || y == altura/2)) return '_';
            else if ((x == 0 && y < altura) || (x == largura && y < altura/2)) return '|';
            else return '.';
        } else if (num == 7) {
            if (x > 0 && x < largura && y == altura) return '_';
            else if (x == largura && y < altura) return '|';
            else return '.';
        } else if (num == 8) {
            if (x > 0 && x < largura && (y == 0 || y == altura || y == altura/2)) return '_';
            else if ((x == 0 && y < altura) || (x == largura && y < altura)) return '|';
            else return '.';
        } else {
            if (x > 0 && x < largura && (y == 0 || y == altura || y == altura/2)) return '_';
            else if ((x == 0 && y >= altura/2 && y < altura) || (x == largura && y < altura)) return '|';
            else return '.';
        }
    }
}

int d, f, x, y;
int main() {
    R[0] = 0;
    while (scanf("%d", &N) == 1 && N > 0) {
        int k = 0;
        fr(i,1,N+1) {
            scanf("%d%d", &d, &f);
            R[k] = R[k-1]+f+2;
            Q[k] = d;
            SCALE[k++] = f;
            R[k] = R[k-1]+1;
            Q[k] = -1;
            SCALE[k++] = 0;
        }
        scanf("%d", &M);
        while (M--) {
            scanf("%d%d", &x, &y);
            int s = upper_bound(R, R+k, x) - R;
            int num = Q[s];
            int z = x - R[s-1];
            printf("%c\n", acha(z,y,SCALE[s],num));
        }
    }
    return 0;
}