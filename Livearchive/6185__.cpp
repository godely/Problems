#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

const double inc = 1;
int n;
double f[20], a[20];

double teste(int ind, double k) {
	rp(i,n+3) a[i] = f[i];
	a[ind] = k;
	fr(i,0,n+1) {
		rp(j,n+3-i-1) {
			a[j] = a[j+1]-a[j];
		}
	}
	double sum = 0.0;
	rp(i,2) {
		sum += abs(a[i]);
	}
	return sum;
}

int melhor;
double menor;
int main() {
	while (scanf("%d", &n) == 1) {
		if (n == 0) break;
		rp(i,n+3) scanf("%lf", &f[i]);
		melhor = 0;
		menor = 100000000000.0;
		rp(i,n+3) {
			for (double j = -200; j <= 200; j+=inc) {
				if (teste(i,j) < menor) menor = teste(i,j), melhor = i;
			}
		}
		printf("%d\n", melhor);
	}
}