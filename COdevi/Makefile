hepsi: derle bagla calistir

derle:
	gcc -I ./include/ -o ./lib/RastgeleKisi.o -c ./src/RastgeleKisi.c
	gcc -I ./include/ -o ./lib/IMEINo.o -c ./src/IMEINo.c
	gcc -I ./include/ -o ./lib/KimlikNo.o -c ./src/KimlikNo.c
	gcc -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.c
	gcc -I ./include/ -o ./lib/Telefon.o -c ./src/Telefon.c
	
bagla:	
	gcc -I ./include/ -o ./bin/Test ./lib/RastgeleKisi.o ./lib/Kisi.o ./lib/KimlikNo.o ./lib/IMEINo.o ./lib/Telefon.o ./src/main.c
	
calistir:
	
	./bin/Test