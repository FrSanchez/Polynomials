CXX=clang++
CXXFLAGS=-g -std=c++11 -Wall -pedantic
BIN=poly

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^ 

%.o: %.c
	$(CXX) $@ -c $<  $(CFLAGS)

clean:
	rm -f *.o
	rm $(BIN)
