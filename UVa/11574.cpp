#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define maxn 1111

const double pi = acos(-1);
const double eps = 1e-9;

int n;
double x[maxn], y[maxn], vx[maxn], vy[maxn], r, rr;
double ang, vel;

int cmp(double a, double b = 0) {
	if (fabs(a-b) < eps) return 0;
	else if (a < b) return -1;
	return 1;
}

double getang(double ang) {
	ang = 450-ang;
	if (cmp(ang,360) >= 0) ang -= 360;
	return (ang/180.0)*pi;
}

double dist2(int i, int j) {
	return (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
}


double a, b, c, d, C1, C2;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%lf", &n, &r);
		rr = r*r;
		rp(i,n) {
			scanf("%lf%lf%lf%lf", &x[i], &y[i], &ang, &vel);
			ang = getang(ang);
			vx[i] = vel*cos(ang);
			vy[i] = vel*sin(ang);
		}
		
		double ans = 1e100;
		fr(i,0,n) {
			fr(j,i+1,n) {
				if (cmp(dist2(i,j),rr) <= 0) { ans = 0; break; }
				C1 = (vx[i]-vx[j]);
				C2 = (vy[i]-vy[j]);
				a = C1*C1 + C2*C2;
				b = 2*(C1*(x[i] - x[j]) + C2*(y[i] - y[j]));
				c = (x[i]*x[i] + x[j]*x[j] + y[i]*y[i] + y[j]*y[j] - 2*x[i]*x[j] - 2*y[i]*y[j] - rr);
				
				d = b*b - 4*a*c;
				if (cmp(d) < 0 || cmp(a) == 0) continue;
				else if (cmp(d) == 0) {
					C1 = -(b/(2*a));
					if (cmp(C1) >= 0) ans = min(ans,C1);
				} else {
					C1 = (-b+sqrt(d))/(2*a);
					if (cmp(C1) >= 0) ans = min(ans,C1);
					C1 = (-b-sqrt(d))/(2*a);
					if (cmp(C1) >= 0) ans = min(ans,C1);
				}
			}
		}
		if (ans > 1e90) printf("No collision.\n");
		else printf("%lld\n", (long long)(ans+0.5));
	}
}