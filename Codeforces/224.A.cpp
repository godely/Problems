#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    int S1, S2, S3;
    scanf("%d%d%d", &S1, &S2, &S3);
    int c = sqrt(S2*S3/S1);
    int a = S2/c;
    int b = S3/c;
    printf("%d\n", 4*(a+b+c));
}
