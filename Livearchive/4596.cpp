#include <bits/stdc++.h>
 
using namespace std;
 
char str[200];
int main() {
    while (scanf("%s", str) == 1) {
        int size = strlen(str), q1 = 0, q2 = 0;
        for (int i = 0; i < size; i++) {
            if (str[i] == '0') {
                q1 ++;
                if (str[(i+1)%size] == '0') {
                    q2 ++;
                }
            }
        }
        double p1 = (double)q2/q1;
		double p2 = (double)q1/size;
		if (p1 > p2) printf("SHOOT\n");
		else if (p1 == p2) printf("EQUAL\n");
		else printf("ROTATE\n");
    }
    return 0;
}