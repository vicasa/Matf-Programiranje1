#include<stdio.h>

unsigned zbir_cifara(unsigned n){
	unsigned zbir=0;
	while(n){
		zbir += n%10;
		n /=10;
	}
	return zbir;
}

int srecan(int n){
	if(n<0) n *=-1;
	while(n>=10) n=zbir_cifara(n);
	return n==1;
}

int main(){
	unsigned n;
	scanf("%u", &n);
	for(unsigned i=1; i<=n; i++){
		if(srecan(i)) printf("%u ", i);
	}
	printf("\n");
}
