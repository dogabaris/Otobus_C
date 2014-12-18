#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

char starih[50];

struct Sefer{
	char no[10];
	char guzergah[100];
    char tarih[20];
    char saat[20];
    int kapasite[1];
    char fiyat[15];
    char plaka[10];
    char koltuk[20];
    char kaptan[50];
    Sefer *sonraki, *onceki;
};
struct Sefer *ilk, *son, *gecici;

////////////////////////////////////////////////////////Sefer Ekleme blogu
void Sefer_Ekle(){

int i=0;

if(ilk==NULL){// ilk kayitsa

ilk = (Sefer *) malloc(sizeof(struct Sefer));

printf("ilk Sefer No Giriniz : ");
fflush(stdin); 
scanf("%s",ilk->no);

printf("ilk G�zergah� Giriniz : ");
fflush(stdin); 
scanf("%s",ilk->guzergah);

printf("ilk Tarih Giriniz : ");
fflush(stdin);
scanf("%s",ilk->tarih);

printf("ilk Saat Giriniz : ");
fflush(stdin);
scanf("%s",ilk->saat);

printf("ilk Kapasite Giriniz : ");
fflush(stdin);
scanf("%d",ilk->kapasite);

printf("ilk Fiyat Giriniz : ");
fflush(stdin);
scanf("%s",ilk->fiyat);

printf("ilk Plaka Giriniz : ");
fflush(stdin);
scanf("%s",ilk->plaka);

printf("ilk Kaptan Giriniz : ");
fflush(stdin);
gets(ilk->kaptan);

ilk->sonraki = NULL;
ilk->onceki = NULL;//ikinci ba�.
son = ilk;

sprintf(starih,"%s.txt",ilk->tarih);
int *kkapasite=ilk->kapasite;

FILE *dosya = fopen(starih, "a");//gg.aa.yy.txt �eklinde yaz�lmas� kayd�,
fprintf(dosya,"No       : %s\n",ilk->no);
fprintf(dosya,"Guzergah : %s\n",ilk->guzergah);
fprintf(dosya,"Tarih    : %s\n",ilk->tarih);
fprintf(dosya,"Saat     : %s\n",ilk->saat);
fprintf(dosya,"Koltuk   : ");
for(i=0;i<*kkapasite;i++)
{
	fprintf(dosya,"%d.B ",i+1);
}
fprintf(dosya,"\n");
fprintf(dosya,"Kapasite : %d\n",*kkapasite);
fprintf(dosya,"Fiyat    : %s\n",ilk->fiyat);
fprintf(dosya,"Plaka    : %s\n",ilk->plaka);
fprintf(dosya,"Kaptan   : %s\n \n \n",ilk->kaptan);

fclose(dosya);
}

else if(son == ilk){// ikinci kayitsa

son = (Sefer *) malloc(sizeof(struct Sefer));

printf("Sefer No Giriniz : ");
fflush(stdin); 
scanf("%s",son->no);

printf("G�zergah� Giriniz : ");
fflush(stdin); 
scanf("%s",son->guzergah);

printf("Tarih Giriniz : ");
fflush(stdin);
scanf("%s",son->tarih);

printf("Saat Giriniz : ");
fflush(stdin);
scanf("%s",son->saat);

printf("Kapasite Giriniz : ");
fflush(stdin);
scanf("%d",son->kapasite);

printf("Fiyat Giriniz : ");
fflush(stdin);
scanf("%s",son->fiyat);

printf("Plaka Giriniz : ");
fflush(stdin);
scanf("%s",son->plaka);

printf("Kaptan Giriniz : ");
fflush(stdin);
gets(son->kaptan);

ilk->sonraki = son;
son->sonraki = NULL;
son->onceki = ilk;//ikinci ba�.

sprintf(starih,"%s.txt",son->tarih);//tarih'i .txt uzant�s�yla birle�tirip yeni stringe atama
int *kkapasite=son->kapasite;


FILE *dosya = fopen(starih, "a");//gg.aa.yy.txt �eklinde yaz�lmas� kayd�,
fprintf(dosya,"No       : %s\n",son->no);
fprintf(dosya,"Guzergah : %s\n",son->guzergah);
fprintf(dosya,"Tarih    : %s\n",son->tarih);
fprintf(dosya,"Saat     : %s\n",son->saat);
fprintf(dosya,"Koltuk   : ");
for(i=0;i<*kkapasite;i++)
{
	fprintf(dosya,"%d.B ",i+1);
}
fprintf(dosya,"\n");
fprintf(dosya,"Kapasite : %d\n",*kkapasite);
fprintf(dosya,"Fiyat    : %s\n",son->fiyat);
fprintf(dosya,"Plaka    : %s\n",son->plaka);
fprintf(dosya,"Kaptan   : %s\n \n \n",son->kaptan);

fclose(dosya);
}

else{// ikiden fazla kay�t varsa

gecici = (Sefer *) malloc(sizeof(struct Sefer));

printf("Sefer No Giriniz : ");
fflush(stdin); 
scanf("%s",gecici->no);

printf("G�zergah� Giriniz : ");
fflush(stdin); 
scanf("%s",gecici->guzergah);

printf("Tarih Giriniz : ");
fflush(stdin);
scanf("%s",gecici->tarih);

printf("Saat Giriniz : ");
fflush(stdin);
scanf("%s",gecici->saat);

printf("Kapasite Giriniz : ");
fflush(stdin);
scanf("%d",gecici->kapasite);

printf("Fiyat Giriniz : ");
fflush(stdin);
scanf("%s",gecici->fiyat);

printf("Plaka Giriniz : ");
fflush(stdin);
scanf("%s",gecici->plaka);

printf("Kaptan Giriniz : ");
fflush(stdin);
gets(gecici->kaptan);

ilk->sonraki = son;
son->sonraki = gecici;
gecici->onceki = son;//bu iki sat�rda gecici sona eklendi.
son = gecici;
son->sonraki = NULL;//bu iki sat�rda da son i�aret�isi son gelen veriye aktar�ld�.

sprintf(starih,"%s.txt",gecici->tarih);
int *kkapasite=gecici->kapasite;

FILE *dosya = fopen(starih, "a");//gg.aa.yy.txt �eklinde yaz�lmas� kayd�,
fprintf(dosya,"No       : %s\n",gecici->no);
fprintf(dosya,"Guzergah : %s\n",gecici->guzergah);
fprintf(dosya,"Tarih    : %s\n",gecici->tarih);
fprintf(dosya,"Saat     : %s\n",gecici->saat);
fprintf(dosya,"Koltuk   : ");
for(i=0;i<*kkapasite;i++)
{
	fprintf(dosya,"%d.B ",i+1);
}
fprintf(dosya,"\n");
fprintf(dosya,"Kapasite : %d\n",*kkapasite);
fprintf(dosya,"Fiyat    : %s\n",gecici->fiyat);
fprintf(dosya,"Plaka    : %s\n",gecici->plaka);
fprintf(dosya,"Kaptan   : %s\n \n \n",gecici->kaptan);

fclose(dosya);
}

}
////////////////////////////////////////////////////////Sefer Ekleme blogu

