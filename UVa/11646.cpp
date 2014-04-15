#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const double EPS = 1e-11, PI = acos(-1);
int main() {
	int cas = 1;
	double a, b;
	while (scanf("%lf : %lf", &a, &b) == 2) {
		double rate = a/b;
		double init = 0.0, fim = 100000000.0, wid, len;
		double c, arco, raio;

		while (fabs(init-fim) > EPS) {
			wid = (init+fim)/2;
			len = rate*wid;
			//printf("%lf %lf     ", wid, len);

			raio = sqrt((wid/2.0)*(wid/2.0) + (len/2.0)*(len/2.0));
			c = acos(((len/2.0)/raio));
			arco = (c*raio);
			if (2*len + 4*arco < 400) {
				init = wid;
			} else {
				fim = wid;
			}
		}

		printf("Case %d: %.10lf %.10lf\n", cas++, rate*wid, wid);
	}
	return 0;
}
