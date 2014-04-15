#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

char str[100];
int main() {
    int N;
    map<string, int> mapa;
    priority_queue<string, vector<string>, greater<string> > heap;
    scanf("%d\n", &N);
    while (N--) {
        gets(str);
        int size = strlen(str);
        int i;
        for(i = 0; str[i] != ' ' && i < size; i++);
        str[i] = '\0';
        if (mapa[string(str)] == 0) heap.push(str);
        mapa[string(str)]++;
    }
    while (!heap.empty()) {
        printf("%s %d\n", heap.top().c_str(), mapa[heap.top()]);
        heap.pop();
    }
    return 0;
}
