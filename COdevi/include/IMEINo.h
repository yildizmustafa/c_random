#ifndef IMEINO_H
#define IMEINO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct IMEINO
{
	char * imeiNo;
	int (*ImeiOnayla)(struct IMEINO*);
	void (*ImeiYokEt)(struct IMEINO*);
};
typedef struct IMEINO* ImeiNo;
ImeiNo RastgeleIMEIOlustur();
ImeiNo DosyadanImei(char*);
int _ImeiOnayla(const ImeiNo);
void _ImeiYokEt(const ImeiNo);


#endif 