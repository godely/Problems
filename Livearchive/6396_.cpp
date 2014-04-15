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

ull LIM = (1ULL<<63);
ull p[] = {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL, 41ULL, 43ULL, 47ULL, 53ULL, 59ULL, 61ULL, 67ULL, 71ULL, 73ULL, 79ULL, 83ULL, 89ULL, 97ULL, 101ULL, 103ULL, 107ULL};

ull f[70];
int x[70], y[20];

map<ull,ull> mapa;
void gen(int j, int last, int cnt, ull r, ull num) {
    if (j) {
                if (mapa.count(r) != 0) {
                        if (mapa[r] > num) mapa[r] = num;
                } else mapa[r] = num;
        }

        ull q = 1;
        for (ull i = 1, k = cnt+1; i <= last; i++, k++) {
                if (num >= LIM/p[j]) break;
                q = (q*k)/i;
                if (r >= LIM/q) break;
                num*=p[j];
                gen(j+1,i,cnt+i,r*q,num);
        }
}

int main() {
        mapa.clear();
        memset(x,0,sizeof x);
        gen(0,65,0,1,1);
        printf("%d\n", (int)mapa.size());
        /*for (map<ull,ull>::iterator it = mapa.begin(); it != mapa.end(); it++) {
          printf("%llu %llu\n", (*it).F, (*it).S);
        }*/
        ull in;
        while (scanf("%llu", &in) == 1) printf("%llu %llu\n", in, mapa[in]);
}
