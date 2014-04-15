#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,vet[22],aux[22],aux2[22];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	scanf("%d",&n);
	printf("Lumberjacks:\n");
	for ( int i = 0 ; i < n ; i++ ){
		for ( int j = 0 ; j < 10 ; j++ ){
			scanf("%d",&vet[j]);
			aux[j] = aux2[j] = vet[j];
		}
		sort ( aux , aux+10 );
		sort ( aux2 , aux2+10 , cmp);
		bool teste = true,teste2 = true;
		for ( int j = 0 ; j < 10 ; j++ ){ 
			if ( aux[j] != vet[j] ){
				teste = false;
				break;
			}
		}
		for ( int j = 0 ; j < 10 ; j++ ){ 
			if ( aux2[j] != vet[j] ){
				teste2 = false;
				break;
			}
		}
		if ( teste || teste2 ) printf("Ordered\n");
		else printf("Unordered\n");
	}
	return 0;
}