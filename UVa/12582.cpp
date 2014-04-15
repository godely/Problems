#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

char str[11111];
int res[30];
int solve(int a, int b) {
	int ret = 1, k;
	fr(i,a,b) {
		k = i;
		i++;
		while (str[i] != str[k]) i++;
		res[str[k]-'A'] = solve(k+1,i);
		ret++;
	}
	return ret;
}

int main() {
	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		memset(res, 0, sizeof res);
		res[str[0]-'A'] = solve(1,strlen(str)-1)-1;
		printf("Case %d\n", cas++);
		rp(i,26) if(res[i] > 0) printf("%c = %d\n", 'A'+i, res[i]);
	}
	return 0;
}