#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof(a))
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


char str[11000], nm[11000];
int sz[30];
string y[30];
map<string,int> mp;

int main() {
	while (gets(str)) {
		if (str[0] == '.') break;
		int off = 0, x;
		mp.clear();
		rp(i,30) y[i] = "";
		while (sscanf(str+off, "%s%n", nm, &x) == 1) {
			off += x;
			mp[nm]++;
		}
		cl(sz,0);
		for (map<string,int>::iterator it = mp.begin(); it != mp.end(); it++) {
			string s = (*it).first;
			int qtd = (*it).second;
			int nmsz = s.size();
			if ((nmsz-2)*qtd > sz[s[0]-'a']) {
				sz[s[0]-'a'] = (nmsz-2)*qtd;
				y[s[0]-'a'] = s;
			}
		}
		bool ok = 0;
		off = x = 0;
		while (sscanf(str+off, "%s%n", nm, &x) == 1) {
			off += x;
			if (ok) printf(" ");
			else ok = 1;
			string ms = string(nm);
			if (y[nm[0]-'a'] == ms) printf("%c.", nm[0]);
			else cout << ms;
		}
		puts("");
		int cnt = 0;
		rp(i,30) if (y[i].size()) cnt++;
		printf("%d\n", cnt);
		rp(i,30) if (y[i].size()) cout << y[i][0] << ". = " << y[i] << endl;
	}
	return 0;
}