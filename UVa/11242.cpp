#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
using namespace std;

int F[11], k;
double L[11111];

int main() {
	int f, r, a;
	double maximo;
	while (scanf("%d", &f) == 1 && f > 0) {
		k = 0;
		scanf("%d", &r);
		rp(i,f) scanf("%d", &F[i]);
		rp(i,r) {
			scanf("%d", &a);
			rp(j,f) {
				L[k++] = (double)a/F[j];
			}
		}
		sort(L,L+k);
		maximo = 0;
		rp(i,k-1) maximo=max(maximo, L[i+1]/L[i]);
		printf("%.2lf\n", maximo);
	}
}