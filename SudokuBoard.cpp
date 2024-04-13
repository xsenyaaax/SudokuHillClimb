//
// Created by senyaaa on 4/10/2024.
//

#include "SudokuBoard.hpp"

SudokuBoard::SudokuBoard(size_t subgridSize) : subgridSize(subgridSize) {
    size_t boardSize = subgridSize * subgridSize;
    board.resize(boardSize, std::vector<int>(boardSize,0));
}

SudokuBoard::SudokuBoard(const std::vector<std::vector<int>> & tmp) : board(tmp) {
    subgridSize = board.size() ;
    for (size_t i = 0; i < board.size(); i ++){
        for (size_t j = 0; j < board[i].size(); j++ ){
            if (board[i][j] == 0) toFill.emplace_back(i,j);
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

            os << std::setw(2) << std::setfill('0') <<  sudoku.board[i][j] << " ";
        }
        os << std::endl;

    }
    return os;
}

void SudokuBoard::setValue(size_t row, size_t col, int val) {
    board[row][col] = val;
}

size_t SudokuBoard::getBoardSize() const{
    return board.size();
}




