#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define _ << ", " <<
#define db(x) //cout << #x " == " << x << endl

typedef long long ll;

int res,n;
int ori[20][20];
int tmp[30][30];

void go2() {
	int t = 0;
	//fr(i,1,n) { fr(j,1,n) printf("%d ", tmp[i][j]); printf("\n"); }
	
	fr(i,2,n) fr(j,1,n) {
		tmp[i][j] = tmp[i-2][j]^tmp[i-1][j-1]^tmp[i-1][j+1];
		
		if( tmp[i][j] < ori[i][j] ) return;
		if( tmp[i][j] != ori[i][j] ) t++;
	} 
	fr(i,1,n) if( tmp[n-2][i]^tmp[n-1][i-1]^tmp[n-1][i+1] ) return;
	
	//db(t); fr(i,1,n) { fr(j,1,n) printf("%d ", tmp[i][j]); printf("\n"); }
	fr(i,1,n) t += (tmp[1][i]!=ori[1][i]);
	res = min(t,res);
}

void go(int k) {
	if( k == n ) { go2(); return; }
	if( !ori[1][k] ) tmp[1][k] = 0, go(k+1);
	tmp[1][k] = 1, go(k+1);
}

bool read() {
	scanf("%d", &n);
	n++;
	fr(i,1,n) fr(j,1,n) scanf("%d", ori[i]+j);
	
	//fr(i,1,n) { fr(j,1,n) printf("%d ", ori[i][j]); printf("\n"); }
	memset(tmp,0,sizeof(tmp));
	res = 100000;
	go(1);
	
	static int caso = 1;
	printf("Case %d: ", caso++);
	
	if( res < 10000 ) cout << res << endl;
	else cout << -1 << endl;
	
	return true;
}

int main() {
	int t = -1;
	cin >> t;
	while( t-- && read() );
	return 0;
}