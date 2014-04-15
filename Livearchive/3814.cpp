#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

char gb1[500], gb2[500];
int p[500], n1[500], n2[500], s1, s2, sp;

bool pMaiorIgualS1() {
    if (sp != s1) return sp > s1;
    for (int i = 0; i < sp; i++) if (p[i] != n1[i]) return p[i] > n1[i];
    return 1;
}

bool pMaiorS2() {
    if (sp != s2) return sp > s2;
    for (int i = 0; i < sp; i++) if (p[i] != n2[i]) return p[i] > n2[i];
    return 0;
}

int bt() {
    if (pMaiorS2()) return 0;
    for (int i = 0; i < sp; i++) {
        //printf("%d", p[i]);
    }
    //printf("\n");
    if (pMaiorIgualS1()) {
        //printf("    >\n");
        return 1;
    }

    int res=0;
    bool pode;
    for (int i = 1; i <= 9; i++) {
        pode=0;
        if (i<=2||i==5) pode=1;
        else if (i==3||i==6||i==9) {
            int sum=i;
            int k=(i==9)?i:3;
            for (int j = 0; j < sp; j++) sum+=p[j];
            if (sum%k==0) pode=1;
        } else {
            int sum=0;
            for (int j = 0; j < sp; j++) {
                sum*=10;
                sum=(sum+p[j])%i;
            }
            sum=(sum*10)+i;
            //printf(">%d %d %d %d\n", sum, i, sum%i, pode);
            if (sum%i==0) pode=1;
        }
        if (pode) {
            p[sp++]=i;
            res+=bt();
            sp--;
        }
    }
    return res;
}

int main() {
    int T,cas=1;
    scanf("%d", &T);
    while (T--) {
        scanf("%s%s", gb1, gb2);
        s1 = strlen(gb1);
        s2 = strlen(gb2);
        for (int i = 0; i < s1; i++) n1[i]=gb1[i]-'0';
        for (int i = 0; i < s2; i++) n2[i]=gb2[i]-'0';
        sp = 0;
        printf("Case %d: %d\n", cas++, bt());
    }
}
