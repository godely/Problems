#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define cl(a,b) memset(a,b,sizeof(a))
#define f(i,j) (i/m)*m+(j/m)
#define get_i(ind) bt[ind][0]
#define get_j(ind) bt[ind][1]

using namespace std;

int grid[10][10];

int n, m;
int line[10], col[10], subsq[10];
int bt[100][2], s;

bool solve(int ind) {
    if (ind >= s) {
        rp(i,n) {
            printf("%d", grid[i][0]);
            fr(j,1,n) printf(" %d", grid[i][j]);
            printf("\n");
        }
        return 1;
    }

    int i = get_i(ind);
    int j = get_j(ind);
    int mask = (line[i]|col[j])|subsq[f(i,j)];
    rp(k,n) {
        if (!(mask&(1<<k))) {
            line[i]|=(1<<k);
            col[j]|=(1<<k);
            subsq[f(i,j)]|=(1<<k);
            grid[i][j] = k+1;
            if (solve(ind+1)) return 1;
            line[i]&=~(1<<k);
            col[j]&=~(1<<k);
            subsq[f(i,j)]&=~(1<<k);
        }
    }
    return 0;
}

int a;
int main() {
    bool ok = 0;
    while (scanf("%d", &m) == 1) {
        if (ok) printf("\n");
        else ok = 1;
        cl(line,0),cl(col,0),cl(subsq,0);
        s = 0;
        n=m*m;
        rp(i,n) {
            rp(j,n) {
                scanf("%d", &a);
                if (a >= 1) {
                    grid[i][j] = a;
                    line[i]|=1<<(a-1);
                    col[j]|=1<<(a-1);
                    subsq[f(i,j)]|=1<<(a-1);
                } else bt[s][0] = i, bt[s++][1] = j;
            }
        }
        //printf("%d\n", s);
        if (!solve(0)) printf("NO SOLUTION\n");
    }
    return 0;
}
