//
// Created by senyaaa on 4/12/2024.
//
#include "SudokuBoard.hpp"

#ifndef BI_ZUM_2024_POGODARS_NEIGHBORGENERATOR_HPP
#define BI_ZUM_2024_POGODARS_NEIGHBORGENERATOR_HPP


class NeighborGenerator {
public:
    NeighborGenerator() = default;
    NeighborGenerator(const NeighborGenerator & neighborGenerator) = default;
    virtual ~NeighborGenerator() = default;
    virtual void generatorNeighbor(SudokuBoard & state) const = 0;
};

#endif //BI_ZUM_2024_POGODARS_NEIGHBORGENERATOR_HPP
