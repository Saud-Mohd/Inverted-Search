OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
sll.exe : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o	