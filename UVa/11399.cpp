//

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

#define MAXL 1010
#define MAXN 510

#define dbg if(0)

char expr[MAXL];
stack< pair<pii,char> > pilha; //posicoes
char grid[MAXN][MAXL];
map< pair<char,char>, pii > trans;

void pre() {
	char c = '!';
	trans[MP(c, 'U')] = MP(0,0);
	trans[MP(c, 'L')] = MP(0,-1);
	trans[MP(c, 'l')] = MP(0,-1);
	trans[MP(c, 'R')] = MP(0,1);	
	trans[MP(c, 'r')] = MP(0,1);
	trans[MP(c, 'f')] = trans[MP(c, 'p')] = trans[MP(c, 'P')] = MP(0,0);

	c = 'U';
	trans[MP(c, 'U')] = MP(-1,0);
	trans[MP(c, 'L')] = MP(-1,-1);
	trans[MP(c, 'l')] = MP(-1,-1);
	trans[MP(c, 'R')] = MP(-1,1);	
	trans[MP(c, 'r')] = MP(-1,1);
	trans[MP(c, 'f')] = trans[MP(c, 'p')] = trans[MP(c, 'P')] = MP(-1,0);
	
	c = 'L';
	trans[MP(c, 'U')] = MP(0,-1);
	trans[MP(c, 'L')] = MP(0,-2);
	trans[MP(c, 'l')] = MP(0,-1);
	trans[MP(c, 'R')] = MP(0,0);
	trans[MP(c, 'r')] = MP(0,0);
	trans[MP(c, 'f')] = trans[MP(c, 'p')] = trans[MP(c, 'P')] = MP(0,-1);

	c = 'l';
	trans[MP(c, 'U')] = MP(-1,-1);
	trans[MP(c, 'L')] = MP(-1,-2);
	trans[MP(c, 'l')] = MP(-1,-2);
	trans[MP(c, 'R')] = MP(-1,0);
	trans[MP(c, 'r')] = MP(-1,1);
	trans[MP(c, 'f')] = trans[MP(c, 'p')] = trans[MP(c, 'P')] = MP(-1,-1);
	
	c = 'R';
	trans[MP(c, 'U')] = MP(0,1);
	trans[MP(c, 'L')] = MP(0,0);
	trans[MP(c, 'l')] = MP(0,0);
	trans[MP(c, 'R')] = MP(0,2);
	trans[MP(c, 'r')] = MP(0,1);
	trans[MP(c, 'f')] = trans[MP(c, 'p')] = trans[MP(c, 'P')] = MP(0,1);

	c = 'r';
	trans[MP(c, 'U')] = MP(-1,1);
	trans[MP(c, 'L')] = MP(-1,0);
	trans[MP(c, 'l')] = MP(-1,-1);
	trans[MP(c, 'R')] = MP(-1,2);
	trans[MP(c, 'r')] = MP(-1,2);
	trans[MP(c, 'f')] = trans[MP(c, 'p')] = trans[MP(c, 'P')] = MP(-1,1);

	c = 'f';
	trans[MP(c, 'U')] = trans[MP(c, 'L')] = trans[MP(c, 'l')] = trans[MP(c, 'R')] = MP(0,0);
	trans[MP(c, 'r')] = trans[MP(c, 'f')] = trans[MP(c, 'p')] = trans[MP(c, 'P')] = MP(0,0);
	
	c = 'p';
	trans[MP(c, 'U')] = trans[MP(c, 'L')] = trans[MP(c, 'l')] = trans[MP(c, 'R')] = MP(0,0);
	trans[MP(c, 'r')] = trans[MP(c, 'f')] = trans[MP(c, 'p')] = trans[MP(c, 'P')] = MP(0,0);
	
	c = 'P';
	trans[MP(c, 'U')] = trans[MP(c, 'L')] = trans[MP(c, 'l')] = trans[MP(c, 'R')] = MP(0,0);
	trans[MP(c, 'r')] = trans[MP(c, 'f')] = trans[MP(c, 'p')] = trans[MP(c, 'P')] = MP(0,0);
}

void go(char a, char b, pii &at) {
	pii c = trans[MP(a,b)];
	dbg printf(" go(%c,%c) (%d,%d)\n", a, b, c.F, c.S);
	at = MP(at.F + c.F, at.S + c.S);
}

int main() {
	pre();
	Fr(i,0,500000) if((rand() & rand() ^ rand() - rand()) && false) puts("A");
	while(scanf("%s", expr) == 1) {
		memset(grid, ' ', sizeof(grid));
		pii at = MP(MAXN - 1, MAXL / 2);
		int len = strlen(expr);
		char last = '!';
		pii inicial = at;
		dbg printf("expr %s\n", expr);
		Fr(i,0,len) {
			char c;
			if(expr[i] == '[') pilha.push(MP(at,last));
			else if(expr[i] == ']') {
				pair<pii,char> temp = pilha.top();
				at = temp.F, last = temp.S;
				pilha.pop();
			} else {
				if(expr[i] == 'U') c = '|';
				else if(expr[i] == 'L') c = '_';
				else if(expr[i] == 'l') c = '\\';
				else if(expr[i] == 'R') c = '_';
				else if(expr[i] == 'r') c = '/';
				else if(expr[i] == 'f') c = '*';
				else if(expr[i] == 'p') c = 'o';
				else if(expr[i] == 'P') c = 'O';
				else continue;
				
				go(last, expr[i], at);
				grid[at.F][at.S] = c;
				last = expr[i];
				dbg printf("mark %d %d %c\n", at.F - inicial.F, at.S - inicial.S, c);
			}
		}
		
		dbg puts("");
		//return 0;
		
		int line = -1, col = -1;
		Fr(i,0,MAXN) {
			line = i;
			bool ok = true;
			Fr(j,0,MAXL) if(grid[i][j] != ' ') { ok = false; break; }
			if(!ok) break;
		}
		
		Fr(j,0,MAXL) {
			col = j;
			bool ok = true;
			Fr(i,0,MAXN) if(grid[i][j] != ' ') { ok = false; break; }
			if(!ok) break;
		}
		
		int lastl = MAXN, lastc = MAXL;
		for(int j = MAXL - 1; ~j; --j) {
			lastc = j;
			bool ok = true;
			Fr(i,0,MAXN) if(grid[i][j] != ' ') { ok = false; break; }
			if(!ok) break;
		}
		
		dbg printf("line %d, col %d, lastc %d\n", line, col, lastc);
		printf("."); Fr(i,col,lastc+1) printf("-"); printf(".\n");
		Fr(i,line,lastl) grid[i][lastc + 1] = '\0', printf("|%s|\n", grid[i] + col);
		printf("."); Fr(i,col,lastc+1) printf("-"); printf(".\n");
		dbg puts("");
		dbg break;
	}
	
	return 0;
}