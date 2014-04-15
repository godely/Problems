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
typedef pair<int,int> pii;

pii fila[10000], aux;
bool vis[100][100];
char g[100][100];
int R, C, M;
int main() {
  int T, cas = 1;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &R, &C, &M);
    printf("Case #%d:\n", cas++);
    int K = R*C - M;
    if (M == 0) {
      rp(i,R) {
        if (i == 0) printf("c");
        else printf(".");
        rp(j,C-1) printf(".");
        puts("");
      }
    } else if (K == 1) {
      rp(i,R) {
        if (i == 0) printf("c");
        else printf("*");
        rp(j,C-1) printf("*");
        puts("");
      }
    } else {
      if (R == 1 && C == 1) {
        if (M == 0) printf("c\n");
        else printf("Impossible\n");
      } else if (C == 1) {
        if (K == 0) printf("Impossible\n");
        else {
          printf("c\n");
          rp(i,K-1) printf(".\n");
          rp(i,M) printf("*\n");
        }
      } else if (R == 1) {
        if (K == 0) printf("Impossible\n");
        else {
          printf("c");
          rp(i,K-1) printf(".");
          rp(i,M) printf("*");
          puts("");
        }
      } else {
        bool found = 0;

        for (int t = 2; t <= R; t++) {
          for (int s = 2; s <= C && t*s <= K; s++) {
            int r = K - t*s;
            if (r == 1 || r > s) continue;
            if (r > 0 && t == R) continue;

            found = 1;
            rp(i,t) {
              if (i == 0) printf("c");
              else printf(".");
              rp(j,s-1) printf(".");
              rp(j,C-s) printf("*");
              puts("");
            }
            if (r > 0) {
              rp(j,r) printf(".");
              rp(j,C-r) printf("*");
              puts("");
              rp(i,R-t-1) {
                rp(j,C) printf("*");
                puts("");
              }
            } else {
              rp(i,R-t) {
                rp(j,C) printf("*");
                puts("");
              }
            }
            break;
          }
          if (found) break;
        }

        if (!found) {
          swap(R,C);
          for (int t = 2; t <= R; t++) {
            for (int s = 2; s <= C && t*s <= K; s++) {
              int r = K - t*s;
              if (r == 1 || r > s) continue;
              if (r > 0 && t == R) continue;

              found = 1;
              rp(i,t) {
                if (i == 0) g[i][0] = 'c';
                else g[i][0] = '.';
                rp(j,s-1) g[i][j+1] = '.';
                rp(j,C-s) g[i][j+s] = '*';
              }
              if (r > 0) {
                rp(j,r) g[t][j] = '.';
                rp(j,C-r) g[t][j+r] = '*';
                rp(i,R-t-1) {
                  rp(j,C) g[t+1+i][j] = '*';
                }
              } else {
                rp(i,R-t) {
                  rp(j,C) g[t+i][j] = '*';
                }
              }

              for (int j = C-1; j >= 0; j--) {
                rp(i,R) printf("%c", g[i][j]);
                puts("");
              }
              break;
            }
            if (found) break;
          }

          if (!found) {
            if (R > 2 && C > 2 && M/(C-2) <= R-2) {
              fila[0] = MP(R-1,C-1);
              cl(vis,0);
              int cnt = 0;
              cl(g,'.');
              g[0][0] = 'c';
              for (int ini = 0, fim = 0; ini <= fim; ini++) {
                aux = fila[ini];

                int i = aux.F;
                int j = aux.S;

                g[i][j] = '*'; cnt++;
                if (cnt == M) break;
                if (i > 2 && !vis[i-1][j]) {
                  vis[i-1][j] = 1;
                  fila[++fim] = MP(i-1,j);
                }
                if (j > 2 && !vis[i][j-1]) {
                  vis[i][j-1] = 1;
                  fila[++fim] = MP(i,j-1);
                }
              }
              rp(i,R) {
                rp(j,C) printf("%c", g[i][j]);
                puts("");
              }
            } else {
              printf("Impossible\n");
            }
          }
        }
      }
    }
  }
  return 0;
}
