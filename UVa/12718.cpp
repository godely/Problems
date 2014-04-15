#include <bits/stdc++.h>

using namespace std;

char str[2000];
int qnt[300];
int main() {
	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		int n = strlen(str);
		int ans = 0, impar;
		for (int i = 1; i <= n; i++) {
			memset(qnt,0,sizeof qnt);
			impar = 0;
			for (int j = 0; j < i; j++) {
				qnt[str[j]]++;
				if (qnt[str[j]]&1) impar++;
				else impar--;
			}
			//printf("> %d: %d\n", i, impar);
			if (impar <= 1) ans++;
			for (int j = i; j < n; j++) {
				qnt[str[j-i]]--;
				if (qnt[str[j-i]]&1) impar++;
				else impar--;
				//printf("%d %d: %c %d\n", i, j, str[j-i], impar);
				qnt[str[j]]++;
				if (qnt[str[j]]&1) impar++;
				else impar--;
				if (impar <= 1) ans++;
			}
			//printf("%d: %d\n", i, ans);
		}
		printf("Case %d: %d\n", cas++, ans);
	}
	return 0;
}