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
#define Fr(a,b,c) for( int a = b ; a < c ; ++a)
#define Rp(a,b) Fr(a,0,b)
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
#define ULMAX 0xffffffffffffffffULL
#define maxn 100100
#define BASE 11

int b[maxn];
vector<pair<ull, pair<int,int> > > vec;
char T[maxn];
char gb[maxn];
ull hash[maxn];
ull B[maxn];

int main() {
	int cas1 = 1;
	B[0] = 1;
	for (int i = 1; i < maxn-10; i++) B[i] = B[i-1]*BASE;
	while (scanf("%s", gb+1) == 1 && gb[1] != 'Q') {
		gb[0] = '0';
		int sz = strlen(gb);
		gb[sz] = '0';
		gb[sz+1] = '\0';
		sz++;
		int i, j, k = 0;
		vec.clear();
		ull tempHash = 0;
		for (i = 0; gb[i]; i++) {
			if (gb[i] == '#' || gb[i] == '*') {
				int mini = (gb[i]=='#');
				for (j = i+1; gb[j] == '#' || gb[j] == '*'; j++) if (gb[j]=='#') mini++;
				i=j-1;
				vec.PB(MP(tempHash,MP(k,mini)));
				tempHash = 0;
				k = 0;
			} else {
				k++;
				tempHash = (tempHash*BASE) + gb[i]-'0'+1;
			}
		}
		if (tempHash > 0) vec.PB(MP(tempHash,MP(k,-1)));
		//Rp(i,vec.size()) printf("%llu (%d %d)\n", vec[i].F, vec[i].S.F, vec[i].S.S);

		int cas2 = 1;
		while (scanf("%s", T+1) == 1 && T[1] != 'E' && T[1] != 'Q') {
			T[0] = '0';
			int sz = strlen(T);
			T[sz] = '0';
			T[++sz] = '\0';
			hash[0] = T[0]-'0'+1;
			for (int i = 1; T[i]; i++) hash[i] = hash[i-1]*BASE + T[i]-'0'+1;
			int last = 0;
			bool can = 0;
			bool passo;
			for (int i = 0; i < vec.size(); i++) {
				passo = 0;
				for (int j = last; j <= sz-vec[i].S.F; j+=2) {
					tempHash = hash[j+vec[i].S.F-1] - ((j == 0) ? 0 : hash[j-1]*B[vec[i].S.F]);
					if (tempHash == vec[i].F) {
						if (vec[i].S.S != -1) passo = 1, last = j + vec[i].S.F + vec[i].S.S;
						else {
							if (j < sz-vec[i].S.F) continue;
							else passo = 1, can = 1;
						}
						break;
					}
				}
				if (!passo) {
					can = 0;
					break;
				}
			}
			if (can) printf("%d.%d. match\n", cas1, cas2++);
			else printf("%d.%d. not\n", cas1, cas2++);
		}
		cas1++;
		if (T[1] == 'Q') break;
	}
	return 0;
}