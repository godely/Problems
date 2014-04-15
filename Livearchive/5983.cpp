//NOT ACC
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iostream>
#include <bitset>
using namespace std;
#define cl(a,b) memset((a),(b),sizeof(a))
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define db(x) if(1) cerr << #x " == " << x << endl;
#define _ <<", "<<
#define F fisrt
#define S second
#define pb push_back
#define mp make_pair
#define MAXN 1<<20
#define inf 0x3F3F3F3F
#define EPS 1e-9
#define ll long long

using namespace std;

int main() {
    int T,a;
    int vet[555][555];
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        fr(i,0,n+1) vet[i] = inf;
        fr(i,0,m+1) vet[i] = 0;
        fr(i,1,n+1) fr(j,1,m+1) {
            scanf("%d", &a);
            vet[i][j] = a+max(vet[i][j-1], vet[i-1,j-1]);
        }
        if (vet[n][m] <= 0) printf("%d")
    }
    return 0;
}
