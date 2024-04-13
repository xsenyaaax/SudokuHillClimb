//
// Created by senyaaa on 4/10/2024.
//
#include <vector>
#include <iomanip>
#include <math.h>

#ifndef BI_ZUM_2024_POGODARS_SUDOKUBOARD_HPP
#define BI_ZUM_2024_POGODARS_SUDOKUBOARD_HPP

/**
 * Class that represents Sudokuboard, kinda intuitive
 */
class SudokuBoard {
public:
    std::vector<std::vector<int>> board;
    size_t subgridSize; // number of squares in 1 subgrid
    std::vector< std::pair<int,int> > toFill; // cells that are need to be filled, used in neighbor generators

    SudokuBoard(size_t subgridSize);
    SudokuBoard(const std::vector<std::vector<int>> & tmp); // NOLINT(*-explicit-constructor)

    void setValue(size_t row, size_t col, int val);
    bool isGiven(size_t row, size_t col) const;
    size_t getBoardSize() const;
    friend std::ostream& operator<<(std::ostream &os, const SudokuBoard & sudoku);
};


#endif //BI_ZUM_2024_POGODARS_SUDOKUBOARD_HPP
