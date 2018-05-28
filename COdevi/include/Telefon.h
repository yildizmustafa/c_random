#ifndef TELEFON_H
#define TELEFON_H
#include "IMEINo.h"
#include "stdio.h"
#include "stdlib.h"
struct TELEFON
{
	char* telefonNo;
	ImeiNo imei;
	void (*TelefonYokEt)(struct TELEFON*);
};
typedef struct TELEFON* Telefon;
Telefon RastgeleTelefonOlustur();
Telefon DosyadanTelefon(char*,char*);
void _TelefonYokEt(const Telefon);

#endif