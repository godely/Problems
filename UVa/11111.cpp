#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <cstring>
#define fr(a,b,c) for(int a=b; a<c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define empty() size==0
#define top() stack[size-1]
#define push(i) stack[size++] = i
#define pop() size--
#define empty2() size2==0
#define top2() stack2[size2-1]
#define push2(i) stack2[size2++] = i
#define pop2() size2--

using namespace std;

char str[111111];
int k;
int godely() {
    for (; str[k] == ' '; k++);
    if (str[k] == '\0') return 0;
    int num = 0;
    int l = 1;
    if (str[k] == '-') l = -1, k++;
    for (; str[k] != ' ' && str[k] != '\0'; k++) num*=10, num+=(str[k]-'0');
    num*=l;
    return num;
}

int stack[111111], size;
int stack2[111111], size2;
int a, len;
bool ok;
char *pt;
int main() {
    while (gets(str)) {
        k = size = size2 = 0;
        ok = 1;
        while ((a = godely())!=0) {
            if (ok) {
                //printf("%d\n", a);
                if (empty()) {
                    if (a < 0) push(-a), push2(0);
                    else ok = 0;
                } else {
                    if (a < 0) {
                        a=-a;
                        if (top() <= a) ok = 0;
                        else {
                            top2()+=a;
                            push(a), push2(0);
                        }
                    } else {
                        if (top() != a) ok = 0;
                        else {
                            if (top2() >= a) ok = 0;
                            pop(), pop2();
                        }
                    }
                }
            }
        };
        if (!empty()) ok = 0;
        if (ok) printf(":-) Matrioshka!\n");
        else printf(":-( Try again.\n");
    }
    return 0;
}
