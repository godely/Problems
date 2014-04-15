#include <bits/stdc++.h>
using namespace std;

int f[30], pos[30], a;

int main() {
	int N, c;
	while (scanf("%d", &N) == 1) {
		for (int i = 1; i <= N; i++) scanf("%d", &a), pos[a] = i;
		for (int i = 1; i <= N; i++) scanf("%d", &f[i]);
		
		c = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j < i; j++) {
				if (pos[f[j]] > pos[f[i]]) c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}