#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;
#define inf 0x3f3f3f3f
#define maxn 101000

int dp[maxn], arr[maxn], sz, x, passo = 0;
int grundy(int tam) {
	if (tam < 0) return 0;
	return dp[tam];
}

void pre() {
	memset(arr,0,sizeof arr);
	dp[0] = 0;
	dp[1] = dp[2] = dp[3] = 1;
	fr(i,4,10001) {
		passo++;
		sz = 0;
		rp(j,i) {
			int a = 0, b = 0;
			if (j-2 >= 0) a = grundy(j-2);
			if (i-j-3 >= 0) b = grundy(i-j-3);
			arr[a^b] = passo;
		}
		for (x = 0; x < maxn; x++) if (arr[x] != passo) {
			dp[i] = x;
			break;
		}
		printf("%d %d\n", i, dp[i]);
	}
}

int n;
char str[maxn];
int main() {
	pre();
	while (scanf("%d", &n) == 1 && n > 0) {
		scanf("%s", str);
		int size = strlen(str);
		int x = 0, cnt = 0;
		bool first = 1;
		for (int i = 0; str[i]; i++) {
			if (str[i] == 'X') {
				if ((i+1 < size && str[i+1] == 'X') || (i+2 < size && str[i+2] == 'X')) {
					cnt = 0;
					x = 1;
					break;
				}
				if (first) x ^= grundy(cnt-2);
				else x ^= grundy(cnt-4);
				cnt = first = 0;
			} else cnt++;
		}
		if (first) x ^= grundy(cnt);
		else x ^= grundy(cnt-2);
		if (!x) printf("N\n");
		else printf("S\n");
	}
	return 0;
}