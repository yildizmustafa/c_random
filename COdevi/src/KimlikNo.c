//Mustafa YILDIZ
//G151210058
//PDP 3. ODEV
#include "KimlikNo.h"

char * TcUret();
KimlikNo RastgeleKimlikNoOlustur()
{
	KimlikNo this=(KimlikNo)malloc(sizeof(struct KIMLIKNO));
	this->kimlikNo=TcUret();
	this->TCOnayla=&_TCOnayla;
	this->TCYokEt=&_TCYokEt;
	return this;
}
KimlikNo DosyadanTC(char * k)
{
	KimlikNo this=(KimlikNo)malloc(sizeof(struct KIMLIKNO));
	this->kimlikNo=k;
	this->TCOnayla=&_TCOnayla;
	this->TCYokEt=&_TCYokEt;
	return this;
}
int _TCOnayla(const KimlikNo this)
{
	//printf("strlen %d",strlen(this->kimlikNo));
	if(strlen(this->kimlikNo)!=11)
	{
		//printf("strlen %d = %s\n",strlen(this->kimlikNo),this->kimlikNo);
		return 1;
	}
	int ciftToplam=0;
	int tekToplam=0;
	for(int i=0;i<=8;i++)
	{
		if(i%2==0)
			tekToplam+=(this->kimlikNo[i]-'0');
		else
			ciftToplam+=(this->kimlikNo[i]-'0');
	}
	int cHane10=(tekToplam*7-ciftToplam)%10;
	int cHane11=(tekToplam+ciftToplam+cHane10)%10;
	if(cHane10==this->kimlikNo[9]-'0' && cHane11==this->kimlikNo[10]-'0')
		return 0;
	return 2;
}
char * TcUret()
{
	char * tc=malloc(sizeof(char)*12);
	int r;
	do
	{
		r=rand()%10;
		tc[0]=r+'0';
	}while(r==0);
	int tekToplam=r;
	int ciftToplam=0;
	for(int i=1;i<9;i++)
	{
		r=rand()%10;
		if(i%2==0)
			tekToplam+=r;
		else
			ciftToplam+=r;
		tc[i]=r+'0';		
	}
	int hane10=(tekToplam*7-ciftToplam)%10;
	int hane11=(tekToplam+ciftToplam+hane10)%10;
	tc[9]=hane10+'0';
	tc[10]=hane11+'0';
	tc[11]='\0';
	return tc;
}

void _TCYokEt(const KimlikNo this)
{
	if(this==NULL)
		return;
	//free(this->kimlikNo);
	free(this);
}