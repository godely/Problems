#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define cl(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define LL long long

using namespace std;

int A[1111111], B[1111111];

LL unite(int ini, int fim) {
    int meio = (ini+fim)/2;
    int k = 0;
    int i = ini, j = meio+1;
    LL invertions = 0;
    for(; i <= meio && j <= fim;) {
        if (A[i] > A[j]) {
            B[k++] = A[j];
            invertions += (meio-i+1);
            j++;
        } else {
            B[k++] = A[i];
            i++;
        }
    }
    for (; i <= meio; i++) B[k++] = A[i];
    for (; j <= meio; j++) B[k++] = A[j];
    for (i = 0; i < k; i++) A[ini+i] = B[i];
    return invertions;
}

LL merge(int ini, int fim) {
    LL res = 0;
    if (ini != fim) {
        res += merge(ini,(ini+fim)/2);
        res += merge((ini+fim)/2+1,fim);
        res += unite(ini,fim);
    }
    return res;
}

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        rp(i,N) scanf("%d", &A[i]);
        printf("%lld\n", merge(0,N-1));
    }
    return 0;
}
