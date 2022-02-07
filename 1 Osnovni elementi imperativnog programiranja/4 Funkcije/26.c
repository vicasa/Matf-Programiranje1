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

int od_nove_godine(int dan, int mesec, int godina){
	int rez=0;
	if(ispravan(dan, mesec, godina)==0) return -1;
	for (int i=1; i<mesec; i++){
		rez += broj_dana(i,godina);
	}
	return rez+dan-1;
}

int main(){
	int dan, mesec, godina, rez;
	printf("Unesite datum: ");
	scanf("%i.%i.%i.", &dan, &mesec, &godina);
	rez=od_nove_godine(dan, mesec, godina);
	if (rez==-1) printf("Neispravan unos!\n");
	else printf("Broj dana od Nove godine je: %i\n", rez);
}
