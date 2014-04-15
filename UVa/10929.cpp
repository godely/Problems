#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define fr(a,b,c) for(int a=b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

char str[1111];
int main() {
    while (gets(str)) {
        int size = strlen(str);
        if (str[0]=='0' && size==1) break;
        int a=0;
        rp(i,size) {
            a*=10;
            a=(a+str[i]-'0')%11;
        }
        if (a) printf("%s is not a multiple of 11.\n", str);
        else printf("%s is a multiple of 11.\n", str);
    }
    return 0;
}
