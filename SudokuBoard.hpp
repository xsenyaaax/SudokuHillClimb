//
// Created by senyaaa on 4/10/2024.
//
#include <vector>
#include <iomanip>
#include <set>

#ifndef BI_ZUM_2024_POGODARS_SUDOKUBOARD_HPP
#define BI_ZUM_2024_POGODARS_SUDOKUBOARD_HPP


class SudokuBoard {
public:
    std::vector<std::vector<int>> board;
    std::set< std::pair<int,int> > givenNumbers;
    size_t subgridSize;
    std::vector< std::pair<int,int> > toFill;

    SudokuBoard(size_t subgridSize);
    SudokuBoard(std::vector<std::vector<int>> tmp); // NOLINT(*-explicit-constructor)

    void setValue(size_t row, size_t col, int val);
    bool isGiven(size_t row, size_t col) const;
    size_t getSubgridsize() const;
    size_t getBoardSize() const;
    friend std::ostream& operator<<(std::ostream &os, const SudokuBoard & sudoku);
};


#endif //BI_ZUM_2024_POGODARS_SUDOKUBOARD_HPP
