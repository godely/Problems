#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;

char str[111111];
int F[111111];
int _st[111111], _end[111111];

int main() {
    str[0]='0';
    gets(str+1);
    int size = strlen(str);
    int start = 1, end = 0, max = -1, temp = 0;
    stack<int> pilha;
    F[0]=0;
    for (int i = 1; i < size; i++) {
        F[i]=F[i-1];
        if (str[i]=='[') F[i]++;
        if (pilha.empty()) {
            pilha.push(i);
        } else {
           // printf("%d %d %c %c\n", F[i], F[pilha.top()-1], str[pilha.top()], str[i]);
            if (str[i]-str[pilha.top()] == 1 || str[i]-str[pilha.top()] == 2) {
                if (_st[pilha.top()-1] > 0) _st[i] = _st[pilha.top()-1];
                else _st[i] = pilha.top();
                if (F[i]-F[_st[i]-1] >= max) {
                    max=F[i]-F[_st[i]-1];
                    end=i;
                    start=_st[i];
                }
                pilha.pop();
            } else {
                pilha.push(i);
            }
        }
    }
    if (max==-1) printf("0");
    else {
        printf("%d\n", max);
        for(int i = start; i <= end; i++) printf("%c", str[i]);
    }
    printf("\n");
}