int Sefer_Iptal(){
	FILE *dosya;
	FILE *temp;//Guncelleme yapmak i�in a��lan ge�ici dosya.
	int tsayac=0;
	int sayac=0;
	int sayac2=0;
	int asayac=0;
	int ksayac=0;
	int dsayac=0;
	int k=9;//�lk koltugun bulundugu karakter
	int kapasitesayac=0;
	int i=1;
	int icsayac=1;
	int kontrolsayac=0;
	int kontrol=0;
	char tarih[100];
	char starih[100];
	char no[1000];
	char sno[1000];
	char satir[500];
	char *psatir = satir;
	char tsatir[1000];
	char *ptsatir = tsatir;
	char ssatir[1000];
	char *pssatir = ssatir;
	char satir2[1000];
	char *psatir2 = satir2;
	char kapasite[50];
	char skoltuk[5];
	char skapasite[50];
	char kelime[50];
	char B[1] = {'B'};
	char *pB = B;
	char harf[1];
	
	printf("�ptal edilecek seferin tarihini giriniz :");
	fflush(stdin);
	scanf("%s",tarih);
	
	printf("Sefer no giriniz :");
	fflush(stdin);
	scanf("%s",no);

	sprintf(starih,"%s.txt",tarih);
	sprintf(sno,"No       : %s",no);
	
	dosya = fopen(starih,"r");
	
	
	
	if (dosya==NULL)
	{
    printf("Dosya bulunamad�!\n");
    exit(1);
	}
	
	while((fscanf(dosya, "%[^\n]", psatir)) != EOF ){//Hangi sat�rlar aras� silinecek asayac a at�l�yor
		sayac++;
		if(strcmp(psatir,sno) == 0) {
			asayac=sayac+9;//silinecek blogun son sat�r�
			ksayac=sayac+4;//koltugun bulundugu sat�r
			kapasitesayac=sayac+5;//kapasitenin tutuldu�u sat�r
      	break;
      	}	
		fgetc(dosya);
	}
	
	fclose(dosya);
	dosya = fopen(starih,"r");
	
	while((fscanf(dosya, "%[^\n]", psatir2)) != EOF ){//Kapasiteyi ��reniyor
		sayac2++;
		if(sayac2==kapasitesayac)
		{
			while(1)
			{
			sprintf(skapasite,"Kapasite : %d",i);
			if(strcmp(skapasite,psatir2)==0)
			{
				
				break;
			}
			i++;	
			}
		}
		fgetc(dosya);
	}
	
	fclose(dosya);
	dosya = fopen(starih,"r");
	
	while((fscanf(dosya, "%[^\n]", ptsatir)) != EOF ){//Biletlerin bo� oldugu kontrol� yap�l�yor..
		dsayac=dsayac+1;
		
		if(dsayac==ksayac){
			
			while(1)
			{
						k=k+4;		
						if(satir[k] == 'B')
						{
							kontrolsayac++;
							if(kontrolsayac==i)
							{
								kontrol=1;
								break;
							}
						}
			}
			
			}
		fgetc(dosya);
	}
	
	fclose(dosya);
	dosya = fopen(starih,"r");
	temp = fopen("temp.txt", "w+");
	
	if(kontrol==1){
	//Koltuklar bo�sa kontrol 1 e e�it oluyor ve silme i�lemi ger�ekle�iyor
		while((fscanf(dosya, "%[^\n]", pssatir)) != EOF ){//Silme i�lemi ve gerisini aynen yazma i�lemi
		tsayac=tsayac+1;
		if(tsayac>=sayac && tsayac<=asayac)
    		{
    			printf(" ");
    		}
    		else
    		{	
    			
				fprintf(temp,"%s\n",pssatir);
			}	
			fgetc(dosya);
	}
	
	fclose(dosya);
	fclose(temp);
	remove(starih);
	rename("Temp.txt", starih);
	}
	if(kontrol==0)
	{
		fclose(dosya);
		fclose(temp);
		printf("Dolu koltuk var veya b�yle bir sefer yok !\n");
	}
	
}
////////////////////////////////////////////////////////
void Kaptan(){
	FILE *dosya;
	FILE *temp;//Guncelleme yapmak i�in a��lan ge�ici dosya.
	int tsayac=0;
	int sayac=0;
	char tarih[100];
	char starih[100];
	char no[1000];
	char sno[1000];
	char satir[500];
	char *psatir = satir;
	char tsatir[500];
	char *ptsatir = tsatir;
	char kaptan[1000];
	char skaptan[1000];
	
	printf("Kaptan de�i�tirilecek seferin tarihini giriniz :");
	fflush(stdin);
	scanf("%s",tarih);
	
	printf("Kaptan de�i�tirilecek sefer no giriniz :");
	fflush(stdin);
	scanf("%s",no);
	
	printf("Yeni kaptan�n ismini giriniz :");
	fflush(stdin);
	gets(kaptan);
	
	sprintf(starih,"%s.txt",tarih);
	sprintf(sno,"No       : %s",no);
	sprintf(skaptan,"Kaptan   : %s",kaptan);
	
	dosya = fopen(starih,"r");
	temp = fopen("temp.txt", "w+");
	
	
	if (dosya==NULL)
	{
    printf("Dosya bulunamad�!\n");
    exit(1);
	}
	
	if (temp==NULL)
	{
    printf("Dosya bulunamad�!\n");
    exit(1);
	}
	
	while((fscanf(dosya, "%[^\n]", psatir)) != EOF ){//kaptan�n bulundugu sat�r aramas� dosya i�inde
		sayac++;
		if(strcmp(psatir,sno) == 0) {
		sayac=sayac+8; //Kaptan�n bilgisinin tutuldugu sat�r� bulur.
      	printf("Kaptan %d. sat�rda !\n",sayac);
      	break;
      	}	
		fgetc(dosya);
	}
	fclose(dosya);
	dosya = fopen(starih,"r");
	
	while((fscanf(dosya, "%[^\n]", ptsatir)) != EOF ){
		tsayac=tsayac+1;
		if(tsayac==sayac)
    		{
    			fprintf(temp,"%s \n",skaptan);
    			printf("esitligi buldu!\n");
    		}
    	else{
    		fprintf(temp,"%s\n",ptsatir);
		}

			fgetc(dosya);
	}
	
	fclose(dosya);
	fclose(temp);
	remove(starih);
	rename("Temp.txt", starih);
	
}
////////////////////////////////////////////////////////
void Listele(){
	char tarih[10];
	char starih[10];
	char satir[150];
	int sayac=0;

	printf("Sefer tarihini giriniz :");
	fflush(stdin);
	gets(tarih);
	sprintf(starih,"%s.txt",tarih);
	
	FILE *dosya = fopen(starih,"r");
	while ((fscanf(dosya, "%[^\n]", satir)) != EOF )
	{
		sayac++;
		printf("%s\n",satir);
		if(sayac%9==0)
		{
			printf("\n");
		}
		fgetc(dosya);
	}
	
	
}
void Bilet_Sat(){
	FILE *dosya;
	FILE *temp;
	int tsayac=0;
	int sayac=0;
	int num;
	int k=13;
	int i=0;
	int j=0;
	int icsayac=1;
	int uzunluk=0;
	int ksayac=0;
	int dsayac=0;
	int dongu=0;
	char tarih[100];
	char starih[100];
	char no[1000];
	char sno[1000];
	char satir[1000];
	char *psatir = satir;
	char tsatir[1000];
	char *ptsatir = tsatir;
	char ssatir[1000];
	char *pssatir = &ssatir[0];
	char yolcuadi[1000];
	char cinsiyet[5];
	char durum;
	char pass[1];
	char koltuksatir[500];
	int main();
	
	printf("Bilet sat�lacak seferin tarihini giriniz :");
	fflush(stdin);
	gets(tarih);
	
	printf("Sefer no giriniz :");
	fflush(stdin);
	gets(no);
	
	printf("Yolcunun ad�n� giriniz :");
	fflush(stdin);
	gets(yolcuadi);
	
	printf("Yolcunun cinsiyetini giriniz :");
	fflush(stdin);
	gets(cinsiyet);
	
	printf("�stenilen koltu�u giriniz :");
	fflush(stdin);
	scanf("%d",&num);
	
	printf("Rezerve etmek i�in R,Satmak i�in D,�ptal i�in B giriniz :");
	fflush(stdin);
	durum=getchar();
	
	sprintf(starih,"%s.txt",tarih);
	sprintf(sno,"No       : %s",no);
	
	dosya = fopen(starih,"r");
	
	
	
	while((fscanf(dosya, "%[^\n]", psatir)) != EOF ){
		sayac++;
		if(strcmp(psatir,sno) == 0) {	
		ksayac=sayac+5; //koltuk bilgisinin tutuldugu sat�r� bulur.
      	
      	break;
      	}	
		fgetc(dosya);
	}
	fclose(dosya);
	dosya = fopen(starih,"r");
	
	while((fscanf(dosya, "%[^\n]", ptsatir)) != EOF ){//O numaradaki biletin bo� oldu�u kontrol� yap�l�yor..
		dsayac=dsayac+1;
		
		if(dsayac==ksayac){
			
			for(i=1;i<num;i++)
			{
				k=k+4;	
			}
						if(tsatir[k] == 'B')
						{
								printf("Koltuk Bo�!\n");
								
						}
						else if(tsatir[k] == 'R')
						{
								printf("Koltuk Rezerve!\n");
						}
						else if(tsatir[k] == 'D')
						{
								printf("Koltuk Dolu!\n");
						}
		}
		
		fgetc(dosya);
	}

			printf("Devam etmek i�in y i�lemi iptal etmek i�in n giriniz :");
			scanf("%s",pass);
			
			
			if(pass[0]=='y')
			{
				k=13;
				fclose(dosya);
				dosya = fopen(starih,"r");
				temp = fopen("temp.txt", "w+");
				while((fscanf(dosya, "%[^\n]", pssatir)) != EOF ){
					
					icsayac=icsayac+1;
					if(icsayac==ksayac)
					{
						k+=(num-1)*4;
						
						while(1){//koltuk sat�r�nda de�i�tirmek	
						
							if(j==k)
								fprintf(temp,"%c",durum);
							
							else
								fprintf( temp,"%c", ssatir[j] );
							if(ssatir[j]=='>')
							{
								break;
							}
						j++;	
						}
						fprintf( temp,"\n");
					}else{
						fprintf(temp,"%s\n",pssatir);
					}
					fgetc(dosya);
				}
				
				
			}
			else
			{
				printf("��lem iptal edildi!\n");
				fclose(dosya);
				fclose(temp);
			}
	fclose(dosya);
	fclose(temp);	
	remove(starih);
	rename("Temp.txt", starih);
	
	
}

