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
#define MP make_pair
#define F first
#define S second

int T, n;
double a[1010], b[1010];

int main() {
  int cas = 1;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    rp(i,n) scanf("%lf", &a[i]);
    rp(i,n) scanf("%lf", &b[i]);
    sort(a,a+n);
    sort(b,b+n);

    int j = 0, pt1 = 0, pt2 = 0;
    rp(i,n) {
      while (j < n && b[j] < a[i]) j++, pt2++;
      j++;
    }
    rp(i,n) {
      rp(j,n-i) {
        if (b[j] > a[i+j]) goto fim;
      }
      pt1 = n-i;
      break;
      fim:;
    }
    printf("Case #%d: %d %d\n", cas++, pt1, pt2);
  }
  return 0;
}
