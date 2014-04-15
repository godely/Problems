#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define LL long long

using namespace std;

char c1[100], c2[100];
int a, b, k, t;

int top[100], vet[100], bot[100];
int main() {
    int N;
    scanf("%d", &N);
    rp(i,N) vet[i]=i, top[i]=bot[i]=-1;
    while (scanf("%s", c1) == 1 && c1[0] != 'q') {
        scanf("%d%s%d", &a, c2, &b);
        if (vet[a] == vet[b]) continue;
        if (bot[a] != -1) top[bot[a]] = -1;
        if (c1[0]=='m') {
            if (c2[1]=='n') { //move a onto b
                k = top[a];
                while (k != -1) t = top[k], vet[k] = k, top[k] = -1, bot[k] = -1, k = t;
                k = top[b];
                while (k != -1) t = top[k], vet[k] = k, top[k] = -1, bot[k] = -1, k = t;
                top[a] = -1;
                top[b] = a;
                vet[a] = vet[b];
                bot[a] = b;
            } else { //move a over b
                k = top[a];
                while (k != -1) t = top[k], vet[k] = k, top[k] = -1, bot[k] = -1, k = t;
                k = b;
                while (top[k] != -1) k = top[k];
                top[a] = -1;
                top[k] = a;
                vet[a] = vet[b];
                bot[a] = k;
            }
        } else {
            if (c2[1]=='n') { //pile a onto b
                k = a;
                while (k != -1) vet[k] = vet[b], k = top[k];
                k = top[b];
                while (k != -1) t = top[k], vet[k] = k, top[k] = -1, bot[k] = -1, k = t;
                top[b] = a;
                bot[a] = b;
            } else { //pile a over b
                k = a;
                while (k != -1) vet[k] = vet[b], k = top[k];
                k = b;
                while (top[k] != -1) k = top[k];
                top[k] = a;
                bot[a] = k;
            }
        }
        //rp(i,N) printf("%d ", top[i]);
        //printf("\n");
    }
    rp(i,N) {
        printf("%d:", i);
        if (vet[i]==i) {
            k = i;
            while (k != -1) printf(" %d", k), k = top[k];
        }
        printf("\n");
    }
    return 0;
}
