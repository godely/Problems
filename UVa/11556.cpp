#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <iostream>
#include <list>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define fr(a,b,c) for( int a = b ; a < c ; a++ )
#define db(x) cerr << #x " == " << x << "\n";
#define _ << ", " <<


int main (){
    unsigned long long lol[52];
    lol[0] = 1;
    for (int i = 1; i <= 50; i++) {
        lol[i] = lol[i-1] + (1ULL<<i);
    }
	unsigned long long x, y;
    while(scanf("%lld %lld", &x, &y)==2){
        printf("%s\n", (x<=lol[y])?"yes":"no");
    }
	return 0;
}
