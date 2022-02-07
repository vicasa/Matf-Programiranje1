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

int broj_dana_godina(int godina){
	if(godina==0) return 0; /*ovo je korisno ako se racuna broj dana izmedju dva datuma od kojih je jedan pre, a drugi posle nove ere*/
	return prestupna(godina) ? 366 : 365;
}

int do_nove_godine(int dan, int mesec, int godina){
	int ong=od_nove_godine(dan, mesec, godina);
	if(ong==-1) return -1;
	return broj_dana_godina(godina)-1-ong;
}

/*
broj_dana_izmedju vraca koliko ima dana (datuma) izmedju dva datuma iskljucujuci jedan od njih,
tako da za dva uzastopna datuma vraca 1, a za dva ista datuma vraca 0.
*/
int broj_dana_izmedju(int dan1, int mesec1, int godina1, int dan2, int mesec2, int godina2){
	if(!( ispravan(dan1,mesec1,godina1) && ispravan(dan2,mesec2,godina2) )) return -1;
	int rez=0;
	if(godina2 < godina1){/*namestamo da oznake sa indeksom 1 predstavljaju stariji (manji) datum*/
		int dan=dan1, mesec=mesec1, godina=godina1;
		dan1=dan2;
		mesec1=mesec2;
		godina1=godina2;
		dan2=dan;
		mesec2=mesec;
		godina2=godina;
	}
	int ong1=od_nove_godine(dan1,mesec1,godina1), ong2=od_nove_godine(dan2,mesec2,godina2);
	if(godina2 == dodina1){
		rez=ong2-ong1;
		return rez>=0? rez: -rez;
	}
	printf("%i.%i.%i.\n",dan1,mesec1,godina1);
	for(int i=godina1+1; i<godina2; i++) rez += broj_dana_godina(i); /*dodajemo dane godina koje su strogo izmedju godina posmatranih datuma */
	
	return rez+ong2+do_nove_godine(dan1, mesec1, godina1)+1;
}

int main(){
	int dan1, mesec1, godina1, dan2, mesec2, godina2, rez;
	printf("Unesite prvi datum: ");
	scanf("%i.%i.%i.", &dan1, &mesec1, &godina1);
	printf("Unesite drugi datum: ");
	scanf("%i.%i.%i.", &dan2, &mesec2, &godina2);
	rez= broj_dana_izmedju(dan1, mesec1, godina1, dan2, mesec2, godina2);
	if (rez==-1) printf("Neispravan unos!\n");
	else printf("Broj dana izmedju dva datuma je: %i\n", rez);
}