void Koltuk_Listele(){
	FILE *dosya;
	FILE *temp;//Guncelleme yapmak i�in a��lan ge�ici dosya.
	int tsayac=0;
	int sayac=0;
	char tarih[100];
	char starih[100];
	char no[1000];
	char sno[1000];
	char satir[500];
	char *psatir = satir;
	char tsatir[500];
	char *ptsatir = tsatir;
	
	printf("Koltuk listelenecek seferin tarihini giriniz :");
	fflush(stdin);
	scanf("%s",tarih);
	
	printf("Sefer no giriniz :");
	fflush(stdin);
	scanf("%s",no);
	
	sprintf(starih,"%s.txt",tarih);
	sprintf(sno,"No       : %s",no);
	
	dosya = fopen(starih,"r");
	
	
	
	if (dosya==NULL)
	{
    printf("Dosya bulunamad�!\n");
    exit(1);
	}
	
	while((fscanf(dosya, "%[^\n]", psatir)) != EOF ){//kaptan�n bulundugu sat�r aramas� dosya i�inde
		sayac++;
		if(strcmp(psatir,sno) == 0) {
		sayac=sayac+4; //Koltuk bilgisinin tutuldugu sat�r� bulur.
      	break;
      	}	
		fgetc(dosya);
	}
	fclose(dosya);
	dosya = fopen(starih,"r");
	while((fscanf(dosya, "%[^\n]", ptsatir)) != EOF ){
		tsayac=tsayac+1;
		if(tsayac==sayac)
    		{
    			printf("%s \n",ptsatir);
    		}
			fgetc(dosya);
	}
	
}


