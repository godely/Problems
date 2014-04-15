#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back
#define inf 0x3f3f3f3f
using namespace std;
 
char T[400010], P[200010];
int b[200010],n,m;
void prep() {
        int i=0,j=-1; b[0]=-1;
        while(i<m) {
                while(j>=0&&P[i]!=P[j])j=b[j];
                ++i;++j;
                b[i]=j;
        }
}
 
bool search() {
        int i=0,j=0;
        while(i<n) {
                while(j>=0&&T[i]!=P[j])j=b[j];
                ++i; ++j;
                if(j==m && i > j && i < n) return 1;
        }
        return 0;
}
 
int main() {
	int tc;
	scanf("%d", &tc);
	while(tc--) {
		scanf("%s", T);
		m = strlen(T);
		n = 2*m;
		fr(i,0,m) P[i] = T[i];
		P[m] = '\0';
		reverse(P,P+m);
		bool pal = !strcmp(P,T);
		fr(i,0,m) T[i+m] = T[i];
		T[n] = '\0';
		prep();
		if(search()) {
			printf("alindrome\n");
		} else if(pal) {
			printf("palindrome\n");
		} else printf("simple\n");
	}
	return 0;
}