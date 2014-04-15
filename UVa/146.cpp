#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char str[500];
int main() {
    while (gets(str) && str[0] != '#') {
        if (!next_permutation(str,str+strlen(str))) printf("No Successor\n");
        else printf("%s\n", str);
    }
    return 0;
}
