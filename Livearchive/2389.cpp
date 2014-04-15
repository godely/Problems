#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

int B[3000], S, base;

bool isPal(int x) {
    if (!x) return true;
    int ind = S++;
    B[ind] = x%base;

    if (!isPal(x/base)) return false;
    if (ind >= S/2) return true;

    return B[ind]==B[S-1-ind];
}

int pals[20], ps;
int main() {
    int N, p;
    while (scanf("%d", &N) == 1 && N > 0) {
        ps = 0;
        for (int i = 2; i <= 16; i++) {
            S = 0, base = i;
            if (isPal(N)) pals[ps++] = i;
        }
        if (!ps) printf("Number %d is not palindrom", N);
        else printf("Number %d is palindrom in basis", N);
        for (int i = 0; i < ps; i++) printf(" %d", pals[i]);
        printf("\n");
    }
}
