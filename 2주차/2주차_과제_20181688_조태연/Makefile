cc=gcc
cflags = -W -g
target = main

objects = main.o count.o output.o

$(target) : $(objects)
	$(cc) $(cflags) -o $(target) $(objects)

%.o : %.c
	$(cc) $(cflags) -c -o $@ $<

main.o count.o output.o : Header.h

.PHONY : clean
clean :
	rm $(target) $(objects)
