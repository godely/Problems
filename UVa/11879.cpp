#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

char gb[111];
int main() {
    unsigned long long N;
    while (scanf("%s", gb) == 1 && gb[0] != '0') {
        int size = strlen(gb);
        int rest = 0;
        for (int i = 0; i < size; i++) {
            rest*=10;
            rest=(rest+gb[i]-'0')%17;
        }
        if (rest == 0)printf("1\n");
        else printf("0\n");
    }
    return 0;
}
