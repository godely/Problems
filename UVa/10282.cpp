#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <iostream>

using namespace std;

int main() {
    map<string, string> dic;
    char *pch, *pch2;
    char gb[200];
    while (gets(gb) && gb[0] != '\0') {
        pch = strtok(gb, " ");
        pch2 = strtok(NULL, " ");
        dic[string(pch2)] = string(pch);
    }
    while (gets(gb)) {
        if (dic.find(gb) != dic.end()) cout << dic[gb] << "\n";
        else printf("eh\n");
    }
    return 0;
}
