//
// Created by senyaaa on 4/12/2024.
//
#pragma once
#include "NeighborGenerator.hpp"
#ifndef BI_ZUM_2024_POGODARS_BESTPOSFILL_HPP
#define BI_ZUM_2024_POGODARS_BESTPOSFILL_HPP


class BestPosFill : public NeighborGenerator{
    void generatorNeighbor(SudokuBoard & state) const override;
};


#endif //BI_ZUM_2024_POGODARS_BESTPOSFILL_HPP
