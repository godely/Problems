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

using namespace std;

bool dp[25][1111];
int back[25][1111];
int vet[30], res[30];
int max_j;
int main() {
    int N, M;
    while (scanf("%d%d", &N, &M) == 2) {
        fr(i,1,M+1) scanf("%d", &vet[i]);
        rp(j,N+1) dp[0][j] = 0;
        back[0][0]=-1;
        dp[0][0] = 1;
        max_j = 0;
        fr(i,1,M+1) {
            for (int j = 0; j <= N; j++) {
                dp[i][j] = 0;
                if (j >= vet[i] && dp[i-1][j-vet[i]]) {
                    dp[i][j]=1;
                    back[i][j] = j-vet[i];
                    //printf(" > %d %d (%d)\n", i, j, back[i][j]);
                    if (j > max_j) max_j = j;
                } else if (dp[i-1][j]) {
                    dp[i][j]=1;
                    back[i][j] = j;
                }
            }
        }
        //printf("%d\n", max_j);
        int i = M, j = max_j, k = 0;
        while (i > 0) {
            //printf("%d %d %d\n", i, j, back[i][j]);
            if (back[i][j] != j) res[k++] = vet[i];
            j = back[i][j];
            i--;
        }
        for (k=k-1; k >= 0; k--) printf("%d ", res[k]);
        printf("sum:%d\n", max_j);
    }
    return 0;
}