void Sefer_Islem()
{
	
	int main();
	int secim=0;
	printf("|----------------------------|\n\n");
	printf("Sefer ��lemlerine Ho�geldiniz...\n\n");
	printf("1 - Sefer Ekle\n");
	printf("2 - Sefer �ptali\n");
	printf("3 - Kaptan De�i�tirme\n");
	printf("4 - Sefer Listele\n");
	printf("5 - Ana Men�\n");
	printf("|----------------------------|\n\n");
	scanf("%d",&secim);
	printf("\n");
	switch(secim)
	{
		case 1:Sefer_Ekle();main();break;
		case 2:Sefer_Iptal();main();break;
		case 3:Kaptan();main();break;
		case 4:Listele();main();break;	
		case 5:main();break;	
		default:printf("Listeden Se�im Yap�n�z !\n\n");secim=0;main();break;
	}
	
}

void Bilet_Islem()
{

	int main();
	
	int secim=0;
	printf("|----------------------------|\n\n");
	printf("Bilet ��lemlerine Ho�geldiniz...\n\n");
	printf("1 - Bilet Satma/Rezerve etme\n");
	printf("2 - Koltuk Listele\n");
	printf("3 - Ana Men�\n");
	printf("|----------------------------|\n\n");
	scanf("%d",&secim);
	printf("\n");
	switch(secim)
	{
		case 1:Bilet_Sat();main();break;
		case 2:Koltuk_Listele();main();break;
		case 3:main();break;	
		default:printf("Listeden Se�im Yap�n�z !\n\n");secim=0;main();break;
	}
	
}

main()
{
	setlocale(LC_ALL, "Turkish");
	
	int secim=0;
	printf("|----------------------------|\n\n");
	printf("Otobus Uygulamas�na Ho�geldiniz...\n\n");
	printf("1 - Sefer ��lemleri\n");
	printf("2 - Bilet ��lemleri\n");
	printf("3 - ��k��\n");
	printf("|----------------------------|\n\n");
	scanf("%d",&secim);
	printf("\n");
	
	switch(secim)
	{
		case 1:Sefer_Islem();break;
		case 2:Bilet_Islem();break;
		case 3:return 0;break;	
			
		default:printf("Listeden Se�im Yap�n�z !\n\n");secim=0;main();break;
	}
	
	
}
