//
// Created by senyaaa on 4/10/2024.
//

#include "SudokuBoard.hpp"
#include <math.h>

SudokuBoard::SudokuBoard(size_t subgridSize) : subgridSize(subgridSize) {
    size_t boardSize = subgridSize * subgridSize;
    board.resize(boardSize, std::vector<int>(boardSize,0));
}

SudokuBoard::SudokuBoard(std::vector<std::vector<int>> tmp) : board(std::move(tmp)) {
    subgridSize = board.size() ;
    for (size_t i = 0; i < board.size(); i ++){
        for (size_t j = 0; j < board[i].size(); j++ ){
            if (board[i][j] != 0) givenNumbers.insert({i,j});
            else toFill.emplace_back(i,j);
        }
    }
}


std::ostream &operator<<(std::ostream &os, const SudokuBoard &sudoku) {
    for (size_t i = 0; i < sudoku.board.size(); i++){
        if (i > 0 && i % (int)std::sqrt(sudoku.subgridSize) == 0){
            for (size_t k = 0; k < sudoku.board.size() * 2 + (int)std::sqrt(sudoku.subgridSize) - 1; ++k) {
                os << "-";
            }
            os << std::endl;
        }
        for (size_t j = 0; j < sudoku.board[i].size(); ++j) {
            // Print vertical line between subgrids
            if (j > 0 && j % (int)std::sqrt(sudoku.subgridSize) == 0) {
                os << "|";
            }

            os << sudoku.board[i][j] << " ";
        }
        os << std::endl;

    }
    return os;
}

void SudokuBoard::setValue(size_t row, size_t col, int val) {
    board[row][col] = val;
}

size_t SudokuBoard::getSubgridsize() const{
    return subgridSize;
}

size_t SudokuBoard::getBoardSize() const{
    return board.size();
}

bool SudokuBoard::isGiven(size_t row, size_t col) const {
    return givenNumbers.count({row, col}) == 1;
}



