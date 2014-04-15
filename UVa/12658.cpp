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
#define PB push_back
#define MP make_pair
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define prox(i) (((i)+1)%n)
#define ant(i) (((i)-1+n)%n)
#define dbg if(0)
#define F first
#define S second
#define isLet(i) (gb[i] >= 'a' && gb[i] <= 'z')
typedef pair<int,int> pii;

char g[10][1000];
int n;

int main() {
	scanf("%d", &n);
	rp(i,5) {
		scanf("%s", g[i]);
	}
	rp(i,n) {
		int pos = i<<2;
		if (g[0][pos] == '.') printf("1");
		else if (g[3][pos] == '*') printf("2");
		else printf("3");
	}
	puts("");
}