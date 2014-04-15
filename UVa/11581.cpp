#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

int grid[1<<9][6][6];

int fix(int k) {
    int s = 0;
    fr(i,1,4) fr(j,1,4) {
        grid[k+1][i][j] = (grid[k][i][j-1]+grid[k][i][j+1]+grid[k][i-1][j]+grid[k][i+1][j])%2;
        s|=grid[k][i][j];
    }
    return s;
}

int main() {
    int T, a;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &a);
        grid[0][1][1] = a>>2;
        grid[0][1][2] = (a&2)>>1;
        grid[0][1][3] = a&1;
        scanf("%d", &a);
        grid[0][2][1] = a>>2;
        grid[0][2][2] = (a&2)>>1;
        grid[0][2][3] = a&1;
        scanf("%d", &a);
        grid[0][3][1] = a>>2;
        grid[0][3][2] = (a&2)>>1;
        grid[0][3][3] = a&1;

        int i = -1;
        while(fix(i+1)) i++;
        printf("%d\n", i);
    }
    return 0;
}
