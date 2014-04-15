//stor
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define fm(a,b,c,d) for(int a=b;a<c;a+=d)
#define db(x) cerr << #x " == " << x << "\n"
#define _ << ", " <<
#define inf 0x3f3f3f3f

int N, M;

struct PT {
	int x, y;
	PT() {}
	PT(int x, int y) : x(x), y(y) {}
	//PT (const PT &p) : x(x), y(y) {}
	PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
	bool operator <(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y, rhs.x); }
	bool operator== (const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y, rhs.x); }
} pts[50];
int cross(PT p, PT q) { return p.x*q.y - p.y*q.x; }

int calc[1<<16], dp[1<<16], passo=0;
int solve(int mask, int aux) {
    if (aux >= M) return 0;
    if (calc[mask] == passo) return dp[mask];
    calc[mask] = passo;

    int newMask, s;
    int retorno = inf;
    for (int i = 0; i < N; i++) {
        //printf("%d %d %d %d %d\n", i, N, mask, 1<<i, mask&(1<<i));
        if (!(mask&(1<<i))) {
            retorno = min(retorno, 1+solve(mask|(1<<i), aux+1));
            for (int j = i+1; j < N; j++) {
                if (!(mask&(1<<j))) {
                    newMask = (mask|(1<<i))|(1<<j);
                    s = 2;
                    for (int k = j+1; k < N; k++) {
                        if ((!(mask&(1<<k))) && cross(pts[j]-pts[i], pts[k]-pts[i]) == 0) {
                            s++;
                            newMask |= (1<<k);
                        }
                    }
                    retorno = min(retorno, 1+solve(newMask, aux+s));
                }
            }
        }
    }
    //printf("%d %d %d\n", mask, aux, retorno);
    return dp[mask] = retorno;
}

int main() {
    int T, cas = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        rp(i,N) {
            scanf("%d%d", &pts[i].x, &pts[i].y);
        }
        passo++;
        printf("Case #%d:\n%d\n", cas++, solve(0,0));
        if (T) printf("\n");
    }
}
