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
typedef unsigned long long ll;
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
#define MAXN 40100
  
int main() {
	int L;
	while (scanf("%d", &L) == 1 && L > 0) {
		ll aux = 1, aux2, sz;
		ll num1 = 0, den1 = 0;
		ll num2 = 0, den2 = 0;
		for (int n = L; n; n--) {
			aux *= n;
			sz = L-n;
			if (sz > 0) {
				num1 += aux*sz;
				den1 += aux;
				if (sz > 1) {
					num2 += aux*(sz+1);
					den2 += aux;
				}
			}
		}
		aux = L;
		ll num0 = 0, den0 = 0;
		for (int n = L-1; n >= 0; n--) {
			aux *= (L-1);
			sz = L-n;
			num0 += aux*sz;
			den0 += aux;
		}
		printf("%.4lf %.4lf %.4lf\n", (double)num0/den0, (double)num1/den1, (double)num2/den2);
	}
}