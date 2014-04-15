#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#define rs str[0]

using namespace std;

int pred(char c) {
    if (c=='(') return 0;
    if (c=='*'||c=='/') return 2;
    else return 1;
}

char str[11];
int main() {
    int T;
    scanf("%d\n", &T);
    while (T--) {
        stack<char> pilha;
        while (gets(str) && rs != '\n' && rs != '\0') {
            if (rs=='(') pilha.push(rs);
            else if (rs==')') {
                while (pilha.top()!='(') printf("%c", pilha.top()), pilha.pop();
                pilha.pop();
            } else if (rs>='0'&&rs<='9') printf("%c", rs);
            else {
                if (pilha.empty()) pilha.push(rs);
                else {
                    while (!pilha.empty() && pred(pilha.top()) >= pred(rs)) printf("%c", pilha.top()), pilha.pop();
                    pilha.push(rs);
                }
            }
        }
        while (!pilha.empty()) printf("%c", pilha.top()), pilha.pop();
        printf("\n");
        if (T) printf("\n");
    }
    return 0;
}
