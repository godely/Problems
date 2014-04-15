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
#include <ctime>
#include <string>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define CL(a,b) memset(a,b,sizeof(a))
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

#define maxn 21000

int N;
int x[maxn], y[maxn], z[maxn];
int minX, maxX, minY, maxY, minZ, maxZ;
int minX_, maxX_, minY_, maxY_, minZ_, maxZ_;

bool onSurface(int x, int y, int z) { return x == minX_ || x == maxX_ || y == minY_ || y == maxY_ || z == minZ_ || z == maxZ_; }

bool test() {
	Fr(i,0,N) if (!onSurface(x[i],y[i],z[i])) return 0;
	return 1;
}

int main() {
	int T, cas = 1; scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		minX = minY = minZ = INF;
		maxX = maxY = maxZ = -INF;
		Fr(i,0,N) {
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
			minX = min(minX,x[i]); maxX = max(maxX,x[i]);
			minY = min(minY,y[i]); maxY = max(maxY,y[i]);
			minZ = min(minZ,z[i]); maxZ = max(maxZ,z[i]);
		}
		bool can = 0;
		
		//printf("%d %d\n", can, mask);	
		int difX = maxX-minX, difY = maxY-minY, difZ = maxZ-minZ;
		int maximo = max(difX,max(difY,difZ));
		
		Fr(i,0,8) {
			minX_ = minX; maxX_ = maxX; minY_ = minY; maxY_ = maxY; minZ_ = minZ; maxZ_ = maxZ;
			if (i&1) minX_ -= (maximo-difX);
			else maxX_ += (maximo-difX);
			if (i&2) minY_ -= (maximo-difY);
			else maxY_ += (maximo-difY);
			if (i&4) minZ_ -= (maximo-difZ);
			else maxZ_ += (maximo-difZ);
			if (test()) {
				can = 1;
				break;
			}
		}
		
		if (!can) printf("Case %d: -1\n", cas++);
		else printf("Case %d: %d\n", cas++, maximo);
	}
	return 0;
}