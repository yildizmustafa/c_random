//Mustafa YILDIZ
//G151210058
//PDP 3. ODEV
#include "Telefon.h"
char * TelefonUret();
Telefon RastgeleTelefonOlustur()
{
	Telefon this=(Telefon)malloc(sizeof(struct TELEFON));
	this->telefonNo=TelefonUret();
	this->imei=RastgeleIMEIOlustur();
	this->TelefonYokEt=&_TelefonYokEt;
	return this;
}
Telefon DosyadanTelefon(char *tel,char* imei)
{
	Telefon this=(Telefon)malloc(sizeof(struct TELEFON));
	this->telefonNo=tel;
	this->imei=DosyadanImei(imei);
	this->TelefonYokEt=&_TelefonYokEt;
	return this;
}
char *TelefonUret()
{
	char * tel=malloc(sizeof(char)*12);
	tel[0]='0';
	tel[1]='5';
	int r;
	do
	{
		r=rand()%10;
		tel[2]=r+'0';
	}while(r==0);
	for(int i=3;i<11;i++)
	{
		r=rand()%10;
		tel[i]=r+'0';
	}
	tel[11]='\0';
	return tel;
	
}

void  _TelefonYokEt(const Telefon this)
{
	if(this==NULL)
		return;
	//this->imei->ImeiYokEt(this->imei);
	free(this->telefonNo);
	free(this);
}