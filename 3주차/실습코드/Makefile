cc=g++
cflags = -W -g
target = main
source = main.cpp array.cpp rangearray.cpp
objects = main.o array.o rangearray.o

all : $(target)

$(target) : $(objects)
	$(cc) $(cflags) -o $(target) $(objects)

%.o : %.cpp
	$(cc) $(cflags) -c -o $@ $<

main.o : Array.h RangeArray.h
array.o : Array.h
rangearray.o : RangeArray.h Array.h

.PHONY : clean
clean :
	rm $(target) $(objects)
