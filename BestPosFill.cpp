//
// Created by senyaaa on 4/12/2024.
//

#include <random>
#include "BestPosFill.hpp"

void BestPosFill::generatorNeighbor(SudokuBoard &state) const {
    size_t boardSize = state.getBoardSize();
    std::random_device rd;
    std::mt19937 gen(rd());
    if (state.toFill.empty())
        return;
    int pos = 0;
    if (state.toFill.size() > 1) {
        std::uniform_int_distribution<int> dist(0, state.toFill.size() - 1);
        pos = dist(gen);
    }

    size_t row = state.toFill[pos].first;
    size_t col = state.toFill[pos].second;

    std::vector<int> rowCollisions(boardSize + 1, 0);
    std::vector<int> colCollisions(boardSize + 1, 0);
    for (size_t num = 1; num <= boardSize; ++num) {
        for (size_t i = 0; i < boardSize; ++i) {
            if (state.board[row][i] == (int)num) {
                rowCollisions[num]++;
            }
            if (state.board[i][col] == (int)num) {
                colCollisions[num]++;
            }
        }
    }

    int minCollisions = std::numeric_limits<int>::max();
    int candidateNum = 0;
    for (size_t num = 1; num <= boardSize; ++num) {
        int totalCollisions = rowCollisions[num] + colCollisions[num];
        if (totalCollisions < minCollisions) {
            minCollisions = totalCollisions;
            candidateNum = num;
        }
    }

    state.setValue(row, col, candidateNum);
}
