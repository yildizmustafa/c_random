//Mustafa YILDIZ
//G151210058
//PDP 3. ODEV
#include "Kisi.h"

Kisi RastgeleKisiUret(char* isim)
{
		Kisi this=(Kisi)malloc(sizeof(struct KISI));
		this->adSoyad=isim;
		this->yas=rand()%100;
		this->tc=RastgeleKimlikNoOlustur();
		this->tlf=RastgeleTelefonOlustur();
		this->KisiYokEt=_KisiYokEt;
		return this;
}
Kisi DosyadanKisi(char* kimlik,char* ad,char*soyad,int yasi,char* tel ,char* imei)
{
	Kisi this=(Kisi)malloc(sizeof(struct KISI));
	this-> adSoyad=ad;
	strcat(this->adSoyad," ");
	strcat(this->adSoyad,soyad);
	this->yas=yasi;
	this->tlf=DosyadanTelefon(tel,imei);
	this->tc=DosyadanTC(kimlik);
	this->KisiYokEt=_KisiYokEt;
	//printf("%s\n",this->adSoyad);
	return this;
}
void _KisiYokEt(const Kisi this)
{
	if(this==NULL)
		return;
	//free(this->adSoyad);
	this->tc->TCYokEt(this->tc);
	this->tlf->TelefonYokEt(this->tlf);
	free(this);
	
}