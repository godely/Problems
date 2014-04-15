#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

char str1[111111], str2[111111];

int main() {
    while (scanf("%s%s", str1, str2) == 2) {
        int size = strlen(str2);
        int k = 0;
        for (int i = 0; i < size; i++) {
            if (str2[i]==str1[k]) k++;
        }
        if (k==strlen(str1)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
