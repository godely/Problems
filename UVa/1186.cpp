#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

char gb[300];
int size;
long long mod = (long long)1<<32;

bool isCons(int i) {
    if (i >= size) return false;
    return ((gb[i] >= 'A' && gb[i] <= 'Z' && gb[i] != 'A' && gb[i] != 'E' && gb[i] != 'I' && gb[i] != 'O' && gb[i] != 'U' && gb[i] != 'Y') || (gb[i] >= 'a' && gb[i] <= 'z' && gb[i] != 'a' && gb[i] != 'e' && gb[i] != 'i' && gb[i] != 'o' && gb[i] != 'u' && gb[i] != 'y'));
}

int main() {
    long long base[210];
    base[0] = 1;
    for (int i = 1; i <= 205; i++) {
        base[i] = (base[i-1]*137)%mod;
    }
    int T, k;
    bool F[15];
    long long int H[15];
    scanf("%d\n", &T);
    k = 0;
    bool isNot;
    memset(H, -1, sizeof H);
    memset(F, 1, sizeof F);
    while (T--) {
        isNot = false;
        F[k] = true;
        gets(gb);
        size = strlen(gb);
        H[k] = 0;
        for (int i = 0; i < size; i++) {
            if (isCons(i) && isCons(i+1) && isCons(i+2) && isCons(i+3) && isCons(i+4)) {
                F[k] = false;
                if (isCons(i+5)) {
                    isNot = true;
                }
            }
            H[k] = (H[k] + gb[i]*base[i])%mod;
            //printf("%lld ", H[k]);
        }
        //printf("\n");
        //printf("> %s %lld\n", gb, H[k]);

        if (!isNot) {
            int count = 0, count2 = 0;
            for (int i = 0; i < 10; i++) {
                if (i == k) continue;
                if (H[i] == H[k]) {
                    count2++;
                    if (count2 > 1) {
                        isNot = true;
                        break;
                    }
                }
                if (F[k] == false && F[i] == false) {
                    count++;
                    if (count > 2) {
                        isNot = true;
                        break;
                    }
                }
            }
        }

        if (isNot) printf("n\n");
        else printf("y\n");

        k = (k+1)%10;
    }
}
