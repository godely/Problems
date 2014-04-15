#include <cstdio>
#include <cstring>
#include <cmath>
#define PARTS 100000.0
#include <iostream>
#include <iomanip>

using namespace std;

int n;
long double a,b,ans,posx,posy,prex,prey,soma;

long double sqr(double x){ return x*x; }
long double dist(double xi,double yi,double xf,double yf){ return sqrt(sqr(xi-xf)+sqr(yi-yf)); }
long double valor_y(double a,double b,double x){ return b*sqrt(fabs(1.0-(sqr(x)/sqr(a)))); }

int main(){
	scanf("%d",&n);
	int cas=1;
	while(n--){
		cin >> b >> a;//scanf("%lf%lf",&b,&a);
		soma=a/PARTS;
		prex=ans=0.0;
		posx=soma;
		prey=b;
		for ( int i = 0 ; i < (int)PARTS ; i++ ){
			posy=valor_y(a,b,posx);
			ans+=dist(prex,prey,posx,posy);
			prex=posx;prey=posy;
			posx+=soma;
		}
		printf("Case %d: ",cas++);//%.6lf\n",cas++,4*ans);
		cout << fixed << setprecision(6) << 4*ans << endl;
	}
	return 0;
}
