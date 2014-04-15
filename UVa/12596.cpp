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
#define INF 1000000000
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

char adj[][10] = {{'T', 'W', 'O'}, {'T', 'W', 'O'}, {'T', 'W', 'O'}, {'T', 'H', 'R', 'E', 'E'}, {'T', 'H', 'R', 'E', 'E'}, {'T', 'H', 'R', 'E', 'E'}, 
				{'F', 'O', 'U', 'R'}, {'F', 'O', 'U', 'R'}, {'F', 'O', 'U', 'R'}, {'F', 'I', 'V', 'E'} , {'F', 'I', 'V', 'E'} , {'F', 'I', 'V', 'E'},
				{'S', 'I', 'X'}, {'S', 'I', 'X'}, {'S', 'I', 'X'}, {'S', 'E', 'V', 'E', 'N'}, {'S', 'E', 'V', 'E', 'N'}, {'S', 'E', 'V', 'E', 'N'}, 
				{'S', 'E', 'V', 'E', 'N'}, {'E', 'I', 'G', 'H', 'T'}, {'E', 'I', 'G', 'H', 'T'}, {'E', 'I', 'G', 'H', 'T'}, {'N', 'I', 'N', 'E'}, 
				{'N', 'I', 'N', 'E'}, {'N', 'I', 'N', 'E'}, {'N', 'I', 'N', 'E'}};
				
int size[] = {3,3,3,5,5,5,4,4,4,4,4,4,3,3,3,5,5,5,5,5,5,5,4,4,4,4};

ll cont[200][150];
ll counter(int c, int lvl) {
	if (~cont[c][lvl]) return cont[c][lvl];
	if (lvl == 0) return cont[c][lvl] = 1;
	
	ll ret = 0, temp;
	Fr(i,0,size[c]) {
		temp = counter(adj[c][i]-'A', lvl-1);
		if (ret > INF-temp) return cont[c][lvl] = INF+1;
		ret += counter(adj[c][i]-'A', lvl-1);
	}
	return cont[c][lvl] = ret;
}

char str[200];
int n, k;
int main() {
//	cin.sync_with_stdio(false);
	memset(cont,-1,sizeof cont);
	Fr(i,0,25) {
		Fr(j,0,26) counter(j, i);
	}
	int T, cas = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%s%d%d", str, &n, &k); k--;
		int lvl = n, ind;
		ll con = 0;
		for (int i = 0; str[i]; i++) {
			if (con+cont[str[i]-'A'][lvl] > k) {
				ind = i;
				lvl--;
				break;
			}
			con+=cont[str[i]-'A'][lvl];
		}
		int atual = str[ind]-'A';
		while (lvl >= 0) {
			Fr(i,0,size[atual]) {
				//printf("%lld %d %c %
				if (con+cont[adj[atual][i]-'A'][lvl] > k) {
					ind = i;
					lvl--;
					break;
				}
				con+=cont[adj[atual][i]-'A'][lvl];
			}
			atual = adj[atual][ind]-'A';
		}
		printf("Case %d: %c\n", cas++, atual+'A');
	}
	return 0;
}