//stor
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#define inf 0x3f3f3f3f
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define P 10000

using namespace std;

char grid[10][10];

bool pode(int i, int j) {
    return i>=0&&i<5&&j>=0&&j<5;
}

int main() {
    int T, CAS=1;
    bool win[5];
    scanf("%d", &T);
    while (T--) {
        win[0]=0;
        win[1]=0;
        rp(i,5) scanf("%s", grid[i]);
        rp(i,5) rp(j,5) {
            if (pode(i+1,j+1) && pode(i+2,j+2)) {
                if (grid[i][j]==grid[i+1][j+1] && grid[i][j]==grid[i+2][j+2]) win[grid[i][j]-'A']=1;
            }
            if (pode(i+1,j) && pode(i+2,j)) {
                if (grid[i][j]==grid[i+1][j] && grid[i][j]==grid[i+2][j]) win[grid[i][j]-'A']=1;
            }
            if (pode(i,j+1) && pode(i,j+2)) {
                if (grid[i][j]==grid[i][j+1] && grid[i][j]==grid[i][j+2]) win[grid[i][j]-'A']=1;
            }
            if (pode(i+1,j-1) && pode(i+2,j-2)) {
                if (grid[i][j]==grid[i+1][j-1] && grid[i][j]==grid[i+2][j-2]) win[grid[i][j]-'A']=1;
            }
        }
        if(win[0]&&win[1]) printf("draw\n");
        else if (win[0]) printf("A wins\n");
        else if (win[1]) printf("B wins\n");
        else printf("draw\n");
    }
}
