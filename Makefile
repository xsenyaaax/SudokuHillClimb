CXX=g++
LD=g++
AR=ar
CXXFLAGS=-std=c++20 -Wall -pedantic -g

OBJS = main.o SudokuBoard.o NeighborGenerator.o RandPosFill.o HillClimb.o SwapTwoRandom.o BestPosFill.o
TARGET = sudoku

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(TARGET) *~ core  Makefile.d

-include Makefile.d

main.o: main.cpp HillClimb.hpp SudokuBoard.hpp NeighborGenerator.hpp
NeighborGenerator.o: NeighborGenerator.cpp NeighborGenerator.hpp SudokuBoard.hpp
RandPosFill.o: RandPosFill.cpp RandPosFill.hpp NeighborGenerator.hpp SudokuBoard.hpp
SudokuBoard.o: SudokuBoard.cpp SudokuBoard.hpp
SwapTwoRandom.o: SwapTwoRandom.cpp SwapTwoRandom.hpp NeighborGenerator.hpp SudokuBoard.hpp
BestPosFill.o: BestPosFill.cpp BestPosFill.hpp NeighborGenerator.hpp SudokuBoard.hpp