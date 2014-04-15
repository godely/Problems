#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define fr(a,b,c) for(int a=b; a < c; a++)
#define fri(a,b,c,d) for(int a=b; a < c; a+=d)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f

using namespace std;

int K[8][3] =
{{1, 1, 1},
{-1,-1,-1},
{1, 1, -1},
{-1,-1, 1},
{1, -1, 1},
{-1, 1,-1},
{1, -1,-1},
{-1, 1, 1}};

long long P[8];
int main() {
    long long N, t, x, y, z;
    while (scanf("%lld", &N) == 1 && N > 0) {
        rp(i,8) P[i]=-inf;
        rp(i,N) {
            scanf("%lld%lld%lld", &x, &y, &z);
            rp(j,8) {
                t = K[j][0]*x+K[j][1]*y+K[j][2]*z;
                if (t>P[j]) P[j]=t;
            }
        }
        long long s = 0;
        fri(i,0,8,2) {
            if (P[i]+P[i+1]>s) s = P[i]+P[i+1];
        }
        printf("%lld\n", s);
    }
    return 0;
}
