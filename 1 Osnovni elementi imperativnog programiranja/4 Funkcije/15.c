#include <stdio.h>
#include<math.h>

/*ukloni(x, p) vraca broj koji se dobija kada se iz dekadnog
zapisa broja x ukloni cifra sa pozicije p, gde se pozicije cifara broje od
cifre jedinica pocevsi od broja 1.
*/
unsigned ukloni(unsigned x, unsigned p){
  unsigned dj= pow(10,p-1);
  unsigned l=x/dj, d=x%dj;
  l=l/10;
  return l*dj+d;
}

/*pozicija_cifre(x, c) vraca najmanju poziciju cifre c u dekadnom
zapisu broju x (pozicija cifre u broju se definise kao i u prethodnoj funkciji)
ako se cifra c nalazi u zapisu broja x; u suprotnom vraca 0.*/ 
unsigned pozicija_cifre(unsigned x, unsigned c){
	if(c>9) return 0;
  int pozicija=0;
  if(x==0 && c==0) return 1;
    while(x>0){
      pozicija++;
      if (c == x%10) return pozicija;
      x = x/10;
    }
  return 0;
}

/*ukloni_cifru(x, c) vraca broj koji se dobija kada se iz dekadnog
zapisa broja x ukloni prvo pojavljivanje cifra c gledajuci zdesna
na levo ako se cifra c nalazi u zapisu broja x; u suprotnom vraca -1.*/
int ukloni_cifru(unsigned x, unsigned c){
  int pozicija=pozicija_cifre(x,c);
  if(pozicija==0) return -1;
  return ukloni(x,pozicija); 
}

int zapis(int x, int y){
  if(x<0) x=-x;
  if(y<0) y=-y;
  if(x<y){int temp=x; x=y; y=temp;} /*obezbedjujemo da x nema manje cifara od y*/
  else if(x==y) return 1;
  if(x==0 || y==0){ /*hendlujemo slucaj ako je bar jedan od brojeva 0, lako dati odgovor, nema potrebe za pozivom funkcije*/
    if(x==0 && y==0) return 1;
    else return 0;}
  int cifra;
  while(x>0){
      if(x==y) return 1; /*ubrzava algoritam*/
      cifra=x%10;
      y=ukloni_cifru(y, cifra);
      if(y==-1) return 0;
      x = x/10;
  }
}

int main(void) {
  int x, y;
  printf("Unesite dva cela broja: ");
  scanf("%i %i", &x, &y);
  if (zapis(x, y)) printf("Uslov je ispunjen.\n");
  else printf("Uslov nije ispunjen.\n");
  
  return 0;
}
