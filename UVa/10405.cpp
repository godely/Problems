#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

char gb1[1111], gb2[1111];
int N1, N2;
int pd[1111][1111];

int solve(int a, int b) {
	if (a >= N1 || b >= N2) return 0;
	if (~pd[a][b]) return pd[a][b];

	int res = 0;
	if (gb1[a] == gb2[b]) res = 1+solve(a+1, b+1);
	else res = max(solve(a+1, b), solve(a, b+1));
	return pd[a][b] = res;
}

int main() {
	while (gets(gb1)) {
		memset(pd, -1, sizeof pd);
		gets(gb2);
		N1 = strlen(gb1);
		N2 = strlen(gb2);
		printf("%d\n", solve(0,0));
	}
}
