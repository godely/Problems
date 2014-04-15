#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <utility>
#include <stack>

using namespace std;

#define tambloco 1000

int valores[1030005], val[1300], efeito[1300][2],sai;

int main (){
	#ifdef INTERNO
		freopen("in", "r", stdin);
	#endif
	int t,n, m, a, b, at, fim, bloco,old;
	char tipo[5], ent[52];
	scanf("%d", &t);
	int caso = 0, qq;
	while(t--){
		printf("Case %d:\n", ++caso);
	    memset(val, 0, sizeof(val));
	    memset(efeito, 0, sizeof(efeito));
	    n = qq = 0;
	    scanf("%d", &m);
	    while(m--){
			scanf("%d %s", &a, ent);
			for(int i = 0; i < a; ++i){
				for(int j = 0; ent[j]; ++j){
					valores[n++] = ent[j]-'0';
				}
			}
	    }
	    for(int i = 0,j = 0; i < n; ++j){
	    	int soma = 0;
			for(int k = 0; k < tambloco; ++k,++i){
				soma += valores[i];
			}
			val[j] = soma;
	    }
	    scanf("%d", &m);
	    for(int i = 0; i < m; ++i){
	        scanf("%s %d %d", tipo, &a, &b);
	        if(tipo[0] != 'S'){
	        	int x = tipo[0] == 'F';
	        	if(tipo[0] == 'I') x = 2;
	            bloco = a/tambloco;
	            at = a - a%tambloco;
	            fim = min(at+tambloco, n);
	            while(at < fim){
	            	old = valores[at];
	            	if(x < 2){
	            		if(at < a || at > b){
							if(efeito[bloco][0]) valores[at] = efeito[bloco][0]-1;
							if(efeito[bloco][1]) valores[at] = 1-valores[at];
	            		}
	            		else valores[at] = x;
					}
	            	else{
	            		valores[at] = efeito[bloco][0] ? efeito[bloco][0]-1 : valores[at];
	            		if((efeito[bloco][1]^(at >= a && at <= b))&1) valores[at] = 1-valores[at];
	            	}
	            	val[bloco] += (valores[at]-old);
                    ++at;
	            }
	            efeito[bloco][0] = efeito[bloco][1] = 0;
	            fim = b/tambloco;
	            while(++bloco < fim){
	            	if(x < 2){
						efeito[bloco][0] = x+1;
						efeito[bloco][1] = 0;
	            	}
	            	else
						efeito[bloco][1] ^= 1;
	            }
	            if(bloco > fim) continue;
	            at = fim*tambloco;
	            fim = min(at+tambloco, n);
	            while(at < fim){
	            	old = valores[at];
	            	if(x < 2){
	            		if(at > b){
							if(efeito[bloco][0]) valores[at] = efeito[bloco][0]-1;
							if(efeito[bloco][1]) valores[at] = 1-valores[at];
	            		}
	            		else valores[at] = x;
					}
	            	else{
	            		valores[at] = efeito[bloco][0] ? efeito[bloco][0]-1 : valores[at];
	            		if(((efeito[bloco][1]^(at <= b))&1)) valores[at] = 1-valores[at];
	            	}
	            	val[bloco] += (valores[at]-old);
                    ++at;
	            }
	            efeito[bloco][0] = efeito[bloco][1] =0;
	        }
	        else{
	            sai = 0;
	            bloco = a/tambloco;
	            fim = min(a - a%tambloco + tambloco, b+1);
	            while(a < fim){
	            	int aux = valores[a];
	            	if(efeito[bloco][0]) aux = efeito[bloco][0]-1;
	            	if(efeito[bloco][1]) aux = 1-aux;
                    sai += aux;
                    ++a;
	            }
	            fim = b/tambloco;
	            while(++bloco < fim){
	            	int aux = val[bloco];
                    if(efeito[bloco][0]) aux = tambloco*(efeito[bloco][0]-1);
                    if(efeito[bloco][1]) aux = tambloco-aux;
                    sai += aux;
	            }
	            at = fim*tambloco;
	            if(a <= b)
	            while(at <= b){
                    int aux = valores[at];
	            	if(efeito[bloco][0]) aux = efeito[bloco][0]-1;
	            	if(efeito[bloco][1]) aux = 1-aux;
                    sai += aux;
                    ++at;
	            }
	            printf("Q%d: %d\n", ++qq, sai);
	        }
	    }
	}
	return 0;
}