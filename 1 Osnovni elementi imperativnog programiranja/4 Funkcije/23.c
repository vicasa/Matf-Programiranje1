#include<stdio.h>

char vrati0_25(int m){
	while(m<0) m+=26;
	while(m>25) m-=26;
	return m;
	
}

char sifra(char c, int k){
	if(c<65) return c;
	if(c<=90) return 65+vrati0_25(c-65-k);
	if(c<97) return c;
	if(c<=122) return 97+vrati0_25(c-97-k);
	return c;
}

int main(){
	int k;
	char c;
	scanf("%i%c", &k, &c); /* %c guta enter koji unesemo nakon broja*/
	
	while(scanf("%c", &c)!=-1) printf("%c", sifra(c,k));

	printf("\n");
}
