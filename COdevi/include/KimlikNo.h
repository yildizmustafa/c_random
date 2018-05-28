#ifndef KIMLIKNO_H
#define KIMLIKNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct KIMLIKNO
{
	char * kimlikNo;
	int (*TCOnayla)(struct KIMLIKNO*);
	void (*TCYokEt)(struct KIMLIKNO*);
};
typedef struct KIMLIKNO* KimlikNo;
KimlikNo RastgeleKimlikNoOlustur();
KimlikNo DosyadanTC(char*);
int _TCOnayla(const KimlikNo);
void _TCYokEt(const KimlikNo);

#endif