linkList:linkList.o main.o
	gcc linkList.o main.o -o linkList
linkList.o:linkList.c
	gcc -c linkList.c -o linkList.o
main.o:main.c
	gcc -c main.c -o main.o
clean:
	@rm -rf *.o linkList