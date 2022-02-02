#include<stdio.h>
#include<math.h>
unsigned broj_cifara(unsigned n){
	unsigned brojac=0;
	if(n==0) return 1;
	while(n){
		brojac++;
		n /=10;
	}
	return brojac;
}

int rotacija(int n){
	int znak=1;
	if(n < 0) {n=-n; znak=-1;}
	unsigned bc=broj_cifara(n), dj=(unsigned)pow(10,bc-1), prva_cifra=n/dj , resto= n%dj;
	return znak*(resto*10 + prva_cifra);
}

int main(){
	int n;
	printf("Unesite novi broj: ");
	scanf("%i", &n);
	while(n){
	printf("Novi broj: %i\n", rotacija(n));
	printf("Unesite novi broj: ");
	scanf("%i", &n);
	}
}
