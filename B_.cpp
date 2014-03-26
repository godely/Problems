#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define CL(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef map<int,int> mii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define y1 Y1

#define maxn 210000
#define maxm 2100000

int q, a, b;
char P[maxn], T[maxn];
int main() {
	scanf("%d%s", &q, P);
	scanf("%s", T);
	rp(i,q) {
		scanf("%d%d", &a, &b);
		printf("%d: %s\n", i+1, T);
		fr(j,a-1,b) T[j] = (T[j]&32) ? T[j]&(~32) : T[j]|32;
	}
}