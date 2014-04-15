#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a, b, sizeof(a))
#define LL long long
#define inf 0x3f3f3f3f

int dp[222], calc[222], size, passo=0;
char s[200];

int solve(int ind) {
	if (ind >= size) return 0;
	if (calc[ind]==passo) return dp[ind];
	calc[ind]=passo;

	int i, j, k;
	int xD = 0;
	int ret = 1+solve(ind+1);
	for(i = 1; ind+i < size; i++) {
		k = 1;
		for (j = i; ind+j+i <= size; j+=i, k++) {
			ret = min(ret, i + 2 + ((int)log10(k) + 1) + solve(ind+j));
			if (strncmp(s+ind, s+ind+j, i) != 0) break;
		}
		ret = min(ret, i + 2 + ((int)log10(k) + 1) + solve(ind+j));
	}
	return dp[ind] = ret;
}


int main() {
	int T, M;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		passo++;
		size = strlen(s);
		printf("%d\n", solve(0));
	}
	return 0;
}
