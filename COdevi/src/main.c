//Mustafa YILDIZ
//G151210058
//PDP 3. ODEV
#include "RastgeleKisi.h"
#include <time.h>
int main(int argc,char**argv)
{
	srand(time(NULL));
	RastgeleKisi k=RastgeleKisiOlustur();
	
	int secim;
	int don=1;
	while(don)
	{		
		printf("1- Rastgele Kisi Uret\n2- Uretilmis Dosyayi Kontrol Et\n3- Cikis\n");
		scanf("%d",&secim);
		switch(secim)
		{
			case 1:
				printf("\nKac kisi uretmek istiyorsunuz: ");
				int sayi;
				scanf("%d",&sayi);
				k->KisiUret(k,sayi);
			break;
			case 2:
				k->KisileriDogrula(k);
			break;
			case 3:
				don=0;
			break;
			
		}
	}
	//k->KisiUret(k,1000);
	//k->KisileriDogrula(k);
	k->YokEt(k);
	return 0;
}