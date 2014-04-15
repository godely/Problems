#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define maxn 200100

int n;
char P[maxn];

bool is(int a, int b) {
	int half = (b-a+1)/2;
	rp(i,half) if (P[a+i] != P[b-i]) return 0;
	return 1;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", P);
		n = strlen(P);
		for (int i = 0; i < n-1; i++) {
			if (P[0] == P[i] && P[i+1] == P[n-1] && is(0,i) && is(i+1,n-1)) {
				printf("alindrome\n");
				goto fim;
			}
		}
		if (is(0,n-1)) printf("palindrome\n");
		else printf("simple\n");
		fim:;
	}
	return 0;
}