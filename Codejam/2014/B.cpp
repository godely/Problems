#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define MOD 1000000007



double f[1000010];
int main() {
  int cas = 1;
  int T; scanf("%d", &T);
  while (T--) {
    double C, F, X;
    scanf("%lf%lf%lf", &C, &F, &X);

    f[0] = 0;
    f[1] = C/2.0;
    for (int i = 1; i <= 1000000; i++) f[i+1] = f[i] + C/(2.0+F*i);

    int ini = 0, fim = 1000000, g, h;
    while (ini < fim) {
      g = (2*ini + fim)/3;
      h = (ini + 2*fim)/3;

      double gt = f[g] + X/(2.0+F*g);
      double ht = f[h] + X/(2.0+F*h);

      if (gt > ht) ini = g+1;
      else fim = h;
    }
    printf("Case #%d: %.7lf\n", cas++, f[ini] + X/(2.0+F*ini));
  }
}
