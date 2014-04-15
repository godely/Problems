#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#define U unsigned long long

using namespace std;

char gb[30], res[30];
U N, fat[20];
int size;

void solve(int ind, U rest) {
    if (ind == size) {
        res[ind] = '\0';
        printf("%s\n", res);
        return;
    }
    int len = strlen(gb+ind);
    sort(gb, gb+size);
    int p=0;
    while (fat[len-1] <= rest) p++,rest-=fat[len-1];

    res[ind] = gb[p];
    gb[p] = '~';

    solve(ind+1, rest);
}

int main() {
    fat[0] = fat[1] = 1;
    for (int i = 2; i <= 20; i++) fat[i]=fat[i-1]*i;
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s%llu", gb, &N);
        size = strlen(gb);
        solve(0, N);
    }
}
