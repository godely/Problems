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

char str[150], str1[150];
int main() {
    int size;
    map<string, string> mapa;
    while (scanf("%s", str1) == 1 && str1[0] != '#') {
        strcpy(str,str1);
        size = strlen(str);
        rp(i,size) if (str[i] <= 'Z') str[i] += 32;
        sort(str, str+size);
        //printf("%s\n", str);
        if (mapa.find(string(str)) != mapa.end()) mapa[string(str)] = "-";
        else mapa[string(str)] = string(str1);
    }
    map<string, string>::iterator it;
    priority_queue<string, vector<string>, greater<string> > heap;
    for (it=mapa.begin(); it!=mapa.end(); it++) {
        if ((*it).S[0] != '-') heap.push((*it).S.c_str());
    }
    while (!heap.empty()) {
        printf("%s\n", heap.top().c_str());
        heap.pop();
    }
    return 0;

}
