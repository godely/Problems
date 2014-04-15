#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
#define MAX_N 500010
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)

double pie[11111];
const double pi = acos(-1);
const double eps = 1e-4;
int N, F;

int pode(double k) {
	int c = 0;
	double lol;
	for (int i = 0; i < N; i++) {
		c += (int)(pie[i]/k);
	}
	return (c >= F);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &F);
		F++;
		rp(i,N) scanf("%lf", &pie[i]), pie[i]=pie[i]*pie[i]*pi;
		double meio, ini = 0, fim = 1000000000;
		while (fabs(ini-fim)>eps) {
			meio = (ini+fim)/2;
			if (pode(meio)) ini=meio;
			else fim=meio;
		}
		printf("%.4lf\n", meio);
	}
	return 0;
}