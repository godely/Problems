#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    double L, f;
    while (scanf("%lf %lf", &L, &f) && L > 0) {
        double v = sqrt(2*L*f);
        double d = v*v/(2*f);
        printf("%.8lf %.8lf\n", v, 3600*v/(L+d));
    }
}
