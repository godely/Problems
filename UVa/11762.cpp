#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define dbg if(0)
#define maxn 10001000

bool C[maxn];
int fat[maxn], qntTotal[maxn], size[maxn];
void crivo() {
	memset(C,0,sizeof C);
	memset(size,0,sizeof size);
	fat[2] = 2;
	size[2]++;
	for (int i = 4; i <= 1000000; i+=2) fat[i] = 2, size[i]++, C[i] = 1;
	for (int i = 3; i <= 1000000; i+=2) {
		if (!C[i]) {
			fat[i] = i;
			size[i]++;
			for (int j = i*2; j <= 1000000; j+=i) {
				C[j] = 1;
				fat[j] = i;
				size[j]++;
			}
		}
	}
	int cnt = 0;
	for (int i = 2; i <= 1000000; i++) {
		if (!C[i]) cnt++;
		qntTotal[i] = cnt;
	}
}

double dp[maxn];
int main() {
	crivo();
	dp[0] = 0.0;
	fr(i,2,1000001) {
		double num1 = qntTotal[i] - size[i];
		double y = 0.0;
		int D = i, last = 1000000000;
		while (D > 1) {
			int temp = fat[D];
			if (fat[D] < last) {
				y += 1.0 + dp[i/fat[D]];
			}
			D /= fat[D];
			last = temp;
		}
		dp[i] = (num1+y)/size[i];
	}
	int T, n, cas = 1; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("Case %d: %lf\n", cas++, dp[n]);
	}
	return 0;
}