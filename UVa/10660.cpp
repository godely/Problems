#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

int N, G[30], L[30], P[30], R[30], k, MENOR;

int dist(int i, int j) {
	int a = i/5, b = i%5;
	int c = j/5, d = j%5;
	return abs(a-c) + abs(b-d);
}

void solve(int i, int j) {
	if (k == 5) {
		int temp, temp2 = 0;
		rp(i,N) {
			temp = inf;
			rp(j,5) {
				temp = min(temp, dist(L[i], P[j]));
			}
			temp2 += temp*G[i];
		}
		if (temp2 < MENOR) {
			MENOR = temp2;
			rp(i,5) R[i] = P[i];
		}
		return;
	}

	if (j >= 5) {
		solve(i+1, 0);
	} else {
		P[k++] = 5*i + j;
		solve(i, j+1);
		k--;
		if (P[k] < 20+k) solve(i, j+1);
	}
}

int main() {
	int T, r, c, p;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		k = 0, MENOR = inf;
		rp(i,N) scanf("%d %d %d", &r, &c, &p), L[i] = 5*r + c, G[i] = p;
		solve(0,0);
		sort(R,R+5);
		printf("%d %d %d %d %d\n", R[0], R[1], R[2], R[3], R[4]);
	}
	return 0;
}