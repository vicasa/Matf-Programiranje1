#include <stdio.h>

unsigned max(int a, int b, int c, int d){
  unsigned m=a;
  if(b>m) m=b;
  if(c>m) m=c;
  if(d>m) m=d;
  return m;
}

void grafikon_v(int a, int b, int c, int d){
  if(a<1 || b<1 || c<1 || d<1) {printf("Greska: neispravan unos.\n"); return;}
  unsigned m=max(a, b, c, d);
  for(unsigned i=m; i>0; i--){
    if(i>a) printf(" ");
    else printf("*");
    if(i>b) printf(" ");
    else printf("*");
    if(i>c) printf(" ");
    else printf("*");
    if(i>d) printf(" ");
    else printf("*");
    printf("\n");
  }
}
int main() {
  int a, b, c, d;
  printf("Unesite brojeve: ");
  scanf("%i %i %i %i", &a, &b, &c, &d);
  grafikon_v(a, b, c, d);
}
