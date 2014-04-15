#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)

int pot[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

int a, b;
int main() {
	int cas = 1;
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &a, &b);
		int res = 0;
		int s = 0, m = a;
		while (m > 0) m/=10, s++;
		int p = pot[s-1];
		fr(i,a,b) {
			m = i;
			do {
				m = (m/10) + (m%10)*p;
				if (m > i && m <= b) res++;
			} while (m != i);
		}
		printf("Case #%d: %d\n", cas++, res);
	}
}