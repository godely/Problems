#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mp make_pair
#define Fi first
#define Se second

const double eps = 1e-4;
int n;
double f[20];
pair<double, double> a[20];
double MENOR;
int MELHOR;

void teste(int ind) {
	rp(i,n+3) a[i] = mp(f[i], 0);
	a[ind] = mp(0, 1);
	fr(i,0,n+1) {
		rp(j,n+3-i-1) {
			a[j].Fi = a[j+1].Fi-a[j].Fi;
			a[j].Se = a[j+1].Se-a[j].Se;
			//printf("(%lf %lf) ", a[j].Fi, a[j].Se);
		}
		//printf("\n");
	}
	//printf("\n");
	//printf("%d:\n", ind);
	rp(i,2) {
		if (fabs(a[i].Fi) < eps || fabs(a[i].Se) < eps) continue;
		a[i].Fi /= a[i].Se;
		a[i].Se = 1;
//		printf("(%lf %lf) ", a[i].Fi, a[i].Se);
	}
//	printf("\n");
	
	if (fabs(a[0].Fi) > eps && fabs(a[0].Se) < eps) return; //a[0].valor > 0 && x inexistente
	if (fabs(a[1].Fi) > eps && fabs(a[1].Se) < eps) return; //a[1].valor > 0 && x inexistente
	
//	printf(" ! %lf\n" , fabs(a[0].Fi - a[1].Fi));
	if(fabs(a[0].Se) > eps && fabs(a[1].Se) > eps && fabs(a[0].Fi - a[1].Fi) > eps) //ambos tem x, mas valores diferentes!	
		return;

	double v = 0;	
	if(fabs(a[0].Se) > eps && fabs(a[1].Se) > eps) v = fabs(a[0].Fi - a[1].Fi); //ambos tem x, mas valores diferentes!
	
	printf("%lf %lf\n", a[0].Fi, a[1].Fi);
	if(v < MENOR) {
		MENOR = v;
		MELHOR = ind;
	}
}

int main() {
	while (scanf("%d", &n) == 1) {
		if (n == 0) break;
		MENOR = 1000000000.0;
		MELHOR = 0;
		rp(i,n+3) scanf("%lf", &f[i]);
		rp(i,n+3) teste(i);
		printf("%d\n", MELHOR);
	}
}