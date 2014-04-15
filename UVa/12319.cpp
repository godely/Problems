#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mod 1000000007

int n, cost1[111][111], cost2[111][111], A, B;
void ff1() { rp(k,n) rp(i,n) rp(j,n) cost1[i][j] = min(cost1[i][j], cost1[i][k] + cost1[k][j]); }
void ff2() { rp(k,n) rp(i,n) rp(j,n) cost2[i][j] = min(cost2[i][j], cost2[i][k] + cost2[k][j]); }
bool comp() {
	rp(i,n) rp(j,n) {
		if (i==j) continue;
		if (cost2[i][j] > A*cost1[i][j]+B) return 0;
	}
	return 1;
}

char str[1000];
char *pt;
int main() {
	int x, y;
	while (scanf("%d\n", &n) == 1 && n > 0) {
		memset(cost1,0x3f,sizeof cost1); memset(cost2,0x3f,sizeof cost2);
		rp(i,n) {
			gets(str);
			pt = strtok(str, " ");
			x = atoi(pt);
			while ((pt = strtok(NULL, " "))) {
				y = atoi(pt);
				cost1[x-1][y-1] = 1;
			}
		}
		rp(i,n) {
			gets(str);
			pt = strtok(str, " ");
			x = atoi(pt);
			while ((pt = strtok(NULL, " "))) {
				y = atoi(pt);
				cost2[x-1][y-1] = 1;
			}
		}
		ff1(); ff2();
		scanf("%d %d", &A, &B);
		if (comp()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}