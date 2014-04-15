#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <iostream>
#define F first
#define S second
#define pii pair<int,int>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

char str[11111];
char grid[111][111];

int main() {
	int T, cas=1;
	scanf("%d\n", &T);
	while (T--) {
		gets(str);
		int size = strlen(str);
		int c = 0;
		rp(i,size) {
			if (str[i] < 'a' || str[i] > 'z') {
				str[i] = '.';
				continue;
			}
			c++;
		}
		int sq = sqrt(c);
		printf("Case #%d:\n", cas++);
		if (sq*sq != c) printf("No magic :(\n");
		else {
			int n = 0, m = 0;
			rp(i,size) {
				if (str[i] != '.') {
					grid[n][m++] = str[i];
					if (m >= sq) m = 0, n++;
				}
			}
			bool ok = 1;
			rp(i,sq/2+1) {
				rp(j,sq) {
					if (grid[i][j] != grid[j][i] || grid[i][j] != grid[sq-1-i][sq-1-j] || grid[i][j] != grid[sq-1-j][sq-1-i]) {
						ok = 0;
						break;
					}
				}
			}
			if (ok) printf("%d\n", sq);
			else printf("No magic :(\n");
		}
	}
	return 0;
}