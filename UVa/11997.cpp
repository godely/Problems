#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
typedef long long ll;
#define inf 0x3f3f3f3f

int k;
int grid[1000][1000];
int res[1000000];

int main() {
	while (scanf("%d", &k) == 1) {
		rp(i,k) rp(j,k) scanf("%d", &grid[i][j]);
		rp(i,k) sort(grid[i],grid[i]+k);
		int sum = 0;
		rp(i,k) sum += grid[i][0];
		int s = 0;
		res[s++] = sum;
		rp(i,k) {
			fr(j,1,k) {
				sum = sum-grid[i][0]+grid[i][j];
				res[s++] = sum;
				sum = sum-grid[i][j]+grid[i][0];
			}
		}
		sort(res,res+s);
		printf("%d", res[0]);
		fr(i,1,k) printf(" %d", res[i]);
		printf("\n");
	}
	return 0;
}