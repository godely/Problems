#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define MAXN 101000

int CA[MAXN], CB[MAXN], A, B, sA, sB, kA, kB;
int X[MAXN], Y[MAXN], passo = 0;

int main() {
	while (scanf("%d%d", &A, &B) == 2 && A > 0) {
		passo++;
		sA = sB = 1;
		scanf("%d", &CA[0]);
		X[CA[0]] = passo;
		fr(i,1,A) {
			scanf("%d", &CA[sA]);
			X[CA[sA]] = passo;
			if (CA[sA] != CA[sA-1]) sA++;
		}
		scanf("%d", &CB[0]);
		Y[CB[0]] = passo;
		fr(i,1,B) {
			scanf("%d", &CB[sB]);
			Y[CB[sB]] = passo;
			if (CB[sB] != CB[sB-1]) sB++;
		}
		
		kA = kB = 0;
		rp(i,sA) if (Y[CA[i]] != passo) kA++;
		rp(i,sB) if (X[CB[i]] != passo) kB++;
		printf("%d\n", min(kA, kB));
	}
	return 0;
}