//stor
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

char str[1111111];
int vet[30];

struct st {
    int c, i;

    st(){}
    st(int c, int i):c(c), i(i){}

    bool operator<(const st &lhs) const {
        if (c != lhs.c) return c < lhs.c;
        return i > lhs.i;
    }

    bool operator>(const st &lhs) const {
        if (c != lhs.c) return c < lhs.c;
        return i < lhs.i;
    }
};

bool cmp1(st a, st b) {
    if (a.c != b.c) return a.c > b.c;
    return a.i < b.i;
}

bool cmp2(st a, st b) {
    return a.i < b.i;
}

char res1[30];
bool mark[30];
int main() {
    int T, N, size;
    scanf("%d", &T);
    priority_queue<st, vector<st>, greater<st> > fila1;
    priority_queue<st, vector<st>, less<st> > fila2;
    while (T--) {
        scanf("%d%s", &N, str);
        size = strlen(str);
        memset(vet,0,sizeof vet);
        rp(i,size-1) {
            vet[str[i]-'A']++;
        }
        while (!fila1.empty()) fila1.pop();
        while (!fila2.empty()) fila2.pop();
        rp(i,N) {
            mark[i]=0;
            fila1.push(st(vet[i],i));
            fila2.push(st(vet[i],i));
        }

        st aux[5];
        int k = 0;
        while (!fila1.empty()) {
            while (!fila1.empty() && mark[fila1.top().i]) fila1.pop();
            if (fila1.empty()) break;
            //printf("%c %c %c\n", aux[0].i+'A', aux[1].i+'A', aux[2].i+'A');
            aux[0] = fila1.top();
            fila1.pop();
            mark[aux[0].i] = 1;
            while (!fila1.empty() && mark[fila1.top().i]) fila1.pop();
            //printf("%c %c %c\n", aux[0].i+'A', aux[1].i+'A', aux[2].i+'A');
            //printf("\n");
            if (fila1.empty()) {
                res1[k++] = aux[0].i+'A';
                break;
            }
            aux[1] = fila1.top();
            fila1.pop();
            mark[aux[1].i] = 1;
            while (!fila2.empty() && mark[fila2.top().i]) fila2.pop();
            if (fila2.empty()) {
                sort(aux,aux+2,cmp2);
                res1[k++] = aux[0].i+'A';
                res1[k++] = aux[1].i+'A';
                break;
            }
            aux[2] = fila2.top();
            fila2.pop();
            mark[aux[2].i] = 1;

            sort(aux,aux+3,cmp1);
            if (aux[0].c == aux[1].c && aux[1].c == aux[2].c) {
                mark[aux[1].i] = 0;
                fila1.push(aux[1]);
                fila2.push(aux[1]);
                res1[k] = aux[0].i+'A';
                res1[N-1-k] = aux[2].i+'A';
            } else if (aux[0].c == aux[1].c || (aux[0].c != aux[1].c && aux[1].c != aux[2].c)) {
                mark[aux[2].i] = 0;
                fila1.push(aux[2]);
                fila2.push(aux[2]);
                sort(aux,aux+2,cmp2);
                res1[k] = aux[0].i+'A';
                res1[N-1-k] = aux[1].i+'A';
            } else {
                //printf("xD\n");
                sort(aux,aux+3,cmp2);
                if (aux[0].c == aux[1].c || aux[1].c == aux[2].c) {
                    mark[aux[1].i] = 0;
                    fila1.push(aux[1]);
                    fila2.push(aux[1]);
                    aux[1] = aux[2];
                } else {
                    mark[aux[2].i] = 0;
                    fila1.push(aux[2]);
                    fila2.push(aux[2]);
                }
                res1[k] = aux[0].i+'A';
                res1[N-1-k] = aux[1].i+'A';
            }
            k++;
        }
        printf("%c", res1[0]);
        for (int i = 1; i < N; i++) {
            printf(" %c", res1[i]);
        }
        printf("\n");
        printf("%d", vet[res1[0]-'A']);
        for (int i = 1; i < N; i++) {
            printf(" %d", vet[res1[i]-'A']);
        }
        printf("\n");
    }
    return 0;
}
