//Mustafa YILDIZ
//G151210058
//PDP 3. ODEV

#include "IMEINo.h"
char *  ImeiOlustur();
ImeiNo RastgeleIMEIOlustur()
{
	ImeiNo this=(ImeiNo)malloc(sizeof(struct IMEINO));
	this->imeiNo=ImeiOlustur();
	this->ImeiOnayla=&_ImeiOnayla;
	this->ImeiYokEt=&_ImeiYokEt;
	return this;
}
ImeiNo DosyadanImei(char* im)
{
	ImeiNo this=(ImeiNo)malloc(sizeof(struct IMEINO));
	this->imeiNo=im;
	this->ImeiOnayla=&_ImeiOnayla;
	this->ImeiYokEt=&_ImeiYokEt;
	return this;
}
char * ImeiOlustur()
{
	char * im=malloc(sizeof(char)*16);
	int r;
	do
	{
		r=rand()%10;
		im[0]=r+'0';
	}while(r==0);
	
	int tekToplam=r;
	int ciftToplam=0;
	for(int i=1;i<14;i++)
	{
		r=rand()%10;
		if(i%2==0)
			tekToplam+=r;
		else
			ciftToplam=ciftToplam+(r*2)/10+(r*2)%10;
		im[i]=r+'0';
	}
	im[14]=((10-(ciftToplam+tekToplam)%10)%10)+'0';
	im[15]='\0';
	return im;
}
int _ImeiOnayla(const ImeiNo this)
{
	if(strlen(this->imeiNo)!=17)
	{
		printf("strlen %d\n",strlen(this->imeiNo));
		//printf(17==strlen(this->imeiNo));
		return 1;
	}
	int tekToplam=0;
	int ciftToplam=0;
	for(int i=1;i<15;i++)
	{
		if(i%2==1)
			tekToplam+=(this->imeiNo[i]-'0');
		else
			ciftToplam=ciftToplam+((this->imeiNo[i]-'0')*2)/10+((this->imeiNo[i]-'0')*2)%10;
	}
	int cHane=(10-(ciftToplam+tekToplam)%10)%10;
	if(cHane==this->imeiNo[15]-'0')
		return 0;
	return 2;
}

void _ImeiYokEt(const ImeiNo this)
{
	if(this==NULL)
		return;
	//free(this->imeiNo);
	free(this);
}
