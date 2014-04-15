//stor
#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define dbg() if(ind==1)

#define add(a,b) ant[z] = atual[b], f[z] = a, atual[b] = z++
//zerar: z=0; cl(atual,0);
int z;

const int inf = -100000000;

int peso[111111], f[111111], ant[111111], atual[111111];
int grau[111111], p[111111];

int dp[111111][111];

int n, k;
int solveTree() {
    queue<int> fila;
    rp(i,n) if (grau[i]==0) fila.push(i);

    int ind;
    while (!fila.empty()) {
        ind = fila.front();
        fila.pop();
        if (atual[ind] == -1) {
            fr(i,1,k+1) dp[ind][i] = peso[ind];
        } else {
            int t = atual[ind], son = f[t];
            //printf("> > %d %d\n", ind, t);
            fr(i,1,k+1) dp[ind][i] = dp[son][i];
            dp[ind][0] = 0;
            t = ant[t];
            while (t != -1) {
                son = f[t];
                for (int i = k; i >= 1; i--) {
                    for (int j = 1; j <= i && j <= k; j++) {
                        //printf("%d %d\n", i,j);
                        dp[ind][i] = max(dp[ind][i], dp[ind][i-j]+dp[son][j]);
                    }
                }
                t = ant[t];
                //dbg() printf("%d\n", t);
            }
            fr(i,1,k+1) dp[ind][i] = max(dp[ind][i], peso[ind]);
        }
        //printf("%d:\n",ind);
        //fr(i,1,k+1) printf("%d ", dp[ind][i]);
        //printf("\n");
        if (ind != 0) {
            grau[p[ind]]--;
            if (grau[p[ind]] == 0) fila.push(p[ind]);
        }
    }

    return dp[0][k];
}

int main() {
    int a;
	while (scanf("%d%d", &n, &k) == 2 && n > 0) {
		rp(i,n) atual[i] = -1, grau[i]=0;
		z = 0;
		rp(i,n) scanf("%d", &peso[i]);
		p[0] = -1;
		rp(i,n-1) {
			scanf("%d", &a);
			add(i+1,a);
			p[i+1] = a;
			grau[a]++;
		}
		printf("%d\n", solveTree());
	}
	return 0;
}
