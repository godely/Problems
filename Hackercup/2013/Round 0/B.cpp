#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

char str[1000];
int dp[110][110], mark[110][110], passo = 0;

bool formSmile(int i) {
	return (str[i] == ':' && (str[i+1] == ')' || str[i+1] == '('));
}

int solve(int ind, int open) {
	//printf("%d %d\n", ind, open);
	if (open < 0) return 0;
	if (!str[ind]) return open == 0;
	if (mark[ind][open] == passo) return dp[ind][open];
	mark[ind][open] = passo;
	
	bool ok = 0;
	if ((str[ind] >= 'a' && str[ind] <= 'z') || str[ind] == ' ' || str[ind] == ':') ok |= solve(ind+1,open);
	if (!ok && formSmile(ind)) ok |= (solve(ind+2,open));
	if (!ok && str[ind] == ')') ok |= solve(ind+1,open-1);
	else if (!ok && str[ind] == '(') ok |= solve(ind+1,open+1);
	return dp[ind][open] = ok;
}

int main() {
	int T, cas = 1;
	scanf("%d\n", &T);
	while (T--) {
		passo++;
		gets(str);
		if (solve(0,0)) printf("Case #%d: YES\n", cas++);
		else printf("Case #%d: NO\n", cas++);
	}
}