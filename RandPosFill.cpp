//
// Created by senyaaa on 4/12/2024.
//
#include "RandPosFill.hpp"
/*
 * Pick random cell from cells to fill and generates random number in it
 */
void RandPosFill::generatorNeighbor(SudokuBoard &state) const {
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
    std::uniform_int_distribution<size_t> numgen(1, boardSize);
    int num = numgen(gen);
    state.setValue(state.toFill[pos].first, state.toFill[pos].second, num);
}
