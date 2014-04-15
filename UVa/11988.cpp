#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define cl(a,b) memset(a,b,sizeof(a))

using namespace std;

struct node {
    char t;
    node *next;

    node() {}
    node(char t) : t(t) {
        next=NULL;
    }
} head, *aux, *first, *last, *auxFirst;

char str[111111];

bool lols(char c) {
    return c=='[' || c==']';
}

int main() {
    while (gets(str)) {
        int size = strlen(str);
        int k;
        for (k = 0; k < size && (str[k] == '[' || str[k] == ']'); k++);
        //printf("%d\n", k);
        head.t = str[k];
        str[size] = '[';
        aux = &head;
        first = &head;
        aux->next = NULL;
        bool is = 1, cs = 0;
        fr(i,k+1,size+1) {
            if (lols(str[i]) && lols(str[i+1])) continue;
            if (str[i]=='[') {
                if (is) {
                    last = aux;
                    is = 0;
                } else {
                    aux->next = first;
                    first = auxFirst;
                }
                cs = 1;
            } else if (str[i]==']') {
                if (is) continue;
                aux->next = first;
                first = auxFirst;
                is = 1;
                cs = 0;
                aux = last;
            } else {
                if (cs) {
                    //printf("> %c\n", str[i]);
                    aux = new node(str[i]);
                    auxFirst = aux;
                    cs = 0;
                } else {
                    aux->next = new node(str[i]);
                    aux=aux->next;
                }
                //printf("%c", aux->next->t);
            }
        }
        aux = first;
        while (aux != 0) {
            printf("%c", aux->t);
            aux=aux->next;
        }
        printf("\n");
    }
    return 0;
}
