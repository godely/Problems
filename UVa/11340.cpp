#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

int pay[300], use[300], passo=0;
char st[11111];
int a, soma;
int main() {
    int N;
    scanf("%d\n", &N);
    while (N--) {
        int K;
        passo++;
        scanf("%d\n", &K);
        for (int i = 0; i < K; i++) {
            scanf("%s%d\n", st, &a);
            use[st[0]]=passo;
            pay[st[0]]=a;
        }
        scanf("%d\n", &K);
        soma=0;
        while (K--) {
            gets(st);
            a = strlen(st);
            rp(i,a) if(use[st[i]]==passo) soma+=pay[st[i]];
        }
        printf("%.2lf$\n", (double)soma/100.0);
    }
    return 0;
}
