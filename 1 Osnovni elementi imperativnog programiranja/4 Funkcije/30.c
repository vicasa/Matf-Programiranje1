#include<stdio.h>

void iscrtaj_stubic(unsigned y){
	for(int i=1; i<=y;i++) printf("*");
	printf("\n");
	return;
}

void grafikon_h(int a, int b, int c, int d){
	if(a<1 || b<1 || c<1 || d<1) {printf("Greska: neispravan unos.\n"); return;}
	iscrtaj_stubic(a);
	iscrtaj_stubic(b);
	iscrtaj_stubic(c);
	iscrtaj_stubic(d);
	return;
}

int main() {
  int a, b, c, d;
  printf("Unesite brojeve: ");
  scanf("%i %i %i %i", &a, &b, &c, &d);
  grafikon_h(a, b, c, d);
}
