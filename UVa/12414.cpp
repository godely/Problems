#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset(a,b,sizeof a)

char str[50], num[5000];
int nm[5000];

int len(int n) {
    if (n == 0) return 1;
    int cnt = 0;
    while (n > 0) n/=10, cnt++;
    return cnt;
}

bool test(int n) {
    int off = 0;
    for (int i = 0; str[i]; i++) {
        sprintf(num+off, "%d", str[i]-'A'+n);
        off += len(str[i]-'A'+n);
    }
    if (off < 3) return 0;
    rp(i,off) nm[i] = num[i]-'0';
    while (off > 3) {
        rp(j,off-1) nm[j] = (nm[j]+nm[j+1])%10;
        off--;
    }
    return nm[0] == 1 && nm[1] == 0 && nm[2] == 0;
}

int main() {
    while (scanf("%s", str) == 1) {
        fr(i,1,10001) {
            if (test(i)) {
                printf("%d\n", i);
                goto fim;
            }
        }
        printf(":(\n");
        fim:;
    }
    return 0;
}