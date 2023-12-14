CC = g++
CFLAGS = -Wall -Iincludes -std=c++20

SOURCES = $(wildcard src/*.cpp)

TARGET = prog

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -rf $(TARGET)