#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

#define MAXN 2100100

int cost[1000];
char str[10000];
int c[300];
int aff[1000];
bool mark[1000];

int main() {
    int sz = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            cost[sz++] = i+j;
        }
    }
    sort(cost,cost+sz);
	int T;
	scanf("%d", &T);
	gets(str);
	while (T--) {
		gets(str);
		cl(c,0);
		for (int i = 0; str[i]; i++) {
		  if (str[i] != ' ')  c[str[i]]++;
		}
		cl(mark,0);
		int k = 0;
		for (int i = 0; str[i]; i++) {
		    if (!mark[str[i]] && str[i] != ' ') mark[str[i]] = 1, aff[k++] = c[str[i]];
		}
		sort(aff,aff+k);
		int res = 0;
		for (int i = k-1, j = 0; i >= 0; i--, j++) {
		    res += aff[i]*cost[j];
		}
		printf("%d\n", res);
	}
	return 0;
}