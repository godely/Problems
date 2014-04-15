#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define pb push_back
#define pode(a) !(mask&(1<<a))
#define getNum() (f*10000 + g*1000 + h*100 + i*10 + j)

bool feasible(int N, int mask) {
	if ((int)log10(N)+1 > 5) return 0;
	while (N) {
		mask |= (1<<(N%10));
		N/=10;
	}
	return mask==1023;
}

int main() {
	int N, mask, G;
	bool ok, lols = 0;
	while (scanf("%d", &N) && N > 0) {
		if (lols) printf("\n");
		else lols=1;
		mask = 0;
		ok = 0;
		for (int f = 0; f <= 9; f++) {
			mask |= (1<<f);
			for (int g = 0; g <= 9; g++) {
				if (pode(g)) {
					mask |= (1<<g);
					for (int h = 0; h <= 9; h++) {
						if (pode(h)) {
							mask |= (1<<h);
							for (int i = 0; i <= 9; i++) {
								if (pode(i)) {
									mask |= (1<<i);
									for (int j = 0; j <= 9; j++) {
										if (pode(j)) {
											mask |= (1<<j);
											G = getNum();
											//if (getNum() < 1300) printf("%d %d\n", getNum(), getNum()*N);
											if (feasible(G*N, mask)) printf("%.5d / %.5d = %d\n", G*N, G, N), ok = 1;
											mask &= ~(1<<j);
										}
									}
									mask &= ~(1<<i);
								}
							}
							mask &= ~(1<<h);
						}
					}
					mask &= ~(1<<g);
				}
			}
			mask &= ~(1<<f);
		}
		if (!ok) printf("There are no solutions for %d.\n", N);
	}
}