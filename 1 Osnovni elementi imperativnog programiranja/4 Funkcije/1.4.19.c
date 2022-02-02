#include<stdio.h>

unsigned zbir_cifara(unsigned n){
	unsigned zbir=0;
	while(n){
		zbir += n%10;
		n /=10;
	}
	return zbir;
}

int srecan(unsigned n){
	while(n>=10) n=zbir_cifara(n);
	return n==1;
}

int main(){
	unsigned n;
	scanf("%u", &n);
	printf("1 ");
	for(unsigned i=2; i<=n; i++){
		if(srecan(i)) printf("%u ", i);
	}
	printf("\n");
}
