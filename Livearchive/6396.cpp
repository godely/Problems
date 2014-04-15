#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
using namespace std;
#define fr(a,b,c) for (int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
#define MP make_pair
#define F first
#define S second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define MAXN 1001

const ull LIM = ((1LL<<63LL)-1LL);

ull prm[1010];
int ps;
bool prime[1010];
ull C[1010][1010];

void pre() {
  cl(prime,1);
  for (int i = 4; i <= MAXN; i+=2) prime[i] = 0;
  ps = 0;
  prm[ps++] = 2;
  for (int i = 3; i <= MAXN; i+=2) {
    if (prime[i]) {
      prm[ps++] = i;
      for (int j = i*i; j <= MAXN; j+=i) prime[j] = 0;
    }
  }

  for (int i = 0; i <= 64; i++) C[i][0] = C[i][i] = 1;
  for (int i = 2; i <= 64; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }
}

pair<ull,ull> B[10000100];
int cs = 0;
void bt(int m, int p, int last, ull s, ull r) {
  if (s > LIM || r > LIM) return;
  if (m == 0) {
    B[cs++] = MP(s,r);
    return;
  }
  ull k = r;
  for (int i = 1; i <= min(m,last); i++) {
    if (k > LIM/prm[p]) break;
    k = k*prm[p];
    if (s > LIM/C[m][i]) continue;
    bt(m-i, p+1, i, s*C[m][i], k);
  }
}

int main() {
  pre();
  fr(i,1,65) {
    bt(i,0,i,1,1);
  }
  sort(B,B+cs);
  ull n;
  while (scanf("%llu", &n) == 1) {
    int ind = lower_bound(B,B+cs,make_pair(n,0ULL)) - B;
    printf("%llu %llu\n", B[ind].F, B[ind].S);
  }
  return 0;
}
