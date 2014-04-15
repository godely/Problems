#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

int N, NN, NNNN, K;
int a, b, c, d;
int g[10][10];

//line mask, col mask, square mask
int lm[10], cm[10], sm[10];
int slm[10][5], scm[10][5];

bool valid(int i, int j, int k, int n) {
	bool vld = (!((lm[i]>>n)&1)) && (!((cm[j]>>n)&1)) && (!((sm[k]>>n)&1));
	if (k >= N) vld &= (((slm[k-N][i%N]>>n)&1) || (!((sm[k-N]>>n)&1)));
	if (k < NN-N) vld &= (((slm[k+N][i%N]>>n)&1) || (!((sm[k+N]>>n)&1)));

	if (k%N > 0) vld &= (((scm[k-1][j%N]>>n)&1) || (!((sm[k-1]>>n)&1)));
	if (k%N < N-1) vld &= (((scm[k+1][j%N]>>n)&1) || (!((sm[k+1]>>n)&1)));
	return vld;
}

void print(int ii, int jj) {
	rp(i,ii) {
		rp(j,NN) printf("%d ", g[i][j]);
		puts("");
	}
	rp(j,jj+1) printf("%d ", g[ii][j]);
	puts("");
}

bool bt(int p) {
	if (p == NNNN) return 1;

	int k = p/NN;
	int i = (p - k*NN)/N + (k/N)*N;
	int j = (p%N) + (k%N)*N;

	//printf(">\n");
	//print(i,j);
	if (g[i][j] != -1) return bt(p+1);

	rp(n,NN) {
		if (valid(i,j,k,n)) {
			g[i][j] = n;
			lm[i] |= (1<<n);
			cm[j] |= (1<<n);
			sm[k] |= (1<<n);
			slm[k][i%N] |= (1<<n);
			scm[k][j%N] |= (1<<n);
			if (bt(p+1)) return 1;
			lm[i] -= (1<<n);
			cm[j] -= (1<<n);
			sm[k] -= (1<<n);
			slm[k][i%N] -= (1<<n);
			scm[k][j%N] -= (1<<n);
			g[i][j] = -1;
		}
	}
	return 0;
}

int main() {
	scanf("%d%d", &N, &K);
	NN = N*N;
	NNNN = NN*NN;
	memset(g,-1,sizeof g);
	rp(i,NN) lm[i] = cm[i] = sm[i] = 0;
	memset(slm,0,sizeof slm);
	memset(scm,0,sizeof scm);
	bool vld = 1;
	rp(i,K) {
		scanf("%d%d%d", &b, &a, &c);
		d = (b/N) + N*(a/N);
		g[a][b] = c;
		if (!valid(a,b,d,c)) vld = 0;
		lm[a] |= (1<<c);
		cm[b] |= (1<<c);
		sm[d] |= (1<<c);
		slm[d][a%N] |= (1<<c);
		scm[d][b%N] |= (1<<c);
	}
	if (!vld || g[0][0] > 0) printf("NO\n");
	else {
		if (N == 1) printf("YES\n");
		else {
			if (g[0][0] == -1 && !valid(0,0,0,0)) printf("NO\n");
			else {
				g[0][0] = 0;
				lm[0] |= 1;
				cm[0] |= 1;
				sm[0] |= 1;
				slm[0][0] |= 1;
				scm[0][0] |= 1;
				if (bt(0)) printf("YES\n");
				else printf("NO\n");
			}
		}
	}
	return 0;
}