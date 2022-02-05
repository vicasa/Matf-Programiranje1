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

int armstrong(int x){
	int n=broj_cifara(x), suma_stepena=0, pomoc=x;
	while(pomoc!=0){
		suma_stepena += pow(pomoc%10,n);
		pomoc /= 10;
	}
	return suma_stepena==x;
}

int main(){
	int n;
	scanf("%i", &n);
	for(int i=10; i<=n; i++) 
		if(armstrong(i)) printf("%i\n", i);
}
