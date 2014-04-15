#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 10100

int main() {
	int H1, M1, H2, M2, a, b;
	while (scanf("%d%d%d%d", &H1, &M1, &H2, &M2) == 4 && (H1+M1+H2+M2) > 0) {
		a = H1*60+M1; b = H2*60+M2;
		if (b < a) printf("%d\n", 24*60-a+b);
		else printf("%d\n", b-a);
	}
	return 0;
}