#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

const int lim = 1<<28;
bool lol[lim];

int main() {
    printf("xD\n");
    for (int i = 1; i < 34000; i++) {
        for (int j = 1; j < 34000; j++) {
            if (i/2 + j + i*j < lim) lol[i/2 + j + i*j] = 1;
            //if ((i+1)/2 + j + i*j < lim) lol[(i+1)/2 + j + i*j] = 1;
        }
        //printf("%d\n", i);
    }
    printf("Vai comecar:\n");
    for (int i = 1; i < lim; i++) if (!lol[i]) printf("%d ", i);
    return 0;
}
