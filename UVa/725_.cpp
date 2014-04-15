#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>
 
/*#define db(a) cout << #a << " = " << a << endl
#define db2(a, b) cout << #a << " = " << a << " "<< #b << " = " << b << endl
#define foreach(it, l) for(typeof(l.begin()) it = l.begin(); it != l.end(); it++)*/
 
using namespace std;
bool digits[10];
int last;
 
bool valid(int numerador, int denominador) {
    if (numerador > 99999) return false;
    memset(digits, true, sizeof digits);
    if (numerador / 10000 == 0) digits[0] = false;
    while (numerador > 0) {
        last = numerador % 10;
        if (digits[last]) digits[last] = false;
        else return false;
        numerador /= 10;
    }
    if (denominador / 10000 == 0)
        if (digits[0]) digits[0] = false;
        else return false;
    while (denominador > 0) {
        last = denominador % 10;
        if (digits[last]) digits[last] = false;
        else return false;
        denominador /= 10;
    }
    return true;
}
 
int main() {
    int N, num;
    bool ok;
    //clock_t now = clock();
    scanf("%d", &N);
    if (N != 0) {
        while (true) {
            ok = false;
            for (int f = 0; f < 10; f++) {
                num = f;
                for (int g = 0; g < 10; g++) {
                    if (g == f) continue;
                    num = num * 10 + g;
                    for (int h = 0; h < 10; h++) {
                        if (h == g || h == f) continue;
                        num = num * 10 + h;
                        for (int i = 0; i < 10; i++) {
                            if (i == h || i == g || i == f) continue;
                            num = num * 10 + i;
                            for (int j = 0; j < 10; j++) {
                                if (j == i || j == h || j == g || j == f) continue;
                                num = num * 10 + j;
                                //db(num);
                                int numerator = num * N;
                                if (valid(numerator, num)) {
                                    ok = true;
                                    //db(numerator % num);
                                    if (numerator / 10000 == 0) {
                                        if (num / 10000 == 0) {
                                            //db2(num, num / 10000);
                                            printf("0%d / 0%d = %d\n", numerator, num, N);
                                        } else
                                            printf("0%d / %d = %d\n", numerator, num, N);
                                    } else {
                                        if (num / 10000 == 0) {
                                            //db2(num,num / 10000);
                                            printf("%d / 0%d = %d\n", numerator, num, N);
                                        } else
                                            printf("%d / %d = %d\n", numerator, num, N);
                                    }
                                }
                                num -= j;
                                num /= 10;
                            }
                            num -= i;
                            num /= 10;
                        }
                        num -= h;
                        num /= 10;
                    }
                    num -= g;
                    num /= 10;
                }
            }
            int temp = N;
            scanf("%d", &N);
            if (!ok)
                if(N != 0)
                printf("There are no solutions for %d.\n\n", temp);
                else
                printf("There are no solutions for %d.\n", temp);
            else printf("\n");
            if(N == 0) break;
        }
    }
    //printf("el tiempo para todo fue: %.3fs", (clock() - now) * 1.0 / (CLOCKS_PER_SEC) );
    return 0;
}