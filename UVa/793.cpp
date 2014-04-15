#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define LSOne(x) (x&(-x))
#define MAXN 1000010
#define p(x) str[x]-'A'
#define inf 0x3f3f3f3f

using namespace std;

int rep[MAXN];
int findset(int i) {
	if (i == rep[i]) return i;
	return rep[i] = findset(rep[i]);
}

void link(int i, int j) {
	rep[findset(i)] = findset(j);
}

bool isSameSet(int i, int j) {
	return findset(i) == findset(j);
}

int lol[3];
char str[1111];
int main() {
	int T, N, a, b;
	char c;
	scanf("%d\n", &T);
	while (T--) {
		scanf("%d\n", &N);
		fr(i,1,N+1) rep[i]=i;
		lol[0] = lol[1] = 0;
		while (gets(str) && str[0] != '\0') {
			sscanf(str, "%c %d %d\n", &c, &a, &b);
			if (c=='c') link(a,b);
			else lol[isSameSet(a,b)]++;
		}
		printf("%d,%d\n", lol[1], lol[0]);
		if (T) printf("\n");
	}
	return 0;
}