#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <iostream>
#include <set>
#define mp make_pair
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)

int di[] = {1,0,0,-1};
int dj[] = {0,1,-1,0};
int N;
int i1, j1;
int i2, j2;
set< pair<int,int> > v;
bool ok;

bool can(int i, int j) { return i >= 0 && i < N && j >= 0 && j < N && !v.count(mp(i,j)); }

bool dfs(int i, int j) {
    if (ok) printf(" ");
    else ok = 1;
    printf("(%d,%d)", j+1, i+1);
    v.insert(mp(i,j));
    if (i == i2 && j == j2) return 1;
    rp(k,4) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (can(ni,nj) && ni == i2 && nj == j2) {
            dfs(ni,nj);
            return 1;
        }
    }
    rp(k,4) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (can(ni,nj)) {
            if (dfs(ni,nj)) return 1;
            printf(" (%d,%d)", j+1, i+1);
        }
    }
    return 0;
}

char str[100000];

int getNum(int &x) {
    int num = 0;
    for (; str[x] != ',' && str[x] != ')'; x++) {
        if (str[x] >= '0' && str[x] <= '9') num*=10, num+=str[x]-'0';
    }
    return num;
}

int main() {
    int T, a, b;
    scanf("%d", &T);
    gets(str);
    while (T--) {
        gets(str);
        int x = 0;
        sscanf(str, "%d%n", &N, &x);
        v.clear();
        int c = 0;
        for (; str[x]; x++) {
            if (str[x] == '(') {
                int j = getNum(x)-1; x++;
                int i = getNum(x)-1;
                if (c == 0) i1 = i, j1 = j;
                else if (c == 1) i2 = i, j2 = j;
                else v.insert(mp(i,j));
                c++;
                //printf("%d %d\n", i, j);
            }
        }
        ok = 0;
        dfs(i1,j1);
        puts("");
    }
}