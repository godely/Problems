#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const double pi = acos(-1);

int main(){
	int T;
	double L, W, R;
	scanf("%d", &T);
	while (T--) {
		scanf("%lf", &L);
		W = L*6.0/10.0;
		R = L*1.0/5.0;
		printf("%.2lf %.2lf\n", pi*R*R, L*W - pi*R*R);
	}
	return 0;
}