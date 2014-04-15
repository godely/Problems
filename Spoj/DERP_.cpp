#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define fr(a,b,c) for( int a = b ; a < c ; ++a )
#define db(x) cerr << #x " == " << x << "\n"
#define _ << ", " <<

using namespace std;

int d[8][3]={
{ 1, 1, 1},
{-1,-1,-1},
{ 1, 1,-1},
{-1,-1, 1},
{ 1,-1, 1},
{-1, 1,-1},
{ 1,-1,-1},
{-1, 1, 1}};
long long s[8], sum, n, x, y, z;
int main(){
	scanf("%d", &n);
	while(n){
		memset(s,0xbf,sizeof s);
		fr(i,0,n){
			scanf("%d%d%d", &x, &y, &z);
			fr(j,0,8){
				sum=d[j][0]*x+d[j][1]*y+d[j][2]*z;
				s[j]=s[j]>sum?s[j]:sum;
			}
		}
		sum=0;
		for(int j=0;j<8;j+=2)sum=sum>(s[j]+s[j+1])?sum:(s[j]+s[j+1]);
		printf("%lld\n", sum);
		scanf("%d", &n);
	}

	return 0;
}
