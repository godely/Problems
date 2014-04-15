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

int K, N, vet[111];
bool dp[111][51111];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &K);
        N = 0;
        fr(i,1,K+1) {
            scanf("%d", &vet[i]);
            N+=vet[i];
        }

        rp(i,N+1) dp[0][i]=0;
        rp(i,K+1) dp[i][0]=1;
        for (int i = 1; i <= K; i++) {
            for (int j = 0; j <= N; j++) {
                if (dp[i-1][j] || (j-vet[i]>=0 && dp[i-1][j-vet[i]])) dp[i][j]=1;
                else dp[i][j]=0;
            }
        }
        int mini=N;
        rp(i,N+1) {
            if (dp[K][i]) {
                //printf("%d %d\n", i, abs(N-2*i));
                mini = min(mini,abs(N-2*i));
            }
        }
        printf("%d\n", mini);
    }
    return 0;
}
