#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

int d, N, M;

struct Matriz {
	long long matriz[20][20];

	Matriz(){}

	Matriz operator*(const Matriz &lhs) const {
		Matriz aux;
		memset(aux.matriz, 0, sizeof(aux.matriz));
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < d; j++) {
				for (int k = 0; k < d; k++) {
					aux.matriz[i][j] = (aux.matriz[i][j]+matriz[i][k]*lhs.matriz[k][j])%M;
				}
			}
		}
		return aux;
	}
};

Matriz fastExp(Matriz mat, int exp) {
	if (exp == 1) return mat;
	else {
		Matriz ret = fastExp(mat, exp/2);
		ret = ret*ret;
		if (exp%2) ret = ret*mat;
		return ret;
	}
}

int coef[50], f[50];

int main() {
	while (scanf("%d%d%d", &d, &N, &M) && d) {
		for (int i = d-1; i >= 0; i--) scanf("%d", &coef[i]);
		for (int i = 0; i < d; i++) scanf("%d", &f[i]);
		if (N <= d) printf("%d\n", f[N-1]%M);
		else {
			Matriz aux;
			memset(aux.matriz, 0, sizeof(aux.matriz));
			for (int i = 0; i < d; i++) {
				aux.matriz[i][i+1] = 1;
			}
			for (int i = 0; i < d; i++) {
				aux.matriz[d-1][i] = coef[i];
			}
			aux = fastExp(aux, N-d);
			long long res = 0;
			for (int i = 0; i < d; i++) {
				res = (res+aux.matriz[d-1][i]*f[i])%M;
			}
			printf("%lld\n", res);
		}
	}
}
