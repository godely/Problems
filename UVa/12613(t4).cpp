#include <bits/stdc++.h>
#define fr(i,a,b) for (int i = (a); i < (b); ++i)
#define N 150005
using namespace std;

typedef long long ll;

char T[N], Taux[N];
int n, RA[N], tempRA[N], SA[N], tempSA[N], c[N], Phi[N], PLCP[N], LCP[N], P[N];

void cs(int k) {
  int i, sum, maxi = max(300, n);

  memset(c, 0, sizeof c);
  for (i = 0; i < n; i++)
    c[i + k < n ? RA[i + k] : 0]++;
  for (i = sum = 0; i < maxi; i++) {
    int t = c[i]; c[i] = sum; sum += t;
  }
  for (i = 0; i < n; i++)
    tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
  for (i = 0; i < n; i++)
    SA[i] = tempSA[i];
}

void consSA() {
  int i, k, r;
  for (i = 0; i < n; i++) RA[i] = T[i];
  for (i = 0; i < n; i++) SA[i] = i;
  for (k = 1; k < n; k <<= 1) {
    cs(k); cs(0);
    tempRA[SA[0]] = r = 0;
    for (i = 1; i < n; i++)
      tempRA[SA[i]] =
        (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    for (i = 0; i < n; i++)
      RA[i] = tempRA[i];
} }

void compLCP() {
  int i, L;
  Phi[SA[0]] = -1;
  for (i = 1; i < n; i++)
    Phi[SA[i]] = SA[i-1];
  for (i = L = 0; i < n; i++) {
    if (Phi[i] == -1) { PLCP[i] = 0; continue; }
    while (T[i + L] == T[Phi[i] + L]) L++;
    PLCP[i] = L;
    L = max(L-1, 0);
  }
  for (i = 1; i < n; i++)
    LCP[i] = PLCP[SA[i]];
}

int length(int suffix) {
    return n-1 - SA[suffix];
}

ll calcDifferent() {
    ll ret = 0;
    fr(i,1,n) {
        ret += length(i) - LCP[i];
    }
    return ret;
}

int main() {
    int nt; scanf("%d", &nt); int _ = 0;
    while (nt--) {
        ll k;
        scanf("%s %lld", T, &k);
        int lenaux = strlen(T);

        Taux[0] = '\0';
        strcpy(Taux, T);
        n = lenaux;

        strcat(T, Taux);
        n += lenaux;
        T[n++] = '$';

        consSA();
        compLCP();
        ll a = calcDifferent();
       /* if (k == 2) {
            printf("Case %d: %lld\n", ++_, a); continue;
        }*/
        n--;
        T[n] = '\0';
        strcat(T, Taux);
        n += lenaux;
        T[n++] = '$';

        consSA();
        compLCP();
        ll b = calcDifferent();

        printf("Case %d: %lld\n", ++_, a + (b-a)*(k-2));

    }
    return 0;
}