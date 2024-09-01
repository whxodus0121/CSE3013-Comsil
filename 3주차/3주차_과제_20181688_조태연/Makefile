CC = g++
CFLAGS = -g -c

OBJECTS = main.o str.o
SRC = main.cpp str.cpp

TARGET = main

$(TARGET): $(OBJECTS) str.h
	$(CC) -o $(TARGET) $(OBJECTS)

clean: 
	rm $(OBJECTS) $(TARGET)
