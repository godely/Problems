#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
	int T, C, d, cas = 1;
	double res;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &C, &d);
		res = (double)((d)*5)/9;
		printf("Case %d: %.2lf\n", cas++, C+res);
	}
}
