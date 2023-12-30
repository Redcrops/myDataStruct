arrayList:main.o arrayList.o
	gcc main.o arrayList.o -o arrayList

main.o:main.c
	gcc -c main.c -o main.o

arrayList.o:arrayList.c
	gcc -c arrayList.c -o arrayList.o

clean:
	@rm -rf *.o arrayList