//stor

#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <iostream>
#define F first
#define S second
#define pii pair<int,int>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)

using namespace std;

char str[1111111];

int main() {
    scanf("%s", str);
    int size = strlen(str);
    rp(i,size/2) swap(str[i], str[size-1-i]);
    for (int i = size-1; i >= 0; i--) if (str[i] == '0') size--;
    if (size == 1) printf("0\n");
    else {

    }
    return 0;
}
