//by joao
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cctype>
#include <cmath>
 
#include <algorithm>
#include <iostream>
#include <utility>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <list>
#include <map>
  
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define pb push_back
#define INF 0x3f3f3f3f
#define MAXN 100

typedef long long ll;

using namespace std;

int m, q, start;
bitset<105> bd[1005], cur, v;
string tmp, s[1005];

int main() {

	while(scanf("%d%d", &m, &q) != EOF) {
		fr(i,0,m) {
			cin >> s[i];
			bd[i].reset(); fr(j,0,s[i].size()) if (s[i][j] == '1') bd[i].set(s[i].size()-1-j);
		}
		
		fr(i,0,q) {
			cur.reset();
			cin >> tmp;
			fr(j,0,tmp.size()) if (tmp[j] == '1') cur.set(MAXN-1-j);
			int resp = INF, idx = 0;
			fr(j,0,m) {
				if (tmp.size() > s[j].size()) continue;
				bitset<105> w; w.reset(); fr(l,0,tmp.size()) w.set(s[j].size()-1-l);
				cur.reset(); fr(l,0,tmp.size()) if (tmp[l] == '1') cur.set(s[j].size()-1-l);
				fr(k,0,s[j].size()-tmp.size()+1) {
					v.reset();
					v = (bd[j]^cur)&w;
					if (v.count() < resp) resp = v.count(), idx = j;
					cur >>= 1;
					w >>= 1;
				}
			}
			printf("%d\n", idx+1);	
		}
	}
	return 0;
}