#include <bits/stdc++.h>
using namespace std;

int size, pos;
char gb[35];
char res[35];

void rec(int ind, int k){
    if (ind > size) return;
    if (k == 0) {
        res[pos] = '\0';
        printf("%s\n", res);
        return;
    }
    
    char h = '<';
    for (int i = ind; i < size; i++) {
        if (h == gb[i]) continue;
        h = gb[i];
        res[pos] = gb[i];
        pos++;
        rec(i+1, k-1);
        pos--;
    }
    return;
}

int main(){
    int k;
    while(scanf("%s",gb)>0){
       scanf("%d",&k);
       size = strlen(gb);
       sort(gb,gb+size);
       pos = 0;
       rec(0,k);
    }
    return 0;
}