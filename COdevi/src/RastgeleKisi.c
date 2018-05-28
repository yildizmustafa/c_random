//Mustafa YILDIZ
//G151210058
//PDP 3. ODEV
#include "RastgeleKisi.h"
#define ISIM_BUFFER 1024
#define MAXCHAR 64
char ** DosyaOku();
int getL(char **);
RastgeleKisi RastgeleKisiOlustur()
{
	RastgeleKisi this=(RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));
	this->isimler=DosyaOku();
	this->KisiUret=&_KisiUret;
	this->KisileriDogrula=&_KisileriDogrula;
	this->YokEt=&_YokEt;
	//printf("sizeof %d\n",getL(this->isimler));
	//printf("%s\n",this->isimler[1]);
	
}

char ** DosyaOku()
{
	FILE * fp;
    char line[MAXCHAR];
    size_t len = 0;
    ssize_t read;

    fp = fopen("./bin/random_isimler.txt", "r");
    if (fp == NULL)
        exit(1);
	
	int i=0;
	int buf=ISIM_BUFFER;
	char ** temp=malloc(sizeof(char **) * ISIM_BUFFER);
	temp[0]=malloc(sizeof(char)*MAXCHAR);
   // while ((read = getline(&line, &len, fp)) != -1)
	   while (fgets(temp[i], MAXCHAR, fp) != NULL)
	{
		if(i+1==buf)
		{
			temp=realloc(temp,sizeof(char *)*(i+1+ISIM_BUFFER));
			buf+=buf;			
		}
		strtok(temp[i],"\n");
		i++;
		temp[i]=malloc(sizeof(char)*MAXCHAR);
		
    }
	temp[i+1]='\0';
    fclose(fp);
	return temp;
}
void _KisiUret(const RastgeleKisi this,int adet)
{
	Kisi *kisiler=malloc(sizeof(struct KISI)*adet);
	int isimL=getL(this->isimler);
	int r;
	FILE *yaz=fopen("./bin/Kisiler.txt","w");
	if(yaz==NULL)
		exit(1);
	for(int i=0;i<adet;i++)
	{
		r=rand()%isimL;
		//printf("%s\n",this->isimler[r]);
		kisiler[i]=RastgeleKisiUret(this->isimler[r]);
		fprintf(yaz,"%s %s %d %s (%s)\n",kisiler[i]->tc->kimlikNo,this->isimler[r],kisiler[i]->yas,kisiler[i]->tlf->telefonNo,kisiler[i]->tlf->imei->imeiNo);
		kisiler[i]->KisiYokEt(kisiler[i]);
	}
	fclose(yaz);
}
void _KisileriDogrula(const RastgeleKisi this)
{
	FILE * oku=fopen("./bin/Kisiler.txt","r");
	char kimlik[16];
	char ad[24];
	char soyad[24];
	int yas;
	char tel[16];
	char imei[20];
	Kisi birKisi;
	int gecerliTc=0;
	int gecersizTc=0;
	int gecerliImei=0;
	int gecersizImei=0;
	while(fscanf(oku,"%s %s %s %d %s %s",kimlik,ad,soyad,&yas,tel,imei) !=EOF)
	{
		birKisi=malloc(sizeof(struct KISI));
		birKisi=DosyadanKisi(kimlik,ad,soyad,yas,tel,imei);
		if(birKisi->tc->TCOnayla(birKisi->tc)==0)
			gecerliTc++;
		else
			gecersizTc++;
		if(birKisi->tlf->imei->ImeiOnayla(birKisi->tlf->imei)==0)
			gecerliImei++;
		else
			gecersizImei++;
		//printf("%s %s %s %d %s %s \n",kimlik,ad,soyad,yas,tel,imei);
		birKisi->KisiYokEt(birKisi);
	}
	printf("Gecerli TC: %d \nGecersiz TC: %d\nGecerli IMEI: %d\nGecersiz IMEI: %d\n",gecerliTc,gecersizTc,gecerliImei,gecersizImei);
	fclose(oku);
}
int getL(char ** isimler)
{
	int i=0;
	while(isimler[i]!=NULL)
	{
		//printf("%s\n",isimler[i]);
		i++;
	}
	return i-1;
}
void _YokEt(const RastgeleKisi this)
{
	if(this==NULL)
		return;
	int sinir=getL(this->isimler);
	for(int i=0; i<sinir;i++)
		free(this->isimler[i]);
	free(this);
	
}