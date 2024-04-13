//
// Created by senyaaa on 4/12/2024.
//

#include "SwapTwoRandom.hpp"

/**
 * Just swaps two random cells, not good tactic, relies on correct starting state
 */
void SwapTwoRandom::generatorNeighbor(SudokuBoard &state) const {
    std::random_device rd;
    std::mt19937 gen(rd());
    if (state.toFill.empty())
        return;
    int pos1 = 0;
    int pos2 = 0;
    if (state.toFill.size() >= 1) {
        std::uniform_int_distribution<int> dist(0, state.toFill.size() - 1);
        pos1 = dist(gen);
        pos2 = dist(gen);
        while (pos1 == pos2){
            pos1 = dist(gen);
            pos2 = dist(gen);
        }
    }
    int x1 = state.toFill[pos1].first, y1 = state.toFill[pos1].second;
    int x2 = state.toFill[pos2].first, y2 = state.toFill[pos2].second;
    std::swap(state.board[x1][y1], state.board[x2][y2]);
}
