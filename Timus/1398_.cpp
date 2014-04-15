#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cassert>
#include <ctime>

#define Fr(a,b,c) for(int a = b; a < c; ++a)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define oo 0x3F3F3F3F

#define dbg if(0)

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long rash;

#define valid(n,m) (0 <= n && n < 8 && 0 <= m && m < 8)
#define MAXT 9

int incx[] = {1,  1, -1, -1};
int incy[] = {1, -1,  1, -1};

int pawnx[] = {1, 1};
int pawny[] = {1, -1};

bool mk[MAXT][MAXT][MAXT][MAXT][2];
int pd[MAXT][MAXT][MAXT][MAXT][2];
// (bishop.x, bishop.y, pawn.x, pawn.y, black turn?)
int rec(int x, int y, int z, int w, int turn) {
	dbg printf(" rec( bishop(%d,%d), pawn(%d,%d), turn %d)\n", x, y, z, w, turn);
	int &dp = pd[x][y][z][w][turn];
	if(mk[x][y][z][w][turn]) return dp;
	mk[x][y][z][w][turn] = true;

	int best = -1; //perdi
	if(!turn) { //white
		Fr(k,0,4) {
			int a = x, b = y;
			Fr(i,1,8) {
				a += incx[k], b += incy[k];
				if(!valid(a,b)) break;
				if(a == z && b == w) { //kill the pawn :P
					best = 1; //I win!
					i = 10, k = 10;
				}

				int r = - rec(a, b, z, w, 1);
				best = max(best, r);
			}
		}
	} else { //black
		Fr(k,0,2) {
			int a = z + pawnx[k], b = w + pawny[k];
			if(a == x && b == y) { //kill the bishop
				best = 1; //I win!
				break;
			}
		}

		bool killed = false, draw = false;
		if(z == 6) { //almost last line
			int a = z + 1, b = w;
			int i = abs(x - a), j = abs(y - b);
			if(i == j) killed = true; //I will killed in next turn ):
			else best = 1; //It's over, my friend!
		}

		if(x == z + 1 && y == w) draw = true, best = max(best, 0); //, puts(" It's a draw!!\n");
		if(best != 1 && !killed && !draw) //Nobody was killed 
			best = - rec(x, y, z + 1, w, 0);
	}

	dbg printf(" pd( bishop(%d,%d), pawn(%d,%d), turn %d) %d\n", x, y, z, w, turn, best);
	return pd[x][y][z][w][turn] = best;
}

char st[2][10];
int main() {
	memset(mk, false, sizeof(mk));
	memset(pd, -1, sizeof(pd));
	int a, b, c, d;
	scanf("%s%s", st[0], st[1]);
	
	a = 7 - (st[0][1] - '1');
	b = st[0][0] - 'a';
	c = 7 - (st[1][1] - '1');
	d = st[1][0] - 'a';
	
	int r = rec(a,b,c,d,0);
	
	if(r == 1) puts("WHITE");
	else if(r == 0) puts("DRAW");
	else puts("BLACK");
	
	return 0;
}