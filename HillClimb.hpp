//
// Created by senyaaa on 4/12/2024.
//
#pragma once
#include "SudokuBoard.hpp"
#include "NeighborGenerator.hpp"
#ifndef BI_ZUM_2024_POGODARS_HILLCLIMB_HPP
#define BI_ZUM_2024_POGODARS_HILLCLIMB_HPP


class HillClimb {
private:
    SudokuBoard board;
    std::unique_ptr<NeighborGenerator> neighborGenerator;
public:
    HillClimb(SudokuBoard & sudokuBoard, int neighborGenChoice);

    void generateStartingState(SudokuBoard & sudokuBoard);
    int calculateScore(const SudokuBoard & state) const;
    bool climb();
};


#endif //BI_ZUM_2024_POGODARS_HILLCLIMB_HPP
