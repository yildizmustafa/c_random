#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Kisi.h"
struct RASTGELEKISI
{
	char **isimler;
	void (*KisiUret)(struct RASTGELEKISI*,int);
	void (*KisileriDogrula)(struct RASTGELEKISI*);
	void (*YokEt)(struct RASTGELEKISI*);
};
typedef struct RASTGELEKISI* RastgeleKisi;
RastgeleKisi RastgeleKisiOlustur();
void _KisiUret(const RastgeleKisi,int);
void _KisileriDogrula(const RastgeleKisi);
void _YokEt(const RastgeleKisi);

#endif