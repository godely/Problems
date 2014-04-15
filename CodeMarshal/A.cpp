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
typedef long long ll;

int main() {
  int cas = 1;
  int T; scanf("%d", &T);
  while (T--) {
    ll N, K, X;
    scanf("%lld%lld%lld", &N, &K, &X);
    ll L = min(N,X+K-1);
    K = L - X + 1;
    printf("Case %d: %lld\n", cas++, N*(N+1)/2 - K*(X+L)/2);
  }
}
