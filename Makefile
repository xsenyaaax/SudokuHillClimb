CXX=g++
LD=g++
AR=ar
CXXFLAGS=-std=c++20 -Wall -pedantic -g

OBJS = main.o
TARGET = sudoku

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(TARGET) *~ core  Makefile.d

-include Makefile.d
