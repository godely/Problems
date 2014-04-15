#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define INF 0x3f3f3f3f

class UndoHistory {
public:
	int minPresses( vector <string> lines ) {
		int sz = lines.size();
		int res = lines[0].size() + sz;
		fr(i,1,sz) {
			int resi = 2+lines[i].size();
			fr(j,0,i) {
				int a = lines[j].size();
				int b = lines[i].size();
				int tempc = INF;
				if (a <= b && lines[j] == lines[i].substr(0,a)) {
					tempc = b-a;
					if (j < i-1) tempc += 2;
				} else {
					for (int k = min(a,b); k >= 0; k--) {
						if (lines[j].substr(0,k) == lines[i].substr(0,k)) {
							tempc = min(tempc, 2 + b - k);
						}
					}
				}
				resi = min(resi,tempc);
			}
			res += resi;
		}
		return res;
	}
};