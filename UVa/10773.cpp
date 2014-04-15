#include <bits/stdc++.h>
using namespace std;
#define cl(a,b) memset((a),(b), sizeof(a))
#define db(x) cerr << #x " == " << x << "\n"
#define _ << ", " <<
#define fr(a,b,c) for( int a = b ; a < c ; a++ )
#define rp(a,c) fr(a,0,c)

int main(){
	int t;
    double d, v, u;
    scanf("%d", &t);
    
    for(int i=1;i<=t;++i){
    scanf("%lf%lf%lf", &d, &v, &u);
    	if(!(v==0||u<=v)){
			double a = d/u;
			double b = d/sqrt(u*u-v*v);
	    	double c = fabs(a-b);
	    	printf("Case %d: %.3lf\n", i, c);
    	}else printf("Case %d: can't determine\n", i);
    }
	
    return 0;
}