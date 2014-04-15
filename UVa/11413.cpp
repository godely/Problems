#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int n, m, vet[1111];

int teste(int x) {
    int k = 1, temp = 0;
    //printf("> %d\n", x);
    for (int i = 0; i < n; i++) {
        if (vet[i] > x) return false;
        //printf("1. %d %d\n", temp, k);
        if (temp+vet[i] > x) temp=vet[i], k++;
        else temp+=vet[i];
        //printf("2. %d %d\n\n", temp, k);
    }
    return k<=m;
}

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) scanf("%d", &vet[i]);
        int ini = 1, fim = 1000000000, meio;
        while (ini != fim) {
            meio = (ini+fim)/2;
            if (teste(meio)) fim=meio;
            else ini=meio+1;
        }
        printf("%d\n", ini);
    }
}
