//...
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


int main (){
	int n, j, i;
	char s[100];
	scanf("%d", &n);
	i=0;
	while(n--){
		scanf("%s", s);
		if(!strcmp(s,"donate")){
			scanf("%d", &j);
			i+=j;
		}
		else printf("%d\n", i);
	}
	
	return 0;
}