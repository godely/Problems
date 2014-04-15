#include <stdio.h>
#define F(I,B,E) for(int I=B; I<E; I++)
main() {
  unsigned long long n,m,s=1,t=3;
  scanf("%I64d%I64d",&n,&m);
  while (n) {
    if (n&1)
      s=(s*t)%m;
    t=(t*t)%m;
    n/=2;
  }
  printf("%I64d",(s+m-1)%m);
  return 0;
}
