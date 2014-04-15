#include <cstdio>
#include <math.h>

using namespace std;

double num;
double res[10000000];
int main() {
    int k = 0;
    while (scanf("%lf", &num)==1) {
        res[k++] = sqrt(num);
    }
    while(k--)printf("%.4lf\n", res[k]);
    return 0;
}
