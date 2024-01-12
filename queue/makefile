TARGET=queue
OBJ=arrayList.o main.o queue.o

$(TARGET):$(OBJ)
	gcc $^ -o $@

arrayList.o:arrayList.c
	gcc -c $^ -o $@

main.o:main.c
	gcc -c $^ -o $@

queue.o:queue.c
	gcc -c $^ -o $@

clean:
	@rm -rf *.o queue