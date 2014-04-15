#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int n[111];
double p[111];
double pd[5111];
int calc[5111], passo = 0;
int N;

double solve(int ind) {
    if (ind > 5000) {
        double ret = 0.0;
        for (int i = 0; i < N; i++) {
            if (n[i] > 0) {
                ret += (double)n[i]*p[i];
            }
        }
        return ret;
    }
    if (calc[ind] == passo) return pd[ind];
    calc[ind] = passo;

    double ret = 0.0;
    for (int i = 0; i < N; i++) {
        //printf("%d %lf\n", ind, ret);
        if (n[i] > 0) {
            ret += (double)n[i]*p[i];
        } else {
            ret += (double)(-n[i])*p[i] + p[i]*solve(ind+1);
        }
    }
    return pd[ind] = ret;
}

int main() {
    int T, cas = 1, aux;
    scanf("%d", &T);
    while (T--) {
        passo++;
        scanf("%d", &N);
        aux = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d %lf", &n[i], &p[i]);
            if(n[i]<0) aux++;
        }
        if(aux==N) printf("Case %d: God! Save me\n", cas++);
        else printf("Case %d: %.2lf\n", cas++, solve(0));
    }
    return 0;
}