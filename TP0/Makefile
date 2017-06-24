solve: celula.o pilha.o solve.o main.o
	gcc solve.o main.o -o solve #inserir comentário mais compentario
main.o: main.c solve.h
	gcc -g -c main.c
solve.o: solve.c solve.h pilha.h
	    gcc -g -c solve.c
pilha.o: pilha.c pilha.h celula.h
	 gcc -g -c pilha.c 
celula.o: celula.c celula.h
	 gcc -g -c celula.c 
clean:
	rm *.o *.gch
	rm solve
