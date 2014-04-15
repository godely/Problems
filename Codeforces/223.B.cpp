#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define ifr(a,b,c) for(int a=b; a>=c; a--)
#define rp(a,b) fr(a,0,b)

using namespace std;

char s[211111], t[211111];
int l[211111], r[211111];

int pos[27][211111], size_[27], memo[27];

int main() {
    gets(s+1);
    gets(t+1);
    s[0]='0';
    t[0]='0';
    int size = strlen(s), sizeT = strlen(t);

    fr(i,1,sizeT) {
        pos[t[i]-'a'][size_[t[i]-'a']++] = i;
    }

    l[0]=0;
    fr(i,1,size) {
        l[i]=l[i-1];
        if (s[i] == t[l[i]+1]) l[i]++;
        //printf("%d ", l[i]);
    }
    //printf("\n");
    ifr(i,size-1,1) {
        r[i]=r[i+1];
        if (s[i] == t[sizeT-r[i]-1]) r[i]++;
    }
    //printf("\n");
    bool ok;
    fr(i,1,size) {
        int m = size_[s[i]-'a'];
        ok = 0;
        fr(j,memo[s[i]-'a'],m) {
            int p = pos[s[i]-'a'][j];
            if (p <= l[i-1]+1 && p >= sizeT-r[i+1]-1) {
                ok = 1;
                break;
            }
            memo[s[i]-'a']++;
        }
        if (!ok) break;
    }
    if (!ok) printf("No\n");
    else printf("Yes\n");
}
