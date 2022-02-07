#include<stdio.h>

int prestupna(int godina){
	return godina%4==0 && (godina%100!=0 || godina%400==0);
}

int broj_dana(int mesec, int godina){
	switch(mesec){
	case 4:
	case 6:
	case 9:
	case 11:
	return 30;
	case 2:
	if(prestupna(godina)) return 29;
	return 28;
	default: return 31;
	}
}

int ispravan(int dan, int mesec, int godina){
	if(godina==0) return 0;
	if(mesec<1 || mesec>12) return 0;
	if(dan<1 || dan>broj_dana(mesec, godina)) return 0;
	return 1;
}

void sledeci_dan(int dan, int mesec, int godina){
	if(ispravan(dan, mesec, godina)==0) {
		printf("Neispravan unos!\n");
		return;
	}
	
	printf("Datum sledeceg dana je: ");
	
	if(dan< broj_dana(mesec, godina)){
		printf("%i.%i.%i.\n", dan+1, mesec, godina);
		return;
	}
	if(mesec<12){
		printf("%i.%i.%i.\n", 1, mesec+1, godina);
		return;
	}
	printf("%i.%i.%i.\n", 1, 1, godina+1);
}

int main(){
	int dan, mesec, godina;
	printf("Unesite datum: ");
	scanf("%i.%i.%i.", &dan, &mesec, &godina);
	sledeci_dan(dan, mesec, godina);
}
