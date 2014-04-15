#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

long long n, m;

struct matriz {
	long long mat[5][5];
	
//	mat() {}

	matriz operator*(const matriz &lhs) const {
		matriz ret;
		memset(ret.mat, 0, sizeof(ret.mat));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					ret.mat[i][j] = (ret.mat[i][j] + (mat[i][k]*lhs.mat[k][j])%m)%m;
				}
			}
		}
		return ret;
	}
};

matriz fastExpo(matriz aux, long long n) {
	if (n == 1) return aux;
	matriz lol = fastExpo(aux, n/2);
	lol=lol*lol;
	if (n%2) lol=lol*aux;
	return lol;
}

int main() {
	matriz aux, resp;
	while (scanf("%lld%lld", &n, &m) == 2) {
		m = 1<<m;
		if (n == 0) {
			printf("0\n");
			continue;
		} else if (n == 1) {
			printf("%d\n",n%m);
			continue;
		} else {
			n--;
			aux.mat[0][0] = 1;
			aux.mat[0][1] = 1;
			aux.mat[1][0] = 1;
			aux.mat[1][1] = 0;
			resp = fastExpo(aux, n);
			printf("%d\n", resp.mat[0][0]);
		}
	}
	return 0;
}