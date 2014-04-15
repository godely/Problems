#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))

const double pi = acos(-1);
const double EPS = 1e-5;

int main(){
	double x, y, c, z;
	int k;
	while(scanf("%lf%lf%lf", &x, &y, &c)>0 && !(x<0)){
		y = (1+y*c)*x;
		z = pi*x/2;
		double i=x/2, j=1e50, R;
		double ang, l = x/2, arc;
		k = 0;
		while (fabs(j-i) > EPS) {
			R = (i+j)/2;
			k++;
			ang = asin(l/R);
			arc = 2*ang*R;
			if (arc < y) {
				j = R;
			} else {
				i = R;
			}
			if (k > 10000) break;
		}
		double t = sqrt(i*i-l*l);
		printf("%.3lf\n", i-t);
	}


	return 0;
}
