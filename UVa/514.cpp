#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#define pii pair<int,int>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

int F[1111];

int main() {
    //freopen("out.txt", "w", stdout);
    bool KKK = 0;
    int N, a;
    stack<int> pilha;
    while (scanf("%d", &N) == 1 && N > 0) {
        while (scanf("%d", &a) == 1 && a > 0) {
            F[0] = a;
            fr(i,1,N) scanf("%d", &F[i]);

            while (!pilha.empty()) pilha.pop();
            pilha.push(1);
            int k = 0, t = 2;
            while (!pilha.empty()) {
                if (pilha.top() == F[k]) {
                    k++;
                    pilha.pop();
                    if (pilha.empty() && t <= N) pilha.push(t++);
                } else {
                    if (t <= N) pilha.push(t++);
                    else {
                        printf("No\n");
                        goto lol;
                    }
                }
            }
            printf("Yes\n");
            lol:;
        }
        printf("\n");
    }
    return 0;
}
