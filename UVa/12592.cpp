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

#define MAXN 30100

int n;
char str[200], str2[200];
map<string, string> m;
int main() {
	int n;
	scanf("%d", &n);
	gets(str);
	Fr(i,0,n) {
		gets(str);
		gets(str2);
		m[str] = str2;
	}
	scanf("%d", &n);
	gets(str);
	Fr(i,0,n) {
		gets(str);
		printf("%s\n", m[str].c_str());
	}
		
	return 0;
}