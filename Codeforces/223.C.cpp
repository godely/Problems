#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define fr(a,b,c) for(int a=b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mod 1000000007

using namespace std;

int N;

struct matriz {
    long long mat[2222];

    matriz() {
        //rp(i,N) rp(j,N) mat[i][j]=0;
    }

    matriz operator*(const matriz &lhs) const {
        matriz ret;// = matriz();
        rp(i,N) {
            ret.mat[i]=0;
            fr(k,0,i+1) {
                ret.mat[i]=(ret.mat[i] + mat[i-k]*lhs.mat[k])%mod;
            }
        }
        return ret;
    }
} aux, ret, vet;

int main() {
    int K;
    scanf("%d%d", &N, &K);
    rp(i,N) scanf("%I64d", &vet.mat[i]);
    if (K == 0) {
        printf("%I64d", vet.mat[0]);
        fr(i,1,N) printf(" %I64d", vet.mat[i]);
    } else {
        rp(i,N) ret.mat[i]=aux.mat[i]=1;

        K--;
        for(; K > 0; K>>=1, aux=aux*aux) if (K&1) ret=ret*aux;
        //printf("\n");
        ret=ret*vet;
        printf("%I64d", ret.mat[0]);
        fr(i,1,N) printf(" %I64d", ret.mat[i]);
        printf("\n");
    }
    return 0;
}
