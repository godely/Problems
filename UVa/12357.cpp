#include <bits/stdc++.h>
using namespace std;
#define FR(a,b,c) for(int a = b; a <= c; a++)
#define LSOne(x) (x&(-x))
#define MAXN 100100
#define ll long long

int line[2][5111][2];

//0 = veio da direita
//1 = veio da esquerda

int main() {
	int N, k, a, res;
	while (scanf("%d", &N) == 1 && N > 0) {
		k = 0;
		res = 0;
		memset(line, 0, sizeof line);
		FR(i,1,N+1) {
			FR(j,1,i) {
				if (i <= N) scanf("%d", &a);
				else a = 0;
				line[1-k][j][0] = line[k][j-1][0] + a;
				line[1-k][j][1] = line[k][j-1][0] + line[k][j][1] + a;
				if (a >= 0) {
					if (line[1-k][j][1] > 0) {
						res += line[1-k][j][1];
						line[1-k][j-1][1] -= line[k][j-1][1];
						line[1-k][j][0] = line[1-k][j][1] = 0;
					}
					printf("%d %d %d\n", i, j, res);
					line[k][j-1][0] = line[k][j-1][1] = line[k][j][0] = line[k][j][1] = 0;
				}
			}
			k=1-k;
		}
		printf("%d\n", res);
	}
	return 0;
}