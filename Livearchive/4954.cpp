#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define fr(a,b,c) for(int a=b; a<c; a++)

using namespace std;

double nx[1111], ny[1111];

int main() {
    int a, b;
    double c, t;
    while (scanf("%d%d%lf", &a, &b, &c) == 3 && a > 0) {
        fr(i,0,a) scanf("%lf", &nx[i]);
        sort(nx,nx+a);
        fr(i,0,b) scanf("%lf", &ny[i]);
        sort(ny,ny+b);

        t = c/2.0;
        bool ok=1;
        if (nx[0]-t > 0.0 || nx[a-1]+t < 75.0 || ny[0]-t > 0.0 || ny[b-1]+t < 100.0) ok=0;
        else {
            fr(i,0,a-1) {
                if (nx[i]+c < nx[i+1]) {
                    ok=0;
                    break;
                }
            }
            if (ok) {
                fr(i,0,b-1) {
                    if(ny[i]+c < ny[i+1]) {
                        ok=0;
                        break;
                    }
                }
            }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
