#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char grid[20][20], touch[20][20];
int N;

int srd(int a, int b) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (a+i >= 0 && b+j >= 0 && a+i < N && b+j < N) count += grid[a+i][b+j]=='*';
        }
    }
    return count;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        bool death=0;
        for (int i = 0; i < N; i++) scanf("%s", grid[i]);
        for (int i = 0; i < N; i++) {
            scanf("%s", touch[i]);
            for (int j = 0; j < N; j++) if (touch[i][j]=='x' && grid[i][j] == '*') death=1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '*') printf("%c", death?'*':'.');
                else if (touch[i][j] == '.') printf(".");
                else printf("%d", srd(i,j));
            }
            printf("\n");
        }
        if (T) printf("\n");
    }
}
