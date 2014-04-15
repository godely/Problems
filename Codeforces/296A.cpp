#include <bits/stdc++.h>
using namespace std;

int a[1111];
int main() {
	int n;
	scanf("%d", &n);
	memset(a,0,sizeof a);
	int b;
	for (int i = 0; i < n; i++) {
		scanf("%d", &b); a[b]++;
	}
	bool ok = 1;
	for (int i = 1; i <= 1000; i++) if (a[i] > (n+1)/2) ok = 0;
	if (ok) printf("YES\n");
	else printf("NO\n");
}