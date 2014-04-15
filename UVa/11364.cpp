#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f

int a, maior, menor;
int main() {
	int t, n; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		maior = 0, menor = inf;
		for (int i = 0; i < n; i++) scanf("%d", &a), maior = max(a,maior), menor = min(a,menor);
		printf("%d\n", (maior-menor)<<1);
	}
	return 0;
}