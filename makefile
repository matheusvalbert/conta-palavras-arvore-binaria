### Makefile ###
#Para compilar digite no terminal "make project"
project:
	gcc -c ST.h
	gcc -c STb.h
	gcc -c Item.h
	gcc -c ST.c
	gcc -c STb.c
	gcc -c Item.c
	gcc -c main.c
	gcc -o Projeto2 main.o ST.o Item.o STb.o
	./Projeto2 < tale.txt -b
	rm -rf *.o
	rm -rf *.h.gch
	rm -rf Projeto2
	#clear
