#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <iostream>
#include <list>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define fr(a,b,c) for( int a = b ; a < c ; a++ )
#define db(x) cerr << #x " == " << x << "\n";
#define _ << ", " <<

int n,m,xi,yi;
char mat[55][55];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void acha(){
    for ( int i = 0 ; i < n ; i++ ){
        for ( int j = 0 ; j < m ; j++ ){
            if ( mat[i][j] == 'P' ){
                xi=i;
                yi=j;
            }
        }
    }
}

bool check(int i,int j){

}

int bfs(int x,int y){
    //cout << x << " " << y << endl;
    if ( mat[x][y] == '#' || mat[x][y] == '-' ) return 0;
    int ans=0;
    int kk = mat[x][y] == 'G';
    mat[x][y]='-';
   // cout << "op" << kk << " " << mat[x][y] << endl ;
    for ( int i = 0 ; i < 4 ; i++ ){
        if ( mat[x+dx[i]][y+dy[i]] == 'T' ){
            return kk;
        }
    }
    for ( int i = 0 ; i < 4 ; i++ ){
        ans+=bfs(x+dx[i],y+dy[i]);
    }
    return ans+kk;
}

int main (){
	while(scanf("%d%d",&m,&n)>0){
	    for ( int i = 0 ; i < n ; i++ ) scanf("%s",mat[i]);
	    acha();
	    printf("%d\n",bfs(xi,yi));
	}
	return 0;
}
