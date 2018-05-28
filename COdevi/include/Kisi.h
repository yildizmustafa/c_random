#ifndef KISI_H
#define KISI_H
#include "Telefon.h"
#include "KimlikNo.h"
#include "stdio.h"
#include "stdlib.h"
struct KISI
{
	char* adSoyad;
	int yas;
	Telefon tlf;
	KimlikNo tc;
	void (*KisiYokEt)(struct KISI*);
};
typedef struct KISI* Kisi;
Kisi RastgeleKisiUret(char*);
Kisi DosyadanKisi(char*,char*,char*,int,char*,char*);
void _KisiYokEt(const Kisi);

#endif