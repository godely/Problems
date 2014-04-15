#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>

using namespace std;

int alfa[] = {500, 508, 56, 786, 440, 417, 409, 372, 68, 92, 369, 280, 468, 85, 476, 306, 484, 497, 428, 134, 348, 325, 853, 513, 356, 248};

map<int, int> isNumber;
char gb[2222222];

int main() {
    for (int i = 0; i < 26; i++) {
        isNumber[alfa[i]] = i+1;
    }
    int T, size, cas=1, hash;
    scanf("%d\n", &T);
    while (T--) {
        gets(gb);
        size = strlen(gb);
        printf("Phrase %d: ", cas++);
        for (int i = 0; i < size; i++) {
            if (gb[i] < '0' || gb[i] > '9') printf("%c", gb[i]);
            else {
                if (gb[i] == '0') printf(" ");
                else {
                    hash=0;
                    for (; i < size; i++) {
                        hash|=(1<<(9-(gb[i]-'0')));
                        //printf("%d %d\n", hash, i);
                        if (isNumber[hash] > 0) break;
                    }
                    printf("%c", isNumber[hash]-1+'A');
                }
            }
        }
        printf("\n");
    }
}
