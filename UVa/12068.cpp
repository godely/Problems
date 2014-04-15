#include <cstdio>
#include <algorithm>
#include <cstring>
#define fr0(a,b) for(int a=0;a<b;a++)
#define fr1(a,b) for(int a=1;a<=b;a++)

using namespace std;

long long gcd(long long a, long long b) {
    if (!a || !b || a == b) return max(a, b);
    return gcd(a%b, b%a);
}

int main(){
    int t,n,cas=1;
    long long G, x[15], S;
    scanf("%d",&t);
    while(t--){
        S = 1;
        G = 1;
        scanf("%d",&n);
        fr0(i,n){
            scanf("%lld",&x[i]);
            G = gcd(S, x[i]);
            S = (S*x[i])/G;
        }
        long long val=0;
        fr0(i,n){
            val+=S/x[i];
        }
        printf("Case %d: %lld/%lld\n",cas++, S*n/gcd(S*n, val), val/gcd(S*n, val));
    }
    return 0;
}
