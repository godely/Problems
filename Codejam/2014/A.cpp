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

int ans, g[10][10];
int p[20];

int main() {
  int cas = 1;
  int T; scanf("%d", &T);
  while (T--) {
    cl(p,0);

    scanf("%d", &ans); ans--;
    rp(i,4) rp(j,4) scanf("%d", &g[i][j]);
    rp(i,4) p[g[ans][i]]++;

    scanf("%d", &ans); ans--;
    rp(i,4) rp(j,4) scanf("%d", &g[i][j]);
    rp(i,4) p[g[ans][i]]++;

    ans = 0;
    int k = -1;
    fr(i,1,17) if (p[i]==2) ans++, k = i;

    printf("Case #%d: ", cas++);
    if (ans == 0) printf("Volunteer cheated!\n");
    else if (ans == 1) printf("%d\n", k);
    else printf("Bad magician!\n");
  }
}
