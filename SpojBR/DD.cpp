#include <cstdio>
#include <cstring>

/* A e B são muito grandes, portanto eh inviavel calcular cada numero sequencialmente.
 * Ao inves disto, utilizamos uma funcao para calcular a resposta de 1 ateh A, e depois
 * subtraimos desta resposta o resultado da mesma funcao para 1 ateh B-1.
 * O digito '0' eh um caso especial que complica ainda mais a questao. Este eh um bom
 * exemplo de que questoes dificeis nem sempre significam muito codigo, mas sim muito raciocinio.
*/

using namespace std;

int a, b, c, d, e, resp[10];
int lol[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

void calc(){
    int j;
    for(j = 8; j >= 0; j--){
        if(a >= lol[j]){
            c = a/lol[j];
            d = a%lol[j];
            e = c%10;
            c /= 10;
            for(int i = 0; i < e; i++) resp[i] += lol[j]*(c+(i?1:0));
            resp[e] += lol[j]*(c-(e?0:1)) + d +1;
            for(int i = e+1; i < 10; i++) resp[i] += lol[j]*c;
        }
    }
}

void calc2(){
    int j;
    for(j = 8; j >= 0; j--){
        if(b >= lol[j]){
            c = b/lol[j];
            d = b%lol[j];
            e = c%10;
            c /= 10;
            for(int i = 0; i < e; i++) resp[i] -= lol[j]*(c+(i?1:0));
            resp[e] -= lol[j]*(c-(e?0:1)) + d +1;
            for(int i = e+1; i < 10; i++) resp[i] -= lol[j]*c;
        }
    }
}

int main (){
	scanf("%d %d", &b, &a);
	while(a){
	    memset(resp, 0, 40);
	    b--;
	    calc();
	    calc2();
	    printf("%d", resp[0]);
	    for(int i = 1 ; i < 10; i++) printf(" %d", resp[i]);
	    printf("\n");
	    scanf("%d %d", &b, &a);
	}
	return 1;
}