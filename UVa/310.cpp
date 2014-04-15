#include <bits/stdc++.h>
using namespace std;
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define mp make_pair
#define pb push_back

int h1[20], s1, h2[20], s2, inihash[20], inisize, fimhash, fimsize;
int mark[1<<16][20], passo = 0;

void lol(int str, int size, int gera, int gerasize, vector<pair<int,int> > &vec) {
	if (!size) {
		vec.pb(mp(gera,gerasize));
		return;
	}
	if (size <= s1 && str == h1[size]) lol(0, 0, gera<<1, gerasize+1, vec);
	if (size <= s2 && str == h2[size]) lol(0, 0, (gera<<1)+1, gerasize+1, vec);
	
	//printf("> %d %d %d\n", s2, (str>>(size-s2)), h2[s2]);
	if (size >= s1 && (str>>(size-s1)) == h1[s1]) lol(str-((str>>(size-s1))<<(size-s1)), size-s1, (gera<<1), gerasize+1, vec);
	if (size >= s2 && (str>>(size-s2)) == h2[s2]) lol(str-((str>>(size-s2))<<(size-s2)), size-s2, (gera<<1)+1, gerasize+1, vec);
}

bool bt(int str, int size) {
	if (mark[str][size] == passo) return 0;
	mark[str][size] = passo;
	//printf("%d %d\n", str, size);
	if(inisize >= size) fr(i,size,inisize+1) if (str == inihash[i]-(inihash[i-size]<<size)) return 1;
	
	bool ret = 0;
	if(s1 >= size) fr(i,size,s1+1) if (str == h1[i]-(h1[i-size]<<size)) ret |= bt(0,1);
	if(!ret && s2 >= size) fr(i,size,s2+1) if (str == h2[i]-(h2[i-size]<<size)) ret |= bt(1,1);
	
	if (!ret) {
		vector<pair<int,int> > vec;
		fr(i,1,size+1) {
			if (s1 >= i && (str>>(size-i)) == h1[s1]-(h1[s1-i]<<i)) {
				//printf("> %d %d\n", str-((str>>(size-i))<<(size-i)), size-i);
				lol(str-((str>>(size-i))<<(size-i)), size-i, 0, 1, vec);
			}
			if (s2 >= i && (str>>(size-i)) == h2[s2]-(h2[s2-i]<<i)) {
				lol(str-((str>>(size-i))<<(size-i)), size-i, 1, 1, vec);
			}
		}
		for (int i = 0; !ret && i < vec.size(); i++) ret |= bt(vec[i].first, vec[i].second);
	}	
	return ret;
}

char a[20], b[20], ini[20], fim[20];
int main() {
	h1[0] = h2[0] = inihash[0] = 0;
	while (scanf("%s", a) == 1) {
		passo++;
		scanf("%s%s%s", b, ini, fim);
		s1 = strlen(a);
		fr(i,1,s1+1) h1[i] = ((h1[i-1]<<1)+(a[i-1]=='b'));
		s2 = strlen(b);
		fr(i,1,s2+1) h2[i] = ((h2[i-1]<<1)+(b[i-1]=='b'));
		inisize = strlen(ini);
		fr(i,1,inisize+1) inihash[i] = ((inihash[i-1]<<1)+(ini[i-1]=='b'));
		fimsize = strlen(fim); fimhash = 0;
		fr(i,1,fimsize+1) fimhash = ((fimhash<<1)+(fim[i-1]=='b'));
		printf(bt(fimhash,fimsize)?"YES\n":"NO\n");
	}
	return 0;
}