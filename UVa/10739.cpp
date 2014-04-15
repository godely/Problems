#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

char gb[1111];
int size, pd[1111][1111], calc[1111][1111], passo=0;

int solve(int ini, int fim) {
	if (ini >= fim) return 0;
	if (calc[ini][fim] == passo) return pd[ini][fim];
	calc[ini][fim] = passo;

	if (gb[ini]==gb[fim]) return pd[ini][fim] = solve(ini+1,fim-1);
	else return pd[ini][fim] = min(1+solve(ini,fim-1), min(1+solve(ini+1,fim), 1+solve(ini+1,fim-1)));
}

int main() {
	int T, cas = 1;
	scanf("%d\n", &T);
	while (T--) {
		passo++;
		gets(gb);
		size = strlen(gb);
		printf("Case %d: %d\n", cas++, solve(0, size-1));
	}
}
