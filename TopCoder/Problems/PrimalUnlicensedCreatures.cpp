// Paste me into the FileEdit configuration dialog

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

bool vivo[6000];
class PrimalUnlicensedCreatures {
public:
   int maxWins( int initialLevel, vector <int> grezPower ) {
		sort(grezPower.begin(),grezPower.end());
		int sz = grezPower.size();
		int F = initialLevel;
		memset(vivo,0,sizeof vivo);
		int res = 0;
		rp(i,sz) {
			rp(j,sz) {
				if (!vivo[j] && F > grezPower[j]) {
					vivo[j] = 1;
					F += grezPower[j]/2;
					res++;
				}
			}
		}
		return res;
   }
};
