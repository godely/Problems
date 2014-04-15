// Paste me into the FileEdit configuration dialog

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define INF 0x3f3f3f3f

int sz;
int t[10];
double rat[10];
double temp[10];

double compute() {
	temp[0] = 0;
	double distMax, tempx;
	fr(i,1,sz) {
		distMax = 0;
		fr(j,0,i) {
			tempx = sqrt((rat[t[j]]+rat[t[i]])*(rat[t[j]]+rat[t[i]]) - (rat[t[j]]-rat[t[i]])*(rat[t[j]]-rat[t[i]]));
			if (tempx+temp[j] > distMax) {
				distMax = tempx+temp[j];
			}
		}
		temp[i] = distMax;
	}
	return temp[sz-1];
}

class MarblePositioning {
public:
	double totalWidth( vector <int> radius ) {
		sz = radius.size();
		rp(i,sz) {
			t[i] = i;
			rat[i] = (double)radius[i];
		}
		double res = 1e100;
		do {
			res = min(res,compute());
		} while (next_permutation(t,t+sz));
		return res;
	}
};